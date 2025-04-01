#include<iostream>
using namespace std;
int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}
void quickSort(int arr[],int low, int high){
    if(low<high){
        int pivotIndex = partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }

}
void printSortedArray(int arr[]){
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {2,7,12,6,9,10};
    quickSort(arr,0,5);
    printSortedArray(arr);


return 0;
}