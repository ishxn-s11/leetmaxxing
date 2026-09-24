function sum(n:number):number{
    let x:number=0;
    while(n!=0){
        x+=n%10;
        n=Math.floor(n/10);
    }

    return x;
}

function smallestIndex(nums: number[]): number {
    let n:number=nums.length;

    for(let i=0;i<n;i++){
        if(sum(nums[i])===i) return i;
    }

    return -1;
};