// Fill out your copyright notice in the Description page of Project Settings.


#include "MUDSaveGameHandler.h"
#include "Kismet/GameplayStatics.h"
#include "MUMacros.h"

UMUDData* UMUDSaveGameHandler::GetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc)
{
	const UMUDSaveGameSlotKey* SlotKey = Cast<UMUDSaveGameSlotKey>(RowKey);
	RETURN_NULL_IF(SlotKey == nullptr || TableKey == nullptr || DataDesc == nullptr)
	RETURN_NULL_IF(RowKey == nullptr || !DataDesc->DataClass->IsChildOf(UMUDSaveGameData::StaticClass()))

	UMUDSaveGameData* Result = Cast<UMUDSaveGameData>(NewObject<UMUDSaveGameData>(this, DataDesc->DataClass));

	RETURN_NULL_IF(Result == nullptr)

	Result->SaveGameData = UGameplayStatics::LoadGameFromSlot(TableKey->GetKey(), SlotKey->SlotKey);
	return Result;
}

bool UMUDSaveGameHandler::SetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc, UMUDData* NewData)
{
	const UMUDSaveGameSlotKey* SlotKey = Cast<UMUDSaveGameSlotKey>(RowKey);
	RETURN_ANY_IF(SlotKey == nullptr || TableKey == nullptr || DataDesc == nullptr || NewData == nullptr, false)
	RETURN_ANY_IF(RowKey == nullptr || !DataDesc->DataClass->IsChildOf(UMUDSaveGameData::StaticClass()), false)

	UMUDSaveGameData* SaveGameData = Cast<UMUDSaveGameData>(NewData);
	RETURN_ANY_IF(SaveGameData == nullptr, false)

	return UGameplayStatics::SaveGameToSlot(SaveGameData->SaveGameData, TableKey->GetKey(), SlotKey->SlotKey);
}
