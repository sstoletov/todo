#include <stdio.h>
#include <stdlib.h>

#define PATH_LIST "/home/srzh/todo/data/list.txt"
#define PATH_SWP "/home/srzh/todo/data/swp.txt"
#define PATH_COMPLETED_LIST "/home/srzh/todo/data/completed_list.txt"
#define BUFFER_SIZE 256

int completed_task() {
    FILE *file_out = fopen(PATH_LIST, "r");
    FILE *file_in = fopen(PATH_SWP, "w");
    FILE *file_dist = fopen(PATH_COMPLETED_LIST, "a");

    if (!file_out || !file_in || !file_dist) {
        perror("Error opening files");
        if (file_out) fclose(file_out);
        if (file_in) fclose(file_in);
        if (file_dist) fclose(file_dist);
        return -1;
    }

    size_t index_task;
    printf("Enter task number (1-based): ");
    if (scanf("%lu", &index_task) != 1 || index_task < 1) {
        printf("Invalid input\n");
        fclose(file_out);
        fclose(file_in);
        fclose(file_dist);
        return -1;
    }
    while (getchar() != '\n'); 
    char buffer[BUFFER_SIZE];
    size_t index = 0;
    int task_found = 0;

    while (fgets(buffer, BUFFER_SIZE, file_out) != NULL) {
        if (index != index_task - 1) {
            if (fputs(buffer, file_in) == EOF) {
                perror("Error writing to swap file");
                goto cleanup;
            }
        } else {
            if (fputs(buffer, file_dist) == EOF) {
                perror("Error writing to completed list");
                goto cleanup;
            }
            task_found = 1;
        }
        index++;
    }

    if (!task_found) {
        printf("Task number %lu not found\n", index_task);
    }

    fclose(file_out);
    fclose(file_in);
    fclose(file_dist);

    file_out = fopen(PATH_SWP, "r");
    file_in = fopen(PATH_LIST, "w");
    if (!file_out || !file_in) {
        perror("Error reopening files");
        if (file_out) fclose(file_out);
        if (file_in) fclose(file_in);
        return -1;
    }

    while (fgets(buffer, BUFFER_SIZE, file_out) != NULL) {
        if (fputs(buffer, file_in) == EOF) {
            perror("Error copying back to list");
            fclose(file_out);
            fclose(file_in);
            return -1;
        }
    }

    fclose(file_out);
    fclose(file_in);
    remove(PATH_SWP); 
    return task_found ? 0 : 1;

cleanup:
    fclose(file_out);
    fclose(file_in);
    fclose(file_dist);
    return -1;
}
