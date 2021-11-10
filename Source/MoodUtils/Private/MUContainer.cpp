// Fill out your copyright notice in the Description page of Project Settings.


#include "MUContainer.h"

bool UMUContainerBPLibrary::TryGetFloat(const FMUContainer& Container, const FName& Key, float& OutData)
{
	return Container.TryGet<float>(Key, OutData);
}

bool UMUContainerBPLibrary::TryGetInt64(const FMUContainer& Container, const FName& Key, int64& OutData)
{
	return Container.TryGet<int64>(Key, OutData);
}

bool UMUContainerBPLibrary::TryGetString(const FMUContainer& Container, const FName& Key, FString& OutData)
{
	return Container.TryGet<FString>(Key, OutData);
}
