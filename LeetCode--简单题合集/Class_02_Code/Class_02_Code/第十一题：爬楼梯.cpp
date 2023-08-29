#include <bits/stdc++.h>
using namespace std;

//该算法在leetcode上超出时间限制
//int climbStairs(int n) {
//	//递归出口
//	if (n <= 2) return n;
//
//
//	return climbStairs(n - 1) + climbStairs(n - 2);
//}

/*
是的，递归解法在处理大规模问题时可能会导致重复计算，从而导致性能问题。为了优化递归解法，可以使用记忆化技术或动态规划。

使用记忆化技术优化递归解法：

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
    //创建一个名为 memo 的整型向量（vector），长度为 n + 1，并且初始化所有元素为0
    //memo 向量用于存储爬楼梯问题中每个位置的计算结果，以避免重复计算。
    std::vector<int> memo(n + 1, 0);
    return climbStairsMemo(n, memo);
}


//动态规划解法:
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


