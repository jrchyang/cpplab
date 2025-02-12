#include <iostream>
#include <vector>

using namespace std;

// leetcode 167
vector<int> two_sum(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int sum = 0;
    vector<int> res;

    while (start < end) {
        sum = nums[start] + nums[end];
        if (sum < target) {
            ++start;
        } else if (sum > target) {
            --end;
        } else {
            res.push_back(start + 1);
            res.push_back(end + 1);
            break;
        }
    }

    return res;
}

int main() {
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> res = two_sum(nums, target);
        cout << "indexs is [" << res[0] << "," << res[1] << "]" << endl;
    }

    return 0;
}
