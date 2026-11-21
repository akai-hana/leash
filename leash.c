#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void echo()
{
    char *args = strtok(NULL, "\n");

    if (args)
	puts(args);

    // TODO: ignore "" '' chars
}

/**
 * Dummy test
 * Currently always returns 0 success.
 */
static int test()
{
    // TODO: handle non-success logic

    return 0;
}

/**
 * Change the shell's prompt 
 */
static void prompt(char promptText[])
{
    char *args = strtok(NULL, "\n");

    if (args) {
	strcpy(promptText, args);
	strcat(promptText, " ");
    }
}


/**
 * Leash shell REPL
 */
int main(void)
{
    char promptText[] = "leash $ ";

    char *line = NULL;
    size_t capacity = 0;

    for (;;) {
	printf("%s", promptText);
	fflush(stdout);

	if (getline(&line, &capacity, stdin) == -1)
	    break;

	// Separates command from args
	char *cmd = strtok(line, " \n");

	// If a command exists, evaluate command list
	if (cmd) {
	    /* COMMAND LIST */

	    // shellutils
	    if (strcmp(cmd, "test") == 0)
		test();
	    else if (strcmp(cmd, "echo") == 0)
		echo();
	    else if (strcmp(cmd, "prompt") == 0)
		prompt(promptText);

	    // fileutils
	    /*
	    else if (strcmp(cmd, "cd") == 0)
		cd();
	    else if (strcmp(cmd, "ls") == 0)
		ls();
	    else if (strcmp(cmd, "mv") == 0)
		mv();
	    else if (strcmp(cmd, "cp") == 0)
		cp();
	    else if (strcmp(cmd, "rm") == 0)
		rm();
	    */

	    // textutils

	    // TODO: make a command table or switch or something

	    // Built-in
	    else if (strcmp(cmd, "exit") == 0)
		break;
	    else
		printf("leash: Unknown command: %s\n", cmd);
	}
    }

    free(line);

    return 0;
}
