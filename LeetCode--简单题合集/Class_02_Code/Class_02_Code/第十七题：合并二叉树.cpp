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
	//�ϲ�����������
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		//�������µĶ�������ֱ����ԭ��tree1��������޸�
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		//�������������߼�˳��
		root1->val += root2->val;	// ��
		//�ݹ鴦��root1��root2
		root1->left = mergeTrees(root1->left, root2->left);	// ��
		root1->right = mergeTrees(root1->right, root2->right); // ��
		return root1;
	}

	//ǰ�����������
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

		cout << root->val << " "; // �����ǰ�ڵ��ֵ
		preOrderTraversal(root->left); // ����������
		preOrderTraversal(root->right); // ����������
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