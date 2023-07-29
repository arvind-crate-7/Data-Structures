#include<bits/stdc++.h>
using namespace std;
//Insertion sor
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        //comparing element to her back element
        for(;j>=0;j--){
            //cheackeng element is greater or not
            if(arr[j]>temp){
                //shifting if that element is greater
                arr[j+1]=arr[j];
            }
            else{
                //if that element is not greater element than as we know array starting is sorted thats why we break 
                break;
            }
        }
        //j+1 because time of loop it chek again and that time j is subtracted by 1 thats why i increase her size
        arr[j+1]=temp;
    }
}
int main(){
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    cout<<"Enter element";
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    insertionSort(n,v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
