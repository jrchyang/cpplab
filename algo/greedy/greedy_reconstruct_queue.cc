#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reconstruct_queue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    int length = people.size();
    vector<vector<int>> res(length);
    for (const vector<int>& item: people) {
        int index = item[1] + 1;
        for (int i = 0; i < length; ++i) {
            if (res[i].empty()) {
                --index;
                if (index == 0) {
                    res[i] = item;
                    break;
                }
            }
        }
    }

    return res;
}

void print_items(vector<vector<int>>& people) {
    for (auto it = people.begin(); it != people.end(); it++) {
        cout << "[" << (*it)[0] << "," << (*it)[1] << "] ";
    }
    cout << endl;
}

int main() {
    {
        vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        vector<vector<int>> res = reconstruct_queue(people);
        print_items(res);
    }
    {
        vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
        vector<vector<int>> res = reconstruct_queue(people);
        print_items(res);
    }

    return 0;
}
