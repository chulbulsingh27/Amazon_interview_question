Multiples queries(list of string) were given as input and we need to simulate INSERT and VIEW operations.
This was basically a heap based problem in which we had to find/track the kth cheapest element.
It was a very lengthy problem to read and understand. I found it similar to median from data stream problem.
  
  
  #include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

vector<string> solve(vector<vector<string>> &entries, int n) {
    priority_queue<pair<int, string>> maxHeap; // max-heap
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;   // min-heap
    vector<string> ans; // to store result
    int k = 1;  // query count
    for (vector<string> entry : entries) {
        string a = entry[0], b = entry[1], c = entry[2];
        if (a == "VIEW") {
            // return the top of max heap
            ans.push_back(maxHeap.top().second);
            k++; // increment query count
            if (!minHeap.empty()) { // add one element from min-heap
                pair<int, string> t = minHeap.top();
                minHeap.pop();
                maxHeap.push(t);
            }
        }
        else {
            // if size is equal to kth query insert the value in min-heap
            if (maxHeap.size() == k) {
                minHeap.push({stoi(c), b});
            }
            else {
                // else insert the value in max-heap
                maxHeap.push({stoi(c), b});
            }
        }

        // if value at top of min-heap is less the value at top of max-heap then swap the values
        if (!minHeap.empty() && ((minHeap.top().first == maxHeap.top().first && minHeap.top().second < maxHeap.top().second) || minHeap.top().first < maxHeap.top().first)) {
            pair<int, string> minTop = minHeap.top();
            pair<int, string> maxTop = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(minTop);
        }
    }
    return ans;
}

int32_t main() {
    fast_io;
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; //  number of entries
        cin >> n;
        vector<vector<string>> entries(n);
        for (int i = 0; i < n; i++) {   // input
            string a, b, c;
            cin >> a >> b >> c;
            entries[i].push_back(a);
            entries[i].push_back(b);
            entries[i].push_back(c);
        }
        vector<string> result = solve(entries, n);
        for (string s : result)
            cout << s << endl;
        cout << endl;
    }
    return 0;
}
