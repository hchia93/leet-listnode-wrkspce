#pragma once
#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * Identical to LeetCode website, do not change its definition to allow testing.
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Utility functions
 */

ListNode* CreateFrom(std::vector<int>& intList)
{
    if (intList.size() == 0)
    {
        return nullptr;
    }

    ListNode* head = new ListNode(intList[0]);
    ListNode* pIterator = head;
    for (int i = 1; i < intList.size(); i++)
    {
        ListNode* node = new ListNode(intList[i]);
        pIterator->next = node;
        pIterator = pIterator->next;
    }
    return head;
}

void PrintListNodeDetail(ListNode* node)
{
    if (node != nullptr)
    {
        std::cout << "Addr :    " << &node << std::endl;
        std::cout << "Value:    " << node->val << std::endl;
        std::cout<<  "NextAddr: " << &node->next << std::endl;
    }
}

void PrintListDetail(ListNode* head)
{
    if (head != nullptr)
    {
        ListNode* pCurrent = head;
        while (pCurrent != nullptr)
        {
            PrintListNodeDetail(pCurrent);
            pCurrent = pCurrent->next;
        }
    }
}

void PrintListVisual(ListNode* head)
{
    if (head != nullptr)
    {
        ListNode* pCurrent = head;
        while (pCurrent != nullptr)
        {
            std::cout << pCurrent->val << " -> ";
            pCurrent = pCurrent->next;
        }
        std::cout << std::endl;
    }
}