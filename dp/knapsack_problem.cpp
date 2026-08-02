// https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM
/*
0 1 Knapsack
Easy
40/40
Average time to solve is 15m
Contributed by
422 upvotes
Asked in companies
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/

// solution 
#include <bits/stdc++.h>
int solverec(vector<int>& weight, vector<int>& value, int index, int capacity){
	if(index==0){
		if(capacity>=weight[index]){
			return value[0];
		}else{
			return 0;
		}
	}
	int incl = 0;
	if(capacity>=weight[index]){
		incl = value[index]+solverec(weight, value, index-1, capacity-weight[index]);
	}
	int excl = solverec(weight, value, index-1, capacity);
	return max(incl, excl);
} 
int solvemem(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>>&dp){
	if(index==0){
		if(capacity>=weight[index]){
			return value[0];
		}else{
			return 0;
		}
	}
	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}
	int incl = 0;
	if(capacity>=weight[index]){
		incl = value[index]+solvemem(weight, value, index-1, capacity-weight[index], dp);
	}
	int excl = solvemem(weight, value, index-1, capacity, dp);
	dp[index][capacity] = max(incl, excl);
	return dp[index][capacity];
}
int solvetab(vector<int>& weight, vector<int>& value, int n, int capacity){
	vector<vector<int>>dp(n, vector<int>(capacity+1, 0));
	for(int w = weight[0]; w<=capacity; w++){
		// if(weight[0]<=capacity){
		// 	dp[0][w] = value[0];
		// }else{
		// 	dp[0][w] = 0;
		// }
		dp[0][w] = value[0];
	}
	for(int i=1; i<n; i++){
		for(int w=0; w<=capacity; w++){
			int incl = 0;
			if(w>=weight[i]){
				incl = value[i]+dp[i-1][w-weight[i]];
			}
			int excl = dp[i-1][w];
			dp[i][w] = max(incl, excl);
		}
	}
	return dp[n-1][capacity];
}
int solve(vector<int>& weight, vector<int>& value, int n, int capacity){
	vector<int>prev(capacity+1, 0);
	vector<int>curr(capacity+1, 0);
	for(int w = weight[0]; w<=capacity; w++){
		// if(weight[0]<=capacity){
		// 	dp[0][w] = value[0];
		// }else{
		// 	dp[0][w] = 0;
		// }
		prev[w] = value[0];
	}
	for(int i=1; i<n; i++){
		for(int w=0; w<=capacity; w++){
			int incl = 0;
			if(w>=weight[i]){
				incl = value[i]+prev[w-weight[i]];
			}
			int excl = prev[w];
			curr[w] = max(incl, excl);
		}
		swap(curr, prev);
	}
	return prev[capacity];
}
int solve1(vector<int>& weight, vector<int>& value, int n, int capacity){
	// vector<int>prev(capacity+1, 0);
	vector<int>curr(capacity+1, 0);
	for(int w = weight[0]; w<=capacity; w++){
		// if(weight[0]<=capacity){
		// 	dp[0][w] = value[0];
		// }else{
		// 	dp[0][w] = 0;
		// }
		curr[w] = value[0];
	}
	for(int i=1; i<n; i++){
		for(int w=capacity; w>=0; w--){
			int incl = 0;
			if(w>=weight[i]){
				incl = value[i]+curr[w-weight[i]];
			}
			int excl = curr[w];
			curr[w] = max(incl, excl);
		}
		// swap(curr, prev);
	}
	return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return solverec(weight, value, n-1, maxWeight);
	// vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	// return solvemem(weight, value, n-1, maxWeight, dp);
	// return solvetab(weight, value, n, maxWeight);
	// return solve(weight, value, n, maxWeight);
	return solve1(weight, value, n, maxWeight);
}