#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int remove_overlap_internal(vector<vector<int>>& internals) {
    int size = internals.size();
    if (size <= 1) {
        return 0;
    }

    sort(internals.begin(), internals.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    int remove = 0;
    int prev = internals[0][1];
    for (int i = 1; i < size; ++i) {
        if (internals[i][0] < prev) {
            ++remove;
        } else {
            prev = internals[i][1];
        }
    }

    return remove;
}

int main() {
    {
        vector<vector<int>> internals = {{1,2},{2,4},{1,3}};
        cout << "need remove " << remove_overlap_internal(internals) << " internals" << endl;
    }

    return 0;
}
