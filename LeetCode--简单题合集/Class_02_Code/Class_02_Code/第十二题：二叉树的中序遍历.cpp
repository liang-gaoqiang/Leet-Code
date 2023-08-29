#include <bits/stdc++.h>
using namespace std;


typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};


void inorderHelper(TreeNode* node, vector<int>& result) {
	if (node) {
		inorderHelper(node->left, result);
		result.push_back(node->val);
		inorderHelper(node->right, result);
	}
}


vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	inorderHelper(root, result);
	return result;
}


//int main() {
//	//C++中存在new关键字，而python中没有！
//	TreeNode* root = new TreeNode(1);
//	root->right = new TreeNode(0);
//	root->right = new TreeNode(2);
//	root->right->left = new TreeNode(3);
//	//获取中序遍历结果
//	vector<int> result = inorderTraversal(root);
//	for (int num : result) {
//		cout << num << " ";
//	}
//	cout << endl;
//	return 0;
//}