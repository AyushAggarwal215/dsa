/*
 Count derangements
Moderate
80/80
Average time to solve is 35m
Contributed by
114 upvotes
Asked in companies
Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 3000

Time limit: 1 sec
Sample Input 1:
2
2
3
Sample Output 1:
1
2
Explanation of Sample Output 1:
In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.

Sample Input 2:
2
1
4
Sample Output 2:
0
9
Explanation of Sample Output 2:
In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.
*/

#include<vector>
const int mod = 1e9+7;
long long solverec(int n){
    if(n<=3){
        return n-1;
    }
    long long ans = ((n-1)*(solverec(n-1)+solverec(n-2)))%mod;
    return ans;
}
long long solvemem(int n, vector<long long>& dp){
    if(n<=3){
        return n-1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = ((n-1)*(solvemem(n-1, dp)+solvemem(n-2, dp)))%mod;
    return dp[n];
}
long long solvetab(int n){
    if(n<=3){
        return n-1;
    }
    vector<long long> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for(int i=4; i<=n; i++){
        dp[i] = ((i-1)*(dp[i-1]+dp[i-2]))%mod;
    }
    return dp[n];
}
long long solve(int n){
    if(n<=3){
        return n-1;
    }
    long long prev2 = 1;
    long long prev1 = 2;
    for(int i=4; i<=n; i++){
        long long curr = ((i-1)*(prev1+prev2))%mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int countDerangements(int n) {
    // long long ans = solverec(n);
    // vector<long long> dp(n+1, -1);
    // int ans = solvemem(n, dp);
    // int ans = solvetab(n);
    long long ans = solve(n);
    return ans;
}