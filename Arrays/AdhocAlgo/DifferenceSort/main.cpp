#include <iostream>
#include<bits/stdc++.h>


using namespace std;
void rearrange(int arr[],int n,int x)
{
    /*
        We can send the value x into
        lambda expression as
        follows: [capture]()
        {
            //statements
            //capture value can be used inside
        }
    */
    stable_sort(arr,arr+n,[x](int a,int b){
                if(abs(a-x)<abs(b-x))
                   return true;
                else
                    return false;
                }
                );
}

int main()
{
    int arr[] = { 10, 5, 3, 9, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    rearrange(arr,n,x);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
