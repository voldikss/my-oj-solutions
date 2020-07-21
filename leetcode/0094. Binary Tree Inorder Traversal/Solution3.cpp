#include "../../vital/binary_tree.cpp"
#include "../../vital/vector.cpp"
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;

        stack<pair<bool, TreeNode *>> st;
        st.push(make_pair(false, root));
        while (!st.empty()) {
            bool visited = st.top().first;
            TreeNode *node = st.top().second;
            st.pop();
            if (!node)
                continue;
            else if (!visited) {
                st.push(make_pair(false, node->right));
                st.push(make_pair(true, node));
                st.push(make_pair(false, node->left));
            } else
                res.push_back(node->val);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> tree_nodes = {1, nullptr, 2, 3};
    TreeNode *tree = build_binary_tree(tree_nodes);
    // print_ascii_tree(tree);
    cout << s.inorderTraversal(tree) << endl;
}