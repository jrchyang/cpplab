#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// leetcode 340
string longest_word(string s, vector<string>& dictionary) {
    auto check = [&](string s, string t) {
        int i = 0, j = 0;
        while ((i < s.size()) && (j < t.size())) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        if (j == t.size()) {
            return true;
        } else {
            return false;
        }
    };

    string res;
    res.clear();
    int size = dictionary.size();
    for (int i = 0; i < size; ++i) {
        auto r = check(s, dictionary[i]);
        if (r == true) {
            if (res.empty()) {
                res = dictionary[i];
            } else {
                if (res.size() < dictionary[i].size()
                    || (res.size() == dictionary[i].size()
                        && res > dictionary[i])) {
                    res = dictionary[i];
                }
            }
        }
    }

    return res;
}

int main() {
    {
        string s = "abpcplea";
        vector<string> dictionary = {"ale","apple","monkey","plea"};
        cout << "result is : " << longest_word(s, dictionary) << endl;
    }
    {
        string s = "abpcplea";
        vector<string> dictionary = {"a","b","c"};
        cout << "result is : " << longest_word(s, dictionary) << endl;
    }

    return 0;
}
