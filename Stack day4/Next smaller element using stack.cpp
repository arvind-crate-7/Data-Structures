#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    ans[n-1] = -1;
    int min = arr[n-1];
    for(int i = n-2;i >= 0;i--){
      if(arr[i] > min){
        ans[i] = min;
      }
      else{
        ans[i] = -1;
      }
      if(arr[i] < arr[i+1]){
        min = arr[i];
      }
    }
    return ans;
}

int main(){
    cout<<"Enter size of the array:";
    int n;
    cin>>n;
    vector<int> v;
    cout<<"Enter numbers:";
    for(int i = 0;i<n;i++){
        int n1;
        cin>>n1;
        v.push_back(n1);
    }
    auto res = nextSmallerElement(v,n);
    for(auto x :res){
        cout<<x<<" ";
    }
}
