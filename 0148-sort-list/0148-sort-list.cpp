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
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* Temp=head;
        while(Temp!=NULL){
            v.push_back(Temp->val);
            Temp=Temp->next;
        }
        sort(v.begin(),v.end());
        int i=0;
        Temp=head;
        while(Temp!=NULL){
            Temp->val=v[i];
            i++;
            Temp=Temp->next;
        }
        return head;
    }
};

class Solution {
    ListNode* split(ListNode* head){
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            if(fast!=nullptr){
                slow=slow->next;
            }
        }
        ListNode*temp=slow->next;
        slow->next=nullptr;
        return temp;
    }
    ListNode* merge(ListNode* first,ListNode* second){
        if(first==nullptr) return second;
        if(second==nullptr) return first;
        if(first->val < second->val){
            first->next=merge(first->next, second);
            return first;
        } else{
            second->next = merge(first, second->next);
            return second;
        }
    }
    ListNode*mergesort(ListNode* head){
        if (head == nullptr || head->next == nullptr)
        return head;
        ListNode *second = split(head);
        head = mergesort(head);
        second = mergesort(second);
        return merge(head, second);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};


