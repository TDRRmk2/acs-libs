#ifndef _INC_RT_ITER_H_
#define _INC_RT_ITER_H_

enum
{
    RTIF_PLAYERS =     2,
    RTIF_MONSTERS =    4,
    RTIF_OBJECTS =     8,
    RTIF_VOODOO =      16,
    RTIF_CORPSES =     32,
    RTIF_NOTARGET =    64,
    RTIF_NOTRACER =    128,
    RTIF_NOMASTER =    256,
    RTIF_CUBE =        512,
    RTIF_NOSIGHT =     1024,
    RTIF_MISSILES =    2048
};

[[call("StkCall"), extern("ACS")]] void RadiusThingIterator_Create (int tid, _Accum radius, int flags);
[[call("StkCall"), extern("ACS")]] void RadiusThingIterator_CreateFromPos (_Accum x, _Accum y, _Accum z, _Accum radius, int flags);
[[call("StkCall"), extern("ACS")]] void RadiusThingIterator_Destroy (void);
[[call("StkCall"), extern("ACS")]] bool RadiusThingIterator_Next (void);

#endif
