#include "shell.h"

/**
 * main - The main function of the shell program.
 *       Continuously prompts the user, reads input, and executes commands until termination.
 *
 * Return: Always 0.
 */
int main(void)
{
	char inputs[120];

	/* Infinite loop for continuous execution */
	while (1)
	{
		/* Display shell prompt */
		prompts();

		/* Read user input into the buffer */
		input(inputs, sizeof(inputs));

		/* Execute the user input as a command */
		executor(inputs);
	}

	/*
	 * The program should never reach here, but return 0 for completeness.
	 */
	return (0);
}
