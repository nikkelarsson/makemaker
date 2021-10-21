% MM(1) mm 1.0
% Niklas Larsson
% September 2021

# NAME
mm –– Create makefiles easily.

# SYNOPSIS
**mm** \[*–q* | *––quiet*\] *–t* | *––type* \<*type*\> \<*name*\> \
**mm** *–h* | *––help* \
**mm** *–V* | *––version*

# DESCRIPTION
**mm** creates and populates a makefile so that you don't have to. **mm** will
populate the makefile according to what *type* is being used. The type can be a
file extension, *c* or *py* for example (without dots! ".py" is invalid, "py"
is correct etc). Different types have different results. For example, if *py* is
used as a type, only install and uninstall -targets are created. On the other
hand, if *c* is used as a type, a target for compiling is created as well.

# OPTIONS
**–t** | **––type** \<*c*|*py*\>
: Use type \<type\>.

**–q** | **––quiet**
: Don't print any output.

**–V** | **––version**
: Print mm version.

**–h** | **––help**
: Print available flags/commands.
