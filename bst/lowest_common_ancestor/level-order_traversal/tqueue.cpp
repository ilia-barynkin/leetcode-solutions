#include <cassert>
#include <iostream>

struct queue {  
    int val;  
    queue* prev;

    queue(int init_val) : val(init_val), prev(NULL) {}
};

struct Queue {
    int value;
    Queue* previous = nullptr;

    Queue* enqueue()
};

Queue* enqueue(int value, Queue* last = nullptr) {
    if (!last)
        return new Queue { value };

    if (last->previous) {
        throw std::runtime_error("Error");
    }

    last->previous = new Queue { value };
    return last->previous;
}

Queue* dequeue(Queue* current) {
    Queue* prev = current->previous;
    free(current);

    return prev;
}

bool testQueue() {
    Queue* q = enqueue(1)

    // test enqueue
    assert(q->value == 1);
    assert(q->previous->value == 2);
    assert(q->previous->previous->value == 3);
    assert(q->previous->previous->previous->value == 4);
    assert(q->previous->previous->previous->previous->value == 5);
}

int main(int argc, char* argv[]) {

    return 0;
}