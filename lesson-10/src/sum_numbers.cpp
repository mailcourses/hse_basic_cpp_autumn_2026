/*


        1
      /   \
     2     3
          / \
         1   5

12 + 135 + 131 = 278
*/

#include <queue>
#include <string>
#include <cassert>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* right{nullptr};
    TreeNode* left{nullptr};
    TreeNode(int val): val(val) {}
};

void helper(TreeNode* root, int cur_val, int& total) {
    if (!root){
        return;
    }

    int new_val = cur_val * 10 + root->val;

    if (!root->right && !root->left) {
        total += new_val;
        return;
    }

    if (root->right){
        helper(root->right, new_val, total);
    }

    if (root->left){
        helper(root->left, new_val, total);
    }
}

int sumNumbersRecursive(TreeNode* root) {
    int total{0};
    helper(root, 0, total);
    return total;
}

int sumNumbers(TreeNode* root) {
    if (!root){
        return 0;
    }

    if (!root->right && !root->left){
        return root->val;
    }

    int cur_sum = 0;
    std::queue<std::pair<TreeNode*, int>> visited;

    visited.push(std::make_pair(root, 0));

    while (!visited.empty()){
        auto [node, num] = visited.front();
        visited.pop();

        int cur_val = num * 10 + node->val;
        if (!node->left && !node->right){
            cur_sum += cur_val;
            continue;
        }

        if (node->left){
            visited.push(std::make_pair(node->left, cur_val));
        }

        if (node->right){
            visited.push(std::make_pair(node->right, cur_val));
        }
    }
    return cur_sum;
}

TreeNode* buildTree()
{
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->right->left = new TreeNode{1};
    root->right->right = new TreeNode{5};
    return root;
}

int main()
{
    {
        TreeNode* root = buildTree();
        assert(sumNumbers(root) == 278);
        assert(sumNumbersRecursive(root) == 278);
    }
    {
        assert(sumNumbers(new TreeNode{5}) == 5);
        assert(sumNumbersRecursive(new TreeNode{5}) == 5);
        assert(sumNumbers(nullptr) == 0);
        assert(sumNumbersRecursive(nullptr) == 0);
    }
}
