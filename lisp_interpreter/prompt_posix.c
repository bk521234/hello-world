#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functiongs */
#ifdef _WIN32
#include <string.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
/*
#include <editline/history.h>
*/
#endif

int main(int argc, char** argv) {
    /* Print Version and Exit Information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");
    puts("Live long and prosper.\n");

    /* In a never ending loop */
    while (1) {
        /* Output our prompt */
        char* input = readline("spock> ");
        add_history(input);

        /* Echo input back to user */
        printf("Your input '%s' is illogical.\n", input);
        free(input);
    }

    return 0;
}

