#include<bits/stdc++.h>
using namespace std;
void linear_search(int a[],int n)
{
    int temp=-1;
    for(int i=0;i<5;i++)
    {
        if(a[i]==n)
        {
            cout<<"Element is at position :"<<i+1<<endl;
            temp=0;
        }
    }
    if(temp==-1)
    {
        cout<<"Element not found.";
    }
}
int main()
{
    int arr[5]={3,5,2,76,21};
    int n;
    cout<<"Enter number for searching:";
    cin>>n;
    linear_search(arr,n);
    return 0;
}
