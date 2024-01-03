// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGCharacterItem.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTING_API URPGCharacterItem : public URPGItem
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGCharacterItem()
	{
		ItemType = URPGAssetManager::CharacterType;
	}
	
};
