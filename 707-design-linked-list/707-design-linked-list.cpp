class node{
    public:
    int val;
    node* next;
    node(int val){
        this->val=val;
    next=NULL;
    }
};
class MyLinkedList {
public:
int size=0;
node* head=new node(0);
MyLinkedList() {
    
}
int get(int index) {
    if(index<0 || index>=size) return -1;
 node* temp=head->next;
    for(int i=0;i<index;i++)
        temp=temp->next;
            return temp->val;
}
void addAtHead(int val) {
  node* temp=head->next;
    head->next=new node(val);
    head->next->next=temp;
    size++;
}
void addAtTail(int val) {
    node* temp=head;
    while(temp->next!=0) temp=temp->next;
    temp->next=new node(val);
    size++;
}
void addAtIndex(int index, int val) {
   if(index>size) return;
    node* temp=head;
    for(int i=0;i<index;i++) temp=temp->next;
    node* temp1=temp->next;
    temp->next=new node(val);
    temp->next->next=temp1;
    size++;
}
void deleteAtIndex(int index) {
     if(index<0 || index>=size) return ;
    node* temp=head;
    for(int i=0;i<index;i++) temp=temp->next;
    node* temp1=temp->next;
    temp->next=temp1->next;
    temp1->next=NULL;
    size--;
    delete temp1;
}
};