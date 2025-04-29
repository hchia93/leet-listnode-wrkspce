#pragma once
#include "ListNode.h"

ListNode* DeleteDuplicates(ListNode* head)
{
    if (head != nullptr)
    {
        ListNode* pIterator = head;

        while (pIterator->next != nullptr)
        {
            if (pIterator->val == pIterator->next->val)
            {
                ListNode* pNext = pIterator->next;
                pIterator->next = pNext->next;
                delete pNext;
            }
            else
            {
                pIterator = pIterator->next;
            }
        }
    }

    return head;
}