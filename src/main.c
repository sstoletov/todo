#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "show_all.h"
#include "add_task.h"
#include "show_active.h"
#include "show_completed.h"
#include "completed_task.h"
#include "clear.h"

const char* path_active = "/home/srzh/todo/data/list.txt";
const char* path_completed = "/home/srzh/todo/data/completed_list.txt";

int main(void) {
    char state[256];

    while (1) {
        if (fgets(state, sizeof(state), stdin) == NULL) {
            perror("Error reading input");
            return 1;
        }

        size_t len = strlen(state);
        if (len > 0 && state[len - 1] == '\n') {
            state[len - 1] = '\0';
        }

        if (strcmp(state, "add") == 0) {
            add_task();
            show_all(path_active, path_completed);
        } else if (strcmp(state, "complete") == 0) {
            completed_task();
            show_all(path_active, path_completed);
        } else if (strcmp(state, "clear") == 0) {
            clear(path_completed);
            show_all(path_active, path_completed);
        } else if (strcmp(state, "show") == 0) {
        	show_all(path_active, path_completed); 
        } else if (strcmp(state, "exit") == 0) {
            show_all(path_active, path_completed);
            return 0;
		} else {
			printf("unknown command\n");
		} 
    } 
    return 0;
}
