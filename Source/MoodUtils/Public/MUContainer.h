// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Union.h"
#include "MUContainer.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct MOODUTILS_API FMUContainer
{
	GENERATED_BODY()
private:
	using DATA_TYPE = TUnion<int64, float, FString>;

	TMap<FName, DATA_TYPE> mDataMap;

public:
	template<typename T>
	bool TryGet(const FName& Key, T& OutData) const;

	template<typename T>
	void SetValue(const FName& Key, const T& InData);
};

UCLASS()
class MOODUTILS_API UMUContainerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static bool MUContainer_TryGetFloat(const FMUContainer& Container, const FName& Key, float& OutData);

	UFUNCTION(BlueprintCallable)
	static bool MUContainer_TryGetInt64(const FMUContainer& Container, const FName& Key, int64& OutData);

	UFUNCTION(BlueprintCallable)
	static bool MUContainer_TryGetString(const FMUContainer& Container, const FName& Key, FString& OutData);

	UFUNCTION(BlueprintCallable)
	static void MUContainer_SetFloat(FMUContainer& Container, const FName& Key, float InData);

	UFUNCTION(BlueprintCallable)
	static void MUContainer_SetInt64(FMUContainer& Container, const FName& Key, int64 InData);

	UFUNCTION(BlueprintCallable)
	static void MUContainer_SetString(FMUContainer& Container, const FName& Key, const FString& InData);

};

template<typename T>
bool FMUContainer::TryGet(const FName& Key, T& OutData) const
{
	if (!mDataMap.Contains(Key))
	{
		return false;
	}

	const DATA_TYPE& Element = mDataMap.FindRef(Key);
	if (!Element.HasSubtype<T>())
	{
		return false;
	}

	OutData = Element.GetSubtype<T>();
	return true;
}

template<typename T>
void FMUContainer::SetValue(const FName& Key, const T& InData)
{
	DATA_TYPE& Data = mDataMap.FindOrAdd(Key);
	Data.SetSubtype<T>(InData);
}
