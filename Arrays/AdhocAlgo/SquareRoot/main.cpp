#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int number=484;
    float sqrtNo,temp;
    sqrtNo=number/2;
    while(sqrtNo!=temp)
    {
        temp=sqrtNo;
        sqrtNo=(number/temp +temp)/2;
        if(sqrtNo==temp)
            break; //it will stop one iteration
    }
    cout << sqrtNo << endl;
    return 0;
}
