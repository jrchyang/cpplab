#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int>& nums, int target, bool first) {
    int index = -1;
    int l = 0;
    int r = nums.size() - 1;
    int mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            index = mid;
            first ? r = mid - 1 : l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return index;
}

// leetcode 34
vector<int> search_range(vector<int>& nums, int target) {
    return vector<int>{find_index(nums, target, true), find_index(nums, target, false)};
}

int main() {
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        vector<int> res = search_range(nums, target);
        cout << "index is : [" << res[0] << "," << res[1] << "]" << endl;
    }
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 6;
        vector<int> res = search_range(nums, target);
        cout << "index is : [" << res[0] << "," << res[1] << "]" << endl;
    }

    return 0;
}
