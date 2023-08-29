#include <bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] > target) {
			right = middle - 1;
		}
		else if (nums[middle] < target) {
			left = middle + 1;
		}
		else {
			return middle;
		}
	}
	//未找到目标值
	return -1;
}


int search02(vector<int>& nums, int target) {
	//当区间是左闭右开的形式时，二分查找略有不同
	int left = 0;
	int right = nums.size();

	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	//未找到目标值
	return -1;
}

//int main() {
//	vector<int> nums = {-1, 0, 3, 5, 9, 12 };
//	int target = 9;
//	cout << search02(nums, target) << endl;
//	return 0;
//}