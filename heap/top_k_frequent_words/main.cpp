#include <vector>
#include <string>
#include <queue>

using namespace std;

#define PRIME 31

size_t hash(const std::string& s) {
    size_t res = 0;

    for (auto c: s) {
        res = res * PRIME + c;
    }

    return res;
}

struct Compare {
    bool operator ()(const string& str1, const string& str2) const {
        return hash(str1) 
    }
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<
    }
};