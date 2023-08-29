#include <bits/stdc++.h>
using namespace std;

/*
二进制异或的性质：同为0(假)，异为1(真)
1、交换律：a^b = b^a
2、结合律：(a^b)^c = a^(b^c)
3、0^a = a, a^a = 0
*/
//T(n) = O(n)
//T(n) = O(1)
int singleNumber(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	int ans = 0;
	for (int &num : nums) {
		ans = ans ^ num;
	}
	return ans;
}


//int main() {
//	//vector<int> nums = { 2, 2, 1 };
//	vector<int> nums = { 4,1,2,1,2 };
//	cout << singleNumber(nums) << endl;
//}

// https://www.bilibili.com/video/BV1qv4y1A7UF/?spm_id_from=333.788&vd_source=526e290f96fb270fa1914cdc0f0b1c73