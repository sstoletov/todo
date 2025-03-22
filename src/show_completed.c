#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PATH "/home/srzh/todo/data/completed_list.txt"

void show_completed() {
	FILE* file = fopen(PATH, "r");

	if (file == NULL) {
		perror("cant open file\n");
		return;
	}
	
	char buffer[256];

	short number = 0;

	while ((fgets(buffer, 256, file)) != NULL) {
		if (buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = '\0';
		}
		printf("\033[32m%d %s\n\033[0m", ++number, buffer);
	}
	fclose(file);

	return;
}
