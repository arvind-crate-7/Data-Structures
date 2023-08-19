#include<iostream>
#include<stack>
using namespace std;
bool isValidParenthesis(string s)
{
    bool flag = true;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
              char top = st.top();
              if ((top == '(' && ch == ')')|| (top == '{' && ch == '}')
              || (top == '[' && ch == ']')){
                  st.pop();
              }
              else{
                  flag = false;
                  break;
              }
            }
            else{
                flag = false;
                break;
            }
        }
    }
    
    if(st.empty() && flag){
        return true;
    }
    return flag;
}

int main(){
    string str;
    cout<<"Enter parantheses:";
    cin>>str;
    bool valid = isValidParenthesis(str);
    if(valid){
        cout<<"Balanced.";
    }
    else{
        cout<<"Not Balanced.";
    }
}
