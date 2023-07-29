#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=(s+e)/2;

    //length of both array
    int length1=mid-s+1;
    int length2=e-mid;

    //creating array
    int *first=new int[length1];
    int *second=new int[length2];

    int mainindex=s;

    //copy values
    for(int i=0;i<length1;i++){
        first[i]=arr[mainindex++];
    }
    for(int i=0;i<length2;i++){
        second[i]=arr[mainindex++];
    }

    //use merge 2 sort array concept

    int index1=0;
    int index2=0;
    mainindex=s;
    //cheacking which one is lesser and push onto the array
    while(index1<length1 && index2<length2){
        if(first[index1]<second[index2]){
            arr[mainindex++]=first[index1++];
        }
        else{
            arr[mainindex++]=second[index2++];
        }
    }
    while(index1<length1){
        arr[mainindex++]=first[index1++];
    }
    while (index2<length2)
    {
        arr[mainindex++]=second[index2++];
    }
    delete []first;
    delete []second;
    
}
void Merge_sort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(e+s)/2;

    //sort left part
    Merge_sort(arr,s,mid);

    //sort right part
    Merge_sort(arr,mid+1,e);

    //combine subarray
    merge(arr,s,e);
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
    Merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
