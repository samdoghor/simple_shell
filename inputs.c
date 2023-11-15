#include "shell.h"

/**
 * input - Reads user input from stdin into the provided buffer.
 *
 * @input_command: Pointer to the buffer for storing user input.
 * @size: Size of the buffer.
 */
void input(char *input_command, size_t size)
{
	/*
	 * Use fgets to read input from stdin into the provided buffer.
	 * If fgets returns NULL, an error or end-of-file (EOF) occurred.
	 */
	if (fgets(input_command, size, stdin) == NULL)
	{
		/*
		 * If feof(stdin) is true, the end-of-file (EOF) was reached.
		 * Print a newline and exit with success status.
		 */
		if (feof(stdin))
		{
			custom_printf("\n");
			exit(EXIT_SUCCESS);
		}
		/*
		 * If fgets returned NULL and feof(stdin) is false,
		 * an error occurred while reading input.
		 * Print an error message and exit with failure status.
		 */
		else
		{
			custom_printf("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}

	/* Remove the newline character from the end of the input string. */
	input_command[strcspn(input_command, "\n")] = '\0';
}
