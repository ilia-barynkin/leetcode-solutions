#include <string>
#include <cassert>
#include <unordered_set>
#include <iostream>

int countEntries(std::string codex, std::string dictionary_raw) {
    std::unordered_set<char> dict;

    for (auto s: dictionary_raw) {
        dict.insert(s);
    }

    int result = 0;

    for (auto c: codex) {
        if (dict.count(c)) ++result;
    }

    return result;
}

int main(int argc, char* argv[]) {
    assert(countEntries("", "") == 0);
    assert(countEntries("a", "b") == 0);
    assert(countEntries("aa", "a") == 2);
    assert(countEntries("ab", "b") == 1);
    assert(countEntries("aa", "aa") == 2);
    
    std::string j, s;

    std::cin >> j >> s;

    std::cout << countEntries(s, j);

    return 0;
}