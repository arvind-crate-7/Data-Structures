class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //base case, recursion ends when NULL is reached
        if (head == NULL) return NULL;

        //the node has to be removed -> it is skipped during the iteration
        if (head->val == val) return removeElements(head->next, val);

        //the node doesn't have to be skipped -> the rest of the list has 
        //to be joined to the node
        head->next = removeElements(head->next, val);
        return head;
        
    }
};


                                    //Approach 2

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        ListNode* temp = head;
        ListNode* prev = head;
        while(temp != NULL){
            if(temp == head && temp -> val == val){
                ListNode* delete1 = temp;
                temp = temp -> next;
                delete delete1;
                head = temp;
                prev = head;
            }
            else if(temp -> val == val){
                ListNode* delete1 = temp;
                prev -> next = temp -> next;
                temp = temp -> next;
                delete delete1;
            }
            else{
                prev = temp;
                temp = temp -> next;
            }
        }
        return head;
    }
};
