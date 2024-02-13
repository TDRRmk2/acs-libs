# acs-libs
A collection of Zandronum ACS libraries. Mainly GDCC.

## safe-malloc
A replacement for libGDCC aimed at simplifying mod interop/compatiblity. Performs memory allocation always starting from near the very top of the address space. Other copies of safe-malloc can coexist without issue since they're all aligned, and regular ACS mods using the same global array are very unlikely to run into any conflicts.
