#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *Previous = nullptr;
        ListNode *Current = head;

        while (Current)
        {
            ListNode *temp = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current = temp;
        }
        return Previous;
    }
};

// Insert at end
ListNode *insertAtend(ListNode *head, int val)
{
    if (!head)
        return new ListNode(val);

    ListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Print list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int n, x;
    ListNode *head = nullptr;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        head = insertAtend(head, x);
    }

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.reverseLinkedList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}



// time complexity: O(n) - We traverse the linked list once to reverse it.
// space complexity: O(1) - We use a constant amount of extra space for the pointers