#include <bits/stdc++.h> 
#include <stack>
#include <math.h>

using namespace std; 

int prefixEvaluate(string s) {
    
	stack<int> operendStack; 

	for (int i = s.size()-1; i >= 0; i--) { 

		if (s[i]>='0' && s[i]<='9') 
			operendStack.push(s[i] - '0'); 
		else { 
			int o1 = operendStack.top(); 
			operendStack.pop(); 
			int o2 = operendStack.top(); 
			operendStack.pop(); 
			if( s[i] == '+')
			    operendStack.push(o1 + o2);
			else if( s[i] == '-')
			    operendStack.push(o1 - o2);
		    else if( s[i] == '*')
			    operendStack.push(o1 * o2);
			else if( s[i] == '/')
			    operendStack.push(o1 / o2);
			    else if( s[i] == '^')
			    operendStack.push(pow(o1,o2));
			else{
			    cout<<"Invalid Expression"; 
			    return -1; 
			}
		} 
	} 
	return operendStack.top(); 
} 

int main() 
{ 
	string s = "-+7*45+20"; 
	cout<<"The result of evaluation of expression "<<s<<" is "<<prefixEvaluate(s); 
	return 0; 
}
