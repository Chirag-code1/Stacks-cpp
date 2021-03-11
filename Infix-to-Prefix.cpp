#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

int prec(char c){
    
        if(c=='^')
        return 3;
        
        else if(c=='*' || c=='/')
        return 2;
        
        else if(c=='+' || c=='-')
        return 1;
        
        else
        return -1;
        
}

string infixtoPrefix(string s){
    
    reverse(s.begin(),s.end());
    //Now we need to traverse the string in order to make '(' into ')' and '(' to ')'. 
    //Rather, what else we can do is we can write "(" wherever we wrote ")" {in infix to postfix} and ")" at place of "("
    //i.e at line no-36,39, 40 in this paricular code.
    stack<char> st;
    string res;
    
    for(int i=0;i<s.length();i++){
        
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
                while(!s.empty() && st.top()!=')'){
                    res+=st.top();
                    st. pop();
                }
                if(!st.empty()){
                    st.pop();
                }
        }
        else{
            
            while(!st.empty() && prec(s[i])<prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    cout<<infixtoPrefix("(a-b/c)*(a/k-l)")<<endl;

    return 0;
}