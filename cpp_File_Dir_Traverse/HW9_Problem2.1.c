#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct File {
    char* pathOfFile;
    int sizeOfFile;
    int fileDirectory;
};

struct D_Link {
    struct File file;
    struct D_Link* down;
    struct D_Link* up;
};

struct D_Link* getEnd(struct D_Link** tip);
struct D_Link* pop(struct D_Link** tip);
struct D_Link* lookNext(struct D_Link** tip);
void push(struct D_Link** tip, struct File file);
int sizeDLink(struct D_Link** tip);
struct File pathDetes(char* path);

struct D_Link* dLinkOpen = NULL;
struct D_Link* dLinkClosed = NULL;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Not Enough Arguements.\n");
        return 0;
    }
    DIR* dir;
    struct dirent* dirStart;
    char* fName;

    push(&dLinkOpen, pathDetes(argv[1]));

    while (sizeDLink(&dLinkOpen) != 0) {
        dir = opendir(lookNext(&dLinkOpen)->file.pathOfFile);
        for (;;) {
            dirStart = readdir(dir);
            if (dirStart == NULL)
                break;
            if (strcmp(dirStart->d_name, ".") != 0 && strcmp(dirStart->d_name, "..") != 0) {
                fName = malloc(strlen(lookNext(&dLinkOpen)->file.pathOfFile) + strlen(dirStart->d_name) + 2);
                sprintf(fName, "%s/%s", lookNext(&dLinkOpen)->file.pathOfFile, dirStart->d_name);
                struct File curr = pathDetes(fName);
                if (curr.fileDirectory == 0) 
                    push(&dLinkOpen, curr);
                else if (curr.fileDirectory == 1)
                    push(&dLinkClosed, curr);
            }
        }
        closedir(dir);
        pop(&dLinkOpen);
    }
    int size = sizeDLink(&dLinkClosed);
    struct D_Link* start = (*&dLinkClosed);
    for (int i = 0; i < size; i++) {
        struct D_Link* start2 = start->down;
        for (int j = i + 1; j < size; j++) {
            if (start->file.sizeOfFile > start2->file.sizeOfFile) {
                struct File tmp = start->file;
                start->file = start2->file;
                start2->file = tmp;
            }
            start2 = start2->down;
        }
        start = start->down;
    }
    struct D_Link* curr = (*&dLinkClosed);

    while (curr != NULL) {
        printf("%d\t%s\n", curr->file.sizeOfFile, curr->file.pathOfFile);
       curr = curr->down;
    } 
}

void push(struct D_Link** tip, struct File file) {
    struct D_Link* curr = (struct D_Link*) malloc(sizeof(struct D_Link));
    curr->file = file;
    if ((*tip) == NULL) {
        *tip = curr;
    }
    else {
        struct D_Link* last = getEnd(tip);
        last->down = curr;
        curr->up = last;
    }
}

struct D_Link* pop(struct D_Link** tip) {
    struct D_Link* curr;
    if ((*tip) == NULL)
        return NULL;
    if ((*tip)->down == NULL) {
        curr = (*tip);
        (*tip) = NULL;
        return curr;
    }
    curr = (*tip);
    (*tip) = (*tip)->down;
    (*tip)->up = NULL;
    return curr;
}


struct D_Link* lookNext(struct D_Link** tip) {
    if ((*tip) == NULL)
        return NULL;
    return (*tip);
}


struct D_Link* getEnd(struct D_Link** tip) {
    struct D_Link* curr = (*tip);
    
    if (curr == NULL)
        return NULL;

    while (curr->down != NULL) {
        curr = curr->down;
    }
    return curr;
}


int sizeDLink(struct D_Link** tip) {
    struct D_Link* curr = (*tip);
    int length = 0;

    while (curr != NULL) {
        length++;
        curr = curr->down;
    }
    return length;
}


struct File pathDetes(char* path) {
    struct File file;
    struct stat status;
    mode_t mode;
    int value;
    value = lstat(path, &status);
    if (value == -1) {
        printf("Cannot read %s\n", path);
        struct File error;
        return error;
    }
    mode = status.st_mode;
    file.pathOfFile = path;
    file.sizeOfFile = status.st_size;
    if (S_ISDIR(mode))
        file.fileDirectory = 0;
    else if (S_ISREG(mode))
        file.fileDirectory = 1;
    else
        file.fileDirectory = -1;
    return file;
}

