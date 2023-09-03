#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node*prev;
    Node(int data){
        this->data = data;
        this->next=NULL;
        this->prev = NULL;
    }
};
void insertAtHead(Node*&head,Node*&tail,int d){
    Node*temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node*&tail,Node*&head, int d){
    Node*temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}void insertAtPosition(Node*&tail,Node*&head, int position, int d){
    Node*temp = head;
    int c = 1;
    if(position==1){
        insertAtHead(head,tail, d);
    }
    while(c<position-1){
        temp = temp->next;
        c ++ ;
    }if(temp->next==NULL){
        insertAtTail(tail,head, d);
    }
    Node*nodetoinsert = new Node(d);
    
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev  = temp;
    

}
void print(Node*head){
    Node*temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
    }
}
int getLength(Node*head){
    if(head==NULL){
        return 0;
    }
    int c = 1;
    Node*temp = head;
    while(temp->next!=NULL){
        c++;
        temp = temp->next;
    }return c;
}
void deleteNode(Node*&head, int position){
    if(position==1){
        Node*temp = head;
        temp->next->prev = NULL;
        head = temp->next;temp->next=NULL;
    
    }else{
        Node*curr = head;
        Node*prev = NULL;
        int c = 0;
        while(c<position-1){
            prev = curr;
            curr = curr->next;
            c++;
        }prev->next=curr->next;
        curr->next=NULL;delete curr;
    }
    
}
int main(){
     Node* head = NULL;
    Node* tail = NULL;

    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(head,tail,11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(head,tail, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(head,tail, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    deleteNode(head, 7);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;





    return 0;
}
