#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <set>

using namespace std;

class Solution {
    map<char, string> letters = {
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> result;

    void backtrack(string& digits, int start = 0) {
        if (start == digits.size()) {
            result.push_back(digits);
        }
        else {
            auto last_digit = digits[start];

            for (auto l : letters[last_digit]) {
                digits[start] = l;
                backtrack(digits, start + 1);
                digits[start] = last_digit;
            }
        }
    }

public:

    vector<string> letterCombinations(string digits) {;
        result.clear();
        
        if (digits.size() > 0)
            backtrack(digits);

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    auto t1 = sol.letterCombinations("29");

    // Input: digits = ""
    // Output: []

    auto t2 = sol.letterCombinations("");

    // Input: digits = "2"
    // Output: ["a","b","c"]

    auto t3 = sol.letterCombinations("2");

    return 0;
}