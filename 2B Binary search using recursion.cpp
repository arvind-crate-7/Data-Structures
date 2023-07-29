#include<iostream>
using namespace std;
// void print(int arr[],int size){
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// bool BinarySearch_recursion(int *arr,int size,int k){
//     print(arr,size);
//     if(size==0){
//         return 0;
//     }
//     int s=0;
//     int e=size-1;
//     int mid=s+(e-s)/2;
//     if(arr[mid]==k){
//         return 1;
//     }
//     else if(arr[mid]<k){
//         int remaining_array=BinarySearch_recursion(arr+mid+1,size/2,k);
//         return remaining_array;
//     }
//     else{
//         int remaining_array=BinarySearch_recursion(arr,size/2,k);
//         return remaining_array;
//     }
// }

//Another method

// for printing of array


void print(int arr[],int s,int e){
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


Binary search


bool BinarySearch_recursion(int arr[],int s,int  e,int k){
    print(arr,s,e);
    if(s>e){
        return 0;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k){
        return 1;
    }
    else if(arr[mid]<k){
        return BinarySearch_recursion(arr,mid+1,e,k);
        
    }
    else{
        return BinarySearch_recursion(arr,s,mid-1,k);
    }
}
int main(){
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    cout<<"Enter element in sorted order:";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element for searching:";
    int k;
    cin>>k;
    //for second function use this
    //bool ans=BinarySearch_recursion(arr,0,n-1,k);
    bool ans=BinarySearch_recursion(arr,n,k);
    if(ans){
        cout<<"Element is present.";
    }
    else{
        cout<<"Element is not present.";
    }

}
