#include <iostream>
#include <vector>

using namespace std;

// leetcode 540
int find_single_non_dup(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int res = mid % 2;
        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        } else if (nums[mid] == nums[mid-1]) {
            res == 0 ? r = mid - 2 : l = mid + 1;
        } else {
            res == 0 ? l = mid + 2 : r = mid - 1;
        }
    }

    return nums[l];
}

int main() {
    {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        cout << "result is : " << find_single_non_dup(nums) << endl;
    }
    {
        vector<int> nums = {3,3,7,7,10,11,11};
        cout << "result is : " << find_single_non_dup(nums) << endl;
    }
    {
        vector<int> nums = {1};
        cout << "result is : " << find_single_non_dup(nums) << endl;
    }
    {
        vector<int> nums = {1,3,3};
        cout << "result is : " << find_single_non_dup(nums) << endl;
    }
    {
        vector<int> nums = {3,3,4};
        cout << "result is : " << find_single_non_dup(nums) << endl;
    }
}
