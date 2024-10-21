#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct File {
    char* filename;
    struct File* next;
} File;

// Structure to represent a Directory
typedef struct Directory {
    char* directoryName;
    struct Directory* subdirectories; // Head of subdirectories linked list
    struct Directory* next;           // Next sibling directory
    File* files;                      // Head of files linked list
    struct Directory* parent;         // Pointer to parent directory
} Directory;

// Structure to represent the File System
typedef struct FileSystem {
    Directory* rootDirectory;
} FileSystem;



Directory* getDirectSubdirectory(Directory* parent, const char* dirName);
Directory* add_subdirectory(Directory* dir, const char* directoryName);
int add_file(Directory* dir, const char* filename);
void print_directory_contents(Directory* dir);
void print_filesystem(FileSystem* fs);
Directory* create_directory(const char* directoryName, Directory* parent);
void print_directory_recursive(Directory* dir, int level); // Declare the function prototype



// Get a direct subdirectory by name
Directory* getDirectSubdirectory(Directory* parent, const char* dirName) {
    Directory* temp = parent->subdirectories;
    while (temp) {
        if (strcmp(temp->directoryName, dirName) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Add a subdirectory to the current directory
Directory* add_subdirectory(Directory* dir, const char* directoryName) {
    if (getDirectSubdirectory(dir, directoryName) != NULL) {
        return NULL;  // Subdirectory already exists
    }

    Directory* newDir = create_directory(directoryName, dir);
    newDir->next = dir->subdirectories;  // Add the new directory to the head of the list
    dir->subdirectories = newDir;

    return newDir;
}

// Add a file to the current directory
int add_file(Directory* dir, const char* filename) {
    File* temp = dir->files;
    while (temp) {
        if (strcmp(temp->filename, filename) == 0) {
            return 0;  // File already exists
        }
        temp = temp->next;
    }

    File* newFile = (File*)malloc(sizeof(File));
    newFile->filename = strdup(filename);
    newFile->next = dir->files;  // Add the new file to the head of the list
    dir->files = newFile;

    return 1;
}

// Print the contents of the current directory
void print_directory_contents(Directory* dir) {
    printf("Directory: %s\n", dir->directoryName);

    // Print subdirectories
    Directory* tempDir = dir->subdirectories;
    printf("Subdirectories:\n");
    while (tempDir) {
        printf("  %s\n", tempDir->directoryName);
        tempDir = tempDir->next;
    }

    // Print files
    File* tempFile = dir->files;
    printf("Files:\n");
    while (tempFile) {
        printf("  %s\n", tempFile->filename);
        tempFile = tempFile->next;
    }
}

// Recursive function to print the directory and its subdirectories/files
void print_directory_recursive(Directory* dir, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s/\n", dir->directoryName);

    // Print files in the directory
    File* file = dir->files;
    while (file) {
        for (int i = 0; i < level + 1; i++) printf("  ");
        printf("%s\n", file->filename);
        file = file->next;
    }

    // Recursively print subdirectories
    Directory* subdir = dir->subdirectories;
    while (subdir) {
        print_directory_recursive(subdir, level + 1);
        subdir = subdir->next;
    }
}

// Recursive function to print the entire file system
void print_filesystem(FileSystem* fs) {
    Directory* root = fs->rootDirectory;
    print_directory_recursive(root, 0);
}

// Create a new directory
Directory* create_directory(const char* directoryName, Directory* parent) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    if (!newDir) {
        perror("Failed to allocate memory for directory");
        exit(EXIT_FAILURE);
    }
    newDir->directoryName = strdup(directoryName);
    newDir->subdirectories = NULL;
    newDir->next = NULL;
    newDir->files = NULL;
    newDir->parent = parent;
    return newDir;
}

// -------------------------BoilerPlate Function Implementations ---------

// Allocate memory to fileSystem
FileSystem* create_filesystem(const char* rootName) {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    if (!fs) {
        perror("Failed to allocate memory for file system");
        exit(EXIT_FAILURE);
    }
    fs->rootDirectory = create_directory(rootName, NULL);
    return fs;
}

// Trim newline from the input string
void trim_newline(char* str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len == 0) return;
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


int main() {
    FileSystem* fs = create_filesystem("root");
    Directory* head = fs->rootDirectory;
    Directory* dir = NULL;

    // Variable to store user input
    char input[256];

    printf("Welcome to the In-Memory File System!\n");
    printf("Available commands:\n");
    printf(" cd <directory_name>\n");
    printf(" mkdir <directory_name>\n");
    printf(" touch <file_name>\n");
    printf(" ls\n");
    printf(" print\n");
    printf(" exit\n\n");

    while (1) {
        printf(">> ");  // Prompt

        // Read input from the user
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character
        trim_newline(input);

        // Check for empty input
        if (strlen(input) == 0) {
            continue;
        }

        // Tokenize the input into command and argument
        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");

        // Handle commands
        if (strcmp(command, "cd") == 0) {
            if (argument == NULL) {
                printf("Error: 'cd' command requires a directory name.\n");
                continue;
            }
            if (strcmp(argument, "..") == 0) {
                if (head != fs->rootDirectory) {
                    head = head->parent;
                    printf("Switched to parent directory %s \n", head->directoryName);
                } else {
                    printf("You are already at root directory\n");
                }
                continue;
            }
            dir = getDirectSubdirectory(head, argument);
            if (dir) {
                printf("Switched to directory %s \n", argument);
                head = dir;
            } else {
                printf("No such subdirectory here\n");
            }
        } else if (strcmp(command, "mkdir") == 0) {
            if (argument == NULL) {
                printf("Error: 'mkdir' command requires a directory name.\n");
                continue;
            }
            dir = add_subdirectory(head, argument);
            if (dir) {
                printf("Created SubDirectory %s \n", argument);
            } else {
                printf("SubDirectory with name %s already exists here\n", argument);
            }
        } else if (strcmp(command, "touch") == 0) {
            if (argument == NULL) {
                printf("Error: 'touch' command requires a file name.\n");
                continue;
            }
            int x = add_file(head, argument);
            if (x) {
                printf("Created file %s \n", argument);
            } else {
                printf("File with name %s already exists here \n", argument);
            }
        } else if (strcmp(command, "ls") == 0) {
            print_directory_contents(head);
        } else if (strcmp(command, "print") == 0) {
            print_filesystem(fs);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the File System. Goodbye!\n");
            break;
        } else {
            printf("Error: Unknown command '%s'.\n", command);
        }
    }

    return 0;
}
