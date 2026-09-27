/*
Brute Force

Maintain A Stack
Traverse 
If The Character Is A Letter Or '(' => Push
If The Character Is ')' => Pop Until '(' Is Encountered
Remove '(' And Push The Popped Characters Back In The Same Order Back Into The Stack.

Time Complexity: O(n^2)
Space Complexity: O(n)

*/

function reverseParentheses(s: string): string {
    const stk:string[]=[];

    for(const i of s){
        if(i!==')') stk.push(i);
        else {
            let temp="";

            while(stk[stk.length-1]!=='(') temp+=stk.pop()!;

            stk.pop();

            for(const j of temp) stk.push(j);
        }
    }

    let ans="";

    while(stk.length>0) ans+=stk.pop()!;

    return ans.split("").reverse().join("");
};