#include <cstdlib>
#include <vector>

struct node {
   int val;
   node *left;
   node *right;
   node(int x) : val(x), left(NULL), right(NULL) {}
   node(int x) : val(x), left(nullptr), right(nullptr) {}
   node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    node* lowestCommonAncestor(node* root, node* p, node* q) {
      if (root == NULL) return NULL;
      if (root == p || root == q) return root;
      node* left = lowestCommonAncestor(root->left, p, q);
      node* right = lowestCommonAncestor(root->right, p, q);
      if (left != NULL && right != NULL) return root;
      if (left == NULL && right == NULL) return NULL;
      return left != NULL ? left : right;
    }

    std::vector<std::vector<int>> levelOrder(node* root) {
        
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  node* root = {2,4,6,8,10,12,14};
  node* p = 6;
  node* q = 14;
  node* ans = s.lowestCommonAncestor(root, p, q);
  cout << ans->val << endl;
  return 0;
}