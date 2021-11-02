// Fill out your copyright notice in the Description page of Project Settings.


#include "MGI_ResourceSubsystem.h"
#include "Engine/AssetManager.h"

void UMGI_ResourceSubsystem::LoadObjAsync(const FSoftObjectPath& Path, FObjectLoadedCallback Callback)
{
	UAssetManager::Get().LoadAssetList({ Path }, FStreamableDelegate::CreateLambda([Path, Callback]()->void{
		Callback.ExecuteIfBound(Path);
	}));
}

void UMGI_ResourceSubsystem::LoadObjAsync(const FString& Path, FObjectLoadedCallback Callback)
{
	LoadObjAsync(FSoftObjectPath(Path), Callback);
}

void UMGI_ResourceSubsystem::LoadObjsAsync(TArray<FString> Paths, FAllObjectLoadedCallback Callback)
{
	TArray<FSoftObjectPath> SoftPaths;
	for (const auto& Path : Paths)
	{
		SoftPaths.Add(Path);
	}
	LoadObjsAsync(SoftPaths, Callback);
}

void UMGI_ResourceSubsystem::LoadObjsAsync(TArray<FSoftObjectPath> Paths, FAllObjectLoadedCallback Callback)
{
	UAssetManager::Get().LoadAssetList(Paths, FStreamableDelegate::CreateLambda([Callback]()->void {
		Callback.ExecuteIfBound();
		}));
}

UObject* UMGI_ResourceSubsystem::GetObject(const FSoftObjectPath& Path) const
{
	return Path.ResolveObject();
}
