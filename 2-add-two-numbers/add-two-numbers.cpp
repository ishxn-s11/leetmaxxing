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

/*
Optimal Approach

Instead Prior Summation And Convertion Operation

For Every Pair Of Digits: sum=digit1+digit2+carry
digit=sum%10
carry=Floor(sum/10)

Time Complexity: O(max(n,m))
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*res=new ListNode(0);
        ListNode*curr=res;
        int carry=0;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum=carry;

            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }

            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
        }

        return res->next;
    }
};