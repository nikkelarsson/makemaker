/*
 *  errors.c
 *  Author: Niklas Larsson
 *  Date: September 28, 2021
 */

#include "errors.h"
#include "langcodes.h"
#include <stdio.h>
#include <string.h>

void fterr(char *lang, char *name, char *arg) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stderr, "%s: virhe: ei tuettu tiedostotyyppi '%s'.\n",
                name, arg);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stderr, "%s: error: unsupported filetype '%s'.\n",
                name, arg);
    }
}

void argerr(char *lang, char *name, char *arg) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stderr, "%s: virhe: tuntematon argumentti '%s'.\n",
                name, arg);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stderr, "%s: error: unrecognized argument '%s'.\n",
                name, arg);
    }
}

void tmerr(char *lang, char *name, char *arg1, char *arg2) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stderr, "%s: virhe: '%s' tai '%s' tarvitaan.\n",
                name, arg1, arg2);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stderr, "%s: error: '%s' or '%s' required.\n",
                name, arg1, arg2);
    }
}

void nmerr(char *lang, char *name) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stderr, "%s: virhe: <nimi> tarvitaan.\n",
                name);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stderr, "%s: error: <name> is required.\n",
                name);
    }
}

void mferr(char *lang, char *name) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stderr, "%s: virhe: ei voitu avata make -tiedostoa.\n", name);
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stderr, "%s: error: could not open makefile.\n", name);
    }
}
