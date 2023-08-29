#include <bits/stdc++.h>
using namespace std;

//���嵥����ṹ
typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode() :val(0), next(nullptr){}
	ListNode(int x) :val(x), next(nullptr){}
	ListNode(int x, ListNode *next):val(x),next(next){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	ListNode dummy(0);
	ListNode* tail = &dummy;

	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val <= l2->val) {
			tail->next = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1 != nullptr)
		tail->next = l1;
	else if (l2 != nullptr)
		tail->next = l2;

	return dummy.next;
}

// ���ڴ�ӡ����ĺ���
void printList(ListNode* head) {
	ListNode* curr = head;
	while (curr != nullptr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}


//int main() {
//	// ������һ����������: 1 -> 2 -> 4
//	ListNode* l1 = new ListNode(1);
//	l1->next = new ListNode(2);
//	l1->next->next = new ListNode(4);
//
//	// �����ڶ�����������: 1 -> 3 -> 4
//	ListNode* l2 = new ListNode(1);
//	l2->next = new ListNode(3);
//	l2->next->next = new ListNode(4);
//
//	// �ϲ�������������
//	ListNode* mergedList = mergeTwoLists(l1, l2);
//
//	// ��ӡ�ϲ��������
//	printList(mergedList);
//
//	// �ͷ��ڴ�
//	delete l1;
//	delete l2;
//	delete mergedList;
//
//	return 0;
//}