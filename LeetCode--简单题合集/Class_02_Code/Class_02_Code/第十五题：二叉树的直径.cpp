#include <bits/stdc++.h>
using namespace std;


typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//class Solution {
//	int Max;  // 方法1：定义全局变量来存储最大直径
//	int depth(TreeNode* root) {
//		if (root == nullptr) return 0;
//		int L, R;
//		L = depth(root->left);
//		R = depth(root->right);
//
//		if (L + R > Max) {
//			Max = L + R;
//		}
//
//		return max(L, R) + 1;
//	}
//public:
//	int diameterOfBinaryTree(TreeNode* root) {
//		/*
//		解题思想：两个叶子节点之间的路径 = 根节点左右儿子的深度之和
//		深度等于根节点到其最深子树的深度加1
//		*/
//		depth(root);
//		return Max;
//	}
//};


class Solution {
	////方法二：maxDiameter引用类型的变量
	int depth(TreeNode* root, int& maxDiameter) { 
	if (root == nullptr) {
		return 0;
	}

	int leftDepth = depth(root->left, maxDiameter);
	int rightDepth = depth(root->right, maxDiameter);
	int diameter = leftDepth + rightDepth;
	// 这条路径可能经过也可能不经过根节点 root,所以下面一行代码就是解决这个问题的！
	maxDiameter = max(maxDiameter, diameter);
	//返回左右节点的深度中最大值的那个
	return max(leftDepth, rightDepth) + 1;

	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		/*
		解题思想：两个叶子节点之间的路径 = 根节点左右儿子的深度之和
		深度等于根节点到其最深子树的深度加1
		*/
		int Max = 0;
		depth(root, Max);
		return Max;
	}
};



//
//int main() {
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->left->left = new TreeNode(6);
//	root->left->right->right = new TreeNode(3);
//	Solution s;
//	int result = s.diameterOfBinaryTree(root);
//	cout << result << endl;
//
//	return 0;
//}
//
