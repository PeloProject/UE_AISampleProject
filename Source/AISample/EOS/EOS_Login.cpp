// Fill out your copyright notice in the Description page of Project Settings.

#include "EOS_Login.h"
#include "OnlineSubsystemUtils.h"


UEOS_Login* UEOS_Login::Login(UObject* WorldContextObject, FString UserID, FString UserToken, EAuthType AuthType)
{
    UEOS_Login* LoginObject = NewObject<UEOS_Login>();
    LoginObject->UserID = UserID;
    LoginObject->UserToken = UserToken;
    LoginObject->AuthType = AuthType;
    LoginObject->WorldContextObject = WorldContextObject;
    return LoginObject;
}

void UEOS_Login::Activate()
{

    World = GEngine->GetWorldFromContextObject(WorldContextObject.Get(), EGetWorldErrorMode::LogAndReturnNull);

    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("Login:World�̎擾�Ɏ��s"));
        OnFailure.Broadcast();
        return;
    }

    IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(World);
    IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface();

    FOnlineAccountCredentials AccountCredentials(StaticEnum< EAuthType>()->GetDisplayValueAsText(AuthType).ToString(), UserID, UserToken);

    if (IdentityPointerRef) {
        IdentityPointerRef->OnLoginCompleteDelegates->AddUObject(this, &UEOS_Login::OnLoginEOSComplete);
        IdentityPointerRef->Login(0, AccountCredentials);
        return;
    }

    OnFailure.Broadcast();
}

void UEOS_Login::OnLoginEOSComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& ErrorVal)
{
    if (bWasSuccessful)
    {
        UE_LOG(LogTemp, Error, TEXT("ログイン成功"));
        OnSuccess.Broadcast();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ログイン失敗 - %s"), *ErrorVal);
        OnFailure.Broadcast();
    }
}