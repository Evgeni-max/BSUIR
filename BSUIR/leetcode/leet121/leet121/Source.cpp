#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 2147483647;
        int price = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) min = prices[i];
            else if (prices[i] - min > price) price = prices[i] - min;
        }
        return price;
    }
};

int main(vector<int>& prices) {
    int min = 2147483647;
    int price = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min) min = prices[i];
        else if (prices[i] - min > price) price = prices[i] - min;
    }
    return price;
}