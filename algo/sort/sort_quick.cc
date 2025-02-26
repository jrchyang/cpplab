#include <iostream>
#include <vector>
#include "show_result.h"

using namespace std;

#if 0
void quick_sort(vector<int>& nums, int l, int r) {
    if (l + 1 >= r) {
        return;
    }

    int first = l, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}
#else
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) {
        return;
    }

    int first = l, last = r, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }

    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}
#endif

int main() {
    {
        vector<int> nums = {1,9,2,8,3,7,4,6,5};
        quick_sort(nums, 0, nums.size()-1);
        VectorPrinter<vector<int>>::print(nums);
    }
    {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        quick_sort(nums, 0, nums.size()-1);
        VectorPrinter<vector<int>>::print(nums);
    }

    return 0;
}
