#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[],int left,int right,int x)
{
    while(left<=right)
    {
        int mid=(right+left)/2;
        if(a[mid]==x)
        {
            return  mid;
        }
        else if(a[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[10],output,n;
    cout<<"Enter 10 numbers in accending order:"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter number you wana search:";
    cin>>n;
    output=binary_search(arr,0,9,n);
    
    if(output==-1)
    {
        cout<<"No element found.";
    }
    else
    {
        cout<<"Element at position:"<<output+1<<endl;
    }
}
