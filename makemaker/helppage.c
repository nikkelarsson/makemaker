/*
 *  helppage.c
 *  Author: Niklas Larsson
 *  Date: September 28, 2021
 */

#include "helppage.h"
#include "langcodes.h"
#include <stdio.h>
#include <string.h>

void hpage(char *lang, char *name) {
    if (strncmp(lang, Finnish, strlen(lang)) == 0) {
        fprintf(stdout, "\nValitsimet:\n");
        fprintf(stdout, "-t,  --type <tyyppi>..... Määritä tyypiksi <tyyppi>.\n");
        fprintf(stdout, "-q,  --quiet............. Älä tulosta mitään.\n");
        fprintf(stdout, "-V,  --version........... Tulosta %s versio.\n", name);
        fprintf(stdout, "-h,  --help.............. Tulosta tämä viesti.\n");
    }
    else if (strncmp(lang, English, strlen(lang)) == 0) {
        fprintf(stdout, "\nOptions:\n");
        fprintf(stdout, "-t,  --type <type>..... Use type <type>.\n");
        fprintf(stdout, "-q,  --quiet........... Don't print any output.\n");
        fprintf(stdout, "-V,  --version......... Print %s version.\n", name);
        fprintf(stdout, "-h,  --help............ Print this message.\n");
    }
}
