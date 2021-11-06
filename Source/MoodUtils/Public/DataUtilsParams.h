// MUD prefix => mood utils data

#pragma once

#include "CoreMinimal.h"
#include "DataUtilsParams.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class MOODUTILS_API UMUDKey : public UObject
{
	GENERATED_BODY()
public:
	virtual FString GetKey() const{ return ""; };
};

UCLASS(BlueprintType, EditInlineNew)
class MOODUTILS_API UMUDDefaultKey : public UMUDKey
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	FString KeyName;

public:
	virtual FString GetKey() const { return KeyName; };
};

UCLASS(BlueprintType, Blueprintable)
class MOODUTILS_API UMUDData : public UObject
{
	GENERATED_BODY()
};

UCLASS(BlueprintType)
class MOODUTILS_API UMUDSourceHandler : public UObject
{
	GENERATED_BODY()
public:
	virtual UMUDData* GetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc){ return nullptr; }

	virtual bool SetDataBy(const UMUDKey* TableKey, const UMUDKey* RowKey, UMUDDataDesc* DataDesc, UMUDData* NewData) { return false; }
};

UCLASS(BlueprintType, EditInlineNew)
class MOODUTILS_API UMUDDataDesc : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMUDData> DataClass;
};

UCLASS(BlueprintType, Blueprintable)
class MOODUTILS_API UMUDSourceDefine : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName SourceName;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMUDSourceHandler> HandlerType;
};

USTRUCT(BlueprintType)
struct MOODUTILS_API FMUDDataDefine
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf <UMUDSourceDefine> SourceDefineClass;

	UPROPERTY(EditAnywhere, Instanced)
	UMUDKey* TableKey;

	UPROPERTY(EditAnywhere, Instanced)
	UMUDDataDesc* DataDesc;
};

UCLASS(BlueprintType)
class MOODUTILS_API UMUDConfigDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TMap<FName, FMUDDataDefine> DataDefines;
};

UCLASS(Config=Game)
class MOODUTILS_API UMUDConfig : public UObject
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, Config)
	TSoftObjectPtr<UMUDConfigDataAsset> ConfigDA;
};

