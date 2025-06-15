// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AISample : ModuleRules
{
	public AISample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "OnlineServicesInterface",
            "CoreOnline",
            "OnlineSubsystem", "OnlineSubsystemEOS", "OnlineSubsystemUtils", "Networking", "Sockets"});

        // パスにプロジェクト名を追加
        string ProjectName = Target.ProjectFile.GetFileNameWithoutExtension();
        PublicIncludePaths.Add(ProjectName);
    }
}
