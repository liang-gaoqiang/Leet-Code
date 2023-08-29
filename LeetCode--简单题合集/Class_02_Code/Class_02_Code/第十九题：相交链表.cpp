#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {

public:
	//�ཻ����˫ָ�뷨
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		/*
		1�����ȣ��ֱ��������������ȡ���ǵĳ���
		2��Ȼ���ýϳ��������ָ�����ƶ�����϶���������λ�á�
		3��֮��ͬʱ�ƶ�����ָ�룬ֱ�������������ߵ��������ĩβ��
		4���������ָ�붼���������ĩβ����ʾ���������ཻ��
		5����������ָ�����������ʾ���������ཻ�������Ľڵ㼴Ϊ���ǵ��ཻ�ڵ㣻
		*/
		if (headA == NULL || headB == NULL) {
			return NULL;
		}
		//1�����ȣ��ֱ��������������ȡ���ǵĳ���
		int lenA = getLength(headA);
		int lenB = getLength(headB);

		ListNode* ptrA = headA;
		ListNode* ptrB = headB;
		//2���ýϳ��������ָ�����ƶ�����϶���������λ��
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

		//3��֮��ͬʱ�ƶ�����ָ�룬ֱ�������������ߵ��������ĩβ��
		while (ptrA != ptrB) {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
			if (ptrA == NULL && ptrB == NULL) {
				return NULL; //5���������ָ�붼���������ĩβ����ʾ���������ཻ��
			}
		}
		return ptrA; // 4������˵������ָ�����������ʾ���������ཻ�������Ľڵ㼴Ϊ���ǵ��ཻ�ڵ㣻
	}

	//������ĳ���
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
//	// Test Case 1: ���ཻ
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