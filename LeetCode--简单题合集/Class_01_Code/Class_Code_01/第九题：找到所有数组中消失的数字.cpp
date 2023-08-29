#include <bits/stdc++.h>
using namespace std;

//排序的方法
//vector<int> findDisappearedNumbers(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	vector<int> res;
//	int cur = 1;
//	for (int i = 0; i < nums.size(); i++) {
//		//如果当前nums[i]==cur,cur就要+1
//		if (cur == nums[i]) {
//			cur++;
//		}
//		//如果cur<nums[i],就把cur到nums[i]之间所有的整数取出，并且存到到res数组中去
//		if (cur < nums[i]) {
//			while (cur != nums[i]) {
//				res.push_back(cur);
//				cur++;
//			}
//			i--;
//		}
//	}
//	while (cur <= nums.size()) {
//		res.push_back(cur);
//		cur++;
//	}
//	return res;
//}

//计数器法
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> counts(nums.size() + 1);
	vector<int> res;
	//遍历nums数组，把数组中每个数字出现的次数记录下来.
	for (int i = 0; i < nums.size(); i++) {
		counts[nums[i]]++;
	}

	//遍历counts数组，把数组中所有值为零的元素所对应的下标存放到结果数组res中。
	for (int i = 1; i < counts.size(); i++) {
		if (counts[i] == 0) {
			res.push_back(i);
		}
	}
	return res;
}
//int main() {
//	vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
//	vector<int> result = findDisappearedNumbers(nums);
//	cout << "Missing numbers: ";
//	for (int num : result) {
//		cout << num << " ";
//	}
//	cout << endl;
//
//	return 0;
//}