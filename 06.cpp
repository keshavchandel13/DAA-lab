#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,1,2,3,2,1,3};
    int size = 7;
    int one =0,two=0,three=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1) one++;
        if(arr[i]==2) two++;
        if(arr[i]==3) three++;       
    }
    int i=0,j=0;
    while(i<one){
        arr[j] =1;
        i++;
        j++;
    }
    i = 0;
    while(i<two){
        arr[j] =2;
        i++;
        j++;
    }
    i=0;
    while(i<three){
        arr[j] =3;
        i++;
        j++;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}