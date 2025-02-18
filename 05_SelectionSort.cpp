#include<iostream>
using namespace std;
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    cout << "Unsorted array\n";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    
    for(int i = 0; i < 5; i++) {
        int minIndex = i; // Store index of minimum element
        for(int j = i + 1; j < 5; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]); // Correctly swap elements
    }

    cout << "\nSorted Array\n";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
