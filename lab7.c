/*Consider running Bubble and Selection Sorts on the two arrays shown below. Write a c 
program to compute the number of swaps performed on each value and the total number of swaps 
performed in the following 2 arrays:

array1: 97  16  45  63  13  22  7  58  72
array2: 90  80  70  60  50  40  30  20  10

The output should have a similar output:
array1:
7: # of times 7 is swapped
13: # of times 13 is swapped ...
total # of swaps

array2:
10: # of times 10 is swapped
20: # of times 20 is swapped...
total # of swaps

Please pay attention that the total # swaps is not equal to the sum 
of the swaps of each value listed above. Can you please think about the reason of this?*/
#include <stdio.h>
#define LEN 9

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int bubbleSort(int array[]){
    int totalSwap = 0;
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&(array[j]), &(array[j+1]));
                totalSwap++;
            }
        }
    }
    return totalSwap;
}

void selectionSort(int array[]){
    int i, j, min_idx;
    for(int i = 0; i < LEN-1; i++){
        min_idx = i;
        for(int j = i+1; j < LEN; j++){
            if(array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        swap(&(array[i]), &(array[min_idx]));
    }
}

void reset(int *array, int **freqarray){
    
}

void main(){
    //Bubble Arrays
    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int freqArray1[9][2] = {{97, 0},{16, 0},{45, 0},{63, 0},{13,0},{22,0},{7,0},{58,0},{72,0}};
    int freqArray2[9][2] = {{90, 0},{80, 0},{70, 0},{60, 0},{50,0},{40,0},{30,0},{20,0},{10,0}};
    printf("%d\n",bubbleSort(array1));
    printArray(array1, 9);

    // bubbleSort(array1);
    // bubbleSort(array2);
    // printArray(array1, 9);
    // printArray(array2, 9);
    // selectionSort(array1);
    // selectionSort(array2);
    // printArray(array1, 9);
    // printArray(array2, 9);

}