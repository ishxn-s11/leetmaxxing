
/*
Binary Search on Answer

Time Complexity: O(n * log(max(piles)))
Space Complexity: O(1)
*/

function minEatingSpeed(piles: number[], h: number): number {

    function f(piles:number[],mid:number):number{
        let total=0;

        for(const pile of piles) total+=Math.ceil(pile/mid);

        return total;
    }

    let low=1;
    let high=Math.max(...piles);
    let ans=high;

    while(low<=high){
        const mid=Math.floor(low+(high-low)/2);
        const total=f(piles,mid);

        if(total<=h){
            ans=mid;
            high=mid-1;
        } else low=mid+1;  
    }

    return ans;
}
