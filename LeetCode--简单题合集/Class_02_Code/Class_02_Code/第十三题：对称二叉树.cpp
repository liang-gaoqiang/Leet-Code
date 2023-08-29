#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(nullptr), right(nullptr) {}
};

bool check(TreeNode* left, TreeNode* right) {
	//如果左子树和右子树都为空，说明只有一个根节点直接返回True
	if (!left && !right) return true;
	//如果左子树或者右子树有一个为空或者左右子树中的值不相等则返回false
	if (!left || !right || left->val != right->val) return false;
	//最后检查左子树的左节点和右子树的右节点是否相等；检查左子树的右节点和右子树的左节点是否相等
	return check(left->left, right->right) && check(left->right, right->left);
}

//判断二叉树是否是轴对称二叉树
bool isSymmetric(TreeNode* root) {
	
	return check(root->left, root->right);
}


//int main() {
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(2);
//	cout << isSymmetric(root);
//	return 0;
//}