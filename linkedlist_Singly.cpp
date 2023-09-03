#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;;
            this->next=NULL;
        }
    }

};
void insertAtHead(Node*&head, int data){
    Node*temp = new Node(data);
    temp->next = head;
    head = temp;

}
void insertAtTail(Node*&tail, int data){
    Node*temp = new Node(data);
    tail->next = temp;
    tail = temp;
 }void insertAtPostion(Node*&head, int data, int p){
     Node*temp = head;
    if(p == 1){
         insertAtHead(head, data);
   } 
     else{
         int c = 1;
       
         while(c<p-1){
             temp = temp->next;
             c = c + 1;
         }
         Node*nodetoinsert = new Node(data);
         nodetoinsert->next = temp->next;
         temp->next = nodetoinsert;


     }
     if(temp->next == NULL){
         insertAtTail(temp, data);
     }
 }
void deleteNode(Node*&head, int position){
    if(position==1){
        Node*temp =head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node*curr = head;
        Node*prev = NULL;
        int c = 1;
        while(c<position){
            prev = curr;
            curr = curr->next;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}
void traverse(Node*&head){
    Node*temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
Node* head = new Node(10);


insertAtHead(head, 12);
insertAtHead(head, 15);
traverse(head);
cout<<"\n";
insertAtHead(head, 10);
traverse(head);
deleteNode(head, 3);
cout<<"\n";
traverse(head);


}
