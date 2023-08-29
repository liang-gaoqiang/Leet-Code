#include <bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
	int t, c = 0;
	for (auto& n : nums) {
		if (!c) {
			t = n;
			c = 1;
		}
		else if (c == n) {
			c++;
		}
		else {
			c--;
		}
	}
	return t;
}

//int main() {
//	vector<int> nums = {3,3,4};
//	cout << majorityElement(nums) << endl;
//	return 0;
//}