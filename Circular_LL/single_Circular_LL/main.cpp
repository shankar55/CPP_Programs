#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
void create_LL(struct node **head,int num)
{
    struct node *new_node,*ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(*head==NULL)
    {
        new_node->next=new_node;
        *head=new_node;
    }else
    {
        ptr=*head;
        while(ptr->next!=*head)
            ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=*head;
    }
}
void sortedInsert(struct node **head,struct node *new_node)
{
    struct node *curr=(*head);
    if(curr==NULL)
    {
        new_node->next=new_node;
        *head=new_node;
    }
    else if(curr->data>new_node->data)
    {
        while(curr->next!=(*head))
            curr=curr->next;
        curr->next=new_node;
        new_node->next=(*head);
        (*head)=new_node;
    }else
    {
        while(curr->next!=(*head)&&curr->next->data<new_node->data)
            curr=curr->next;
        new_node->next=curr->next;
        curr->next=new_node;
    }
}
void printList(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}
void reverse(struct node **head)
{
    struct node *curr=*head;
    struct node *prev,*next;
    next=NULL;
    prev=NULL;
    do
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }while(curr!=(*head));
    (*head)->next=prev;
    *head=prev;
}
int main()
{
    int n;
    int num;
    struct node *head=NULL;
    struct node *temp;
    cout<<"Enter Size of Circular Linked List: ";
    cin>>n;
    cout<<"Enter Elements of Linked List: ";
    for(int i=0;i<n;i++)
    {
        cin>>num;
        temp=new node(num);
        sortedInsert(&head,temp);
    }
   // reverse(&temp);
    printList(head);
    return 0;
}
