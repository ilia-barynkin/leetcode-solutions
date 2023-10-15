#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    // todo: map, vector
    int lengthOfLongestSubstring(const string& s) {
        int result = 0;
        int i =0, j = 0;
        unordered_set<char> m;

        while(j < s.length()){
            while (m.count(s[j])) {
                m.erase(s[i++]);
            }

            m.insert(s[j]);

            if (j - i + 1 > result)
                result = j - i + 1;
            ++j;
        }

        return result;
    }
};