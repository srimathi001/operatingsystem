#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 100
#define MAX_FILES 100

typedef struct {
    char name[20];
    int file_count;
    char files[MAX_FILES][20];
} Directory;

Directory directories[MAX_DIRS];
int dir_count = 0;

void create_directory(char* name) {
    if (dir_count >= MAX_DIRS) {
        printf("Directory limit exceeded.\n");
        return;
    }

    Directory new_dir;
    strcpy(new_dir.name, name);
    new_dir.file_count = 0;

    directories[dir_count] = new_dir;
    dir_count++;

    printf("Directory '%s' created successfully.\n", name);
}

void create_file(char* dir_name, char* file_name) {
    int i;
    Directory* dir = NULL;

    // Find the directory
    for (i = 0; i < dir_count; i++) {
        if (strcmp(directories[i].name, dir_name) == 0) {
            dir = &directories[i];
            break;
        }
    }

    if (dir == NULL) {
        printf("Directory '%s' does not exist.\n", dir_name);
        return;
    }

    if (dir->file_count >= MAX_FILES) {
        printf("File limit exceeded in directory '%s'.\n", dir_name);
        return;
    }

    // Check if the file already exists in the directory
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i], file_name) == 0) {
            printf("File '%s' already exists in directory '%s'.\n", file_name, dir_name);
            return;
        }
    }

    strcpy(dir->files[dir->file_count], file_name);
    dir->file_count++;

    printf("File '%s' created successfully in directory '%s'.\n", file_name, dir_name);
}

void list_files(char* dir_name) {
    int i;
    Directory* dir = NULL;

    // Find the directory
    for (i = 0; i < dir_count; i++) {
        if (strcmp(directories[i].name, dir_name) == 0) {
            dir = &directories[i];
            break;
        }
    }

    if (dir == NULL) {
        printf("Directory '%s' does not exist.\n", dir_name);
        return;
    }

    printf("Files in directory '%s':\n", dir_name);
    for (i = 0; i < dir->file_count; i++) {
        printf("- %s\n", dir->files[i]);
    }
}

int main() {
    create_directory("user1");
    create_directory("user2");
    create_directory("user3");

    create_file("user1", "file1");
    create_file("user1", "file2");
    create_file("user1", "file3");

    create_file("user2", "file4");
    create_file("user2", "file5");

    create_file("user3", "file6");
    create_file("user3", "file7");

    list_files("user1");
    list_files("user2");
    list_files("user3");

    return 0;
}
