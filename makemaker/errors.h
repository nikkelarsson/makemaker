/*
 *  errors.h
 *  Author: Niklas Larsson
 *  Date: September 28, 2021
 */

/**
 *  Unsupported filetype error.
 *  Throws an error in the specified language 'lang'.
 */
void fterr(char *lang, char *name, char *arg);

/**
 *  Unrecognized argument error.
 *  Throws an error in the specified language 'lang'.
 */
void argerr(char *lang, char *name, char *arg);

/**
 *  Type missing -error.
 *  Throws an error in the specified language.
 */
void tmerr(char *lang, char *name, char *arg1, char *arg2);

/**
 *  Name missing error.
 *  Throws an error in the specified language.
 */
void nmerr(char *lang, char *name);

/**
 *  Can't open makefile -error.
 *  Throws an error in the specified language 'lang'.
 */
void mferr(char *lang, char *name);
