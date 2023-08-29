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
	TreeNode* invertTree(TreeNode* root) {
		//��һ����ȷ��ֹ����
		if (root == nullptr) return root;
		//ȷ�������߼��������ڵ�����Ӻ��Һ���---->swap(root->left,root->right)ǰ��������С�����
		//C++���ú���swap
		swap(root->left, root->right);
		invertTree(root->right);
		invertTree(root->left);
		return root;
	}

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
};

//int main() {
//	Solution s;
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->left->left = new TreeNode(6);
//	root->left->right->right = new TreeNode(3);
//	s.invertTree(root);
//	vector<int> result = s.preTraversal(root);
//	for (int res : result) {
//		cout << res << " ";
//	}
//	cout << endl;
//	return 0;
//}