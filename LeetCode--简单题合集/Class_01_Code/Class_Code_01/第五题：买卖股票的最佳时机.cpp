#include <bits/stdc++.h>
using namespace std;

//第一步：遍历数组prices，注意下表从1开始，防止数组下表越界
//第二步：计算最大利润，prices[i] - lowest_price，这里的价格是需要判断的，根据每次循环判断当前的价格是否是最大的

//暴力破解法--leetcode超出时间控制
//int maxProfit(vector<int>& prices) {
//	if (prices.empty()) return 0;
//	int maxprofit = 0;
//	for (int i = 0; i < prices.size(); i++) {
//		for (int j = i + 1; j < prices.size(); j++) {
//			int profit = prices[j] - prices[i];
//			if (profit > maxprofit) {
//				maxprofit = profit;
//			}
//		}
//	}
//	return maxprofit;
//}

//一层for循环
int maxProfit(vector<int>& prices) {
	if (prices.empty()) return 0;
	int lowestprice = prices[0];
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < lowestprice) {
			lowestprice = prices[i];
		}
		else if (prices[i] - lowestprice > maxProfit) {
			maxProfit = prices[i] - lowestprice;
		}
	}
	return maxProfit;
}


//int main() {
//	vector<int> prices = {7,5,3,1,6,4};
//	//vector<int> prices = {7,6,4,3,1};
//	//vector<int> prices = {7,1,5,3,6,4};
//	cout << maxProfit(prices) << endl;
//	return 0;
//}

// https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/easy/121.best-time-to-buy-and-sell-stock