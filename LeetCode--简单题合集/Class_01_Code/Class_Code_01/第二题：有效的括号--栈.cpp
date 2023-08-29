#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


bool isValid(string s) {
	unordered_map<char, char> pair = {
				{'(', ')'}, {'[', ']'}, {'{', '}'}
	};
	stack<char> stk;

	if (s.size() % 2 != 0)
		return false;


	for (int i = 0; i < s.size(); i++) {
		if (pair.find(s[i]) != pair.end()) {
			// ����ַ��������ţ��ͰѶ�Ӧ�������ż���ջ�С� 
			stk.push(pair[s[i]]);
		}
		else {
			//����ַ��������ţ�������ַ�ƥ��
			if (stk.empty() || stk.top() != s[i]) {
				return false;
			}
			stk.pop();
		}
	}
	return stk.empty();
}


//int main() {
//	string s = "()";
//	cout << isValid(s) << endl;
//	return 0;
//}
