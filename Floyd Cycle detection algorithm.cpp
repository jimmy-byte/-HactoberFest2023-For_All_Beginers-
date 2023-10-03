#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;        
        fast = fast->next->next;  

        
        if (slow == fast) {
            return true;
        }
    }

    
    return false;
}

int main() {
    // Create a linked list with a cycle
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;  

  
    bool hasCycleResult = hasCycle(node1);
    std::cout << "Does the linked list have a cycle? " << (hasCycleResult ? "Yes" : "No") << std::endl;

    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
