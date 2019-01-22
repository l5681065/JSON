// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class JSONQuery_UE4Target : TargetRules
{
	public JSONQuery_UE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "JSONQuery_UE4" } );
	}
}
