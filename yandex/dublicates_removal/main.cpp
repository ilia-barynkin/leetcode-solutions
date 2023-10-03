#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    int count;
    std::cin >> count;
    int prev, curr;

    if (std::cin >> prev) 
        std::cout << prev << std::endl;

    for (int i = 1; i < count; ++i) {
        std::cin >> curr;
        if (curr < prev) {
            std::cout << curr << std::endl;
            prev = count;
        }
        fprintf(stderr, "%d \n",  curr);
    }

    return 0;
}