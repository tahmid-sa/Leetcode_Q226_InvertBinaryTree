#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void invertTreeHelper(TreeNode* node) {
    if (node != nullptr) {
        invertTreeHelper(node->left);

        TreeNode* leftNode = node->left;
        node->left = node->right;
        node->right = leftNode;

        invertTreeHelper(node->left);
    }
}

TreeNode* invertTree(TreeNode* root) {
    invertTreeHelper(root);

    return root;
}

int main()
{
    TreeNode n1(1, nullptr, nullptr);
    TreeNode n3(3, nullptr, nullptr);
    TreeNode n6(6, nullptr, nullptr);
    TreeNode n9(9, nullptr, nullptr);

    TreeNode n2(2, &n1, &n3);
    TreeNode n7(7, &n6, &n9);

    TreeNode n4(4, &n2, &n7);

    return 0;
}