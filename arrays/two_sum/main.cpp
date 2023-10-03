#include <vector>
#include <cassert>
// #include <map>
#include <algorithm>
#include <numeric>
#include <cstdlib>

int id_bsearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int& val, const std::vector<int>& nums) {
    int half_len = (end - begin) / 2;

    if (begin >= end) 
        return -1;

    int nums_id = *(begin + half_len);

    if (nums[nums_id] == val)
        return nums_id;
    if (val < nums[nums_id])
        return id_bsearch(begin, begin + half_len, val, nums);
    //else if(val > *(begin + half_len))
    return id_bsearch(begin + half_len + 1, end, val, nums);
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> idx(nums.size());
        std::iota(idx.begin(), idx.end(), 0);
        std::stable_sort(idx.begin(), idx.end(), [&nums] (auto a, auto b) { return nums[a] < nums[b]; });

        for (auto idx_it = idx.begin(); idx_it != idx.end(); ++idx_it) {
            int found_id = id_bsearch(idx_it + 1, idx.end(), target - nums[*idx_it], nums);
            
            if(found_id != -1) {
                return {*idx_it, found_id};
            }
        }

        return {};
    }
};

bool test(std::vector<int> nums, int target, const int first_id, const int sec_id) {
    Solution s;
    auto res = s.twoSum(nums, target);
    
    return res[0] == first_id && res[1] == sec_id;
}

int main(int argc, char* argv[]) {
    assert(test({2,7,11,15}, 9, 0, 1));
    assert(test({3,2,4}, 6, 1, 2));
    assert(test({3,3}, 6, 0, 1));

    return 0;
}