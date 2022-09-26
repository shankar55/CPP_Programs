#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/'||op=='%')
        return 2;
    else if(op=='^')
        return 3;
    return 0;
}
int applyOP(int a,int b,char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
    }
}

int evaluate(string exp)
{
    int i;
    stack<char>ops;
    stack<int>values;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]==' ') continue;
        else if(exp[i]=='(')
        {
            ops.push(exp[i]);
        }
        else if(isdigit(exp[i]))
        {
            int val=0;
            while(i<exp.size()&&isdigit(exp[i]))
            {
                val=val*10+(exp[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if(exp[i]==')')
        {
            while(!ops.empty()&&ops.top()!='(')
            {
                int value2=values.top();
                values.pop();
                int value1=values.top();
                values.pop();
                char op=ops.top();
                ops.pop();
                values.push(applyOP(value1,value2,op));
            }
            if(!ops.empty())
                ops.pop();
        }
        else
        {
            while(!ops.empty()&&precedence(ops.top())>=precedence(exp[i]))
            {
                int value2=values.top();
                values.pop();
                int value1=values.top();
                values.pop();
                char op=ops.top();
                ops.pop();
                values.push(applyOP(value1,value2,op));
            }
            ops.push(exp[i]);
        }
    }
    while(!ops.empty())
    {
        int value2=values.top();
        values.pop();
        int value1=values.top();
        values.pop();
        char op=ops.top();
        ops.pop();
        values.push(applyOP(value1,value2,op));
    }
    return values.top();
}
int main()
{
    cout << evaluate("10 + 2 * 6") << endl;
    return 0;
}
