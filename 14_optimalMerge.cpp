#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to calculate the minimum merge cost
int optimalMergeCost(vector<int> &files) {
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());

    int totalCost = 0;

    while (minHeap.size() > 1) {
        // Extract two smallest files
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Merge these files
        int mergeCost = first + second;
        totalCost += mergeCost;

        // Push the merged file back into the minHeap
        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> files = {4, 3, 2, 6};

    cout << "Minimum cost to merge files: " << optimalMergeCost(files) << endl;

    return 0;
}
