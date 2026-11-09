/*
Optimal Approach

Create An Ordered Set Available Containing All Server.
Create A Min Heap Busy Storing {freeTime, serverId}.
Initialize count[k] With 0.
Process Requests In Increasing Order{
  Before Assigning The Request, Release All Servers Whose freeTime<=arrival[i].
  Insert Those Server IDs Back Into Available.
  Calculate preferred Server: i%k.
  Find The First Available Server Using available.lower_bound(preferred).
  If No Such Server Exists => Select available.begin().
  If The Set Is Empty => Drop The Request.
  Otherwise{
    Remove The Selected Server From Available.
    Increment Its Request Count.
    Insert {arrival[i]+load[i],serverId} Into The Min Heap.
    }
}
Find The Maximum Request Count.
Return All Servers Having That Maximum Count.

Time Complexity: O((n+k)*log(k))
Space Complexity: O(k)
*/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        set<int>available;

        for(int i=0;i<k;i++) available.insert(i);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busy;
        vector<int>cnt(k,0);

        for(int i=0;i<n;i++){

            while(!busy.empty() && busy.top().first<=arrival[i]){
                int server=busy.top().second;
                busy.pop();
                available.insert(server);
            }
 
            if(available.empty()) continue;

            int pref=i%k;
            auto it=available.lower_bound(pref);

            if(it==available.end()) it=available.begin();

            int server=*it;
            available.erase(it);
            cnt[server]++;
            busy.push({arrival[i]+load[i],server});
        }

        int mxi=*max_element(cnt.begin(),cnt.end());
        vector<int>ans;

        for(int i=0;i<k;i++){

            if(cnt[i]==mxi) ans.push_back(i);
        }

        return ans;  
    }
};