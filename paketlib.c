#include "paketlib.h"

__addrdef __mod_arr paklib_sta;
paklib_sta __fixed Packet_RvalFixed;
paklib_sta __str Packet_RvalStr;

union intandfix
{
    int i;
    __fixed f;
    __str s;
}

[[call("StkCall"), optional_args(1)]]
__str Packet_AppendFixed (__str pac, __fixed val, int width)
{
    union intandfix u = { .f = val };

    return Packet_Append(pac, val.i, width);
}

[[call("StkCall"), optional_args(1)]]
__str Packet_ReadFixed (__str pac, int width)
{
    pac =  Packet_Read(pac, width);
    union intandfix u = { .i = Packet_Rval };

    Packet_RvalFixed = u.f;

    return pac;
}

[[call("StkCall")]]
__str __Packet_ReadStr_C (__str pac)
{
    pac =  Packet_ReadStr(pac);
    union intandfix u = { .i = Packet_Rval };

    Packet_RvalStr = u.s;

    return pac;
}
