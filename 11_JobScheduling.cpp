#include<iostream>
#include <algorithm>
using namespace std;
struct Job{
    int id;
    int dead;
    int profit;
};
bool compare(Job a, Job b){
    return (a.profit>b.profit);
}

void jobScheduling(Job arr[], int n){
    // Sort on the basis of the profit
    sort(arr,arr+n,compare);
    // Highest deadline
    int maxi = arr[0].dead;
    for(int i = 1;i<n;i++){
        maxi = max(maxi, arr[i].dead);
    }
    // Declare the space to store  the 
    int slot[maxi+1];
    // Initilize the slot array with -1
    for(int i=0;i<=maxi;i++)
        slot[i] = -1;
    int countJobs = 0, profit = 0;
    for(int i=0;i<n;i++){
        for(int j = arr[i].dead;j>0;j--){
            if(slot[j]==-1){
                profit+=arr[i].profit;
                countJobs++;
                slot[j] = arr[i].id;
                break;
            }
        }
    }
    cout<<"The max Profit is: "<<profit<<endl;
    cout<<"The max Jobs can be done: "<<countJobs<<endl;



}


int main(){
    int n = 6;
    Job arr[n] = {
        {1,4,25},
        {2,2,24},
        {3,4,15},
        {4,2,10},
        {5,2,20},
        {6,4,12},
    };
    jobScheduling(arr,n);
return 0;
}