/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.04%)
 * Total Accepted:    222.2K
 * Total Submissions: 528.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

using std::vector;

struct TreeNode;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ret;
        vector<TreeNode *> row{root};
        vector<TreeNode *> new_row;
        vector<int> res;
        while (row.size())
        {
            for (auto p : row)
            {
                res.push_back(p->val);
                if (p->left)
                {
                    new_row.push_back(p->left);
                }
                if (p->right)
                {
                    new_row.push_back(p->right);
                }
            }
            row.clear();
            row.swap(new_row);
            ret.push_back(res);
            res.clear();
        }
        return ret;
    }
};
