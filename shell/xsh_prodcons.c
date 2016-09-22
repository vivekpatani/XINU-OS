#include <xinu.h>
#include <prodcons.h>

int n; //Definition for the global variable 'n'
/*Now global variable n will be pn Heap so it is acessible*/

shellcmd xsh_prodcons(int nargs, char *args[])

{
	//Argument verification and validations.
	int count = 2000;
	
	// If number of arguments are more than expected.
	if (nargs > 2) {
		printf("Usage: %s\n\n", args[0]);
		printf("Too Many Arguments\n");
		printf("\tAccepts at most one argument\n");
		printf("\tuse --help for more information\n");
		return 0;
	}
	
	// Help argument
	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays the consumed values\n");
		printf("\t1 Argument is expected.\n");
		printf("\tIf 0 given, then default will be 2000\n");
		printf("\t--help\t Display this help and exit\n");
		return 0;
	}
	
	// If there is an input.
	if (nargs == 2) {
		count = atoi(args[1]);
	}
	resume( create(producer, 1024, 20, "producer", 1, count));
	resume( create(consumer, 1024, 20, "consumer", 1, count));
	
	return (0);
}
