#include <iostream>
#include <vector>

using namespace std;

// leetcode 154
int find_min_in_rotated_sorted_array(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        if (nums[l] < nums[r]) {
            break;
        }
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[r]) {
            r = mid;
        } else if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            --r;
        }
    }

    return nums[l];
}

int main() {
    {
        vector<int> nums = {1,3,5};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {2,2,2,0,1};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {2,5,6,6,0,1,2};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {3};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {3,3,3,3,3,3,3,3};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }
    {
        vector<int> nums = {0,0,1,1,2,0};
        cout << "result is : " << find_min_in_rotated_sorted_array(nums) << endl;
    }

    return 0;
}
