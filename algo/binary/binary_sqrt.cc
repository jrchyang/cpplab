#include <iostream>

using namespace std;

// leetcode 69
int my_sqrt(int x) {
    if (x == 0) {
        return x;
    }

    int l = 1, r = x, mid = 0, sqrt = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        sqrt = x / mid;
        if (sqrt == mid) {
            return mid;
        } else if (sqrt > mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return r;
}

int main() {
    cout << "result is : " << my_sqrt(4) << endl;
    cout << "result is : " << my_sqrt(8) << endl;
    return 0;
}
