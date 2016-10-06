#include<xinu.h>
#include<future.h>
syscall future_free(future* f){
	int status = 0;
	status += freemem((char* )f, sizeof(future));
	if (status == 3) return OK;
	else return SYSERR;
}