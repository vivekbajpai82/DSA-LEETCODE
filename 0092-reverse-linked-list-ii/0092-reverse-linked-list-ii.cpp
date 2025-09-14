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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        int i=0;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
            i++;
        }
        while (left < right) {
            swap(v[left - 1], v[right - 1]);
            left++;
            right--;
        }
        i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=v[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};