#include <memory>
#include <cstdlib>
#include <iostream>
#include <vector>

#define INIT_STACK_SIZE 32 * sizeof(int)

typedef struct CStack {
    size_t cap = INIT_STACK_SIZE;
    int* head = (int*)malloc(sizeof(int) * cap); // dummy
    int* curr = head;

    inline void push(int val) {
        curr += sizeof(int);
        
        if (head - curr == cap) {
            cap *= 2;
            head = (int*)realloc(head, sizeof(int) * cap);
        }

        *curr = val;
    }

    inline int pop() {
        curr -= sizeof(int);
        
        if (curr == head) {
            std::cout << "stack underflow" << std::endl;
            exit;
        }

        return *curr;
    }
} Struct;