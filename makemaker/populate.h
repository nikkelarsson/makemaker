/*
 *  populate.h
 *  Author: Niklas Larsson
 *  Date: September 21, 2021
 */

#include <stdbool.h>


/**
 *  Initialize the makefile by creating it.
 *  Returns 0 upon success, 1 upon error.
 */
int init_makefile(char *lang, char *name);

/**
 *  Write the necessary .PHONY information to the makefile.
 *  Returns 0 upon success, 1 upon error.
 */
int populate_phony(char *lang, char *name, bool write_clean);

/**
 *  Write the section to the makefile that contains
 *  program's name. Returns 0 upon success, 1 upon error.
 */
int populate_prog(char *prname, char *lang, char *name);

/**
 *  Write the section to the makefile that contains
 *  program's installation path.
 */
int populate_ip(char *lang, char *name);

/**
 *  Write the section to the makefile that contains
 *  the location to the sourcecode. Returns 0 upon
 *  success, 1 upon error.
 */
int populate_src(char *prname, char *lang, char *name);

/**
 *  Write the section to the makefile that contains
 *  the location to the objectcode files. Returns 0
 *  upon success, 1 upon error.
 */
int populate_obj(char *lang, char *name);

/**
 *  Write the section to the makefile that defines,
 *  what c compiler will be used. Returns 0 upon
 *  success, 1 upon error.
 */
int define_cc(char *lang, char *name);

/**
 *  Write the section to the makefile that defines,
 *  what python interpreter will be used.
 *  Returns 0 upon success, 1 upon error.
 */
int define_pyinter(char *lang, char *name);

/**
 *  Write the section to the makefile that contains
 *  the main target, its dependecies, and the commands
 *  to execute. Returns 0 upon success, 1 upon error.
 */
int populate_main_target(char *prname, char *lang, char *name);

/**
 *  Write the install -section to the makefile.
 *  Returns 0 upon success, 1 upon error.
 */
int populate_install(char *lang, char *name, char *prtype);

/**
 *  Write the uninstall -section to the makefile.
 *  Returns 0 upon success, 1 upon error.
 */
int populate_uninstall(char *lang, char *name, char *prtype);

/**
 *  Write the section to the makefile that contains
 *  the clean target and the commands to execute this.
 *  Returns 0 upon success, 1 upon error.
 */
int populate_clean(char *prname, char *lang, char *name);

/**
 *  Create the makefile "fully", populating it
 *  with all the necessary stuff.
 */
void create_makefile(char *prname, char *prtype, char *lang, char *name);
