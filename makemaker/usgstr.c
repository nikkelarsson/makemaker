/*
 *  usgstr.c
 *  Author: Niklas Larsson
 *  Date: September 28, 2021
 */

#include "usgstr.h"
#include "langcodes.h"
#include <stdio.h>
#include <string.h>

void usgstr(char *lang, char *name) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stdout, "Käyttö: %s [valitsimet] -t | --type <tyyppi> <nimi>\n", name);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stdout, "Usage: %s [options] -t | --type <type> <name>\n", name);
    }
}
