#include <xinu.h>
#include <prodcons.h>

void consumer(int count) {
	
	int32 i;
	for (i = 1; i<= count; i++)
		kprintf("The Value of n is %d \n", n);	
}

