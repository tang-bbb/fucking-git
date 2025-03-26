#include <bits/stdc++.h>
#include <array>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   vector<array<int, 3>> b; 
    for (int i = 0; i < 321; i++) {
        for (int j = 0; j < 321; j++) {
            int x = i * 3 + 1, y = j * 3 + 1;
            b.push_back({x + y - 1, x, y});
            b.push_back({x + y, x + 1, y});
            b.push_back({x + y, x, y + 1});
            b.push_back({x + y + 3, x + 1, y + 1});
        }
    }
    sort(b.begin(),b.end());
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m=sqrt(2*n)+3;
        vector<vector<int>>f(m*3,vector<int>(m*3,0));
        vector<vector<int>>g(m,vector<int>(m,0));
        int k0=0,k1=0;
        for(int i=0;i<n;i++){
            int x,y;
            if(a[i]){
                while(f[b[k1][1]][b[k1][2]])k1++;
                x=b[k1][1],y=b[k1][2];
            }
            else {
                while(g[b[k0][1]/3][b[k0][2]/3])k0++;
                x=b[k0][1],y=b[k0][2];
            }
            f[x][y]=1;
            g[x/3][y/3]=1;
            cout<<x<<' '<<y<<endl;
        }
    }
    return 0;
}


    