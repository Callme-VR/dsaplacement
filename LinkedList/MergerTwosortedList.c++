// g++ MergerTwosortedList.c++ -o merge
// ./merge


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummynode(0);
        ListNode* node = &dummynode;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if (list1) node->next = list1;
        else node->next = list2;

        return dummynode.next;
    }
};

// Insert at end
ListNode* insertAtEnd(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, m, x;
    ListNode *list1 = nullptr, *list2 = nullptr;

    cout << "Enter size of first sorted list: ";
    cin >> n;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list1 = insertAtEnd(list1, x);
    }

    cout << "Enter size of second sorted list: ";
    cin >> m;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> x;
        list2 = insertAtEnd(list2, x);
    }

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Solution obj;
    ListNode* merged = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}