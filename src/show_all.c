#include <stdio.h>

#include "show_active.h"
#include "show_completed.h"

void show_all() {
	
	printf("\033[34mActive list \n\033[0m");
	show_active();

	printf("\n\033[34mComplete list \n\033[0m"); 
	show_completed();

	return;
}

