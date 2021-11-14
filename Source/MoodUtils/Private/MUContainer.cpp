// Fill out your copyright notice in the Description page of Project Settings.


#include "MUContainer.h"

bool UMUContainerBPLibrary::MUContainer_TryGetFloat(const FMUContainer& Container, const FName& Key, float& OutData)
{
	return Container.TryGet<float>(Key, OutData);
}

bool UMUContainerBPLibrary::MUContainer_TryGetInt64(const FMUContainer& Container, const FName& Key, int64& OutData)
{
	return Container.TryGet<int64>(Key, OutData);
}

bool UMUContainerBPLibrary::MUContainer_TryGetString(const FMUContainer& Container, const FName& Key, FString& OutData)
{
	return Container.TryGet<FString>(Key, OutData);
}

void UMUContainerBPLibrary::MUContainer_SetFloat(FMUContainer& Container, const FName& Key, float InData)
{
	Container.SetValue<float>(Key, InData);
}

void UMUContainerBPLibrary::MUContainer_SetInt64(FMUContainer& Container, const FName& Key, int64 InData)
{
	Container.SetValue<int64>(Key, InData);
}

void UMUContainerBPLibrary::MUContainer_SetString(FMUContainer& Container, const FName& Key, const FString& InData)
{
	Container.SetValue<FString>(Key, InData);
}
