#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

        TreeNode* buildBST(const vector<int>& nums, int val) {
            // Build the initial tree.
            TreeNode* root = nullptr;
            for (int val: nums){
                root = insertIntoBST(root, val);
            }

            // Add the value.
            root = insertIntoBST(root, val);

            // Print the level order traversal of the BST for debug.
            levelOrder(root);
            cout << endl;

            return root;
        }

        void levelOrder(TreeNode* root) {
            // If reach branch end, return.
            if (!root) {
                cout << " null ";
                return;
            }

            // FIFO order
            queue<TreeNode*> q;
            q.push(root);

            // Breaking apart tree top level down.
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur) {
                    cout << cur->val << " ";
                    q.push(cur->left);   // push even if null
                    q.push(cur->right);  // push even if null
                } else {
                    cout << " null ";
                }

            }
        }
};

int main() {
    Solution sol;

    // test 1
    vector<int> tree_cfg = {4,2,7,1,3};
    sol.buildBST(tree_cfg, 5);

    // test 2
    tree_cfg = {40,20,60,10,30,50,70};
    sol.buildBST(tree_cfg, 25);

    // test 3
    tree_cfg = {4,2,7,1,3};
    sol.buildBST(tree_cfg, 5);

    return 0;
}