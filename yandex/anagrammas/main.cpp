#include <unordered_map>
#include <iostream>

int main(int argc, char* argv[]) {
    fprintf(stderr)
    std::unordered_map<char, int> entries;
    std::string word;

    std::cin >> word;

    for (auto c : word)
        entries[c]++;
    

    std::cin >> word;

    for (auto c: word)
        entries[c]--;

    int result = 1;

    for (auto kvp : entries) {
        if (kvp.second) {
            result = 0;
            break;
        }
    }

    std::cout << result;

    return 0;
}