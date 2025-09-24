#include <iostream>
#include <algorithm> 
using namespace std;

struct activity {
    int start;
    int finish;
};

// Sorting activities based on finish time
bool compare(activity a1, activity a2) {
    return a1.finish < a2.finish;
}

int main() {
    struct activity activities[] = { {2, 4}, {2, 6}, {0, 4}, {5, 8}, {1,2} };
    int n = sizeof(activities) / sizeof(activities[0]);

    // Sorting the activities
    sort(activities, activities + n, compare);

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": Start = " << activities[i].start 
             << ", Finish = " << activities[i].finish << endl;
    }
    int last_selected =0,  count = 1;
    for(int i = 1; i<n; i++){
        if(activities[i].start >= activities[last_selected].finish ){
            count++;
            last_selected = i;
        }
    }
    cout<<"The number of activities can be performed "<<count;

    return 0;
}
