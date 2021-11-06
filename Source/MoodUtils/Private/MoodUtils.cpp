// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoodUtils.h"
#include "ISettingsModule.h"
#include "DataUtilsParams.h"

#define LOCTEXT_NAMESPACE "FMoodUtilsModule"

void FMoodUtilsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").RegisterSettings(
		"Project",
		"Plugins",
		TEXT("MUD Config"),
		FText::FromString("MUD Config"),
		FText::FromString("MUD Config"),
		GetMutableDefault<UMUDConfig>());
}

void FMoodUtilsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").UnregisterSettings("Project", "Plugins", "MUD Config");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMoodUtilsModule, MoodUtils)