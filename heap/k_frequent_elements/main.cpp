#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>

struct Compare {
    bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> h;

        for (auto n : nums) {
            freq[n]++;
        }

        for (auto pair: freq) {
            h.push(pair);

            if (h.size() > k) {
                h.pop();
            }
        }

        std::vector<int> result;

        while(!h.empty()) {
            result.push_back(h.top().first);
            h.pop();
        }

        return result;
    }
};

int main(int argc, char* argv[]) {

    // Example 1:

    // Input: nums = [1,1,1,2,2,3], k = 2
    // Output: [1,2]

    Solution sol;
    assert(sol.topKFrequent({1,1,1,2,2,3}, 2) == std::vector<int>({1,2}));

    // Example 2:

    // Input: nums = [1], k = 1
    // Output: [1]

    assert(sol.topKFrequent({1}, 1) == std::vector<int>({1}));

    return 0;
}