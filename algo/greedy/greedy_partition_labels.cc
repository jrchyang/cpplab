#include <iostream>
#include <vector>

using namespace std;

vector<int> partition_labels(string s) {
    int last_index[26] = {0};
    int length = s.size();

    for (int i = 0; i < length; ++i) {
        last_index[s[i] - 'a'] = i;
    }

    vector<int> partions;
    int start = 0;
    int end = 0;
    for (int i = 0; i < length; ++i) {
        end = max(end, last_index[s[i] - 'a']);
        if (i == end) {
            partions.push_back(end - start + 1);
            start = end + 1;
        }
    }

    return partions;
}

void print_result(vector<int>& partions) {
    for (const int& len: partions) {
        cout << len << " ";
    }
    cout << endl;
}

int main() {
    {
        vector<int> partions = partition_labels("ababcbacadefegdehijhklij");
        print_result(partions);
    }
    {
        vector<int> partions = partition_labels("eccbbbbdec");
        print_result(partions);
    }

    return 0;
}
