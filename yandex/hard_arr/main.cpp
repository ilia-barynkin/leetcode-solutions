#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void count(const std::vector<int>& arr, std::unordered_map<int, int>& counter) {
    for (int element : arr) {
        if (counter.find(element) != counter.end()) {
            counter[element]++;
        } else {
            counter[element] = 1;
        }
    }
}

void findFreqEl(const std::vector<int>& arr, std::vector<int>& result) {
    std::unordered_map<int, int> counter;
    count(arr, counter);
    int maxCount = 0;
    
    for (const auto& pair : counter)
        maxCount = std::max(maxCount, pair.second);

    for (const auto& pair : counter)
        if (pair.second == maxCount) {
            result.push_back(pair.first);
        }

    std::stable_sort(result.begin(), result.end());
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    std::string inputStr;
    std::getline(input, inputStr);
    std::vector<int> vec;
    std::string tmp;

    for (char c : inputStr) {
        if (c == '[' || c == ',' || c == ']') {
            if (!tmp.empty()) {
                vec.push_back(std::stoi(tmp));
                tmp.clear();
            }
        } 
        else if (c != ' ') {
            tmp += c;
        }
    }

    std::vector<int> res;
    findFreqEl(vec, res);

    for (int i = 0; i < res.size(); i++) {
        output << res[i];

        if (i != res.size() - 1) {
            output << " ";
        }
    }
    output << std::endl;

    return 0;
}