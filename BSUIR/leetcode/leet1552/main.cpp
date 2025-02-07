#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        const int n = position.size();
        sort(position.begin(), position.end());
        int min = 1, max = (position[n - 1] - position[0]) / (m - 1);

        return find_distance(position, m, min, max);
    }
private:
    int find_distance(vector<int>& position, int m, int min, int max) {
        if (max == min) {
            if (max != 1) {
                return max;
            }
            else if (isDistance(position, max, m - 1)) {
                return 1;
            }
            else return 0;
        }
        if(max == min + 1) {
            if (isDistance(position, max, m - 1)) return max;
            else if (isDistance(position, min, m - 1)) return min;
            else return 0;
        }

        if (isDistance(position, (max + min) / 2, m - 1)) {
            return find_distance(position, m, (max + min) / 2, max);
        }
        else {
            return find_distance(position, m, min, (max + min) / 2 - 1);
        }
    }
    bool isDistance(vector<int>& position, int distance, int m) {
        int last = position[0];
        for (int i = 0; i < position.size(); ++i) {
            if (position[i] - last >= distance) {
                last = position[i];
                --m;
                if (m == 0) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> v {5,4,3,2,1,1000000000};
    cout << s.maxDistance(v, 2);
}