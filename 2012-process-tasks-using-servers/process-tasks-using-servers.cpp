/*
Optimal Approach

Instead Of Scanning Every Server Repeatedly
Maintain Two Priority Queues.
Heap 1: Available Server ->(weight,index)
Heap 2: Busy Server ->(freeTime,weight,index)

Time Complexity: O((n+m)*log(n+m))
Space Complexity: O(n+m)
*/

typedef long long ll;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>available;
        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>>busy;
        int n=servers.size();

        for(int i=0;i<n;i++) available.push({servers[i],i});

        vector<int>ans;
        ll curr=0;

        for(int j=0;j<tasks.size();j++){
            curr=max(curr,(ll)j);

            while(!busy.empty() && get<0>(busy.top())<=curr){
                auto [freeTime,w,idx]=busy.top();
                busy.pop();
                available.push({w,idx});
            }

            if(available.empty()){
                auto [freeTime,w,idx]=busy.top();
                busy.pop();
                curr=freeTime;
                ans.push_back(idx);
                busy.push({curr+tasks[j],w,idx});
            }else{
                auto [w,idx]=available.top();
                available.pop();
                ans.push_back(idx);
                busy.push({curr+tasks[j],w,idx});
            }
        }

        return ans;
    }
};