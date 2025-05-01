#pragma once
#include "ListNode.h"

#define SHOW_DEBUG_STEP 1
#if SHOW_DEBUG_STEP 
    #define DEBUG_STEP(x) x;
#else 
    #define DEBUG_STEP(x)
#endif


/**
 * Leet Code 82 - If a node is ever duplicated, remove them entirely
 */
ListNode* DeleteDuplicates_DistinctOnly(ListNode* head)
{
    if (head != nullptr)
    {
        ListNode* pPrevious = nullptr;
        ListNode* pCurrent = head;
        ListNode* pNode = nullptr;

        while (pCurrent->next != nullptr)
        {
            if (pCurrent->val == pCurrent->next->val)
            {
                // additionally mark current node to delete after deleting all trailing duplicates. 
                pNode = pCurrent;

                DEBUG_STEP(PrintListVisual("pre-delete-duplicate", head, pCurrent));

                // deleting trailing duplicates
                ListNode* pNext = pCurrent->next;
                pCurrent->next = (pNext != nullptr) ? pNext->next : nullptr;
                delete pNext;
                pNext = nullptr;

                DEBUG_STEP(PrintListVisual("post-delete-duplicate", head, pCurrent));
            }
            else
            {
                if (pNode != nullptr)
                {
                    if (pPrevious != nullptr)
                    {
                        pPrevious->next = pCurrent->next;
                        delete pNode;
                        pNode = nullptr;

                        pCurrent = pPrevious->next;
                        DEBUG_STEP(PrintListVisual("previous found", head, pCurrent));
                        
                    }
                    else // previous is nullptr, promoting new head.
                    {
                        head = pCurrent->next;
                        delete pNode;
                        pNode = nullptr;

                        // old head removed, assign to new head.
                        pCurrent = head;

                        DEBUG_STEP(PrintListVisual("no previous found, promote new head", head, pCurrent));
                    }
                }
                else
                {
                    pPrevious = pCurrent;
                    pCurrent = pCurrent->next;
                    DEBUG_STEP(PrintListVisual("move", head, pCurrent));
                }
            }
        }
        
        // if current node is still marked delete when there is no next node (unable to handle in loop) 
        if (pNode != nullptr)
        {
            // promoting head to last known previous node
            if (pPrevious != nullptr)
            {
                pPrevious->next = nullptr;
                delete pNode;
                pNode = nullptr;
            }
            else // promoting head to nullptr when there is no more previous node
            {
                return nullptr;
            }
            
        }
    }

    return head;
}

/**
 * Leet Code 83 - Remove all duplicate nodes
 */
ListNode* DeleteDuplicates(ListNode* head)
{
    if (head != nullptr)
    {
        ListNode* pCurrent = head;

        while (pCurrent->next != nullptr)
        {
            if (pCurrent->val == pCurrent->next->val)
            {
                DEBUG_STEP(PrintListVisual("pre-delete-duplicate", head, pCurrent));
                ListNode* pNode = pCurrent->next;
                pCurrent->next = pNode->next;
                delete pNode;
                pNode = nullptr;

                DEBUG_STEP(PrintListVisual("post-delete-duplicate", head, pCurrent));
            }
            else
            {
                pCurrent = pCurrent->next;
                DEBUG_STEP(PrintListVisual("move", head, pCurrent));
            }
        }
    }

    return head;
}