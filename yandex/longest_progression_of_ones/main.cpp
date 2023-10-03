#include <iostream>

int main(int argc, char* argv[]) {
    int count;
    std::cin >> count;
    int result = 0;
    int max_result = 0;

    for (int i = 0; i < count; ++i) {
        int curr;
        std::cin >> curr;
        result = curr * (result + 1);
        
        if (result > max_result)
            max_result = result;
    }

    std::cout << max_result;

    return 0;
}