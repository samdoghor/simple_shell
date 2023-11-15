#include "shell.h"

/**
 * custom_printf - Custom implementation of printf that writes to STDOUT_FILENO.
 *
 * @characters: The format string to be printed.
 */
void custom_printf(const char *characters)
{
	/*
	 * Write the characters to STDOUT_FILENO using the write system call.
	 */
	write(STDOUT_FILENO, characters, strlen(characters));
}
