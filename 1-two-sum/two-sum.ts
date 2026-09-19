//Better Appproach 

function twoSum(nums: number[], target: number): number[] {
    const m=new Map<number,number>();

    for(let i=0;i<nums.length;i++){
        const a=nums[i];
        const x=target-a;

        if(m.has(x)) return [m.get(x)!,i];

        m.set(a,i);
    }

    return [-1];
};