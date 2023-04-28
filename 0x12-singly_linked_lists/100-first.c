#include <stdio.h>
/**
 * beforemain - functure to run before main
 * Retur: no return value
 */

void __attribute__ ((constructor)) beforemain()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}
