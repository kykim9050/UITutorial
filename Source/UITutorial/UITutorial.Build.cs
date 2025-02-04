// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UITutorial : ModuleRules
{
	public UITutorial(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(System.IO.Path.Combine(ModuleDirectory, ""));

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" , "UMG"});

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" , "EditorStyle" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
