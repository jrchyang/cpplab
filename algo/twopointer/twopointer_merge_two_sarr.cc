#include <iostream>
#include <vector>

using namespace std;

// leetcode 88
void merge_two_sorted_array(vector<int>& num1, int m, vector<int>& num2, int n) {
    int tail = m-- + n-- - 1;

    while (m >= 0 && n >= 0) {
        num1[tail--] = num1[m] > num2[n] ? num1[m--] : num2[n--];
    }

    while (n >= 0) {
        num1[tail--] = num2[n--];
    }
}

void print_vector(const vector<int>& vec) {
    for (const int& item: vec) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    {
        vector<int> num1 = {1,2,3,0,0,0};
        vector<int> num2 = {2,5,6};
        int m = 3;
        int n = 3;
        merge_two_sorted_array(num1, m, num2, n);
        print_vector(num1);
    }

    return 0;
}
