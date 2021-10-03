/*
 *  main.c -- Makefile Creation Tool: Create basic makefiles quickly.
 *  Author: Niklas Larsson
 *  Date: September 20, 2021
 */

#include "populate.h"
#include "descstr.h"
#include "usgstr.h"
#include "errors.h"
#include "helppage.h"
#include "succmsg.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LANG getenv("LANG")
#define NAME "mm"
#define VERSION "1.0"

#define QUIET_OPT_SHORT "-q"
#define QUIET_OPT_LONG "--quiet"
#define HELP_OPT_SHORT "-h"
#define HELP_OPT_LONG "--help"
#define VERSION_OPT_SHORT "-V"
#define VERSION_OPT_LONG "--version"
#define TYPE_OPT_SHORT "-t"
#define TYPE_OPT_LONG "--type"

#define len(string) (sizeof(string) / sizeof(*string))
#define SIZE 50

bool invargs = false;
bool quiet = false;
bool help_req = false;
bool version_req = false;
bool type_req = false;
bool ignore = false;
char ptype[SIZE];
char prname[SIZE];
bool prname_exists = false;

int main(int argc, char *argv[]) {

    /* Show usage string if missing args. */
    bool args = (argc > 1) ? true : false;
    if (! args) {
        dstr(LANG, NAME, VERSION);
        usgstr(LANG, NAME);
        return 1;
    }

    /* Parse command line arguments. Make separate file for this? */
    for (int i = 1; i < argc; ++i) {

        /* Validate project "type". */
        if (type_req && ! ignore) {
            if (strncmp(argv[i], "c", len(argv[i])) == 0) {
                strlcpy(ptype, argv[i], len(argv[i]));
            }
            else if (strncmp(argv[i], "py", len(argv[i])) == 0) {
                strlcpy(ptype, argv[i], len(argv[i]));
            }
            else {
                if (! invargs) {
                    invargs = true;
                }
                fterr(LANG, NAME, argv[i]);
            }
            ignore = true;
        }

        else if (argv[i][0] != '-' && ! prname_exists) {
            prname_exists = true;
            strlcpy(prname, argv[i], strlen(argv[i])+1);
        }
        else if (strncmp(argv[i], QUIET_OPT_SHORT, len(QUIET_OPT_SHORT)) == 0) {
            quiet = true;
        }
        else if (strncmp(argv[i], QUIET_OPT_LONG, len(QUIET_OPT_LONG)) == 0) {
            quiet = true;
        }
        else if (strncmp(argv[i], HELP_OPT_SHORT, len(HELP_OPT_SHORT)) == 0) {
            help_req = true;
        }
        else if (strncmp(argv[i], HELP_OPT_LONG, len(HELP_OPT_LONG)) == 0) {
            help_req = true;
        }
        else if (strncmp(argv[i], VERSION_OPT_SHORT, len(VERSION_OPT_SHORT)) == 0) {
            version_req = true;
        }
        else if (strncmp(argv[i], VERSION_OPT_LONG, len(VERSION_OPT_LONG)) == 0) {
            version_req = true;
        }
        else if (strncmp(argv[i], TYPE_OPT_SHORT, len(TYPE_OPT_SHORT)) == 0) {
            type_req = true;
        }
        else if (strncmp(argv[i], TYPE_OPT_LONG, len(TYPE_OPT_LONG)) == 0) {
            type_req = true;
        }
        else {
            if (! invargs) {
                invargs = true;
            }
            argerr(LANG, NAME, argv[i]);
        }
    }

    /* Handle invalid args. */
    if (invargs) {
        return 1;
    }

    /* Handle -V and --version. */
    if (version_req) {
        if (! help_req) {
            dstr(LANG, NAME, VERSION);
            return 0;
        }
    }

    /* Handle -h and --help. */
    if (help_req) {
        dstr(LANG, NAME, VERSION);
        usgstr(LANG, NAME);
        hpage(LANG, NAME);
        return 0;
    }

    /* Handle scenarios where -t or --type is missing. */
    if (! type_req) {
        tmerr(LANG, NAME, TYPE_OPT_SHORT, TYPE_OPT_LONG);
        return 1;
    }

    /* Handle scenarios where <name> is missing. */
    if (! prname_exists) {
        if (quiet) {
            nmerr(LANG, NAME);
        }
        if (type_req) {
            nmerr(LANG, NAME);
        }
        return 1;
    }

    /* Create the makefile. */
    create_makefile(prname, ptype, LANG, NAME);
    if (! quiet) {
        succmsgprint(LANG, NAME);
    }
    return 0;
}
