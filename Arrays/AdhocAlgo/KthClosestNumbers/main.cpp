#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int findCrossOver(int arr[],int low,int high,int x)
{
    if(arr[high]<=x)
        return high;
    if(arr[low]>x)
        return low;
    int mid=(low+high)/2;
    if(arr[mid]<=x&&arr[mid+1]>x)
        return mid;
    if(arr[mid]<x)
        return findCrossOver(arr,mid+1,high,x);
    return findCrossOver(arr,low,mid-1,x);
}
void printKclosest(int arr[],int x,int k,int n)
{
    int l=findCrossOver(arr,0,n-1,x);
    int r=l+1;
    int count=0;
    if(arr[l]==x) l--;
    while(l>=0&&r<n&&count<k)
    {
        if(x-arr[l]<arr[r]-x)
            cout<<arr[l--]<<" ";
        else
            cout<<arr[r++]<<" ";
        count++;
    }
    while(l>=0&&count<k)
    {
     cout<<arr[l--]<<" ";
     count++;
    }
    while(r<n&&count<k)
    {
     cout<<arr[r++]<<" ";
     count++;
    }

}
int main()
{
    int arr[] ={12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 35, k = 4;
    printKclosest(arr, x, k, n);
    return 0;
}
