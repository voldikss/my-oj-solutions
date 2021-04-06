#include "../../include/global.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int slow = 1;
        int fast = 2;
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow - 1])
                nums[++slow] = nums[fast];
        }
        cout << nums << endl;
        return slow + 1;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> nums = {1, 2, 3};
    // vector<int> nums = {};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
