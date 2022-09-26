#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Don't Enter any braces it will show Invalid Expression
#define MAX 100
char st[MAX];
int top=-1;
char infix[100],postfix[100],temp[100];
void push(char st[],char ch)
{
    if(top==MAX-1)
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top]=ch;
    }
}
char pop(char st[])
{
    char ch;
    if(top==-1)
        cout<<"stack Underflow"<<endl;
    else
    {
        ch=st[top];
        top--;
    }
    return ch;
}
int getpriority(char op)
{
    if(op=='*'||op=='%'||op=='/')
        return 1;
    else if(op=='+'||op=='-')
        return 0;
    return -1;
}
void InfixToPostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(st,source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((top!=-1)&&(source[i]!='('))
            {
                target[j]=pop(st);
                j++;
            }
            if(top==-1)
            {
                cout<<"Incorrect Expression"<<endl;
                exit(1);
            }
            temp=pop(st);
            i++;
        }
        else if(isdigit(source[i])||isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
        {
            while((top!=-1)&&(st[top]!='(')&&(getpriority(st[i])>getpriority(source[i])))
            {
                target[j]=pop(st);
                j++;
            }
            push(st,source[i]);
            i++;
        }
        else
        {
            cout<<"Invalid Element in Expression"<<endl;
            exit(1);
        }
    }
    while((top!=-1)&&(st[top]!='('))
    {
        target[j]=pop(st);
        j++;
    }
    target[j]='\0';
}
void reverse(char str[])
{
    int len,i=0,j=0;
    len=strlen(str);
    j=len-1;
    while(j>=0)
    {
        if(str[i]=='(')
            temp[i]=')';
        else if(str[i]==')')
            temp[i]='(';
        else
            temp[i]=str[j];
        i++;
        j--;
    }
    temp[i]='\0';
}
int main()
{
    cout<<"Enter any expression: ";
    cin>>infix;
    reverse(infix);
    strcpy(postfix,"");
    InfixToPostfix(infix,postfix);
    cout<<"The Postfix expression is: "<<postfix<<endl;
    //Using the same logic we can convert Infix to Prefix
    strcpy(temp,"");
    reverse(postfix);
    cout<<"The Prefix expression is: "<<temp<<endl;
    return 0;
}
