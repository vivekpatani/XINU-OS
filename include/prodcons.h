/*Global varibale for the consumer problem*/
extern int n; /*this is just declaration*/

/*function Prototype*/
void consumer(int count);
void producer(int count);

uint future_prod(future *fut);
uint future_cons(future *fut);

extern sid32 produced, consumed, future_prod_id, future_cons_id;