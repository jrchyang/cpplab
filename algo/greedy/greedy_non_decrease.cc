#include <iostream>
#include <vector>

using namespace std;

bool check_non_decrease(vector<int>& nums) {
    int cnt = 0;
    int length = nums.size();

    for (int i = 0; i < length - 1; ++i) {
        int x = nums[i];
        int y = nums[i+1];

        if (x > y) {
            ++cnt;
            if (cnt > 1) {
                return false;
            }

            if (i != 0 && y < nums[i-1]) {
                nums[i+1] = x;
            }
        }
    }

    return true;
}

int main() {
    {
        vector<int> nums = {4,2,3};
        cout << (check_non_decrease(nums) ? "true" : "false") << endl;
    }
    {
        vector<int> nums = {4,2,1};
        cout << (check_non_decrease(nums) ? "true" : "false") << endl;
    }

    return 0;
}
