#include <iostream>
#include <math.h>

using namespace std;

// leetcode 633
bool judge_square(int c) {
    int l = 0;
    int r = sqrt(c);
    int res = 0, a = 0, b = 0;

    while (l <= r) {
        a = l * l;
        b = r * r;
        res = c - b;

        if (res < a) {
            --r;
        } else if (res > a) {
            ++l;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    int c = 5;
    cout << c << " result is " << (judge_square(c) ? "true" : "false") << endl;

    return 0;
}
