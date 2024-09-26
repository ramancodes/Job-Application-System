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

void counting_sort(int arr[], int size){
    int max = getMax(arr, size);
    int *count = new int[max+1]{0};

    for(int i=0; i<size; i++){
        count[arr[i]] += 1;
    }

    for(int i=1; i<=max; i++){
        count[i] += count[i-1];
    }

    int *outArr = new int[size];
    for(int i=size-1;i>=0;i--){
        outArr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    display(outArr, size);
}

int main(){
    int arr[] = {4, 5, 2, 7, 6, 9, 2, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting: ";
    display(arr, size);
    cout<<"After Sorting: ";
    counting_sort(arr, size);
}