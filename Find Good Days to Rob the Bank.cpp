
https://leetcode.com/problems/find-good-days-to-rob-the-bank/

Given array arr[] with n values and integer k , calculate the optimal value for K in array and print all the index of the elements with are matching the optimal value criteria.

Optimal value criteria,

for k , arr[i] is optimal point if
arr[i-k]>=arr[i-k-1]>=arr[i-k-2].....>=arr[i]<=arr[i+1]<=arr[i+2]<=arr[i+3]<=.......arr[i+k]

Example:

Input:

arr = [4,2,2,2,3,4]
k = 2

Output:

[3,4]

vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int size=s.size(),cnt=1;
        vector<int>pre(size,0),suf(size,0);
        pre[0]=1;
        for(int i=1;i<size;i++){
            if(s[i]<=s[i-1])
                cnt++;
            else
                cnt=1;
             pre[i]=cnt;
        }
        suf[size-1]=1;cnt=1;
        for(int i=size-2;i>=0;i--){
            if(s[i]<=s[i+1])
                cnt++;
            else
                cnt=1;
            suf[i]=cnt; 
        }
        vector<int>ans;
        for(int i=0;i<size;i++)
            if(pre[i]-1>=time && suf[i]-1>=time)
                ans.push_back(i);
        return ans;
    }
