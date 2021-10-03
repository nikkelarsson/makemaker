/*
 *  populate.c
 *  Author: Niklas Larsson
 *  Date: September 21, 2021
 */

#include "populate.h"
#include "errors.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

FILE *makefile;

int init_makefile(char *lang, char *name) {
    makefile = fopen("Makefile", "w");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fclose(makefile);
    return 0; 
}

int populate_phony(char *lang, char *name, bool write_clean) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    if (write_clean) {
        fprintf(makefile, ".PHONY: clean install uninstall\n");
    }
    else {
        fprintf(makefile, ".PHONY: install uninstall\n");
    }
    fclose(makefile);
    return 0;
}

int populate_prog(char *prname, char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "PROGRAM = %s\n", prname);
    fclose(makefile);
    return 0;
}

int populate_ip(char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "BIN_INSTALL_PATH = $(HOME)/.local/bin/\n");
    fclose(makefile);
    return 0;
}

int populate_src(char *prname, char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "SRC = $(wildcard ./%s/*.c)\n", prname);
    fclose(makefile);
    return 0;
}

int populate_obj(char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "OBJ = $(SRC:.c=.o)\n");
    fclose(makefile);
    return 0;
}

int define_cc(char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "CC = \"/usr/bin/gcc\"\n\n");
    fclose(makefile);
    return 0;
}

int define_pyinter(char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "PY_INTERPRETER = python3\n\n");
    fclose(makefile);
    return 0;
}

int populate_main_target(char *prname, char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "%s: $(OBJ)\n", prname);
    fprintf(makefile, "\t$(CC) -o $@ $^\n\n");
    fclose(makefile);
    return 0;
}

int populate_install(char *lang, char *name, char *prtype) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    if (strncmp(prtype, "py", strlen(prtype)) == 0) {
        fprintf(makefile, "install:\n");
        fprintf(makefile, "\t@echo \"Installing $(PROGRAM) ...\"\n");
        fprintf(makefile, "\t$(PY_INTERPRETER) -m pip install .\n");
        fprintf(makefile, "\t@echo \"$(PROGRAM) installed.\"\n\n");
    }
    else if (strncmp(prtype, "c", strlen(prtype)) == 0) {
        fprintf(makefile, "install:\n");
        fprintf(makefile, "\t@echo \"Installing $(PROGRAM) ...\"\n");
        fprintf(makefile, "\t@mkdir -p $(BIN_INSTALL_PATH)\n");
        fprintf(makefile, "\tcp -f $(PROGRAM) $(BIN_INSTALL_PATH)\n");
        fprintf(makefile, "\t@echo \"$(PROGRAM) installed to $(BIN_INSTALL_PATH).\"\n\n");
    }
    fclose(makefile);
    return 0;
}

int populate_uninstall(char *lang, char *name, char *prtype) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    if (strncmp(prtype, "py", strlen(prtype)) == 0) {
        fprintf(makefile, "uninstall:\n");
        fprintf(makefile, "\t@echo \"Uninstalling $(PROGRAM) ...\"\n");
        fprintf(makefile, "\t$(PY_INTERPRETER) -m pip uninstall -y $(PROGRAM)\n");
        fprintf(makefile, "\t@echo \"$(PROGRAM) uninstalled.\"\n\n");
    }
    else if (strncmp(prtype, "c", strlen(prtype)) == 0) {
        fprintf(makefile, "uninstall:\n");
        fprintf(makefile, "\t@echo \"Uninstalling $(PROGRAM) ...\"\n");
        fprintf(makefile, "\trm $(BIN_INSTALL_PATH)$(PROGRAM)\n");
        fprintf(makefile, "\t@echo \"$(PROGRAM) uninstalled from $(BIN_INSTALL_PATH).\"\n\n");
    }
    fclose(makefile);
    return 0;
}

int populate_clean(char *prname, char *lang, char *name) {
    makefile = fopen("Makefile", "a");
    if (! makefile) {
        mferr(lang, name);
        return 1;
    }
    fprintf(makefile, "clean:\n");
    fprintf(makefile, "\trm -f $(OBJ) %s\n", prname);
    fclose(makefile);
    return 0;
}

void create_makefile(char *prname, char *prtype, char *lang, char *name) {
    init_makefile(lang, name);
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        populate_phony(lang, name, true);
    }
    else {
        populate_phony(lang, name, false);
    }
    populate_prog(prname, lang, name);
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        populate_ip(lang, name);
    }
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        populate_src(prname, lang, name);
        populate_obj(lang, name);
    }
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        define_cc(lang, name);
    }
    else {
        define_pyinter(lang, name);
    }
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        populate_main_target(prname, lang, name);
    }
    populate_install(lang, name, prtype);
    populate_uninstall(lang, name, prtype);
    if (! (strncmp(prtype, "py", strlen(prtype)) == 0)) {
        populate_clean(prname, lang, name);
    }
}
