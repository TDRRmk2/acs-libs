#include <ACS_Zandronum.h>

[[call("StkCall")]] int ActorLib_CheckActorInventory (int tid, __str name);
[[call("StkCall")]] void ActorLib_GiveActorInventory (int tid, __str name, int amount);
[[call("StkCall")]] void ActorLib_TakeActorInventory (int tid, __str name, int amount);
[[call("StkCall")]] void ActorLib_UseActorInventory (int tid, __str name, int amount);
[[call("StkCall")]] void ActorLib_ClearActorInventory (int tid);

typedef struct
{
    int tid;
    __prop actorClass {default: ACS_GetActorClass(->tid)}

    __prop x {default: ACS_GetActorX(->tid)}
    __prop y {default: ACS_GetActorY(->tid)}
    __prop z {default: ACS_GetActorZ(->tid)}

    __prop velX {default: ACS_GetActorVelX(->tid)}
    __prop velY {default: ACS_GetActorVelY(->tid)}
    __prop velZ {default: ACS_GetActorVelZ(->tid)}

    __prop angle {default: ACS_GetActorAngle(->tid), operator=: ACS_SetActorAngle(->tid, ...)}
    __prop pitch {default: ACS_GetActorPitch(->tid), operator=: ACS_SetActorPitch(->tid, ...)}
    __prop roll {default: ACS_GetActorRoll(->tid), operator=: ACS_SetActorRoll(->tid, ...)}

    __prop checkInv {operator(): ActorLib_CheckActorInventory(->tid, ...)}
    __prop giveInv {operator(): ActorLib_GiveActorInventory(->tid, ...)}
    __prop takeInv {operator(): ActorLib_TakeActorInventory(->tid, ...)}
    __prop useInv {operator(): ActorLib_UseActorInventory(->tid, ...)}
  //__prop dropInv {operator(): DropInventory(->tid, ...)}
  //__prop dropItem {operator(): DropItem(->tid, ...)}
    __prop clearInv {operator(): ActorLib_ClearActorInventory(->tid, ...)}

    __prop getUserVar {operator(): ACS_GetUserVariable(->tid, ...)}
    __prop getUserArray {operator(): ACS_GetUserArray(->tid, ...)}
    __prop damage {operator(): ACS_DamageActor(->tid, ...)}
    __prop morph {operator(): ACS_MorphActor(->tid, ...)}
    __prop unmorph {operator(): ACS_UnMorphActor(->tid, ...)}
    __prop pickActor {operator(): ACS_PickActor(->tid, ...)}
    __prop lineAttack {operator(): ACS_LineAttack(->tid, ...)}
    __prop setPos {operator(): ACS_SetActorPosition(->tid, ...)}
    __prop setVel {operator(): ACS_SetActorVelocity(->tid, ...)}
    __prop setState {operator(): ACS_SetActorState(->tid, ...)}
    __prop setSpecial {operator(): ACS_SetThingSpecial(->tid, ...)}
    __prop setUserVar {operator(): ACS_SetUserVariable(->tid, ...)}
    __prop setUserArray {operator(): ACS_SetUserArray(->tid, ...)}
    __prop warp {operator(): ACS_Warp(->tid)}

    __prop activeSound {default: ACS_GetActorPropertyString(->tid, APROP_ActiveSound), operator=: ACS_SetActorPropertyString(->tid, APROP_ActiveSound, ...)}
    __prop accuracy {default: ACS_GetActorProperty(->tid, APROP_Accuracy), operator=: ACS_SetActorProperty(->tid, APROP_Accuracy, ...)}
    __prop alpha {default: ACS_GetActorPropertyFixed(->tid, APROP_Alpha), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Alpha, ...)}
    __prop ambush {default: ACS_GetActorProperty(->tid, APROP_Ambush), operator=: ACS_SetActorProperty(->tid, APROP_Ambush, ...)}
    __prop attackSound {default: ACS_GetActorPropertyString(->tid, APROP_AttackSound), operator=: ACS_SetActorPropertyString(->tid, APROP_AttackSound, ...)}
    __prop attackZOffset {default: ACS_GetActorPropertyFixed(->tid, APROP_AttackZOffset), operator=: ACS_SetActorPropertyFixed(->tid, APROP_AttackZOffset, ...)}
    __prop chaseGoal {default: ACS_GetActorProperty(->tid, APROP_ChaseGoal), operator=: ACS_SetActorProperty(->tid, APROP_ChaseGoal, ...)}
    __prop damage {default: ACS_GetActorProperty(->tid, APROP_Damage), operator=: ACS_SetActorProperty(->tid, APROP_Damage, ...)}
    __prop damageFactor {default: ACS_GetActorPropertyFixed(->tid, APROP_DamageFactor), operator=: ACS_SetActorPropertyFixed(->tid, APROP_DamageFactor, ...)}
    __prop damageMultiplier {default: ACS_GetActorPropertyFixed(->tid, APROP_DamageMultiplier), operator=: ACS_SetActorPropertyFixed(->tid, APROP_DamageMultiplier, ...)}
    __prop damageType {default: ACS_GetActorPropertyString(->tid, APROP_DamageType), operator=: ACS_SetActorPropertyString(->tid, APROP_DamageType, ...)}
    __prop deathSound {default: ACS_GetActorPropertyString(->tid, APROP_DeathSound), operator=: ACS_SetActorPropertyString(->tid, APROP_DeathSound, ...)}
    __prop dormant {default: ACS_GetActorProperty(->tid, APROP_Dormant), operator=: ACS_SetActorProperty(->tid, APROP_Dormant, ...)}
    __prop dropped {default: ACS_GetActorProperty(->tid, APROP_Dropped), operator=: ACS_SetActorProperty(->tid, APROP_Dropped, ...)}
    __prop friction {default: ACS_GetActorPropertyFixed(->tid, APROP_Friction), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Friction, ...)}
    __prop friendly {default: ACS_GetActorProperty(->tid, APROP_Friendly), operator=: ACS_SetActorProperty(->tid, APROP_Friendly, ...)}
  //__prop friendlySeeBlocks {default: ACS_GetActorProperty(->tid, APROP_FriendlySeeBlocks), operator=: ACS_SetActorProperty(->tid, APROP_FriendlySeeBlocks, ...)} not in gdcc
    __prop frightened {default: ACS_GetActorProperty(->tid, APROP_Frightened), operator=: ACS_SetActorProperty(->tid, APROP_Frightened, ...)}
    __prop gravity {default: ACS_GetActorPropertyFixed(->tid, APROP_Gravity), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Gravity, ...)}
    __prop health {default: ACS_GetActorProperty(->tid, APROP_Health), operator=: ACS_SetActorProperty(->tid, APROP_Health, ...)}
    __prop height {default: ACS_GetActorPropertyFixed(->tid, APROP_Height), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Height, ...)}
    __prop invulnerable {default: ACS_GetActorProperty(->tid, APROP_Invulnerable), operator=: ACS_SetActorProperty(->tid, APROP_Invulnerable, ...)}
    __prop jumpZ {default: ACS_GetActorPropertyFixed(->tid, APROP_JumpZ), operator=: ACS_SetActorPropertyFixed(->tid, APROP_JumpZ, ...)}
    __prop mass {default: ACS_GetActorProperty(->tid, APROP_Mass), operator=: ACS_SetActorProperty(->tid, APROP_Mass, ...)}
    __prop masterTID {default: ACS_GetActorProperty(->tid, APROP_MasterTID), operator=: ACS_SetActorProperty(->tid, APROP_MasterTID, ...)}
    __prop maxDropOffHeight {default: ACS_GetActorPropertyFixed(->tid, APROP_MaxDropOffHeight), operator=: ACS_SetActorPropertyFixed(->tid, APROP_MaxDropOffHeight, ...)}
    __prop maxStepHeight {default: ACS_GetActorPropertyFixed(->tid, APROP_MaxStepHeight), operator=: ACS_SetActorPropertyFixed(->tid, APROP_MaxStepHeight, ...)}
    __prop meleeRange {default: ACS_GetActorPropertyFixed(->tid, APROP_MeleeRange), operator=: ACS_SetActorPropertyFixed(->tid, APROP_MeleeRange, ...)}
  //__prop nameTag {default: ACS_GetActorPropertyString(->tid, APROP_NameTag), operator=: ACS_SetActorPropertyString(->tid, APROP_NameTag, ...)}
  //__prop noTrigger {default: ACS_GetActorProperty(->tid, APROP_NoTrigger), operator=: ACS_SetActorProperty(->tid, APROP_NoTrigger, ...)}
  //__prop noTarget {default: ACS_GetActorProperty(->tid, APROP_NoTarget), operator=: ACS_SetActorProperty(->tid, APROP_NoTarget, ...)}
    __prop painSound {default: ACS_GetActorPropertyString(->tid, APROP_PainSound), operator=: ACS_SetActorPropertyString(->tid, APROP_PainSound, ...)}
    __prop radius {default: ACS_GetActorPropertyFixed(->tid, APROP_Radius), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Radius, ...)}
  //__prop reactionTime {default: ACS_GetActorProperty(->tid, APROP_ReactionTime), operator=: ACS_SetActorProperty(->tid, APROP_ReactionTime, ...)}
    __prop renderStyle {default: ACS_GetActorProperty(->tid, APROP_RenderStyle), operator=: ACS_SetActorProperty(->tid, APROP_RenderStyle, ...)}
    __prop scaleX {default: ACS_GetActorPropertyFixed(->tid, APROP_ScaleX), operator=: ACS_SetActorPropertyFixed(->tid, APROP_ScaleX, ...)}
    __prop scaleY {default: ACS_GetActorPropertyFixed(->tid, APROP_ScaleY), operator=: ACS_SetActorPropertyFixed(->tid, APROP_ScaleY, ...)}
    __prop score {default: ACS_GetActorProperty(->tid, APROP_Score), operator=: ACS_SetActorProperty(->tid, APROP_Score, ...)}
    __prop seeSound {default: ACS_GetActorPropertyString(->tid, APROP_SeeSound), operator=: ACS_SetActorPropertyString(->tid, APROP_SeeSound, ...)}
    __prop soundClass {default: ACS_GetActorPropertyString(->tid, APROP_SoundClass), operator=: ACS_SetActorPropertyString(->tid, APROP_SoundClass, ...)}
    __prop spawnHealth {default: ACS_GetActorProperty(->tid, APROP_SpawnHealth), operator=: ACS_SetActorProperty(->tid, APROP_SpawnHealth, ...)}
    __prop species {default: ACS_GetActorPropertyString(->tid, APROP_Species), operator=: ACS_SetActorPropertyString(->tid, APROP_Species, ...)}
    __prop speed {default: ACS_GetActorPropertyFixed(->tid, APROP_Speed), operator=: ACS_SetActorPropertyFixed(->tid, APROP_Speed, ...)}
    __prop stamina {default: ACS_GetActorProperty(->tid, APROP_Stamina), operator=: ACS_SetActorProperty(->tid, APROP_Stamina, ...)}
    __prop stencilColor {default: ACS_GetActorProperty(->tid, APROP_StencilColor), operator=: ACS_SetActorProperty(->tid, APROP_StencilColor, ...)}
    __prop targetTID {default: ACS_GetActorProperty(->tid, APROP_TargetTID), operator=: ACS_SetActorProperty(->tid, APROP_TargetTID, ...)}
    __prop tracerTID {default: ACS_GetActorProperty(->tid, APROP_TracerTID), operator=: ACS_SetActorProperty(->tid, APROP_TracerTID, ...)}
    __prop viewHeight {default: ACS_GetActorPropertyFixed(->tid, APROP_ViewHeight), operator=: ACS_SetActorPropertyFixed(->tid, APROP_ViewHeight, ...)}
  //__prop waterLevel {default: ACS_GetActorProperty(->tid, APROP_WaterLevel), operator=: ACS_SetActorProperty(->tid, APROP_WaterLevel, ...)}
  //__prop waterDepth {default: ACS_GetActorPropertyFixed(->tid, APROP_WaterDepth), operator=: ACS_SetActorPropertyFixed(->tid, APROP_WaterDepth, ...)}
} ActorT;

__addrdef extern __mod_arr actorlib_sta;
extern const actorlib_sta ActorT self;
