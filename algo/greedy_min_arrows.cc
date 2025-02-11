#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_min_arrows(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int total = 1;
    int prev =  points[0][1];
    for (const vector<int>& balloon: points) {
        if (balloon[0] > prev) {
            ++total;
            prev = balloon[1];
        }
    }

    return total;
}

int main() {
    {
        vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
        cout << "need " << find_min_arrows(points) << " arrows" << endl;
    }
    {
        vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
        cout << "need " << find_min_arrows(points) << " arrows" << endl;
    }
    {
        vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
        cout << "need " << find_min_arrows(points) << " arrows" << endl;
    }

    return 0;
}
