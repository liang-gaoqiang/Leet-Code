#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int count = 0; // ͳ��0�ĸ���
    // �������飬������Ԫ������ǰ��
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[count] = nums[i];
            count++;
        }
    }
    // ������ĩβ�����Ӧ������0
    for (int i = count; i < nums.size(); i++) {
        nums[i] = 0;
    }

    //�������
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

//int main() {
//    // ��������
//    vector<int> nums = { 0, 1, 0, 3, 12 };
//    moveZeroes(nums);
//	return 0;
//}