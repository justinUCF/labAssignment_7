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

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void increment(int freqarray[][2], int value){
    for(int i = 0; i < LEN; i++){
        if(freqarray[i][0] == value){
            freqarray[i][1]++;
            return;

        }
    }
}
void reset(int array[], int stati[], int freqarray[][2]){
    for(int i =0; i < LEN; i++){
        array[i] = stati[i];
        freqarray[i][1] = 0;
    }
    return;
}
int bubbleSort(int array[], int freqarray[][2]){
    int totalSwap = 0;
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&(array[j]), &(array[j+1]));
                increment(freqarray, array[j]);
                increment(freqarray, array[j+1]);
                totalSwap++;
            }
        }
    }
    return totalSwap;
}

int selectionSort(int array[], int n,int freqarray[][2]){
    int i, j, min_idx, temp;
    int totalSwap = 0;
    for(int i = 0; i < n-1; i++){
        min_idx = i;
        for(int j = i+1; j < n; j++){
            if(array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            increment(freqarray, array[i]);
            increment(freqarray, array[min_idx]);
            totalSwap++;
        }
    }
    return totalSwap;
}


void main(){
    //Bubble Arrays
    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int static1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int static2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int freqArray1[9][2] = {{7, 0},{13, 0},{16, 0},{22, 0},{45,0},{58,0},{63,0},{72,0},{97,0}};
    int freqArray2[9][2] = {{10, 0},{20, 0},{30, 0},{40, 0},{50,0},{60,0},{70,0},{80,0},{90,0}};
    int totalSwap = 0;
    //Print bubble sort data
    printf("Bubble Sorts:\n");
    //array 1
    printf("Array1:\n");
    totalSwap = bubbleSort(array1, freqArray1);
    for(int i = 0; i < 9; i++){
        printf("%d:\t%d\n", freqArray1[i][0], freqArray1[i][1]);
    }
    printf("%d\n", totalSwap);
    //array 2
    printf("Array2:\n");
    totalSwap = bubbleSort(array2, freqArray2);
    for(int i = 0; i < 9; i++){
        printf("%d:\t%d\n", freqArray2[i][0], freqArray2[i][1]);
    }
    printf("%d\n", totalSwap);

    //Reset both arrays to default
    reset(array1, static1, freqArray1);
    reset(array2, static2, freqArray2);

    //Print selection sort data
    printf("Selection Sorts:\n");
    //array1
    printf("Array1:\n");
    totalSwap = selectionSort(array1, LEN, freqArray1);
    for(int i = 0; i < 9; i++){
        printf("%d:\t%d\n", freqArray1[i][0], freqArray1[i][1]);
    }
    printf("%d\n", totalSwap);
    //array2
    printf("Array2:\n");
    totalSwap = selectionSort(array2, LEN, freqArray2);
    for(int i = 0; i < 9; i++){
        printf("%d:\t%d\n", freqArray2[i][0], freqArray2[i][1]);
    }
    printf("%d\n", totalSwap);
    return;
}