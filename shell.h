#ifndef SHELL_H
#define SHELL_H

/** Standard Library Headers **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Function: prompts
 * ----------------------------
 * Displays the shell prompt.
 */
void prompts(void);

/*
 * Function: custom_printf
 * ----------------------------
 * Custom implementation of printf.
 *
 * characters: The format string to be printed.
 */
void custom_printf(const char *characters);

/*
 * Function: input
 * ----------------------------
 * Reads user input into the provided buffer.
 *
 * input_command: Pointer to the buffer for storing user input.
 * size: Size of the buffer.
 */
void input(char *input_command, size_t size);

/*
 * Function: executor
 * ----------------------------
 * Executes the given command using the system shell.
 *
 * exec_input: The command to be executed.
 */
void executor(const char *exec_input);

#endif

