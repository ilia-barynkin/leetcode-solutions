#include <vector>
#include <algorithm>

/*
    Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:
    - `i != j`, `i != k`, and `j != k`
    - `nums[i] + nums[j] + nums[k] == 0`

    Notice that the solution set must not contain duplicate triplets.
*/
class Solution {
public:
    // int search(int target) {

    // }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::stable_sort(nums.begin(), nums.end());
        
        for (auto v: nums) {
            if (v > 0)
                break;
            
            
        }
    }
};