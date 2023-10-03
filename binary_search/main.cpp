#include <vector>
#include <cassert>
#include <stdio.h>

class Solution {
public:
    int bsrch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {
        int half_len = (end - begin) / 2;

        if (*(begin + half_len) == target)
            return half_len;
        else if (half_len == 0) {
            return -1;
        }
        else if (*(begin + half_len) < target) {
            auto res = bsrch(begin + half_len + 1, end, target);
            return res >= 0 ? half_len + 1 + res : -1;
        }
        else //if (target < *(begin + half_len))
            return bsrch(begin, begin + half_len, target);
    }

    int search(std::vector<int> nums, int target) {
        return bsrch(nums.begin(), nums.end(), target);
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    assert(sol.search({-1,0,3,5,9,12}, -1) == 0);
    assert(sol.search({-1,0,3,5,9,12}, 9) == 4);
    assert(sol.search({-1,0,3,5,9,12}, 2) == -1);
    assert(sol.search({-1,0,3,5,9,12}, 5) == 3);
    assert(sol.search({5}, 1) == -1);
    assert(sol.search({5}, 5) == 0);
    assert(sol.search({-1,0,3,5,9,12}, 13) == -1);

    fprintf(stderr, "Urk!\n");

    return 0;
}