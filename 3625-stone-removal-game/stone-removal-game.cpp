class Solution {
public:
    bool canAliceWin(int n) {
        int rem=10;
        bool turn=true;

        while(n>=rem){
            n-=rem;
            rem--;
            turn=!turn;
        }

        return !turn;
    }
};