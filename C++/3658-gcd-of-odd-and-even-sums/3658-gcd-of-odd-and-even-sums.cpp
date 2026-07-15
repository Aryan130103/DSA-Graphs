class Solution {
public:
    int gcd(int sumEven,int sumOdd){
        int x=min(sumEven,sumOdd);
        int ans=INT_MIN;
        for(int i=1;i<x+1;i++){
            if(sumEven%i==0 && sumOdd%i==0){
                ans=max(ans,i);
            }
        }
        return ans;
    }
    int gcdOfOddEvenSums(int n) {
        if(n==1) return n;
        int sumOdd=n*n;
        int sumEven=n*(n-1);
        return gcd(sumEven,sumOdd);
    }
};