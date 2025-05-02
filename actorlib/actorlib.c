#include <ACS_Zandronum.h>

#include "actorlib.h"

__addrdef __mod_arr actorlib_sta;
const ActorT actorlib_sta self;

[[call("StkCall")]]
int ActorLib_CheckActorInventory (int tid, __str name)
{
    return (tid) ? ACS_CheckActorInventory(tid, name) : ACS_CheckInventory(name);
}

[[call("StkCall")]]
void ActorLib_GiveActorInventory (int tid, __str name, int amount)
{
    (tid) ? ACS_GiveActorInventory(tid, name, amount) : ACS_GiveInventory(name, amount);
}

[[call("StkCall")]]
void ActorLib_TakeActorInventory (int tid, __str name, int amount)
{
    (tid) ? ACS_TakeActorInventory(tid, name, amount) : ACS_TakeInventory(name, amount);
}

[[call("StkCall")]]
void ActorLib_UseActorInventory (int tid, __str name)
{
    (tid) ? ACS_UseActorInventory(tid, name) : ACS_UseInventory(name);
}

[[call("StkCall")]]
void ActorLib_ClearActorInventory (int tid)
{
    (tid) ? ACS_ClearActorInventory(tid) : ACS_ClearInventory();
}
