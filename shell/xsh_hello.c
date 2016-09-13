/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*-----------------------------------------------------------------------------
 * xsh_hello - obtain name and print welcome message with name
 *-----------------------------------------------------------------------------
 */
shellcmd xsh_hello(int nargs, char *args[]) {

	//int32 retval;			/* return value */
	char name[64];			/* printable name is ascii */

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays Hello Message to say hi\n");
		printf("\tNo options to invoke here\n");
		printf("\tAuthored by:\n");
		printf("\tPooja Singh and Vivek Patani\n");
		printf("\t--help\tDisplay this useless help and exit\n");
		return 0;
	}

	if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments dude\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}

	if (nargs == 2) {
		strncpy (args[1], name, 64);
		printf("Copied");
	}
	
	if (name[0] == '\0') {
		printf("Hello Vivek, Welcome to the world of XINU!");
	} else {
		printf("\nHello\n%s, Welcome to the world of XINU!",name);
	}

	return 0;
}
