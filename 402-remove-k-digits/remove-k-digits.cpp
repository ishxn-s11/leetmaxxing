/*
Maintain A Stack
Traverse The String And Compare The Elements With Top Of The Stack
If Top Of The Stack Is Greater => Pop It And Decrement k
Push The Current Element
While k>0 => Pop Every Element Out Of The Stack And Decrement k
If Stack Is Empty => Return 0

Time Complexity: O(3*n+k)
Space Complexity: O(2*n)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>stk;

        for(int i=0;i<n;i++){

            while(!stk.empty() && k>0 && (stk.top()-'0')>(num[i]-'0')){
                stk.pop();
                k--;
            }

            stk.push(num[i]);
        }

        while(k>0){
            stk.pop();
            k--;
        }

        if(stk.empty()) return "0";

        string res="";

        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }

        while(res.size()!=0 && res.back()=='0') res.pop_back();

        reverse(res.begin(),res.end());

        if(res.empty()) return "0";

        return res;
    }
};