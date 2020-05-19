//
//  main.cpp
//  Add_Two_Numbers_LL
//
//  Created by Jacqueline Dagdigian on 5/19/20.
//  Copyright © 2020 Jacqueline Dagdigian. All rights reserved.
//
/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* result = new ListNode();
    auto dummyResult = result;
    
    if(l1 == nullptr || l2 == nullptr)
        return (l1 == nullptr ? l2 : l1);

    while(l1 != nullptr || l2 != nullptr)
    {
        if(l1 == nullptr)
            l1 = new ListNode();
        if(l2 == nullptr)
            l2 = new ListNode();
        
        int sum = l1->val + l2->val + dummyResult->val;
        
        if(l1->next != nullptr || l2->next != nullptr || sum/10 > 0)
        {
            dummyResult->next = new ListNode(sum/10);
            dummyResult->val = sum%10;
            dummyResult->next->val = sum/10;
        }
        else
        {
            dummyResult->val = sum;
        }
        
        dummyResult = dummyResult->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return result;
}

int main(int argc, const char * argv[])
{
    ListNode* num1 =  new ListNode(9, new ListNode(4, new ListNode(4, new ListNode(9, new ListNode(2)))));
    ListNode* num2 =  new ListNode(5, new ListNode(6, new ListNode(6)));
    ListNode* result = addTwoNumbers(num1, num2);
    
    cout << "Result: ";
    while(result != nullptr)
    {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}



