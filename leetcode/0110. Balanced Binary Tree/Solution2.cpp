#include "../../include/binary_tree.hpp"
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
    bool isBalanced(TreeNode *root) {
        return this->depth(root) > -1;
    }

    int depth(TreeNode *node) {
        if (!node) return 0;
        int left = this->depth(node->left);
        int right = this->depth(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};

int main() {

    return 0;
}
