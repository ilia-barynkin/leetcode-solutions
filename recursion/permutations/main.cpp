#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    vector<vector<int>> result;

    void backtrack(vector<int> nums, int start = 0) {
        if (start == nums.size() - 1) {
            result.push_back(nums);
        }
        else {
            backtrack(nums, start + 1);

            for (int next = start + 1; next < nums.size(); ++next) {
                swap(nums[start], nums[next]);
                backtrack(nums, start + 1);
                swap(nums[next], nums[start]);
            }
        }
    }

public:
    vector<vector<int>> permute(const vector<int>& nums) {
        result.clear();
        backtrack(nums);

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    
    //sol.permute({1});
    //sol.permute({1, 2});
    sol.permute({1,2,3});// == vector<vector<int>>({{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}));

    return 0;

}