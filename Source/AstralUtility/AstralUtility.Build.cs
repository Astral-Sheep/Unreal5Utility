// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AstralUtility : ModuleRules
{
	public AstralUtility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] {
				
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"CoreUObject",
				"Engine",
			}
		);
	}
}
