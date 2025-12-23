#ifndef _INC_PAKETLIB_H_
#define _INC_PAKETLIB_H_

[[extern("ACS")]] extern __mod_reg int Packet_Rval;
extern __mod_reg __fixed Packet_RvalFixed;
extern __mod_reg __str Packet_RvalStr;

[[call("StkCall"), extern("ACS")]]                      int Packet_GetMaxSize (void);
[[call("StkCall"), extern("ACS")]]                      int Packet_GetSize (str pac);
[[call("StkCall"), extern("ACS")]]                      __str Packet_New (void);
[[call("StkCall"), extern("ACS")]]                      __str Packet_Append (__str pac, int val);
[[call("StkCall")]]                                     __str Packet_AppendFixed (__str pac, __fixed val);
[[call("StkCall"), extern("ACS")]]                      __str Packet_AppendStr (__str pac, __str val);
[[call("StkCall"), extern("ACS")]]                      int Packet_Send (__str scrip, __str pac, int client);
[[call("StkCall"), extern("ACS")]]                      __str Packet_Read (__str pac);
[[call("StkCall")]]                                     __str Packet_ReadFixed (__str pac);
[[call("StkCall"), extern("ACS")]]                      __str Packet_ReadStr(__str pac);
[[call("StkCall")]]                                     __str __Packet_ReadStr_C(__str pac);
[[call("StkCall"), extern("ACS")]]                      int Packet_PackValue(int pack, int pos, int width, int v);
[[call("StkCall"), extern("ACS"), optional_args(1)]]    int Packet_UnpackValue(int pack, int pos, int width, bool sign);
[[call("StkCall")]]                                     int Packet_PackValueFixed(int pack, int pos, int width, __fixed v);
[[call("StkCall"), optional_args(1)]]                   __fixed Packet_UnpackValueFixed(int pack, int pos, int width, bool sign);

#define Packet_ReadStr __Packet_ReadStr_C

#endif
