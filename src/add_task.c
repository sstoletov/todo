#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "/home/srzh/todo/data/list.txt"
#define MAX_BUFFER 256

void add_task() {
    char buffer[MAX_BUFFER];
    
    if (fgets(buffer, MAX_BUFFER, stdin) == NULL) {
        printf("Error reading input\n");
        return;
    }
    
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    FILE* file = fopen(PATH, "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    if (fprintf(file, "%s\n", buffer) < 0) {
        printf("Error writing to file\n");
        fclose(file);
        return;
    }
    
    if (fclose(file) != 0) {
        perror("Error closing file");
    }

	return;
}
