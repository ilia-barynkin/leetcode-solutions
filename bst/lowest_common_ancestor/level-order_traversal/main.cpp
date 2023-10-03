#include <vector>
#include <cassert>

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode() {
        if (left) 
            delete left;
        if (right)
            delete right;
    }
};

TreeNode* insert(TreeNode** root, int val) {
    if (!(*root))
        return (*root) = new TreeNode(val);

    if (!(*root)->left) 
        return insert(&(*root)->left, val);
    if (!(*root)->right)
        return insert(&(*root)->right, val);

    assert(false);
}

// TreeNode* initBinaryTree(std::vector<int> init_vals) : vals(init_vals.size()) {
//     for (int i = 0; i < init_vals.size(); ++i) {
//         vals[2 * i + 1] = init_vals[i];
//     }
// }
 
class Solution {
public:
std::vector<std::vector<int>> levelOrder(TreeNode* root, int level = 0) {
    static std::vector<std::vector<int>> result;
    if (level == 0) result.clear();
    
    if (root) {
        if (result.size() == level) result.push_back(std::vector<int>());
        
        result[level].push_back(root->val);

        if (root->left)
            levelOrder(root->left, level + 1);

        if (root->right)
            levelOrder(root->right, level + 1);
    }

    return result;
}
};

int main(int argc, char* argv[]) {

    Solution sol;

    // tests

    // Input: root = [3,9,20,null,null,15,7]
    // Output: [[3],[9,20],[15,7]]
    TreeNode* root;
    root = insert(&root, 3);
    auto rl = insert(&root, 9);
    auto rr = insert(&root, 20);
    auto rrl = insert(&rr, 15);
    auto rrr = insert(&rr, 7);

    auto res = sol.levelOrder(root);

    delete root;

    // Input: root = [1]
    // Output: [[1]]

    root = insert(&root, 1);

    res = sol.levelOrder(root);

    return 0;
}