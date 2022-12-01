// store[n][m]
// n is number of eaters
// m is number of dishes


void solve(vector<vector<int>>&store){
    int n=store.size();
    map<int,set<int>>mp;
    
    for(int i=0;i<n;i++){
        for(auto j:store[i]){
            if(mp[i].count(j)!=0){
                cout<<"Error"; return;
            }
            mp[i].insert(j);
        }
    }
    
    map<int,int>cnt;
    for(int i=0;i<n;i++){
        for(auto j:store[i]){
            cnt[j]+=1;
        }
    }
    
    vector<pair<int,int>>ans;
    for(auto i:cnt){
        ans.push_back({i.second,i.first});
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    
    for(int i=0;i<min(3,n);i++){
        cout<<ans[i].second<<" ";
    }
}