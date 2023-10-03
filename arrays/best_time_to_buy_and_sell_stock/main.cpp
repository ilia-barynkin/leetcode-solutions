#include <vector>
#include <cassert>
#include <limits>

#define INT_MAX std::numeric_limits<int>::max();

class Solution {
public:
    int maxProfit(std::vector<int> prices) {
        auto min_price = INT_MAX;
        auto max_profit = 0;

        for (auto v: prices) {
            if (min_price > v) {
                min_price = v;
            }

            max_profit = v - 
        }
    }
};

int maxProfit_test(std::vector<int> prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main(int argc, char* argv[]) {
    Solution sol;
    //  Input: prices = [7,1,5,3,6,4]
    //  Output: 5

    //assert(sol.maxProfit({7,1,5,3,6,4}) == 5);

    //  Input: prices = [7,6,4,3,1]
    //  Output: 0

    //assert(sol.maxProfit({7,6,4,3,1}) == 0);

    assert(maxProfit_test({3, 7, 1, 2}));
}