#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
// fastest
// TODO: analyze
int maxProfit(const vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    
    int max_profit = 0;
    int min_price = prices[0];
    
    for (int i = 1; i < prices.size(); ++i) {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    
    return max_profit;
}
};

int main(int argc, char* argv[]) {
    Solution sol;
    // Example 1:

    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    // Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    assert(sol.maxProfit({7,1,5,3,6,4}) == 5);

    // Example 2:

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    // Explanation: In this case, no transactions are done and the max profit = 0.

    assert(sol.maxProfit({7,6,4,3,1}) == 0);


    return 0;
}