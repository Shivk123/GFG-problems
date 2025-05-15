//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    int prec(char c) {
      if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;
    }
    bool check_op(char c){
        return(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'|| c=='('|| c==')' );
    }
    
  public:
    string infixToPostfix(string& s) {
        string ans;
        stack<char> st;
        
        for(char c: s){
            if(!check_op(c)){
                ans+=c;
            }
            else if(c=='(')st.push('(');
            else if(c==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && prec(c)<=prec(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.
//   Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends