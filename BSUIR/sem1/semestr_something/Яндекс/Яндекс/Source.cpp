#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> palka(N);
	vector<int> p(N);

	for (int i = 0; i < N; ++i) {
		p[i] = 1;
		cin >> palka[i].first;
		cin >> palka[i].second;
		for (int j = i - 1; j >= 0; --j) {
			if (palka[j].first > palka[j + 1].first) {
				swap(palka[j].first, palka[j + 1].first);
				swap(palka[j].second, palka[j + 1].second);
			}
			else break;
		}
	}

	int max1 = palka[0].second;
	for (int i = 1; i < N; ++i) {
		if (palka[i].first == palka[i - 1].first) {
			p[i] = p[i - 1] = 0;
		}
		else {
			if (palka[i].second <= max1) {
				p[i] = p[i - 1] = 0;
			}
			else {
				max1 = palka[i].second;
			}
		}
	}

	int min2 = palka[N - 1].second;
	for (int i = N - 2; i >= 0; --i) {
		if (palka[i].first == palka[i + 1].first) {
			p[i] = p[i + 1] = 0;
		}
		else {
			if (palka[i].second >= min2) {
				p[i] = p[i + 1] = 0;
			}
			else {
				min2 = palka[i].second;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (p[i]) ++count;
	}

	cout << count;
}