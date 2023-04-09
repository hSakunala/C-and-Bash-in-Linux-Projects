#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct node{
    int size; 
    char pathFile[1024]; 
    struct node *down; 
};
struct node *tip;

void file(char *filename, struct stat statbuf){
    struct node *ptrNode;
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->size = statbuf.st_size;
    ptrNode = tip;

    strcpy(node->pathFile, filename); 
    if (tip == NULL) 
        tip = node;
    else{
        int tipSize= tip-> size;
        int nodeSize= node->size;
        if (tipSize > nodeSize){                             
            node->down = tip;
            tip = node;
        }
        else{
            while(ptrNode->down != NULL && ptrNode->down->size < nodeSize)
                ptrNode = ptrNode->down;
            node->down = ptrNode->down;
            ptrNode->down = node;
        }
        
    }
}


void traverse(char* pathname){
    struct stat statbuf;
    mode_t mode;
    int result, charsRead;
    DIR *pDir;
    struct dirent * pEnt;
    char fileName[1024];

    result = stat(pathname, &statbuf);
    if (result == -1)
        return;   
    mode = statbuf.st_mode;

    if (S_ISREG(mode))
        file(pathname, statbuf);
    else if ( S_ISDIR(mode)){
        pDir = opendir(pathname);
        while ((pEnt = readdir(pDir)) != NULL){
            if (strcmp(pEnt->d_name, ".")!=0 && strcmp(pEnt->d_name, "..")!=0){
                strcpy(fileName, pathname);
                strcat(fileName, "/");
                strcat(fileName, pEnt->d_name);
                traverse(fileName);
            }
        }
        closedir(pDir);
    }
}

int main(int argc, char *argv[])
{   
    if(argc!=2 || strlen(argv[1])==0) {
        printf("%s dir\n", argv[0]);  
        exit(1);     
    }
    traverse(argv[1]);

    while (tip != NULL){
        printf("%d\t%s\n", tip->size, tip->pathFile);
        tip = tip->down;
    }

    return 0;
}