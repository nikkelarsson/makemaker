/*
 *  descstr.c -- Description strings.
 *  Author: Niklas Larsson
 *  Date: September 27, 2021
 */

#include "descstr.h"
#include "langcodes.h"
#include <stdio.h>
#include <string.h>

void dstr(char *lang, char *name, char *version) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stdout, "%s %s, make -tiedostojen luomisohjelma.\n",
                name, version);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stdout, "%s %s, makefile creation tool.\n",
                name, version);
    }
}
