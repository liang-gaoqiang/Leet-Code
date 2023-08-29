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
//	int Max;  // ����1������ȫ�ֱ������洢���ֱ��
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
//		����˼�룺����Ҷ�ӽڵ�֮���·�� = ���ڵ����Ҷ��ӵ����֮��
//		��ȵ��ڸ��ڵ㵽��������������ȼ�1
//		*/
//		depth(root);
//		return Max;
//	}
//};


class Solution {
	////��������maxDiameter�������͵ı���
	int depth(TreeNode* root, int& maxDiameter) { 
	if (root == nullptr) {
		return 0;
	}

	int leftDepth = depth(root->left, maxDiameter);
	int rightDepth = depth(root->right, maxDiameter);
	int diameter = leftDepth + rightDepth;
	// ����·�����ܾ���Ҳ���ܲ��������ڵ� root,��������һ�д�����ǽ���������ģ�
	maxDiameter = max(maxDiameter, diameter);
	//�������ҽڵ����������ֵ���Ǹ�
	return max(leftDepth, rightDepth) + 1;

	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		/*
		����˼�룺����Ҷ�ӽڵ�֮���·�� = ���ڵ����Ҷ��ӵ����֮��
		��ȵ��ڸ��ڵ㵽��������������ȼ�1
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
