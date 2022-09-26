#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
}Node;
Node *head=NULL;
void push(Node **head_ref,int num){
    Node *new_node;
    new_node=new node(num);
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
void print_LL(Node *node)
{
    Node *temp=node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
Node *reverse(Node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    Node *rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}
Node *addTwoList(Node *first,Node *second){
    Node *res,*prev,*temp;
    res=prev=temp=NULL;
    int carry=0,sum;
    while(first!=NULL||second!=NULL)
    {
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=(sum>=10?1:0);
        sum=sum%10;
        temp=new node(sum);
        if(res==NULL)
            res=temp;
        else
            prev->next=temp;
        if(first)
            first=first->next;
        if(second)
            second=second->next;
        if(carry>0)
            temp->next=new node(carry);
        return res;
    }
}
int main()
{
    Node *first=NULL,*second=NULL;
    Node *result;
    int A[]={6,4,9,5,7};
    int B[]={4,8};
    int n1=sizeof(A)/sizeof(A[0]);
    int n2=sizeof(B)/sizeof(B[0]);
    for(int i=0;i<n1;i++)
    {
        push(&first,A[i]);
    }
    for(int i=0;i<n2;i++)
    {
        push(&second,B[i]);
    }
    first=reverse(first);
    second=reverse(second);
    print_LL(first);
    print_LL(second);
    result=addTwoList(first,second);
    print_LL(result);
    return 0;
}
