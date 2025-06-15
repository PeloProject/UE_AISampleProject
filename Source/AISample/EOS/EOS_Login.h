// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "EOS_DataDefinition.h"
#include "EOS_Login.generated.h"

/**
 * 
 */
UCLASS()
class AISAMPLE_API UEOS_Login : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "EOS")
	static UEOS_Login* Login(UObject* WorldContextObject, FString UserID, FString UserToken, EAuthType AuthType);

	virtual void Activate() override;

private:
	void OnLoginEOSComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& ErrorVal);

private:
	UWorld* World;
	TWeakObjectPtr<UObject> WorldContextObject;
	FString UserID;
	FString UserToken;
	EAuthType AuthType;
	
};
