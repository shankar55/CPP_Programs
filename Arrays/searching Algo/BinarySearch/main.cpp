#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Binary Search
//Time Complexity -->O(log n)
void solve()
{
     cout<<"BINARY SEARCH :"<<endl;
    int arr[]={10, 20, 30, 60, 50, 80, 90, 110, 130, 170};
    int target=110,pos,found=0;
    cout<<"The target element is: "<<target<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Size of array: "<<n<<endl;
    int low=0,high=n-1;
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            pos=mid;
            found=1;
            break;
        }
        else if(arr[mid]<target)
        low=mid++;
        else
            high=mid--;
    }
    if(found==1)
        cout<<"Element found at: "<<pos;
    else
        cout<<"Element not found in the array";

}
int main()
{
    time_t start,end;
    time(&start); // start time
    // {your code goes here}
    solve();
    time(&end);  // end time
    double time_taken = double(end - start); // calulate diffrence
    cout<<"\nTime taken to execute: "<<time_taken;
    return 0;
}
