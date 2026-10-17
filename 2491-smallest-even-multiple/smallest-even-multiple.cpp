/*
If n Is Even => Its Already The Required Smallest Number 
Otherwise If n is Odd => Twice The Number Is The Required Number
*/

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n%2==0?n:2*n;
    }
};