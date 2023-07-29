#include<iostream>
using namespace std;
bool LinearSearch_recursion(int *arr,int size,int k){
    if(size==0){
        return 0;
    }
    if(arr[0]==k){
        return 1;
    }
    else{
        int remaning_part=LinearSearch_recursion(arr+1,size-1,k);
        return remaning_part;
    }
}
int main(){
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    cout<<"Enter element:";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element for searching:";
    int k;
    cin>>k;
    bool ans=LinearSearch_recursion(arr,n,k);
    if(ans){
        cout<<"Element is present.";
    }
    else{
        cout<<"Element is not present.";
    }

}
