#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <functional>

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

void PrintListNodeDetail(const ListNode& node)
{
    std::cout << "Value:    " << node.val << std::endl;
    std::cout << "Addr :    " << &node << std::endl;
    std::cout<<  "NextAddr: " << &node.next << std::endl;
}

void PrintListDetail(const ListNode* const head)
{
    if (head != nullptr)
    {
        const ListNode* pCurrent = head;
        while (pCurrent != nullptr)
        {
            PrintListNodeDetail(*pCurrent);
            pCurrent = pCurrent->next;
        }
    }
}

void PrintListVisual(const std::string& name, const ListNode* head)
{
    std::cout << name << ":";
    if (head != nullptr)
    {
        const ListNode* pCurrent = head;
        while (pCurrent != nullptr)
        {
            std::cout << pCurrent->val;
            if (pCurrent->next != nullptr)
            {
                std::cout << " -> ";
            }
            else
            {
                std::cout << " :| ";
            }
            pCurrent = pCurrent->next;
        }
        std::cout << std::endl;
    }

    else
    {
        std::cout << " :| " << std::endl;
    }
}

void PrintListVisual(const std::string& name, const ListNode* head, const ListNode* current)
{
    std::cout << name << ":";
    if (head != nullptr)
    {
        const ListNode* pCurrent = head;
        while (pCurrent != nullptr)
        {
            const bool showMarker = (current == pCurrent);
            if (showMarker)
            {
                std::cout <<"[";
            }

            std::cout << pCurrent->val;

            if (showMarker)
            {
                std::cout << "]";
            }

            if (pCurrent->next != nullptr)
            {
                std::cout << " -> ";
            }
            else
            {
                std::cout << " :| ";
            }
            
            pCurrent = pCurrent->next;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << " :| " << std::endl;
    }
}

static void MakeTest(std::vector<int>& data, const char* testName, const std::function<ListNode* (ListNode*)>& testFunction)
{
    ListNode* pInstance = CreateFrom(data);
    PrintListVisual(std::format("{}", testName), pInstance);

    if (testFunction != nullptr)
    {
        ListNode* pResult = testFunction(pInstance);
        PrintListVisual("Solution", pResult);

        if (pResult != nullptr)
        {
            delete pResult;
        }
    }
    else
    {
        delete pInstance;
    }
    

    std::cout<<std::endl<<std::endl;
}