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

function removeKdigits(num: string, k: number): string {
    const stk:string[]=[];

    for(let i=0;i<num.length;i++){

        while(stk.length>0 && k>0 && stk[stk.length-1]>num[i]){
            stk.pop();
            k--;
        }

        stk.push(num[i]);
    }  

    while(k>0){
        stk.pop();
        k--;
    }
    
    let res=stk.join("");
    let i=0;

    while(i<res.length && res[i]==='0') i++;

    res=res.substring(i);

    return res.length===0 ?"0":res;
};