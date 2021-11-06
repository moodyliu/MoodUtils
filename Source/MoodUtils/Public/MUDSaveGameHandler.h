// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataUtilsParams.h"
#include "MUDSaveGameHandler.generated.h"

UCLASS(BlueprintType, Blueprintable)
class MOODUTILS_API UMUDSaveGameData : public UMUDData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	class USaveGame* SaveGameData;
};

UCLASS(BlueprintType, EditInlineNew)
class MOODUTILS_API UMUDSaveGameSlotKey : public UMUDKey
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int SlotKey;

public:
	virtual FString GetKey() const { return FString::FromInt(SlotKey); };
};

/**
 * 
 */
UCLASS()
class MOODUTILS_API UMUDSaveGameHandler : public UMUDSourceHandler
{
	GENERATED_BODY()

	virtual UMUDData* GetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc) override;

	virtual bool SetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc, UMUDData* NewData) override;
	
};
