#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>


static int compareInteger(const void *x, const void *y)
{
    if ((*(int *)x) > (*(int *)y))
        return 1;
    if ((*(int *)x) < (*(int *)y))
        return -1;
    return 0;
}

int main(int argc, char *argv[])
{

    int numProcs, rank, root = 0;
    int numValues=0, numValues_Bloc;
    int i;
    int *values, *valuesData;
    MPI_Op op;
    int binOfNum, temp;
    FILE *filePtr;
    char filename[40];


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    if (rank == root)
    {
        printf("Enter Binary Filename: ");      
        scanf("%40s", filename);  
        filePtr = fopen(filename, "rb"); 
        
        while(fread(&binOfNum, sizeof(binOfNum), 1, filePtr)){
            numValues++;
            if (binOfNum == temp)
                break;
            temp = binOfNum;
        }
        values = (int *)malloc(numValues * sizeof(int));
        // printf("Numbers for sorting \n ");
        fclose(filePtr);
        filePtr = fopen(filename, "rb"); 
        int i=0;
        while(fread(&binOfNum, sizeof(binOfNum), 1, filePtr)){
            values[i] = binOfNum;
            // printf("%d ", values[i]);
            if (binOfNum == temp)
                break;
            temp = binOfNum;
            i++;
        }
        fclose(filePtr);
    }
    // printf("\n");

    MPI_Bcast(&numValues, 1, MPI_INT, 0, MPI_COMM_WORLD);
   
    numValues_Bloc = numValues / numProcs;
    valuesData = (int *)malloc(numValues_Bloc * sizeof(int));
    MPI_Scatter(values, numValues_Bloc, MPI_INT, valuesData,
                numValues_Bloc, MPI_INT, root, MPI_COMM_WORLD);


    qsort((char *)valuesData, numValues_Bloc, sizeof(int), compareInteger);

    if (rank == root)
    {
        filePtr = fopen(filename, "wb");

        // printf("Total Values : %d \n", numValues);
        // printf("Sorted Values : \n");
        for (i = 0; i < numValues; i++){
            fwrite(&valuesData[i],sizeof(valuesData[i]),1, filePtr );
            // printf("%d ", valuesData[i]);
        }
        // printf(" \n ");
        fclose(filePtr);
        free(values);
    } 

    free(valuesData);
    MPI_Finalize();
    return 0;
}
