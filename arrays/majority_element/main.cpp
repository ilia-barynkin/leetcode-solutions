#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        std::unordered_map<int, int> cs;
        int max = nums[0];

        for (auto n: nums) {
            ++cs[n];
            
            if (cs[max] < cs[n])
                max = n;
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    //assert(sol.majorityElement({3,3,4}) == 3);
    assert(sol.majorityElement({3,2,3}) == 3);
    assert(sol.majorityElement({6,5,5}) == 5);

    return 0;
}