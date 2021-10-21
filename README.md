# About
**makemaker** or **mm**, was written purely out of interest towards the C-language.
To actually serve a purpose, it was written to provide me an easy way of creating
makefiles.

# How it works
**mm** works very simply. It creates a makefile to the current directory and
populates it with content. It can be used, for example, to create a makefile for
a Python project.  This is especially useful, since Python programs can be
installed with **pip**, and **make** and a makefile together can offer an easy
interface for doing all of this. As makefiles are maybe more traditionally used
with C programs, **mm** naturally has the ability to create one for those, too.

# Installation
**mm** can be installed using **make**. To start off, go to the root of
the project and run the following:

To compile, run:
``` bash
make
```

To install, run:
``` bash
sudo make install
```

To uninstall, run:
``` bash
sudo make uninstall
```
