// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FightingTarget : TargetRules
{
	public FightingTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Game;
        bUsesSteam = true;
        ExtraModuleNames.AddRange(new string[] { "Fighting" });

		DefaultBuildSettings = BuildSettingsVersion.V2;
	}
}
