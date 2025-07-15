#ifndef _INC_PAKETLIB_H_
#define _INC_PAKETLIB_H_

enum
{
    PACKET_WORD,
    PACKET_SHORT,
    PACKET_BYTE
};

[[extern("ACS")]] extern __mod_reg int Packet_Rval;
extern __mod_reg __fixed Packet_RvalFixed;
extern __mod_reg __str Packet_RvalStr;

[[call("StkCall"), extern("ACS")]]                      int Packet_GetMaxSize (void);
[[call("StkCall"), extern("ACS")]]                      int Packet_GetSize (str pac);
[[call("StkCall"), extern("ACS")]]                      __str Packet_New (void);
[[call("StkCall"), extern("ACS"), optional_args(1)]]    __str Packet_Append (__str pac, int val, int width);
[[call("StkCall"), optional_args(1)]]                   __str Packet_AppendFixed (__str pac, __fixed val, int width);
[[call("StkCall"), extern("ACS")]]                      __str Packet_AppendStr (__str pac, __str val);
[[call("StkCall"), extern("ACS")]]                      int Packet_Send (__str scrip, __str pac, int client);
[[call("StkCall"), extern("ACS"), optional_args(1)]]    __str Packet_Read (__str pac, int width);
[[call("StkCall"), optional_args(1)]]                   __str Packet_ReadFixed (__str pac, int width);
[[call("StkCall"), extern("ACS")]]                      __str Packet_ReadStr(__str pac);
[[call("StkCall")]]                                     __str __Packet_ReadStr_C(__str pac);

#define Packet_ReadStr __Packet_ReadStr_C

#endif
