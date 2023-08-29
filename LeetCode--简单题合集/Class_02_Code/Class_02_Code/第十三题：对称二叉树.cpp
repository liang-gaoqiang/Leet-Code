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
	//�������������������Ϊ�գ�˵��ֻ��һ�����ڵ�ֱ�ӷ���True
	if (!left && !right) return true;
	//���������������������һ��Ϊ�ջ������������е�ֵ������򷵻�false
	if (!left || !right || left->val != right->val) return false;
	//���������������ڵ�����������ҽڵ��Ƿ���ȣ�������������ҽڵ������������ڵ��Ƿ����
	return check(left->left, right->right) && check(left->right, right->left);
}

//�ж϶������Ƿ�����Գƶ�����
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