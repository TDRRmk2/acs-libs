# acs-libs
A collection of Zandronum ACS libraries. Some

## ptrace
### NOTE: decorate.ptrace is required for proper functionality.
A pseudo-linetrace library. Much like ZScript's `linetrace` or QuakeC's `trace`, allows tracing a hitscan line, and get information about it. Things like where the trace ended (can be in mid-air, even), if it hit anything, the total distance between the start and end of the trace and a temporary (1-tic) TID to whatever actor it hit, if any.
All information is returned in `PTrace_Data` after calling the `PTrace` function. In ACC, it's accessed as follows:
```
PTrace_Data[PTRACE_HIT]
PTrace_Data[PTRACE_POS_X] // y and z as well
PTrace_Data[PTRACE_HIT_ACTOR]
PTrace_Data[PTRACE_DISTANCE]
```
In BCC and GDCC (both fronts), there's headers available, which allow for much nicer access as a struct, as well as proper type support:
```
PTrace_Data.hitType
PTrace_Data.posX // y and z as well again
PTrace_Data.hitActor
PTrace_Data.distance
```
Note that all necessary information must be retrieved immediately after calling the function. Subsequent calls to `PTrace` will overwrite this struct, and `Delay`s also risk the same thing (and after a single tic the hit actor TID will be invalidated).

## paketlib
A library for Zandronum written in plain ACS (BCS and C headers to use the enhanced language features are available, too) that allows creating packets, sending and reading them over the network very easily.
As an example:
```c
Script "lol" OPEN
{
	str p = Packet_New();
	
	p = Packet_Append(p, 1122334499, PACKET_WORD);
	p = Packet_Append(p, 0, PACKET_WORD);
	p = Packet_AppendStr(p, "This is a test");
	p = Packet_Append(p, 13.5, PACKET_WORD);
	
	Packet_Send("ClientReceivePacket", p, -1);
}

Script "ClientReceivePacket" (int p) CLIENTSIDE
{
	p = Packet_Read(p, PACKET_WORD);
	int i1 = Packet_Rval;
	
	p = Packet_Read(p, PACKET_WORD);
	int i2 = Packet_Rval;
	
	p = Packet_ReadStr(p);
	str s = Packet_Rval;
	
	p = Packet_Read(p, PACKET_WORD);
	int f = Packet_Rval;

	Log(i:i1);
	Log(i:i2);
	Log(s:s);
	Log(f:f);
}
```
It's decently light on bandwidth usage as well. Overhead is a mere 1 extra byte for each 8-32bit integer/fixed point number/bool, and only 3 extra bytes for an entire string.

## ACS_Common
A header for GDCC meant to simplify writing code without `libGDCC` and `libc`, and for code intended to be ported from ACC/BCC. It does the following:
* Enables ACS strings by default, and defines a `str` alias to them.
* Enables the fixed point type for literals by default.
* Includes `ACS_Zandronum.h`, as well as `stdbool.h` and `stdfix.h` to provide the remaining ACS types.
* Defines `ACS_SHORT_NAMES` so ACS functions are included without the `ACS_` prefix.
* Adds a `def_local` macro to use inside functions, to allow using local arrays without requiring libGDCC.
* Adds a set of printing macros taking advantage of macro magic and `_Generic` (Can be used like: `Print("This is a number: ", 10, (char)'.');`).
* Adds the `LanguageLookup`, `GetPrintName` and `IntToHex` macros to cover the gaps not covered by the print functions.

**Remember to rename both** `modprefix_sta` **ocurrences to fit your project.**

## actorlib
A library making use of GDCC's struct properties to provide an `ActorT` struct that can call many functions in a more seamless way. For example:
```c
ActorT monster = {someMonsterTID};

monster.health = 200; // calls ACS_SetActorProperty(0, APROP_Health, 200)
if(monster.height < 32.0) // calls ACS_GetActorPropertyFixed(0, APROP_Height)
{
    monster.speed = 32.0;
    monster.scaleX = monster.scaleX - 0.1;
}
```
It also provides a global called `self`, in much the same vein as QuakeC. This allows referring to the script activator without any extra definitions:
```c
self.giveInv("Shotgun", 1);
self.health = 150;
self.viewHeight = self.height - 2.0;
```

## safe-malloc
### DEPRECATED, NO LONGER NECESSARY WITH CURRENT LIBGDCC
A replacement for libGDCC aimed at simplifying mod interop/compatiblity. Performs memory allocation always starting from near the very top of the address space. Other copies of safe-malloc can coexist without issue since they're all aligned, and regular ACS mods using the same global array are very unlikely to run into any conflicts.
