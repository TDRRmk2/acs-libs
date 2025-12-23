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

[[call("StkCall")]]
__str Packet_AppendFixed (__str pac, __fixed val)
{
    union intandfix u = { .f = val };

    return Packet_Append(pac, u.i);
}

[[call("StkCall")]]
__str Packet_ReadFixed (__str pac)
{
    pac =  Packet_Read(pac);
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

[[call("StkCall")]]
int Packet_PackValueFixed(int pack, int pos, int width, __fixed v)
{
    union intandfix u = { .f = v };

    return Packet_PackValueFixed(pack, pos, width, u.i);
}

[[call("StkCall"), optional_args(1)]]
__fixed Packet_UnpackValueFixed(int pack, int pos, int width, bool sign)
{
    union intandfix u = { .i = Packet_UnpackValueFixed(pack, pos, width, sign) };

    return u.f;
}
