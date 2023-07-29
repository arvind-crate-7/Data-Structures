#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    //This is for worst case 
    //time complexity is O(n^2)


    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }

    //this is best casse
    //in any round there is no swap of element than it will sorted thats why we terminat loop in between
    // time complexity is O(n)

    for(int i=1;i<n;i++){
        bool swaped=false;
        for(int j=0;j<n-i;j++){
            //loop run n-i because last element in each round is sort thats why 
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped=true;
            }
        }
        if(swaped==false){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
}
