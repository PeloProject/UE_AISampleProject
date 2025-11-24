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
            "OnlineSubsystem",
            "OnlineSubsystemEOS",
            "OnlineSubsystemUtils",
            "Networking",
            "Sockets"});

        // �p�X�Ƀv���W�F�N�g����ǉ�
        string ProjectName = Target.ProjectFile.GetFileNameWithoutExtension();
        PublicIncludePaths.Add(ProjectName);
    }
}
