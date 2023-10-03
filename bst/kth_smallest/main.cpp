#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum TraverseOrder {
    PreOrder,
    InOrder,
    PostOrder
};

typedef bool (*pred)(TreeNode* node);


void depthFirstTraversal(TreeNode* node, pred fn, TraverseOrder order) {
    for (auto offset = 0; offset <= 2; ++offset) {
        auto shift = (order + offset) % (TraverseOrder::PostOrder + 1);
        auto curr_node = node + shift * sizeof(size_t) + (shift != 0) * sizeof(int);
        
        if (fn(curr_node))
            return;
        else
            depthFirstTraversal(curr_node, fn, order);
    }
}

TreeNode* getNode(int val, TreeNode* root = NULL) {
    if (!root)
        return root = new TreeNode(val);

    if (root->val == val) 
        return root;
    
    if (val < root->val)
        return getNode(val, root->left);
    else // if (node->val < val)
        return getNode(val, root->right);
}

int minBst(TreeNode* root) {
    return (root->left ? minBst(root->left) : root->val);
}

class Solution {
public:
    #define NULL_NODE std::numeric_limits<int>::max();
    
    int kthSmallest(TreeNode* root, int k, int &count) {
        if (!root) {
            return NULL_NODE;
        }

        auto result = kthSmallest(root->left, k, count);

        if (result != NULL_NODE) {
            return result;
        }
        
        ++count;

        if (count == k) {
            return root->val;
        }

        if (count == k) 
            return result;
    }
};

int main(int argc, char* argv[]) {
    auto root = getNode(0);
    
    auto rl = getNode(-2, root);
    auto rll = getNode(-3, root);
    auto rlr = getNode(-1, root);
    auto rr = getNode(2, root);
    auto rrl = getNode(1, root);
    auto rrr = getNode(3, root);

    depthFirstTraversal(root, [](TreeNode* node) { std::cout << node->val << std::endl; });

    return 0;
}