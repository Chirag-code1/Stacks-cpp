//Basic operations on Stacks:
#include <iostream>
using namespace std;
#define n 100

class stack{
    int* arr;
    int top;
    
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    
    void push(int x){
        
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        
    else{
        top++;
        arr[top]=x;
    }
    }
    
    void pop(){
        if(top==-1){
            cout<<"No element to pop"<<endl;;
            return;
        }
        else{
            top--;
        }
    }
        
    int Top(){
        if(top==-1){
            cout<<"Stack overflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    
    bool empty(){
        return top==-1;
    }

    
    
};


int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
   cout<<st.Top()<<endl; //4
   st.pop(); //1 2 3 remained.
   cout<<st.Top()<<endl; //3
   st.pop(); //3 poped.
   st.pop(); //2 poped.
   st.pop(); //1 poped.
   st.pop();
   cout<<st.empty()<<endl; //1

    return 0;
}
