// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "EOS_DataDefinition.generated.h"


UENUM()
enum class EAuthType : uint8
{
	//認証を行いません
	none,
	//Epic Gamesアカウントを介して認証を行います
	epicgames,
	//PlayStation Networkを介して認証を行います
	psn,
	//Xbox Liveを介して認証を行います
	xboxlive,
	//Nintendo Switch Onlineを介して認証を行います
	nintendoswitchonline,
	//Steamを介して認証を行います
	steam,
	//Google Play Games Servicesを介して認証を行います
	googleplaygamesservices,
	//Apple Game Centerを介して認証を行います
	gamecenter,
	//Amazon GameLiftを介して認証を行います
	gamelift,
	//ブラウザを介して認証を行います
	accountportal,
	//DevAuthToolを介して認証を行います
	developer
};