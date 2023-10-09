#include <vector>

class Solution {
public:
    void backtrack(std::vector<int> nums, std::vector<std::vector<int>> &result, inst start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        
    }
};