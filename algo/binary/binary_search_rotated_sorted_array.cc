#include <iostream>
#include <vector>

using namespace std;

int find_k(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return -1;
    } else if (size == 1) {
        return 0;
    }

    int l = 0, r = size - 1;
    while (l < r) {
        if (nums[l] < nums[r]) {
            if (r < size - 1) {
                return r + 1;
            } else {
                return l;
            }
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

    return l;
}

bool binary_search(vector<int>& nums, int target, int left, int right) {
    int l = left;
    int r = right;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return false;
}

// leetcode 81
#if 0
bool search(vector<int>& nums, int target) {
    int k = find_k(nums);
    cout << "(k is : " << k << ") ";
    if (k == 0) {
        return binary_search(nums, target, 0, nums.size() - 1);
    } else {
        if (nums[0] <= target && target <= nums[k-1]) {
            return binary_search(nums, target, 0, k-1);
        } else if (nums[k] <= target && nums[nums.size()-1]) {
            return binary_search(nums, target, k, nums.size()-1);
        } else {
            return false;
        }
    }
}
#else
bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[l] == nums[mid]) {
            ++l;
        } else if (nums[mid] <= nums[r]) {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    return false;
}
#endif

int main() {
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int target = 0;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {2,5,6,6,0,1,2};
        int target = 3;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {3};
        int target = 3;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {3,3,3,3,3,3,3,3};
        int target = 3;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {3,3,3,3,3,3,3,3};
        int target = 1;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
        int target = 2;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {0,0,1,1,2,0};
        int target = 2;
        cout << "result is : " << (search(nums, target) ? "true" : "false") << endl;
    }

    return 0;
}
