#include <bits/stdc++.h>
using namespace std;


//定义二叉树节点
typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

//深度等于根节点到其最深子树的深度加1

int maxDepth(TreeNode* root) {
	int max_depth = 0;
	if (root == nullptr) return 0;
	// 递归计算左子树和右子树的最大深度
	int left_Depth = maxDepth(root->left);
	int right_Depth = maxDepth(root->right);
	// 返回左子树和右子树中较大的深度加1
	return max(left_Depth, right_Depth) + 1;
}

//int main() {
//	// 创建二叉树
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//
//	// 计算二叉树的最大深度
//	int depth = maxDepth(root);
//
//	// 输出结果
//	std::cout << "二叉树的最大深度为：" << depth << std::endl;
//	return 0;
//}
