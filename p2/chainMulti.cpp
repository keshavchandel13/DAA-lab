#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int findmin(vector<int> arr, int i, int j, vector<vector<int>> dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int k = i; k<= j-1;k++){
        int ans =  findmin(arr, i,k, dp) + findmin(arr, k+1, j,dp) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, ans);
    }
    return mini;
}
int  matrixMultiplication(vector<int> arr, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return findmin(arr, 1, n-1, dp);
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);


return 0;
}