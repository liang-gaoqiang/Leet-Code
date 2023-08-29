#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {

public:
	//相交链表：双指针法
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		/*
		1、首先，分别遍历两个链表，获取它们的长度
		2、然后，让较长的链表的指针先移动到与较短链表对齐的位置。
		3、之后，同时移动两个指针，直到它们相遇或者到达链表的末尾。
		4、如果两个指针都到达链表的末尾，表示两个链表不相交。
		5、否则两个指针相遇，则表示两个链表相交，相遇的节点即为它们的相交节点；
		*/
		if (headA == NULL || headB == NULL) {
			return NULL;
		}
		//1、首先，分别遍历两个链表，获取它们的长度
		int lenA = getLength(headA);
		int lenB = getLength(headB);

		ListNode* ptrA = headA;
		ListNode* ptrB = headB;
		//2、让较长的链表的指针先移动到与较短链表对齐的位置
		if (lenA > lenB) {
			int diff = lenA - lenB;
			while (diff > 0) {
				ptrA = ptrA->next;
				diff--;
			}
		}
		else if (lenB > lenA) {
			int diff = lenB - lenA;
			while (diff > 0) {
				ptrB = ptrB->next;
				diff--;
			}
		}

		//3、之后，同时移动两个指针，直到它们相遇或者到达链表的末尾。
		while (ptrA != ptrB) {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
			if (ptrA == NULL && ptrB == NULL) {
				return NULL; //5、如果两个指针都到达链表的末尾，表示两个链表不相交。
			}
		}
		return ptrA; // 4、否则说明两个指针相遇，则表示两个链表相交，相遇的节点即为它们的相交节点；
	}

	//求链表的长度
	int getLength(ListNode* head) {
		int length = 0;
		ListNode* curr = head;

		while (curr != NULL) {
			length++;
			curr = curr->next;
		}

		return length;
	}
};

//int main() {
//	Solution s;
//	// Test Case 1: 不相交
//	ListNode* headA1 = new ListNode(1);
//	headA1->next = new ListNode(2);
//	headA1->next->next = new ListNode(3);
//	headA1->next->next->next = new ListNode(4);
//	headA1->next->next->next->next = NULL;
//
//	ListNode* headB1 = new ListNode(5);
//	headB1->next = new ListNode(6);
//	headB1->next->next = new ListNode(7);
//	headB1->next->next->next = new ListNode(8);
//	headB1->next->next->next->next = NULL;
//	ListNode* result1 = s.getIntersectionNode(headA1, headB1);
//	if (result1 == NULL) {
//		std::cout << result1 << std::endl;
//	}
//	
//	// Test Case 2: Intersection
//	ListNode* headA2 = new ListNode(1);
//	headA2->next = new ListNode(2);
//	headA2->next->next = new ListNode(3);
//	headA2->next->next->next = new ListNode(4);
//	headA2->next->next->next->next = NULL;
//
//	ListNode* headB2 = new ListNode(5);
//	headB2->next = new ListNode(6);
//	headB2->next->next = headA2->next->next;  // Intersection point
//	headB2->next->next->next = NULL;
//	ListNode* result2 = s.getIntersectionNode(headA2, headB2);
//	if (result2 != NULL) {
//		std::cout << "Intersection at node with value: " << result2->val << std::endl;
//	}
//	else {
//		std::cout << "No intersection" << std::endl;
//	}
//
//	return 0;
//}