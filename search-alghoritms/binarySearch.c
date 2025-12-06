#include<stdio.h>;

int main(){
    int arr[5] = {1,2,3,4,5};

    int result = binarySearch(arr, 4);

    if(result == -1){
        printf("Número não encontrado...");
    }else{

        printf("O número está na posição %d do array", result);
    }

    return 0;
}

int binarySearch(int array[], int target){
    int start = 0;
    int end = sizeof(array) - 1;

    while (start <= end){
        int middle = start + (end - start)/2;

        if(array[middle] < target){
            start = middle + 1;
        } else if(array[middle] > target){
            start = middle - 1;
        }else{
            return middle;
        }
    }

    return -1;
}