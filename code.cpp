//manish kumar patel
#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define err() cout<<"--------------------------"<<endl; 
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl



#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second

#define pii pair<int,int>
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"

int binaryss(V &a,V &v,int i,int h)
{
    int lo=0,hi=h;
    while(lo<hi)
    {
        // err3(i,lo,hi);
        int mid=(lo+hi)/2;
        // err1(v[mid]);
        if(a[v[mid]]<=a[i])
        {
            lo=mid+1;
        }
        else
        {
            hi=mid;
        }
       
    }
    // err2()
    return lo;
}
int len_of_lis(V &v)
{
    int l=v.size();
    V v1(l,-1);
    V v2(l,-1);
    int len=0;
    v1[0]=0;
    rep(i,1,l)
    {
        if(v[v1[len]]<v[i])// here you can make changes for lis or lnds
        {
            ++len;
            v1[len]=i;
        }
        else
        {
            int kk=binaryss(v,v1,i,len);
            // err3(i,kk,len);
            // errA(v1);
            if(kk-1>=0 && v[v1[kk-1]]==v[i])
            {

            }
            else
            {
                v1[kk]=i;
            }
           
        }
      
    }
    // errA(v1);
    return len;

}
int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        #ifndef ONLINE_JUDGE
         clock_t tStart = clock();
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int t;
        cin>>t;
        // t=1;
           
        while(t--)
        {
            
            int n;
            cin>>n;
            V v(n,0);
            rep(i,0,n)
            {
                cin>>v[i];
            }
            cout<<len_of_lis(v)+1;


        }
        #ifndef ONLINE_JUDGE
            printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
            #endif
} 
