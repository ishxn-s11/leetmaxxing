/*
Optimal Approach

Choose Two Large Prime Moduli
Precompute Powers Of The Rolling Hash Base For Both Moduli.
Calculate The Hash Of The First Window.
Slide Through The Remaining Windows.
Store The Frequency Of Each Pair Of Hashes.
If Any Pair Occurs Exactly Once, Return True.
Else Return false.
Set low=1,high=n.
Calculate mid.
If check(mid) Is True, Save The Answer And Search Smaller Lengths.
Else => Search Larger Lengths.
Return The Minimum Valid Length.

Time Complexity: O(n*log(n))
Space Complexity: O(n)
*/

typedef long long ll;
static constexpr ll BASE=233;
static constexpr ll MOD1=1000000007;
static constexpr ll MOD2=1000000009;
using Hash=pair<ll,ll>;

class Solution {
public:

    struct PairHash{
        size_t operator()(const Hash& p) const{
            return hash<ll>()(p.first)^(hash<ll>()(p.second)<<1);
        }
    };

    vector<ll>pow1,pow2;

    void precomp(int n){
        pow1.resize(n+1,1);
        pow2.resize(n+1,1);

        for(int i=1;i<=n;i++){
            pow1[i]=(pow1[i-1]*BASE)%MOD1;
            pow2[i]=(pow2[i-1]*BASE)%MOD2;
        }
    }

    bool check(vector<int>& nums,int len){
        int n=nums.size();
        unordered_map<Hash,int,PairHash>freq;
        ll h1=0,h2=0;

        for(int i=0;i<len;i++){
            h1=(h1*BASE+nums[i])%MOD1;
            h2=(h2*BASE+nums[i])%MOD2;
        }

        freq[{h1,h2}]++;

        for(int i=len;i<n;i++){
            h1=(h1-nums[i-len]*pow1[len-1]%MOD1+MOD1)%MOD1;
            h1=(h1*BASE+nums[i])%MOD1;
            h2=(h2-nums[i-len]*pow2[len-1]%MOD2+MOD2)%MOD2;
            h2=(h2*BASE+nums[i])%MOD2;
            freq[{h1,h2}]++;
        }

        for(auto& [h,cnt]:freq){

            if(cnt==1) return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        precomp(n);
        int low=1,high=n;
        int ans=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(nums,mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return ans;
    }
};
