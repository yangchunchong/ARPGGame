// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FightingEditorTarget : TargetRules
{
	public FightingEditorTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[] { "Fighting" });

		DefaultBuildSettings = BuildSettingsVersion.V2;
	}
}
