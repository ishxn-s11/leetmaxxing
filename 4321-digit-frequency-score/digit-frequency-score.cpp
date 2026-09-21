class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum=0,d=log10(n)+1;

        while(d--){
            sum+=(n%10);
            n/=10;
        }

        return sum;
    }
};