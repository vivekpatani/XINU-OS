#include<xinu.h>
#include<future.h>  
future* future_alloc(int future_flag){
	future *f = (future *)getmem(sizeof(future));
	(*f).flag = future_flag ;
	(*f).state = FUTURE_EMPTY;
	(*f).pid = -1;
	(*f).value = NULL;
	return f;
}