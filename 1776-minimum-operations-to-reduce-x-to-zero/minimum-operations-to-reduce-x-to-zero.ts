/*
Prefix Sum + Hashmap 

Let The Sum From Left Chosen Segment Of The Array And Right Chosen Segment 
Of The Array Be left And right Respectively, Also, Let The Total Sum Of 
The Array Be sum

According To The Problem, We Have To Choose Minimum Elements Of Right And Left
Such That left + right == x

This Is Equivalent To Maximizing A Window Of (sum-x)

Therefore, The Problem Becomes Identical To 'Maximum Subarray Sum Equals k'

Time Complexity: O(n)
Space Complexity: O(k) Where k Is The Size Of Map
*/


function minOperations(nums: number[], x: number): number {
    const n=nums.length;

    const mp=new Map<number,number>();

    mp.set(0,-1);

    let sum=0;

    for(let i=0;i<n;i++){
        sum+=nums[i];
        mp.set(sum,i);
    }

    if(sum<x) return -1;

    const rem=sum-x;
    let len=-Infinity;

    sum=0;

    for(let i=0;i<n;i++){
        sum+=nums[i];

        const s=sum-rem;

        if(mp.has(s)){
            const idx=mp.get(s)!;

            len=Math.max(len,i-idx);
        }
    }

    return len==-Infinity?-1:n-len;
};