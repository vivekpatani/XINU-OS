/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*-----------------------------------------------------------------------------
 * xsh_hello - obtain name and print welcome message with name
 *-----------------------------------------------------------------------------
 */
shellcmd xsh_hello(int nargs, char *args[]) {

	char name[64];			/* printable name is ascii */
	
	/* When the arguments are greater than 1 */
	if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments dude\n", args[0]);
		return 1;
	}
	
	/* When the arguments are lesser than 1 */
	if (nargs < 2) {
		fprintf(stderr, "%s: too few arguments dude\n", args[0]);
		return 1;
	}
	
	/* When the input is correct */
	if (nargs == 2) {
		printf("\nHello %s, Welcome to the world of XINU!\n", args[1]);
	}

	return 0;
}
