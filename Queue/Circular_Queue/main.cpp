#include <iostream>
#include<bits/stdc++.h>

using namespace std;
struct node {
    int data;
    struct node *next;
};
struct Queue
{
    struct node *front,*rear;
};
void enQueue(struct Queue *q,int value)
{
    struct node *temp=new node;
    temp->data=value;
    if(q->front==NULL)
        q->front=temp;
    else
        q->rear->next=temp;
    q->rear=temp;
    q->rear->next=q->front;
}
int deQueue(struct Queue *q)
{
    if(q->front==NULL)
    {
        cout<<"Queue is empty";
        return INT_MIN;
    }
    int value;
    if(q->front==q->rear)
    {
        value=q->front->data;
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else
    {
        struct node *temp=q->front;
        value=temp->data;
        q->front=q->front->next;
        q->rear->next=q->front;
        free(temp);
    }
    return value;
}
void displayQueue(struct Queue *q)
{
    struct node *temp=q->front;
    while(temp->next!=q->front)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}
int main()
{
     // Create a queue and initialize front and rear
    Queue* q = new Queue;
    q->front = q->rear = NULL;

    // Inserting elements in Circular Queue
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);

    // Display elements present in Circular Queue
    displayQueue(q);

    // Deleting elements from Circular Queue
    cout<<"\nDeleted value: "<<deQueue(q);
    cout<<"\nDeleted value: "<<deQueue(q);

    // Remaining elements in Circular Queue
    displayQueue(q);

    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);
    return 0;
}
