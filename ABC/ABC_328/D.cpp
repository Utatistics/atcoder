#include <bits/stdc++.h>

struct Node {
    char value;
    Node* prev;
    Node* next;

    Node(char v) : value(v), prev(nullptr), next(nullptr) {}
};

int main() {
    std::string S;
    std::cin >> S;


    Node* head = nullptr;
    Node* tail = nullptr;
    for (auto c : S) {
        Node* node = new Node(c);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    Node* node = head;
    while (node != nullptr) {
        if (node->value != 'B') {
            node = node->next;
            continue;
        }
        if (node->prev == nullptr || node->next == nullptr) { // skip head or tail
            node = node->next;
            continue;
        }

        if (node->prev->value == 'A' && node->next->value == 'C') {
            Node* left = node->prev->prev;
            Node* right = node->next->next;

            if (left != nullptr) left->next = right;
            else head = right;

            if (right != nullptr) right->prev = left;
            else tail = left;
    
            if (left != nullptr) node = left;
            else node = right;
        } 
        else {
            node = node->next;
        }
    }

    Node* ans = head;
    while (ans != nullptr) {
        std::cout << ans->value;
        ans = ans->next;
    }
    std::cout << std::endl;

    return 0;
}
