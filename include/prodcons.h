#include <xinu.h>
#include <stdio.h>

/*Global varibale for the consumer problem*/
extern int n; /*this is just declaration*/

/*function Prototype*/
void consumer(int count);
void producer(int count);

uint32 future_prod(future *fut);
uint32 future_cons(future *fut);

extern sid32 produced, consumed, future_prod_id;