#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {2,5,6};
    vector <int> unionArr;
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j=0;
    while(i<n && j<m){
        
        if( arr1[i]<=arr2[j] ){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i] ){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else if( arr1[i]>arr2[j] ){
            if(unionArr.size()==0 || unionArr.back()!=arr2[j] ){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }

    }
    while(i<n){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i] ){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    while(j<m){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j] ){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    // Printing sorted array
    for(int i:unionArr){
        cout<<i<<" ";
    }

return 0;
}