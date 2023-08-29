#include <bits/stdc++.h>
using namespace std;

//���㷨��leetcode�ϳ���ʱ������
//int climbStairs(int n) {
//	//�ݹ����
//	if (n <= 2) return n;
//
//
//	return climbStairs(n - 1) + climbStairs(n - 2);
//}

/*
�ǵģ��ݹ�ⷨ�ڴ�����ģ����ʱ���ܻᵼ���ظ����㣬�Ӷ������������⡣Ϊ���Ż��ݹ�ⷨ������ʹ�ü��仯������̬�滮��

ʹ�ü��仯�����Ż��ݹ�ⷨ��

*/

int climbStairsMemo(int n, std::vector<int>& memo) {
    if (n <= 2)
        return n;

    if (memo[n] != 0)
        return memo[n];

    memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
    return memo[n];
}

int climbStairs(int n) {
    //����һ����Ϊ memo ������������vector��������Ϊ n + 1�����ҳ�ʼ������Ԫ��Ϊ0
    //memo �������ڴ洢��¥��������ÿ��λ�õļ��������Ա����ظ����㡣
    std::vector<int> memo(n + 1, 0);
    return climbStairsMemo(n, memo);
}


//��̬�滮�ⷨ:
//int climbStairs(int n) {
//    if (n <= 2)
//        return n;
//
//    std::vector<int> dp(n + 1, 0);
//    dp[1] = 1;
//    dp[2] = 2;
//
//    for (int i = 3; i <= n; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//
//    return dp[n];
//}


//int main() {
//	int n = 5;
//	int result = climbStairs(n);
//	cout << result << endl;
//	return 0;
//
//}


