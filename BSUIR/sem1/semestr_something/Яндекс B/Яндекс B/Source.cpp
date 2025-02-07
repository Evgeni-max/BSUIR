#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compareStrings(string& str1, string& str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int minLen = std::min(len1, len2);

	for (int i = 0; i < minLen; ++i) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
		else continue;
	}
	return 0;
}

int bin_find(string& str, vector<string>& l, int beg, int end) {
	if (beg > end) return -1;
	if (beg == end) {
		if (compareStrings(str, l[beg]) == 0) {
			return beg;
		}
		else return -1;
	}

	if (compareStrings(str, l[(beg + end) / 2]) == -1) {
		bin_find(str, l, beg, (beg + end) / 2);
	}
	else if (compareStrings(str, l[(beg + end) / 2]) == 1) {
		bin_find(str, l, (beg + end) / 2, end);
	}
	else {
		int index = (beg + end) / 2;
		while (1) {
			if (index == 0) return 0;

			if (l[index - 1].compare(0, str.length(), str) == 0) {
				--index;
			}
			else {
				return index;
			}
		}
	}
}

int main() {
	string s;
	vector<string> l;
	cin >> s;
	int max = 0;
	string buf = "";
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			if (max < buf.length()) max = buf.length();
			l.push_back(buf);
			buf = "";
		}
		else if (s[i] == ',') {
			if (max < buf.length()) max = buf.length();
			buf += s[i];
			l.push_back(buf);
			buf = "";
		}
		else {
			buf += s[i];
		}
	}

	int len = max * 3;
	int numb;
	string str;
	for (int i = 0; i < Q; ++i) {
		cin >> numb >> str;
		int index = bin_find(str, l, 0, N - 1);
		if (index == -1 || index + numb >= N) {
			std::cout << -1 << '\n';
			continue;
		}
		if (l[index + numb].compare(0, str.length(), str) == 0) {
			cout << index + numb << '\n';
		}
		else cout << -1 << '\n';
	}
}