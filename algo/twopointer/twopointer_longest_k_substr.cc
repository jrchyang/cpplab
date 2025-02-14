#include <iostream>
#include <vector>

using namespace std;

// leetcode 340
int longest_k_substr(string s, int k) {
    int res = 0, cnt = 0;
    vector<int> need(128, 0);

    for (int l = 0, r = 0; r < s.size(); ++r) {
        if (need[s[r]]++ == 0) {
            ++cnt;
        }
        while (cnt > k) {
            if (--need[s[l++]] == 0) {
                --cnt;
            }
        }
        res = max(res, r - l + 1);
    }

    return res;
}

int main() {
    {
        string s = "eceba";
        int k = 2;
        cout << "reslut is : " << longest_k_substr(s, k) << endl;
    }
    {
        string s = "aa";
        int k = 1;
        cout << "reslut is : " << longest_k_substr(s, k) << endl;
    }

    return 0;
}
