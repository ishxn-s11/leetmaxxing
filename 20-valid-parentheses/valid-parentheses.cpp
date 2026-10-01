class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(char i:s){
            if(i=='(' || i=='{' || i=='[') stk.push(i);
            else{
                if(stk.empty()) return false;

                char top=stk.top();

                if((i==')'&& top!='(') || (i=='}'&& top!='{') ||(i==']'&& top!='[')) return false;

                stk.pop();
            }
        }
        
        return stk.empty();
    }
};