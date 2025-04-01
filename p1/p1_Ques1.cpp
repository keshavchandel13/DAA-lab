#include<iostream>
#include<algorithm>
// ACtivity
using namespace std;
struct Activity{
    int start;
    int finish;
};
bool compare(Activity a, Activity b){
    return a.finish < b.finish;
}
int main(){
    int n;
    cout<<"Enter the number of the activities"<<endl;
    cin>>n;
    Activity arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the activity "<<i+1<<" start "<<" end"<<endl;
        cin>>arr[i].start;
        cin>>arr[i].finish;
    }
    // sorting 
    sort(arr,arr+n,compare);
    // Printing the activity
    cout<<"ID\tSt\tfini"<<endl;
    for(int i = 0;i<n;i++){
        cout<<i+1<<"\t"<<arr[i].start<<"\t"<<arr[i].finish<<endl;
    }
    // ACtivity selection
    int last_selected = 0, count = 1;
    for(int i = 1;i<n;i++){
        if(arr[last_selected].finish<=arr[i].start){
            last_selected = i;
            count++;
        }
    }
    cout<<"The number of activity person can do is: "<<count<<endl;

return 0;
}