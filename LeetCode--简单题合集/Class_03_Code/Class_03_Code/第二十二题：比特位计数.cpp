#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(0), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {

public:
	// ��̬�滮�����
	vector<int> countBits(int n) {
		// ÿ�����������ż����ʱ���������ת���ɶ�������1�ĸ����ͺ͸���������2֮���������һ���ġ�
		// ����ʱ��������ת���ɶ�����֮��1�ĸ����ͺ�����ǰһλ������1�ĸ����ټ�1������2��3��4��5  (10, 11, 100, 101)
		// dp[i]ֵ��ʾi�Ķ�������1�ĸ���
		// i ��ʾ0~n֮�������
		vector<int> dp(n + 1);
		for (int i = 0; i <= n; i++) {
			if (i % 2 == 1) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = dp[i / 2];
			}
		}
		return dp;
	}

	// ���������۲�0~n֮�䣬�����Ƿ���2��n������ʽ,ͨ���۲��֪������2��n���ݣ����Ķ���������1�ĸ�������1
	// ���i���Ƕ��������ݵ�ʱ���������������1�ĸ��������������2��n����
	vector<int> countBitsByTwo(int n) {
		int highBit = 0;
		vector<int> dp(n + 1);
		// ��0~n֮������2�������ݵ�dpֵ����ֵΪ1��
		for (int i = 1; i <= n; i++) {
			if ((i & (i - 1)) == 0) {
				dp[i] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			// ���i��2���������ݣ���¼���벻��2���������ݵ��������2����������λ��
			if ((i & (i - 1)) == 0) {
				highBit = i;
			}

			// ���i����2����������
			if ((i & (i - 1)) != 0) {
				dp[i] = dp[i - highBit] + 1;
			}
		}

		return dp;
	}
};

//int main() {
//	Solution s;
//	// Case one: n = 2
//	int n = 2;
//	vector<int> result1 = s.countBits(n);
//	for (int res : result1) {
//		cout << res << " ";  // 0 1 1
//	}
//	cout << endl;
//
//	// Case two: n = 5
//	int n2 = 5;
//	vector<int> result2 = s.countBitsByTwo(n2);
//	for (int res : result2) {
//		cout << res << " ";  // 0 1 1 2 1 2
//	}
//	cout << endl;
//	return 0;
//}