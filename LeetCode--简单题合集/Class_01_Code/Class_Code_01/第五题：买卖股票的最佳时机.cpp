#include <bits/stdc++.h>
using namespace std;

//��һ������������prices��ע���±��1��ʼ����ֹ�����±�Խ��
//�ڶ����������������prices[i] - lowest_price������ļ۸�����Ҫ�жϵģ�����ÿ��ѭ���жϵ�ǰ�ļ۸��Ƿ�������

//�����ƽⷨ--leetcode����ʱ�����
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

//һ��forѭ��
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