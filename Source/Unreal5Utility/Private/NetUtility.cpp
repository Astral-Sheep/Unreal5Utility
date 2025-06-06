// Copyright Thomas SURBON. All rights reserved.

#include "NetUtility.h"
#include "GameFramework/Actor.h"

#define IMPLEMENT_NETMODE_TEST(Name)\
	bool UNetUtility::Name##_Actor(AActor *Actor)\
	{\
		return Actor->Name();\
	}\
	\
	bool UNetUtility::Name##_Component(UActorComponent *Component)\
	{\
		return Component->Name();\
	}

IMPLEMENT_NETMODE_TEST(IsDedicatedServer)
IMPLEMENT_NETMODE_TEST(IsListenServer)
IMPLEMENT_NETMODE_TEST(IsStandalone)
IMPLEMENT_NETMODE_TEST(IsClient)

bool UNetUtility::IsServer_Actor(AActor *Actor)
{
	return IsServer(Actor);
}

bool UNetUtility::IsServer_Component(UActorComponent *Component)
{
	return IsServer(Component);
}
