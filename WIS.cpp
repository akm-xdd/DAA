#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end, weight;
};

bool compareIntervals(Interval i1, Interval i2) {
    return (i1.end < i2.end);
}

int latestNonConflict(Interval intervals[], int i) {
    for (int j=i-1; j>=0; j--) {
        if (intervals[j].end <= intervals[i].start) {
            return j;
        }
    }
    return -1;
}

int findMaxWeight(Interval intervals[], int n) {
    sort(intervals, intervals+n, compareIntervals);

    int *dp = new int[n];
    dp[0] = intervals[0].weight;

    for (int i=1; i<n; i++) {
        int inclWeight = intervals[i].weight;
        int l = latestNonConflict(intervals, i);
        if (l != -1) {
            inclWeight += dp[l];
        }
        dp[i] = max(inclWeight, dp[i-1]);
    }

    int result = dp[n-1];
    delete[] dp;
    return result;
}

int main() {
    Interval intervals[] = {{1, 4, 3}, {2, 6, 5}, {4, 7, 2}, {5, 9, 4}, {6, 8, 4}};
    int n = sizeof(intervals)/sizeof(intervals[0]);
    cout << "Max weight = " << findMaxWeight(intervals, n) << endl;
    return 0;
}
