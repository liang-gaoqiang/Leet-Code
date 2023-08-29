#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int count = 0; // 统计0的个数
    // 遍历数组，将非零元素依次前移
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[count] = nums[i];
            count++;
        }
    }
    // 在数组末尾添加相应数量的0
    for (int i = count; i < nums.size(); i++) {
        nums[i] = 0;
    }

    //遍历输出
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

//int main() {
//    // 测试样例
//    vector<int> nums = { 0, 1, 0, 3, 12 };
//    moveZeroes(nums);
//	return 0;
//}