using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = -1;
        if (prices.empty() || prices.size() <= 1) return 0;
        auto a = prices.begin();
        auto b = prices.begin()+1;
        while (b != prices.end()) {
            // if price drop
            if (*a > *b) a = b;
            // if price not drop
            int profit = *b - *a;
            if (max == -1) max = profit;
            if (profit > max) max = profit;
            b++;
        }
        return max > 0 ? max : 0;
    }
};
