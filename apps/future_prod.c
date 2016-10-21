#include <xinu.h>
#include <prodcons.h>

typedef struct futent future;

/* Producer for that future */
uint32 future_prod(future *fut) {
	
	int i, j;

	j=(int)fut;

	for (i=0; i<1000; i++) j += i;

	future_set(fut, &j);
	return OK;
}