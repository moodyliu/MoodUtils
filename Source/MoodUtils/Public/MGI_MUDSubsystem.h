// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataUtilsParams.h"
#include "MGI_MUDSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MOODUTILS_API UMGI_MUDSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	UMUDData* GetData(FName TableName, const UMUDKey* RowKey);

	UFUNCTION(BlueprintCallable)
	bool SetData(FName TableName, const UMUDKey* RowKey, UMUDData* NewData);

private:

	const UMUDConfigDataAsset* GetConfig();

	UMUDSourceHandler* GetHandler(const FMUDDataDefine* Define);

	const FMUDDataDefine* GetMUDDataDefine(FName TableName);

	UPROPERTY()
	UMUDConfigDataAsset* ConfigDA = nullptr;
	UPROPERTY()
	TMap<FName, UMUDSourceHandler*> Handlers;
};
