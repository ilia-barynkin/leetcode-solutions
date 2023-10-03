#include <iostream>
#include <vector>
#include <cassert>

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Define the levelOrder function
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

// Define the test function
void test_levelOrder() {
    // Create test cases
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    
    TreeNode* root2 = new TreeNode(1);

    // Perform the test and assert the results
    std::vector<std::vector<int>> result1 = levelOrder(root1);
    assert(result1 == std::vector<std::vector<int>>{{1}, {2, 3}, {4, 5, 6, 7}});
    
    std::vector<std::vector<int>> result2 = levelOrder(root2);
    assert(result2 == std::vector<std::vector<int>>{{1}});

    // Clean up memory
    delete root1->left->right;
    delete root1->left->left;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2;
    
    std::cout << "All tests passed!" << std::endl;
}

// Run the tests
int main() {
    test_levelOrder();
    return 0;
}