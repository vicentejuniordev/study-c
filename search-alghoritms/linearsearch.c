#include <stdio.h>;

int main(){

    int arr[5] = {3,4,5,6,8};

    int isFound = linearSearch(arr, 4);

    if(isFound == -1){
        printf("Número não encontrado...");
    }else{
        printf("O número está na posição %d do vetor", isFound);
    }


    return 0;

}

int linearSearch(int array[], int number){
    for(int i = 0; i < sizeof(array); i++){
        if(array[i] == number){
            return i;
        }
    }
    return -1;
}