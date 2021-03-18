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
#include <variant>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;
        int maxpos = 0;
        for (int i = 0; i < len; i++) {
            if (i > maxpos) return false;
            maxpos = max(maxpos, i + nums[i]);
        }
        return maxpos >= len - 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto nums = vector<int>{2, 3, 1, 1, 4};
    auto res = s.canJump(nums);
    cout << res << endl;
    return 0;
}