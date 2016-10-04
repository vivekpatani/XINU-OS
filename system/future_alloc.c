#include<xinu.h>
#include<future.h>  
future* future_alloc(int future_flag){

future *f = (future *)getmem(sizeof(future));
(*f).flag = future_flag ;
(*f).state = FUTURE_EMPTY;
(*f).pid = (pid32)-1;
(*f).value = 0;
return f;























}
