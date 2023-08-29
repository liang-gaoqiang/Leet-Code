#include <bits/stdc++.h>
using namespace std;

//暴力破解法
int removeElement(vector<int>& nums, int val) {
	int new_array_lenggth = nums.size();

	for (int i = 0; i < new_array_lenggth; i++) {
		if (nums[i] == val) {
			for (int j = i + 1; j < new_array_lenggth; j++) {
				nums[j - 1] = nums[j];
			}
			i--	;
			new_array_lenggth--;
		}
		
	}
	return new_array_lenggth;
}

//双指针法又叫快慢指针法：通过一个快指针和一个慢指针在一个for循环下完成两个for循环的工作.
int removeElement02(vector<int>& nums, int val) {
	int slowindex = 0;
	for (int fastindex = 0; fastindex < nums.size(); fastindex++) {
		if (val != nums[fastindex]) {
			nums[slowindex++] = nums[fastindex];
		}
	}
	return slowindex;
}


//int main() {
//	vector<int> nums = {0,1,2,2,3,0,4,2};
//	int val = 3;			  
//	cout << removeElement(nums, val) << endl;
//}