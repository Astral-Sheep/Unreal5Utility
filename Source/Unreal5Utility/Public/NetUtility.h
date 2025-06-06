// Copyright Thomas SURBON. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Net/UnrealNetwork.h"
#include "NetUtility.generated.h"

class AActor;
class UActorComponent;

/**
 * 
 */
UCLASS()
class UNREAL5UTILITY_API UNetUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsDedicatedServer")
	static bool IsDedicatedServer_Actor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsDedicatedServer")
	static bool IsDedicatedServer_Component(UActorComponent* Component);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsListenServer")
	static bool IsListenServer_Actor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsListenServer")
	static bool IsListenServer_Component(UActorComponent* Component);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsStandalone")
	static bool IsStandalone_Actor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsStandalone")
	static bool IsStandalone_Component(UActorComponent* Component);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsClient")
	static bool IsClient_Actor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsClient")
	static bool IsClient_Component(UActorComponent* Component);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsServer")
	static bool IsServer_Actor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking", DisplayName="IsServer")
	static bool IsServer_Component(UActorComponent* Component);

	template<class T>
	static bool IsServer(const T *const Object)
	{
		return Object->GetNetMode() == NM_DedicatedServer || Object->GetNetMode() == NM_ListenServer;
	}
};

// #ifndef IS_SERVER
// #define IS_SERVER(Object) (Object->GetNetMode() == NM_DedicatedServer || Object->GetNetMode() == NM_ListenServer)
// #endif //IS_SERVER

#ifndef IsDedicatedServer
#define IsDedicatedServer() GetNetMode() == NM_DedicatedServer
#endif //IsDedicatedServer

#ifndef IsListenServer
#define IsListenServer() GetNetMode() == NM_ListenServer
#endif //IsListenServer

#ifndef IsStandalone
#define IsStandalone() GetNetMode() == NM_Standalone
#endif //IsStandalone

#ifndef IsClient
#define IsClient() GetNetMode() == NM_Client
#endif //IsClient