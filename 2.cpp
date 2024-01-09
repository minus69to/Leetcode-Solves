#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void appendToEnd(int x)
    {
        ListNode *newNode = new ListNode(x);
        ListNode *current = this;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
};

void printList(ListNode *head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty!\n";
    }

    ListNode *current = head;

    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

//////////////////////////////

class Solution
{
public:
    void appendToEnd(ListNode *head, int data)
    {
        ListNode *current = head;
        ListNode *newNode = new ListNode(data);

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l = new ListNode(0);

        int carry = 0, sum = 0;
        int l1f = 1, l2f = 1;

        while (l1 != nullptr || l2 != nullptr)
        {
            sum = 0;
            if (l1 != nullptr && l2 != nullptr)
            {
                sum = l1->val + l2->val + carry;
            }
            else if (l1 == nullptr)
            {
                sum = l2->val + carry;
            }
            else if (l2 == nullptr)
            {
                sum = l1->val + carry;
            }


            if (sum > 9)
            {
                appendToEnd(l, sum - 10);
                carry = 1;
            }
            else
            {
                appendToEnd(l, sum);
                carry = 0;
            }

            if (l2 != nullptr && l2f == 1)
            {
                l2 = l2->next;
            }
            else
            {
                l2 = nullptr;
                l2f = 0;
            }

            if (l1 != nullptr && l1f == 1)
            {
                l1 = l1->next;
            }
            else
            {
                l1 = nullptr;
                l1f = 0;
            }
        }

        if (carry == 1)
        {
            appendToEnd(l, 1);
        }

        l = l->next;
        // printList(l);
        return l;
    }
};

int main()
{
    ListNode *l1 = new ListNode(9);
    l1->appendToEnd(9);
    l1->appendToEnd(9);
    l1->appendToEnd(9);
    l1->appendToEnd(9);
    l1->appendToEnd(9);
    l1->appendToEnd(9);

    ListNode *l2 = new ListNode(9);
    l2->appendToEnd(9);
    l2->appendToEnd(9);
    l2->appendToEnd(9);

    Solution sol;
    ListNode *l = sol.addTwoNumbers(l1, l2);

    printList(l1);

    return 0;
}