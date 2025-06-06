// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unreal5Utility : ModuleRules
{
	public Unreal5Utility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
			}
		);
	}
}
