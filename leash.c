#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;
    size_t capacity = 0;

    for (;;) {
	printf("leash $ ");
	fflush(stdout);

	if (getline(&line, &capacity, stdin) == -1)
	    break;
    }

    free(line);
    return 0;
}
