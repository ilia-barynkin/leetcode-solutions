#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        auto minPrice = prices[0];
        auto maxProfit = 0;
        
        for (auto v: prices) {
            if (v < minPrice)
                minPrice = v;
            else if (v - minPrice > maxProfit)
                maxProfit = v - minPrice;
        }

        return maxProfit;
    }
};

int main(int argc, char* argv[]) {
    // Example 1:

    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    // Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Solution sol;
    assert(sol.maxProfit({7,1,5,3,6,4}) == 5);

    // Example 2:

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    // Explanation: In this case, no transactions are done and the max profit = 0.
    assert(sol.maxProfit({7,6,4,3,1}) == 0);
}