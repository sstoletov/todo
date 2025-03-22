#include <stdio.h>

#include <stdio.h>

void clear(const char* path) {
    FILE* file = fopen(path, "w");
    
	if (file == NULL) {
        perror("Failed to clear file");
        return;
    }
    
    if (fclose(file) != 0) {
        perror("Error closing file");
        return;
    }
    
    return;
}
