#include<iostream>
using namespace std;
void bubble_sort(int* arr,int n){
    if(n==0 || n==1){
        return ;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble_sort(arr,n-1);
}
int main()
{
    int n;
    cout<<"Enter Size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter Element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
