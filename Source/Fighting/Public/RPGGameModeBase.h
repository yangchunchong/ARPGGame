// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Fighting.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameModeBase.generated.h"

/** Base class for GameMode, should be blueprinted */
UCLASS()
class FIGHTING_API ARPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	ARPGGameModeBase();

	/** Overriding this function is not essential to this sample since this function 
	 *	is not being called in normal circumstances. Added just to streamline 
	 *	dev-time activities (like automated testing). The default ResetLevel 
	 *	implementation doesn't work all that well with how things are set up in 
	 *	Fighting (and that's ok, this is exactly why we override functions!). 
	 */
	virtual void ResetLevel() override;

	/** Returns true if GameOver() has been called, false otherwise */
	virtual bool HasMatchEnded() const override;

	/** Called when the game is over i.e. the player dies, the time runs out or the 
	 *	game is finished*/
	UFUNCTION(BlueprintCallable, Category=Game)
	virtual void GameOver();
	/** Called when the game is over i.e. the player dies, the time runs out or the 
	 *	game is finished*/
	UFUNCTION(BlueprintCallable, Category=Game)
	virtual void GameOverFinish();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="DoRestart", ScriptName="DoRestart"))
	void K2_DoRestart();

	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameOver", ScriptName="OnGameOver"))
	void K2_OnGameOver();

	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameOverFinish", ScriptName="OnGameOverFinish"))
	void K2_OnGameOverFinish();

	UPROPERTY(BlueprintReadOnly, Category=Game)
	uint32 bGameOver : 1;

	UPROPERTY(BlueprintReadOnly, Category = Game)
	uint32 bGameOverFinish : 1;
};

