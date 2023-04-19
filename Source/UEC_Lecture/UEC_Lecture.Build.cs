// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEC_Lecture : ModuleRules
{
	public UEC_Lecture(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
