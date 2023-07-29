#include<iostream>
using namespace std;
int partion(int arr[],int s,int e){
    int pivot=arr[s];

    //counting lesser value of pivot
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    //place pivot element in right place

    int pivotindex=s+cnt;
    swap(arr[pivotindex],arr[s]);

    //left ko arrange like all element which present left of the pivot is lesser
    //and all element which is right of the pivot is greater 
    int i=s,j=e;
     while(i<pivotindex && j>pivotindex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
     }
     return pivotindex;
}
void Quick_Sort(int *arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }

    //partion karne pe
    int p=partion(arr,s,e);

    //leftpart sort
    Quick_Sort(arr,s,p-1);

    //right part sort
    Quick_Sort(arr,p+1,e);
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
    Quick_Sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
