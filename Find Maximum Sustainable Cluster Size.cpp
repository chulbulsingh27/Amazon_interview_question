// solution 1
int findMaximumSustainableClusterSize(vector processingPower, vector bootingPower, long powerMax) {
int i =0,j=0;
int n = processingPower.size();
int sum = 0;
map<int,int> maxBoot;
int ans=0;
while(j<n){

sum+=processingPower[j];
maxBoot[bootingPower[j]]++;
while(maxBoot.size()>0 && maxBoot.rbegin()->first+sum*(j-i+1)>powerMax){
auto itr= maxBoot.find(bootingPower[i]);
if(itr->second>1) {
itr->second-=1;
}else{
maxBoot.erase(itr);
}
sum-=processingPower[i];
i+=1;
}
if(j-i+1>ans){
ans=j-i+1;
}
j++;
}
return ans;
}


// solution 2 


int max_power_per_network(const vector<int> & process, const vector<int> & boot, int maxpower) {
    int i = 0, j = 0;
    int n = process.size();
    int sum = 0;
    map <int, int> maxboot;
    int ans = 0;
    while (j < n) {
        sum += process[j];
        maxboot[boot[j]]++;
        // compute consumption right now
        while (maxboot.rbegin()->first + sum * (j-i+1) > maxpower) {
            auto itr = maxboot.find(boot[i]);
            if (itr->second > 1) {
                itr->second -= 1;
            } else {
                maxboot.erase(itr);
            }
            sum -= process[i];
            i += 1;
        }
        // update subarr length
        if (j - i + 1 > ans) {
            ans = j - i + 1;
            cout << "max sub array length updated to: " << ans << endl;
        }
        j++;
    }
    return ans;
}
