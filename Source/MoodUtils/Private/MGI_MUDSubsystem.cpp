// Fill out your copyright notice in the Description page of Project Settings.


#include "MGI_MUDSubsystem.h"

const FMUDDataDefine* UMGI_MUDSubsystem::GetMUDDataDefine(FName Name) 
{
	const UMUDConfigDataAsset* Config = GetConfig();
	if (Config && Config->DataDefines.Contains(Name))
	{
		return &Config->DataDefines[Name];
	}
	return nullptr;
}

UMUDData* UMGI_MUDSubsystem::GetData(FName TableName, const UMUDKey* RowKey)
{
	const FMUDDataDefine* DataDefine = GetMUDDataDefine(TableName);
	UMUDSourceHandler* Handler = GetHandler(DataDefine);
	if (Handler)
	{
		return Handler->GetDataBy(DataDefine->TableKey, RowKey, DataDefine->DataDesc);
	}
	return nullptr;
}

bool UMGI_MUDSubsystem::SetData(FName TableName, const UMUDKey* RowKey, UMUDData* NewData)
{
	const FMUDDataDefine* DataDefine = GetMUDDataDefine(TableName);
	UMUDSourceHandler* Handler = GetHandler(DataDefine);
	if (Handler)
	{
		return Handler->SetDataBy(DataDefine->TableKey, RowKey, DataDefine->DataDesc, NewData);
	}
	return false;
}

const UMUDConfigDataAsset* UMGI_MUDSubsystem::GetConfig()
{
	if (ConfigDA)
	{
		return ConfigDA;
	}

	const UMUDConfig* DefaultConfig = GetDefault<UMUDConfig>();
	ConfigDA = DefaultConfig->ConfigDA.LoadSynchronous();
	return ConfigDA;
}

UMUDSourceHandler* UMGI_MUDSubsystem::GetHandler(const FMUDDataDefine* Define)
{
	if (Define == nullptr)
	{
		return nullptr;
	}

	const UMUDSourceDefine* SourceDefine = Cast<UMUDSourceDefine>(Define->SourceDefineClass->GetDefaultObject());
	if (SourceDefine == nullptr)
	{
		return nullptr;
	}

	if (!Handlers.Contains(SourceDefine->SourceName))
	{
		UMUDSourceHandler* Handler = Cast<UMUDSourceHandler>(SourceDefine->HandlerType->GetDefaultObject());
		if (Handler)
		{
			Handlers.Add(SourceDefine->SourceName, Handler);
		}
	}
	
	if (Handlers.Contains(SourceDefine->SourceName))
	{
		return Handlers[SourceDefine->SourceName];
	}
	return nullptr;
}
