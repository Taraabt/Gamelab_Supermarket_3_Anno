// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GamelabSupermarket : ModuleRules
{
	public GamelabSupermarket(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "GameplayTags"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GamelabSupermarket",
			"GamelabSupermarket/Variant_Platforming",
			"GamelabSupermarket/Variant_Platforming/Animation",
			"GamelabSupermarket/Variant_Combat",
			"GamelabSupermarket/Variant_Combat/AI",
			"GamelabSupermarket/Variant_Combat/Animation",
			"GamelabSupermarket/Variant_Combat/Gameplay",
			"GamelabSupermarket/Variant_Combat/Interfaces",
			"GamelabSupermarket/Variant_Combat/UI",
			"GamelabSupermarket/Variant_SideScrolling",
			"GamelabSupermarket/Variant_SideScrolling/AI",
			"GamelabSupermarket/Variant_SideScrolling/Gameplay",
			"GamelabSupermarket/Variant_SideScrolling/Interfaces",
			"GamelabSupermarket/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
