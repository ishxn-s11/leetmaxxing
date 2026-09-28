/*
Initialise depth=0,max_d=0
Traverse Every Character In s
If s[i]=='('{
    depth++
    Update max_d
}
If s[i]==')' => depth--
Return max_d

Time Complexity: O(n)
Space Complexity: O(1)
*/

function maxDepth(s: string): number {
    let depth:number=0;
    let max_d:number=0;

    for(const i of s){
        if(i==='('){
            depth++;
            max_d=Math.max(max_d,depth);
        }else if(i===')') depth--;
    }

    return max_d;
};