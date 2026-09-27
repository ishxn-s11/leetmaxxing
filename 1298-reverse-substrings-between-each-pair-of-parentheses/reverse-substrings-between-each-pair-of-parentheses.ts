/*
Optimal Approach Wormhole Traversal

Instead Of Physically Reversing Substrings,
Simulate Reversal By Changing Our Traversal Direction.

Mantain A Stack Of Indicess For Finding Matching Parenthesis
Store The Indices In A Vector
Traverse
When A Parenthesis Is Encountered{
    Jump To Its Matching Parenthesis
    Reverse The Direction
}
When A Letter Is Encountered => Append To The ans

Time Complexity: O(n)
Space Complexity: O(n)
*/

function reverseParentheses(s: string): string {
    const n=s.length;

    const pair:number[]=new Array(n).fill(0);
    const stk:number[]=[];

    for(let i=0;i<n;i++){
        if(s[i]==='(') stk.push(i);
        else if(s[i]===')'){
            const j=stk.pop()!;

            pair[i]=j;
            pair[j]=i;
        }
    }

    let ans="";
    let dir=1;

    for(let i=0;i<n;i+=dir){
        if(s[i]==='(' || s[i]===')'){
            i=pair[i];
            dir=-dir;
        }else ans+=s[i];
    }

    return ans;
};