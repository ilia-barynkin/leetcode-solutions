#include <vector>
#include <limits>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

#define DUMMY_VAL std::numeric_limits<int>::max()

inline ListNode* insertPrev(ListNode* next, int val = DUMMY_VAL) {
    return new ListNode(DUMMY_VAL, next);
}

inline ListNode* initList(std::vector<int> vals) {
    auto head = new ListNode(DUMMY_VAL);
    auto tail = head;
    
    for (auto v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }

    auto res = head->next;

    return res;
}

inline void makeLoop(ListNode* list, int pos) {
    ListNode* cycleNode = nullptr;

    for (int i = 0; list && list->next; ++i) {
        if (i == pos)
            cycleNode = list;

        list = list->next;
    }

    if (cycleNode)
        list->next = cycleNode;

}

inline std::vector<int> listToVec(ListNode* node, int maxNodes = DUMMY_VAL) {
    std::vector<int> res;

    while (node) {
        res.push_back(node->val);
        node = node->next;

        if (--maxNodes == 0) 
            break;
    }

    return res;
}

inline void printList(ListNode* list, int maxNodes = DUMMY_VAL)
{
    while (list) {
        std::cout << list->val;
        list = list->next;

        if (list)
            std::cout << " -> ";

        if (--maxNodes == 0)
            break;
    }

    std::cout << std::endl;
}