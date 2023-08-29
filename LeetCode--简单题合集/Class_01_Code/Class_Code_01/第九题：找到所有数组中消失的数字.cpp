#include <bits/stdc++.h>
using namespace std;

//����ķ���
//vector<int> findDisappearedNumbers(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	vector<int> res;
//	int cur = 1;
//	for (int i = 0; i < nums.size(); i++) {
//		//�����ǰnums[i]==cur,cur��Ҫ+1
//		if (cur == nums[i]) {
//			cur++;
//		}
//		//���cur<nums[i],�Ͱ�cur��nums[i]֮�����е�����ȡ�������Ҵ浽��res������ȥ
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

//��������
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> counts(nums.size() + 1);
	vector<int> res;
	//����nums���飬��������ÿ�����ֳ��ֵĴ�����¼����.
	for (int i = 0; i < nums.size(); i++) {
		counts[nums[i]]++;
	}

	//����counts���飬������������ֵΪ���Ԫ������Ӧ���±��ŵ��������res�С�
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