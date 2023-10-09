#include <vector>
#include <cassert>

#define DUMMY 1

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> prefixPrd(nums.size());//(nums.size());
        std::vector<int> postfixPrd(nums.size());//(nums.size());

        prefixPrd[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            prefixPrd[i] = nums[i - 1] * prefixPrd[i - 1];
        }

        postfixPrd[nums.size() - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; --i) {
            postfixPrd[i] = nums[i + 1] * postfixPrd[i + 1];
        }

        std::vector<int> result(nums.size());

        for (auto i = 0; i < nums.size(); ++i) {
            result[i] = prefixPrd[i] * postfixPrd[i];
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    // Example 1:

    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]
    assert(sol.productExceptSelf(std::vector<int>({1,2,3,4})) == std::vector<int>({{24,12,8,6}}));
    //assert(sol.productExceptSelf(a) == std::vector<int>({24,12,8,6}));

    // Example 2:

    // Input: nums = [-1,1,0,-3,3]
    // Output: [0,0,9,0,0]

    //a = {-1,1,0,-3,3};
    //assert(sol.productExceptSelf(a) == std::vector<int>({24,12,8,6}));

    return 0;
}