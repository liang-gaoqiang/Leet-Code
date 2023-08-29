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


class Solution {

public:
	//合并两个二叉树
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		//不定义新的二叉树，直接在原来tree1上面进行修改
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		//遍历二叉树的逻辑顺序
		root1->val += root2->val;	// 中
		//递归处理root1和root2
		root1->left = mergeTrees(root1->left, root2->left);	// 左
		root1->right = mergeTrees(root1->right, root2->right); // 右
		return root1;
	}

	//前序遍历二叉树
	void preHelper(TreeNode* node, vector<int>& result) {
		if (node) {
			result.push_back(node->val);
			preHelper(node->left, result);
			preHelper(node->right, result);
		}
	}


	vector<int> preTraversal(TreeNode* root) {
		vector<int> result;
		preHelper(root, result);
		return result;
	}

	void preOrderTraversal(TreeNode* root) {
		if (root == nullptr) return;

		cout << root->val << " "; // 输出当前节点的值
		preOrderTraversal(root->left); // 遍历左子树
		preOrderTraversal(root->right); // 遍历右子树
	}

};

//int main() {
//	Solution s;
//	TreeNode* root1 = new TreeNode(1);
//	TreeNode* root2 = new TreeNode(2);
//	root1->left = new TreeNode(3);
//	root1->right = new TreeNode(2);
//	root1->left->left = new TreeNode(5);
//
//	root2->left = new TreeNode(1);
//	root2->right = new TreeNode(3);
//	root2->right->right = new TreeNode(4);
//	root2->right->right = new TreeNode(7);
//	TreeNode* mergedRoot = s.mergeTrees(root1, root2);
//
//	vector<int> result = s.preTraversal(mergedRoot);
//	for (int res : result) {
//		cout << res << " ";
//	}
//	cout << endl;
//
//	return 0;
//}