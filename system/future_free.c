#include<xinu.h>
#include<future.h>
syscall future_free(future* f){
	syscall sig = freemem((char*)f, sizeof(future));
	return sig;
}