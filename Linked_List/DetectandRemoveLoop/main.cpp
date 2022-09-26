#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
struct node *head=NULL;
void create_LL()
{
    int num;
    cin>>num;
    struct node *new_node,*ptr;
    new_node=new node(num);
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }else{
        ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
    }
}
int countNodesinLoop(struct node *n)
{
    int res=1;
    struct node *temp=n;
    while(temp->next!=n)
    {
        res++;
        temp=temp->next;
    }
    return res;
}
int detectLoop(struct node *head)
{
    struct node *slow_ptr,*fast_ptr;
    slow_ptr=fast_ptr=head;
    while(slow_ptr&&fast_ptr&&fast_ptr->next)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if(slow_ptr==fast_ptr)
            return countNodesinLoop(slow_ptr);
    }
    return 0;
}
void hashandRemove(struct node *head)
{
   if(head==NULL||head->next==NULL)
    return ;
   struct node *slow_ptr,*fast_ptr;
   struct node  *ptr1=head,*ptr2=NULL;
   slow_ptr=fast_ptr=head;
   while(fast_ptr&&fast_ptr->next)
   {
       if(slow_ptr==fast_ptr)
       {
        //ptr2 is node where
        //slow and fast are meeting
        ptr2=slow_ptr;
        break;
       }
       slow_ptr=slow_ptr->next;
       fast_ptr=fast_ptr->next->next;
   }
   //if there is no cycle
   if(ptr2==NULL)
    return ;
    //start ptr1 from head and ptr2 from meeting pt of slow
    //and fast, then point where ptr1 and ptr2 will meet
    //will be starting point of loop
   while(ptr1!=ptr2)
   {
       ptr1=ptr1->next;
       ptr2=ptr2->next;
   }
   //start traversing from starting of loop till
   //last node of loop and point it's next pointer to null;
       struct node *temp=ptr1;
       while(temp->next!=ptr1){
           temp=temp->next;
       }
       temp->next=NULL;
}
void print_LL()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main()
{
    int n;
    cout<<"Enter size of LL:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        create_LL();
    }
    print_LL();
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
    int flag=detectLoop(head);
    cout<<"No of Nodes in Loop: "<<flag;
    hashandRemove(head);
    print_LL();
    return 0;
}
