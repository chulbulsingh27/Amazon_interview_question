https://leetcode.com/problems/k-closest-points-to-origin/

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        int n = points.size();
        for(int i=0;i<n;i++){
            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(maxh.size() > k) maxh.pop();
        }
        vector<vector<int>>ans;
        while(maxh.size()>0){
            pair<int,int>p= maxh.top().second;
            vector<int> vec;
            vec.push_back(p.first);
            vec.push_back(p.second);
            ans.push_back(vec);
            maxh.pop();
        }
        return ans;
    }
    
    https://leetcode.com/discuss/interview-question/1895396/amazon-sde-new-grad-oa-k-most-popular-combos
    
    // #include <bits/stdc++.h>
using namespace std;

vector<long> bestCombo(vector<int> popularity, int k) {
    long posTotal = 0;
    vector<long> ans, out;
    for(int p: popularity) {
        if(p > 0)
            posTotal += p;
    }

    for(int& p: popularity) {
        p = abs(p);
    }
    sort(popularity.begin(), popularity.end());

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    int n = popularity.size();
    pq.push({popularity[0], 0});
    while(pq.size() && out.size() < k - 1) {
        auto s = pq.top();
        int u = s[0], i = s[1];
        pq.pop();
        out.push_back(u);
        if(i + 1 < n) {
            pq.push({u+popularity[i+1],i+1});
            pq.push({(u-popularity[i])+popularity[i+1],i+1});
        }
    }

    ans.push_back(posTotal);
    for(int o: out) {
        ans.push_back(posTotal - o);
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> p(n);
    for(int&i : p) cin >> i;
    cin >> k;

    auto b = bestCombo(p, k);
    for(int i: b)
        cout << i << " ";
    return 0;
}




The first question was posted with a lot of other text, but ultimately you can boil it down to this :
Given N number of elements, find the minimum number of swaps required so that the maximum element is at
the beginning and the minimum element is at last with the condition that only swapping of adjacent elements is allowed.
Examples:

Input: a[] = {3, 1, 5, 3, 5, 5, 2}
Output: 6

void solve(int a[], int n)
{
    int maxx = -1, minn = a[0], l = 0, r = 0;
    for (int i = 0; i < n; i++) {
 
        // Index of leftmost largest element
        if (a[i] > maxx) {
            maxx = a[i];
            l = i;
        }
 
        // Index of rightmost smallest element
        if (a[i] <= minn) {
            minn = a[i];
            r = i;
        }
    }
    if (r < l)
        cout << l + (n - r - 2);
    else
        cout << l + (n - r - 1);
}




// https://leetcode.com/problems/substring-with-largest-variance/

int largestVariance(string s) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                int highFreq = 0;
                int lowFreq = 0;
                bool prevHadLowFreqChar = false;
                for (char ch : s) {
                    if (ch - 'a' == i)
                        highFreq++;
                    else if (ch - 'a' == j)
                        lowFreq++;
                    if (lowFreq > 0)
                        res = max(res, highFreq - lowFreq);
                    else if (prevHadLowFreqChar)
                        res = max(res, highFreq - 1);
                    if (highFreq - lowFreq < 0) {
                        highFreq = 0;
                        lowFreq = 0;
                        prevHadLowFreqChar = true;
                    }
                }
            }
        }
        return res;
    }
    
    amazon web services has n servers.....
    
    Sum of Scores of Subarray
    
    
    int subarrayPower(vector<int>& h) {
    long long res = 0, sz = h.size(), mod = 1000000007;
    vector<int> ps_l(sz + 1), pm_l(sz + 1); // prefix sum and prefix mul from the left.
    vector<int> ps_r(sz + 1), pm_r(sz + 1); // ... from right.
    vector<int> st;
    for (int i = 0; i < sz; ++i) {
        ps_l[i + 1] = (ps_l[i] + h[i]) % mod;
        pm_l[i + 1] = (pm_l[i] + (long long)h[i] * (i + 1)) % mod;
    }
    for (int i = sz - 1; i >= 0; --i) {
        ps_r[i] = (ps_r[i + 1] + h[i]) % mod;
        pm_r[i] = (pm_r[i + 1] + h[i] * (sz - i)) % mod;
    }        
    for (int right = 0; right <= sz; ++right) {
        while(!st.empty() && (right == sz || h[st.back()] >= h[right])) {
            int pivot = st.back();
            st.pop_back();
            int left = st.empty() ? 0 : st.back() + 1;
            long long left_sum = (mod + pm_l[pivot + 1] - pm_l[left] - left * (ps_l[pivot + 1] - ps_l[left]) % mod) % mod;
            long long right_sum = (mod + pm_r[pivot + 1] - pm_r[right] - (sz - right) * (ps_r[pivot + 1] - ps_r[right])) % mod;
            long long all_sum = (right_sum * (pivot - left + 1) + left_sum * (right - pivot)) % mod;
            res = (res + all_sum * h[pivot]) % mod;
        }
        st.push_back(right);
    }
    return res;
}


