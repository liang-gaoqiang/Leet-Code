#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};


class Solution {

public:
	//环形链表：双指针法
	bool hasCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}

		ListNode* fast = head->next;
		ListNode* slow = head;
		
		while (fast != slow) {
			if (fast == NULL || fast->next == NULL) {
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}

};

//int main() {
//	Solution s;
//	// Test Case 1: No cycle
//	ListNode* head1 = new ListNode(1);
//	head1->next = new ListNode(2);
//	head1->next->next = new ListNode(3);
//	head1->next->next->next = new ListNode(4);
//	head1->next->next->next->next = NULL;
//	bool result1 = s.hasCycle(head1);
//	cout << result1 << endl;
//
//	// Test Case 2: Cycle exists
//	ListNode* head2 = new ListNode(1);
//	head2->next = new ListNode(2);
//	head2->next->next = new ListNode(3);
//	head2->next->next->next = new ListNode(4);
//	head2->next->next->next->next = head2->next;  // Creating a cycle
//	bool result2 = s.hasCycle(head2);
//	cout << result2 << endl;
//
//	return 0;
//}