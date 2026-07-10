#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal
struct TreeNode {
    int val;
    // Each Treenode is a branch
    TreeNode *left;
    TreeNode *right;

    // No input.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // A single input. Adds node with no children to BST.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Full constructor. 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        TreeNode* insertIntoBST(TreeNode * root, int val){
            // If reach empty space, add the tree node.
            if (!root) return new TreeNode(val);

            // Left go left. Right go right.
            if (val < root->val){
                root->left = insertIntoBST(root->left, val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }

            return root;
        }

        TreeNode* buildBST(const vector<int>& nums) {
            // Build the initial tree.
            TreeNode* root = nullptr;
            for (int val: nums){
                root = insertIntoBST(root, val);
            }

            // Print the level order traversal of the BST for debug.
            vector<int> vals = this->inorderTransveral(root);

            return root;
        }

        // Follow the left branch down first.
        void inorder(TreeNode* root, vector<int>& out){
                if (!root) return;
                inorder(root->left,out);
                out.push_back(root->val);
                inorder(root->right,out);
            }

        vector<int> inorderTransveral(TreeNode* root){
            vector<int> order_tree {};
            this->inorder(root, order_tree);

            for (auto val:order_tree){
                cout << val << " ";
            }        
            cout << endl;
            
            return order_tree;
        }
        
};

int main() {
    Solution sol;

    // test 1
    vector<int> tree_cfg = {1,2,3,5,1,6,1,4,2,10,50,30};
    sol.buildBST(tree_cfg);

    return 0;
}