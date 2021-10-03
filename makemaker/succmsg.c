/*
 *  succmsg.c
 *  Author: Niklas Larsson
 *  Date: September 28, 2021
 */

#include "succmsg.h"
#include "langcodes.h"
#include <stdio.h>
#include <string.h>

void succmsgprint(char *lang, char *name) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stdout, "%s: make -tiedosto luotu.\n", name);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stdout, "%s: makefile created.\n", name);
    }
}
