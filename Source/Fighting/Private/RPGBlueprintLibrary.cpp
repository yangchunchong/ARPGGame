// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGBlueprintLibrary.h"
#include "FightingLoadingScreen.h"


URPGBlueprintLibrary::URPGBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void URPGBlueprintLibrary::PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime)
{
	IFightingLoadingScreenModule& LoadingScreenModule = IFightingLoadingScreenModule::Get();
	LoadingScreenModule.StartInGameLoadingScreen(bPlayUntilStopped, PlayTime);
}

void URPGBlueprintLibrary::StopLoadingScreen()
{
	IFightingLoadingScreenModule& LoadingScreenModule = IFightingLoadingScreenModule::Get();
	LoadingScreenModule.StopInGameLoadingScreen();
}

bool URPGBlueprintLibrary::IsInEditor()
{
	return GIsEditor;
}

bool URPGBlueprintLibrary::EqualEqual_RPGItemSlot(const FRPGItemSlot& A, const FRPGItemSlot& B)
{
	return A == B;
}

bool URPGBlueprintLibrary::NotEqual_RPGItemSlot(const FRPGItemSlot& A, const FRPGItemSlot& B)
{
	return A != B;
}

bool URPGBlueprintLibrary::IsValidItemSlot(const FRPGItemSlot& ItemSlot)
{
	return ItemSlot.IsValid();
}

bool URPGBlueprintLibrary::DoesEffectContainerSpecHaveEffects(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	return ContainerSpec.HasValidEffects();
}

bool URPGBlueprintLibrary::DoesEffectContainerSpecHaveTargets(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	return ContainerSpec.HasValidTargets();
}

FRPGGameplayEffectContainerSpec URPGBlueprintLibrary::AddTargetsToEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec, const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors)
{
	FRPGGameplayEffectContainerSpec NewSpec = ContainerSpec;
	NewSpec.AddTargets(HitResults, TargetActors);
	return NewSpec;
}

TArray<FActiveGameplayEffectHandle> URPGBlueprintLibrary::ApplyExternalEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	TArray<FActiveGameplayEffectHandle> AllEffects;

	// Iterate list of gameplay effects
	for (const FGameplayEffectSpecHandle& SpecHandle : ContainerSpec.TargetGameplayEffectSpecs)
	{
		if (SpecHandle.IsValid())
		{
			// If effect is valid, iterate list of targets and apply to all
			for (TSharedPtr<FGameplayAbilityTargetData> Data : ContainerSpec.TargetData.Data)
			{
				AllEffects.Append(Data->ApplyGameplayEffectSpec(*SpecHandle.Data.Get()));
			}
		}
	}
	return AllEffects;
}

FString URPGBlueprintLibrary::GetProjectVersion()
{
	FString ProjectVersion;

	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
	);

	return ProjectVersion;
}

bool URPGBlueprintLibrary::HasPlotIndex(int64 SrcInt, int64 CheckInt, int64& ResultInt)
{
	bool bHas = false;
	int64 CheckNum = 1;
	if (CheckInt < 0)
		return bHas;
	else if(CheckInt > 0)
		CheckNum = static_cast<int64>(1) << CheckInt;
	if ((CheckNum & SrcInt) == CheckNum)
	{
		bHas = true;
	}
	ResultInt = CheckNum | SrcInt;
	return bHas;
}

int64 URPGBlueprintLibrary::GetCheckPlotNum(int64 CheckInt)
{
	int64 CheckNum = 1;
	if (CheckInt < 0)
		return 0;
	else if (CheckInt > 0)
		CheckNum = static_cast<int64>(1) << CheckInt;
	return CheckNum;
}
