#include <bits/stdc++.h> 
using namespace std;
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<int> st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool redudant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top =='-' || top == '*' ||top == '/'){
                        redudant = false;
                    }
                    st.pop();
                }
                if (redudant) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main(){
    cout<<"Enter string:";
    string s;
    cin>>s;
    bool flag = findRedundantBrackets(s);
    if(flag){
        cout<<"yes, there is redundant bracket.";
    }
    else{
        cout<<"There is no extra brackt.";
    }
}
