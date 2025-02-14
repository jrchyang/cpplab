#include <iostream>
#include <string>

using namespace std;

// leetcode 680
bool valid_palindrome(string s) {
    auto check = [&](int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    };

    int size = s.size();
    int l = 0, r = size - 1;
    while (l <= r) {
        if (s[l] != s[r]) {
            return check(l, r - 1) || check(l + 1, r);
        }
        ++l;
        --r;
    }

    return true;
}

int main() {
    {
        string s = "aba";
        cout << "result is " << (valid_palindrome(s) ? "true" : "false") << endl;
    }
    {
        string s = "abca";
        cout << "result is " << (valid_palindrome(s) ? "true" : "false") << endl;
    }
    {
        string s = "abc";
        cout << "result is " << (valid_palindrome(s) ? "true" : "false") << endl;
    }
    {
        string s = "a";
        cout << "result is " << (valid_palindrome(s) ? "true" : "false") << endl;
    }

    return 0;
}
