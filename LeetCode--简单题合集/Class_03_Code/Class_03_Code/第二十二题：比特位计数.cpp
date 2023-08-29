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
	// 动态规划法求解
	vector<int> countBits(int n) {
		// 每当这个数字是偶数的时候，这个数字转换成二进制中1的个数就和该整数除以2之后的数字是一样的。
		// 奇数时，该数字转换成二进制之后1的个数就和它的前一位数字中1的个数再加1。例如2、3、4、5  (10, 11, 100, 101)
		// dp[i]值表示i的二进制中1的个数
		// i 表示0~n之间的数字
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

	// 方法二：观察0~n之间，数字是否是2的n次幂形式,通过观察可知，凡是2的n次幂，它的二进制数中1的个数总是1
	// 如果i不是二的整次幂的时候，则该数二进制中1的个数是离它最近的2的n次幂
	vector<int> countBitsByTwo(int n) {
		int highBit = 0;
		vector<int> dp(n + 1);
		// 将0~n之间所有2的整数幂的dp值均赋值为1；
		for (int i = 1; i <= n; i++) {
			if ((i & (i - 1)) == 0) {
				dp[i] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			// 如果i是2的整数次幂，记录下离不是2的整数次幂的数最近的2的整数次幂位置
			if ((i & (i - 1)) == 0) {
				highBit = i;
			}

			// 如果i不是2的整数次幂
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