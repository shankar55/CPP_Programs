#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//In this problem, they given left and right brackets count we need to count how many valid brackets can form
int main()
{
    int l,r;
    cin>>l>>r;
    int n=l>r?r:l;
    cout<<n*(n+1)/2;
    return 0;
}
