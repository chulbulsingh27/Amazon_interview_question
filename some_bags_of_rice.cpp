#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector&arr, int i, int j, int target){
int temp = -1;
while(i<=j){
int mid = (i+j)/2;
if(arr[mid] > target) j = mid-1;
else if(arr[mid]==target) return mid;
else i = mid+1;
}
return -1;
}

void helper(vector&arr,vector&dp, int i){
if(i == arr.size()){
return;
}
int res = binarySearch(arr,i+1,arr.size()-1,arr[i]*arr[i]);
if(res !=-1){
dp[res] = max(dp[res],dp[i]+1);
}
helper(arr,dp,i+1);
return;
}

int main(){
int n;
cin >> n;
vector arr(n,0);
for(int i = 0; i< n;i++){
cin >> arr[i];
}
sort(arr.begin(),arr.end());
vector dp(n,1);
helper(arr,dp,0);
int ans = *max_element(dp.begin(),dp.end());
if(ans==1) cout << -1 << endl;
else cout << ans << endl;
return 0;
}
