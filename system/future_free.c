#include <xinu.h>

/* Frees up the allocated memory to a future */
syscall future_free(future* f){
	syscall sig = freemem((future*)f, sizeof(future));
	return sig;
}