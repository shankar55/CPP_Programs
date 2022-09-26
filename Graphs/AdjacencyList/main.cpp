#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    char vertex;
    struct node *next;
};
struct node * gnode;
void displayGraph(struct node *adj[],int no_of_nodes);
void createGraph(struct node *adj[],int no_of_nodes);
void deleteGraph(struct node *adj[],int no_of_nodes);
int main()
{
    int no_of_nodes,i;
    struct node * adj[10];
    cout<<"Enter no of nodes in Graph: ";
    cin>>no_of_nodes;
    for(i=0;i<no_of_nodes;i++)
        adj[i]=NULL;
    createGraph(adj,no_of_nodes);
    cout<<endl<<"\nThe Graph is :"<<endl;
    displayGraph(adj,no_of_nodes);
    deleteGraph(adj,no_of_nodes);
    return 0;
}
void createGraph(struct node * adj[],int no_of_nodes)
{
    struct node * new_node,*last;
    int i,j,n,val;
    for(i=0;i<no_of_nodes;i++)
    {
        last=NULL;
        cout<<"\nEnter the no of neighbours of "<<i<<": ";
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cout<<"\nEnter neighbour "<<j<<" of "<<i<<": ";
            cin>>val;
            new_node=(struct node *)malloc(sizeof(struct node));
            new_node->vertex=val;
            new_node->next=NULL;
            if(adj[i]==NULL)
                adj[i]=new_node;
            else
                last->next=new_node;
            last=new_node;
        }
    }
}
void displayGraph(struct node *adj[],int no_of_nodes)
{
    struct node *ptr;
    for(int i=0;i<no_of_nodes;i++)
    {
        cout<<"\n The neighbour nodes of "<<i<<"are : ";
        ptr=adj[i];
        while(ptr!=NULL)
        {
            int val=ptr->vertex;
            cout<<val<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
void deleteGraph(struct node *adj[],int no_of_nodes)
{
    struct node *temp,*ptr;
    for(int i=0;i<no_of_nodes;i++)
    {
        ptr=adj[i];
        while(ptr!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
            free(temp);
        }
        adj[i]=NULL;
    }
}
