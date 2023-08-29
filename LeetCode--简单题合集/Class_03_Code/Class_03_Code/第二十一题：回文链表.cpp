#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(0), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {

public:
	// ����ջ�������������
	bool isPalindrome(ListNode* head) {
		// ��һ��������һ��ջ�������洢�����еĽڵ�
		stack<int> stk;

		// �ڶ������������е�����Ԫ�ؾ���ջ
		ListNode* cur = head;
		while (cur) {
			stk.push(cur->val);
			cur = cur->next;
		}

		// �������� ��ջ�����Һ�����Ԫ�رȽ�
		cur = head;
		while (cur) {
			int topVal = stk.top();
			stk.pop();
			if (cur->val != topVal) {
				return false;
			}
			cur = cur->next;
		}
		return true;
	}



};

//int main() {
//	Solution s;
//	// Case one: is Palindrome        1 -> 2 -> 3 -> 2 -> 1
//	ListNode* head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(2);
//	head->next->next->next->next = new ListNode(1);
//	bool result1 = s.isPalindrome(head);
//	if (result1) {
//		cout << "The linked list is a palindrome." << endl;
//	}
//	else {
//		cout << "The linked list is not a palindrome." << endl;
//	}
//	// Case one: not is Palindrome       1 -> 2 -> 3 -> 4 -> 5
//	ListNode* head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//
//	bool result = s.isPalindrome(head);
//	if (result) {
//		
//		cout << "The linked list is a palindrome." << endl;
//	}
//	else {
//		cout << "The linked list is not a palindrome." << endl;
//	}
//	return 0;
//}