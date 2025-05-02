// Common things for simplified ACC porting.
#ifndef INC_ACS_COMMON_H
#define INC_ACS_COMMON_H

#define ACS_SHORT_NAMES
#include <ACS_Zandronum.h>

#include <stdbool.h>
#include <stdfix.h>

// From this point on you can use stuff like "local int test[10]", and also allows
// pointers in this local space, so arrays are usable unlike register variables.
#define def_local __addrdef __loc_arr local

#pragma GDCC FIXED_LITERAL ON
#pragma GDCC STRENT_LITERAL ON

typedef __str str;

__addrdef extern __mod_arr modprefix_sta;

#define __tdb_print(a) (_Generic((a), _Bool: ACS_PrintNumber, int: ACS_PrintNumber, _Accum: ACS_PrintFixed, __str: ACS_PrintString, char: ACS_PrintChar))(a)

#define TDB_PRINT_1(a1) __tdb_print(a1)
#define TDB_PRINT_2(a1,a2) __tdb_print(a1), __tdb_print(a2)
#define TDB_PRINT_3(a1,a2,a3) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3)
#define TDB_PRINT_4(a1,a2,a3,a4) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4)
#define TDB_PRINT_5(a1,a2,a3,a4,a5) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5)
#define TDB_PRINT_6(a1,a2,a3,a4,a5,a6) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6)
#define TDB_PRINT_7(a1,a2,a3,a4,a5,a6,a7) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7)
#define TDB_PRINT_8(a1,a2,a3,a4,a5,a6,a7,a8) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8)
#define TDB_PRINT_9(a1,a2,a3,a4,a5,a6,a7,a8,a9) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9)
#define TDB_PRINT_10(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10)
#define TDB_PRINT_11(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11)
#define TDB_PRINT_12(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11), __tdb_print(a12)
#define TDB_PRINT_13(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11), __tdb_print(a12), __tdb_print(a13)
#define TDB_PRINT_14(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11), __tdb_print(a12), __tdb_print(a13), __tdb_print(a14)
#define TDB_PRINT_15(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11), __tdb_print(a12), __tdb_print(a13), __tdb_print(a14), __tdb_print(a15)
#define TDB_PRINT_16(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16) __tdb_print(a1), __tdb_print(a2), __tdb_print(a3), __tdb_print(a4), __tdb_print(a5), __tdb_print(a6), __tdb_print(a7), __tdb_print(a8), __tdb_print(a9), __tdb_print(a10), __tdb_print(a11), __tdb_print(a12), __tdb_print(a13), __tdb_print(a14), __tdb_print(a15), __tdb_print(a16)

#define TDB_GET_PRINT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,NAME,...) NAME
#define Append(...) (TDB_GET_PRINT_MACRO(__VA_ARGS__, TDB_PRINT_16, TDB_PRINT_15, TDB_PRINT_14, TDB_PRINT_13, TDB_PRINT_12, TDB_PRINT_11, TDB_PRINT_10, TDB_PRINT_9, TDB_PRINT_8, TDB_PRINT_7, TDB_PRINT_6, TDB_PRINT_5, TDB_PRINT_4, TDB_PRINT_3, TDB_PRINT_2, TDB_PRINT_1)(__VA_ARGS__))

#define Print(...) ((void)ACS_BeginPrint(), Append(__VA_ARGS__), ACS_EndPrint())
#define PrintBold(...) ((void)ACS_BeginPrint(), Append(__VA_ARGS__), ACS_EndPrintBold())
#define Log(...) ((void)ACS_BeginPrint(), Append(__VA_ARGS__), ACS_EndLog())
#define StrParam(...) ((void)ACS_BeginPrint(), Append(__VA_ARGS__), ACS_EndStrParam())

#define TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, ...) ((void)ACS_BeginHudMessage(), Append(__VA_ARGS__), ACS_OptHudMessage(type, id, color, x, y, holdTime))

#define HudMessage(type, id, color, x, y, holdTime, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessage())
#define HudMessageBold(type, id, color, x, y, holdTime, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageBold())

#define HudMessageX(type, id, color, x, y, holdTime, opt1, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageX(opt1))
#define HudMessageXX(type, id, color, x, y, holdTime, opt1, opt2, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageXX(opt1, opt2))
#define HudMessageXXX(type, id, color, x, y, holdTime, opt1, opt2, opt3, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageXXX(opt1, opt2, opt3))

#define HudMessageBoldX(type, id, color, x, y, holdTime, opt1, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageBoldX(opt1))
#define HudMessageBoldXX(type, id, color, x, y, holdTime, opt1, opt2, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageBoldXX(opt1, opt2))
#define HudMessageBoldXXX(type, id, color, x, y, holdTime, opt1, opt2, opt3, ...) (TDB_HUDMESSAGE_COMMON(type, id, color, x, y, holdTime, __VA_ARGS__), ACS_EndHudMessageBoldXXX(opt1, opt2, opt3))

#define LanguageLookup(n) (ACS_BeginStrParam(), ACS_PrintLocalized(n), ACS_EndStrParam())
#define GetPrintName(n) (ACS_BeginStrParam(), ACS_PrintName(n), ACS_EndStrParam())
#define IntToHex(n) (ACS_BeginStrParam(), ACS_PrintHex(n), ACS_EndStrParam())

#endif
