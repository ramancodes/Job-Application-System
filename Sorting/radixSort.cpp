#include <iostream>
using namespace std;
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getMax(int arr[], int size){
    int max = arr[0];
    for(int i= 1; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void counting_sort_digit(int arr[], int size, int ex){
    int max = getMax(arr, size);
    int *count = new int[10]{0};
    int *outArr = new int[size];

    for(int i=0; i<size; i++){
        int digit = (arr[i]/ex)%10;
        count[digit] += 1;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int i=size-1;i>=0;i--){
        int digit = (arr[i]/ex)%10;
        outArr[count[digit]-1] = arr[i];
        count[digit]--;
    }
    for(int i=0; i<size; i++){
        arr[i] = outArr[i];
    }
}

void radixSort(int arr[], int size){
    int max = getMax(arr, size);
    for(int ex=1; max/ex>0; ex*=10){
        counting_sort_digit(arr, size, ex);
    }
    display(arr, size);
}

int main(){
    int arr[] = {4, 15, 22, 702, 60, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting: ";
    display(arr, size);
    cout<<"After Sorting: ";
    radixSort(arr, size);
}