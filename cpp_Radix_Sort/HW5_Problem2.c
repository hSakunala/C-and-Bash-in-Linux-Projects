#include <stdio.h>
#include <stdlib.h>

void radixsort(float array[], int size, int numBits)
{
    // for(int e=0; e<size; e++){
    //     unsigned int x= (unsigned int) array[e];
    //     array[e]=x;
    // }
    unsigned int* arrUnsigned= (unsigned int*) array;
    float arr0[size];
    float arr1[size];
    for(int d=0;d<numBits;d++){
        int a0=0;
        int a1=0;
        for(int i=0;i<size; i++){
            int temp= arrUnsigned[i]>>d;
            if(d==31){
                if (temp&1){
                    arr0[a0]=array[i];
                    a0++;
                }
                else{
                    arr1[a1]=array[i];
                    a1++;
                }
            }
            else{
                if (temp&1){
                    arr1[a1]=array[i];
                    a1++;
                }
                else{
                    arr0[a0]=array[i];
                    a0++;
                }
            }
        }
        if(d==31){
            int g=1;
            for(int x=0;x<a0;x++){
                    array[a0-g]=arr0[x];
                    g++;
            }

            for(int y=a0;y<size;y++)
                    array[y]=arr1[y-a0];
        }
        else{
            for(int x=0;x<a0;x++)
                    array[x]=arr0[x];
            for(int y=a0;y<size;y++)
                    array[y]=arr1[y-a0];
        }
    }

    for(int z=0; z<size; z++)
        printf("%f\t", array[z]);
    printf("\n");
}

int main()
{
    int len;
    printf("Enter a lenght of array: ");
    scanf("%d", &len);
    float arr[len];
    float x;
    for (int i = 0; i < len; i++){
        printf("Index - %d : ",i);
        scanf("%f", &x);
        arr[i]=x;}
    
    radixsort(arr, len, 32);
}
