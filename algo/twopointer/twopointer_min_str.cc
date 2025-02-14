#include <iostream>
#include <vector>
#include <string>

using namespace std;

string min_windows(string s, string t) {
    vector<int> need(128, 0);
    vector<bool> flag(128, false);
    for (int i = 0; i < t.size(); ++i) {
        flag[t[i]] = true;
        ++need[t[i]];
    }

    int cnt = 0;
    int l = 0;
    int min_l = 0;
    int min_size = s.size() + 1;
    for (int r = 0; r < s.size(); ++r) {
        if (flag[s[r]] == false)
            continue;

        if (--need[s[r]] >= 0) {
            ++cnt;
        }
        while (cnt == t.size()) {
            if (r - l + 1 < min_size) {
                min_l = l;
                min_size = r - l + 1;
            }
            if (flag[s[l]] && ++need[s[l]] > 0) {
                --cnt;
            }
            ++l;
        }
    }

    return min_size > s.size() ? "" : s.substr(min_l, min_size);
}

int main() {
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << "reslut is : " << min_windows(s, t) << endl;
    }

    return 0;
}
