// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/StreamableManager.h"
#include "MGI_ResourceSubsystem.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FObjectLoadedCallback, const FSoftObjectPath&, Path);
DECLARE_DYNAMIC_DELEGATE(FAllObjectLoadedCallback);

/**
 * 
 */
UCLASS()
class MOODUTILS_API UMGI_ResourceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void LoadObjAsync(const FSoftObjectPath& Path, FObjectLoadedCallback Callback); 

	void LoadObjsAsync(TArray<FSoftObjectPath> Paths, FAllObjectLoadedCallback Callback);

	UFUNCTION(BlueprintCallable)
	void LoadObjAsync(const FString& Path, FObjectLoadedCallback Callback);

	UFUNCTION(BlueprintCallable)
	void LoadObjsAsync(TArray<FString> Paths, FAllObjectLoadedCallback Callback);

	UFUNCTION(BlueprintCallable)
	UObject* GetObject(const FSoftObjectPath& Path)const;
protected:
	
};

