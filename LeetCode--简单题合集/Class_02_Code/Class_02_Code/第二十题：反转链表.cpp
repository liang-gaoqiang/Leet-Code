#include <bits/stdc++.h>
using namespace std;


typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {

public:
	//��ת����:˫ָ�뷨
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = head;

		while (cur) {
			ListNode* temp;
			temp = cur->next;	//��ǰ����cur����һ���ڵ�λ��
			cur->next = pre;	//����ı䷽��Ĳ���
			pre = cur;			//�ƶ�pre��cur��λ���ƶ�һλ(������һλ)
			cur = temp;			
		}
		return pre;
	}

	//��ת�����ݹ鷨
	ListNode* reverseList2(ListNode* head) {
		return reverse(head, NULL);
	}

	ListNode* reverse(ListNode* cur, ListNode* pre) {
		if (cur == NULL) return pre;

		ListNode* temp = cur->next;
		cur->next = pre;
		return reverse(temp, cur);
	}

	//��ӡ����
	void display(ListNode* head) {
		ListNode* current = head;

		while (current != nullptr) {
			std::cout << current->val << " ";
			current = current->next;
		}

		std::cout << std::endl;
	}

};

int main() {
	Solution s;
	// Create a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = NULL;
	// Reverse the linked list
	ListNode* reversedList = s.reverseList2(head);
	// Print the reversed linked list
	s.display(reversedList);
	return 0;
}