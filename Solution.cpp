struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        unordered_map<int,int>m;
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            if(m.find(curr->data)!=m.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next; 
            }
            else{
                m[curr->data]++;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
