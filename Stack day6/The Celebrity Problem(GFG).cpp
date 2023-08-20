#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    bool knows(vector<vector<int>> & m ,int a,int b,int n){
        if(m[a][b] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        stack<int> s;
        
        //step 1 push all element in stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //step 2 slecting potential candidate
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(m,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //checking candidate is celebirity or not
        int ans = s.top();
        
        //checking row all element is zero or not
        int zerocount = 0;
        
        for(int i = 0;i<n;i++){
            if(m[ans][i] == 0){
                zerocount++;
            }
        }
        
        if(zerocount != n){
            return -1;
        }
        
        //checking col all element is 1 except diognal
        int onecount = 0;
        
        for(int i = 0;i<n;i++){
            if(m[i][ans] == 1){
                onecount++;
            }
        }
        
        if(onecount != n-1){
            return -1;
        }
        
        return ans;
        
    }
};

int main()
{
    int t;
    cout<<"Enter no of test case:";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter size of the matrix:";
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        cout<<"Enter elements:";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
