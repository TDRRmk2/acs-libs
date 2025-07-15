// GDCC-CC header
#ifndef _INC_PTRACE_H_
#define _INC_PTRACE_H_

enum
{
    PTRACE_HIT_NONE,
    PTRACE_HIT_MAP,
    PTRACE_HIT_ACTOR,
    PTRACE_HIT_TOTAL
};

enum
{
    PTRF_ABSPOSITION = 1,
    PTRF_ABSOFFSET = 2,
    PTRF_THRUSPECIES = 4
};

struct PTrace_DataStruct
{
    int hitType;
    __fixed posX;
    __fixed posY;
    __fixed posZ;
    int hitActor;
    __fixed distance;
};

[[extern("ACS")]] __addrdef extern __mod_arr PTrace_Data;
[[address(0)]] extern PTrace_Data struct PTrace_DataStruct PTrace_Data_C;

[[call("StkCall"), extern("ACS"), optional_args(4)]] extern void PTrace (int tid, __fixed angle, __fixed distance, __fixed pitch, int flags, __fixed offsetz, __fixed offsetfw, __fixed offsetside);

#define PTrace_Data PTrace_Data_C

#endif
