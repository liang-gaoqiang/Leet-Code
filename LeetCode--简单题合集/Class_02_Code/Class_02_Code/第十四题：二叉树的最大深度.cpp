#include <bits/stdc++.h>
using namespace std;


//����������ڵ�
typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

//��ȵ��ڸ��ڵ㵽��������������ȼ�1

int maxDepth(TreeNode* root) {
	int max_depth = 0;
	if (root == nullptr) return 0;
	// �ݹ��������������������������
	int left_Depth = maxDepth(root->left);
	int right_Depth = maxDepth(root->right);
	// �������������������нϴ����ȼ�1
	return max(left_Depth, right_Depth) + 1;
}

//int main() {
//	// ����������
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//
//	// �����������������
//	int depth = maxDepth(root);
//
//	// ������
//	std::cout << "��������������Ϊ��" << depth << std::endl;
//	return 0;
//}
