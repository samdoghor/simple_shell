#include "shell.h"

/**
 * executor - Executes the given command using the system shell.
 *
 * @exec_input: The command to be executed.
 */
void executor(const char *exec_input)
{
	/* Fork a new process */
	pid_t child_pid = fork();

	/* Declaration of the wait function */
	pid_t status;

	/* Check if forking the child process was successful */
	if (child_pid == -1)
	{
		custom_printf("Error forking child process.\n");
		exit(EXIT_FAILURE);
	}

	/* Code for the child process */
	else if (child_pid == 0)
	{
		/** Child process **/

		/** Parse the command and its arguments **/
		char *args[128]; /** Maximum 128 arguments (adjust as needed) **/
		int arg_count = 0;

		/* Tokenize the command string using space as the delimiter */
		char *token = strtok((char *)exec_input, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /** Null-terminate the arguments array **/

		/** Execute the command using execve **/
		execve(args[0], args, NULL);

		/** If execve fails, print an error message and exit **/
		custom_printf("Error executing command.\n");
		exit(EXIT_FAILURE);
	}

	/* Code for the parent process */
	else
	{
		/** Parent process **/

		/* Wait for the child process to complete */
		waitpid(child_pid, &status, 0);
	}
}
