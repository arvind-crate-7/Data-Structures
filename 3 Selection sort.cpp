#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    cout<<"Enter element of the array:";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j]){
                min=j;
            }
            
        }
        swap(arr[min],arr[i]);
    }
    cout<<"The sorted by selection sort:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
