# acs-libs
A collection of Zandronum ACS libraries. Mainly GDCC.

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

## safe-malloc
A replacement for libGDCC aimed at simplifying mod interop/compatiblity. Performs memory allocation always starting from near the very top of the address space. Other copies of safe-malloc can coexist without issue since they're all aligned, and regular ACS mods using the same global array are very unlikely to run into any conflicts.

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
