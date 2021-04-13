#include <iostream>
#include<stack>
using namespace std;

void reverseString(string s){
    
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' '&& i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main()
{
    string s="Hey, how are you doing?";
    
    //Logic: we will check for the blank spaces, if we get any then we will push that word in stack & after doing 
    //it with every word. we will pop them and print them.
    reverseString(s);
    
    return 0;

}
