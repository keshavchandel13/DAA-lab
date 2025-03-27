#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
struct Item{
    int profit;
    int weight;
};
bool compare(Item a, Item b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1 > r2; // Sort in decending order
}
int calculateKnapsack(int capacity, vector<Item>&items){
    sort(items.begin(),items.end(),compare);

    double maxProfit = 0.0;
    for(auto &item : items){
        if(capacity>=item.weight){
            capacity-=item.weight;
            maxProfit+=item.profit;
        }
        else{
            maxProfit+=(double)item.profit*capacity/item.weight;
            break; // knapsack is full
        }
    }
    return maxProfit;
}
int main(){
    int capacity = 120;
    vector<Item> items={
        {60,35},
        {80,45},
        {40,15},
        {30,10},
        {70,50},
        {90,40},
        {25,12}
    };
    int maxProfit = calculateKnapsack(capacity,items);
    cout<<"The max profit is: "<<maxProfit;
    return 0;
}