#include <iostream>
#include <vector>

using namespace std;

// leetcode 4
#if 0
int median_two_sorted_arrays(vector<int>& nums1, vector<int>& nums2) {
    int size_1 = nums1.size();
    int size_2 = nums2.size();
    int total = size_1 + size_2;
    int index = total % 2 == 0 ? total / 2 - 1 : total / 2;

    while (1) {
        int mid_1 = size_1 / 2;
        int mid_2 = size_2 / 2;
        if (nums1[mid_1] < nums2[mid_2]) {

        }
    }
}
#else
int two_pointer(vector<int>& nums1, vector<int>& nums2) {
}
#endif
