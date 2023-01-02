class Solution {
    bool isOperand(string ch)
    {
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
        return false;
        else
            return true;
    }
    
    int compute(int x,int y, string ch)
    {
        if(ch=="+")
            return x+y;
        if(ch=="-")
            return y-x;
        if(ch=="*")
            return x*y;
        else
            return y/x;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it:tokens)
        {
            if(isOperand(it))
            {
                int num=stoi(it);
                st.push(num);
            }
            else
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int ans=compute(x,y,it);
                st.push(ans);
            }
        }        
        return st.top();
    }
};