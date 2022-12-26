// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RedHoodAdventure : ModuleRules
{
	public RedHoodAdventure(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","Paper2D","AIModule","GameplayTasks","NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { "RedHoodAdventure/Public/Character", "RedHoodAdventure/Public/Player", "RedHoodAdventure/Public/Enemy" ,"RedHoodAdventure/Public/UI"});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
