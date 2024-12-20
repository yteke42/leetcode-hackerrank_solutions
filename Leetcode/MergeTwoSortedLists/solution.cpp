#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2; //return the other list if one of them doesnt exists
    if (!list2) return list1;

    ListNode* dummy = new ListNode(); 
    ListNode* tail = dummy;

    while (list1 && list2) { //continue until one of the lists is nullptr
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;}
    if (list2) {
        tail->next = list2;}
    

    ListNode* mergedList = dummy->next; //point to the head of the merged list

    delete dummy; // Clean up the dummy node
    return mergedList;
}

