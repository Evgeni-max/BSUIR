#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class triple {
public:
    int l;
    int r;
    int a;
    triple(int l, int r, int a) {
        this->a = a;
        this->l = l;
        this->r = r;
    }
    triple() {
        this->a = 0;
        this->l = 0;
        this->r = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, bufL, bufR, bufA;
    cin >> N;
    vector<triple> trio(N);
    unordered_map<long long, int> map1;

    long long result = 0;
    for (int i = 0; i < N; ++i) {
        cin >> bufL >> bufR >> bufA;
        trio[i].l = bufL;
        trio[i].r = bufR;
        trio[i].a = bufA;
    }

    long long Q, nowA = 0;
    int count = 0;
    cin >> Q;
    long long* questions = new long long[Q];
    unordered_set<long long> ques;

    long long buf;
    for (int i = 0; i < Q; ++i) {
        cin >> buf;
        questions[i] = buf * 2;
        ques.insert(questions[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int h = trio[i].l; h < trio[i].r; ++h) {
            ++count;
            result += nowA * 2 + trio[i].a;
            if (ques.find(result) != ques.end()) {
                map1.insert(pair<long long, int>(result, count));
            }
            nowA += trio[i].a;
        }
    }

    for (int i = 0; i < Q; ++i) {
        std::cout << map1[questions[i]] << "\n";
    }

    return 0;
}