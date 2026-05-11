#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void manacher(const vector<T>& s, vector<int>& d1, vector<int>& d2){
    int n = s.size();
    d1.assign(n, 0);
    d2.assign(n, 0);
    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while(i-k >= 0 && i+k < n && s[i-k]==s[i+k]) k++;
        d1[i] = k--;
        if(i+k > r){ l=i-k; r=i+k; }
    }
    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(i-k-1 >= 0 && i+k < n && s[i-k-1]==s[i+k]) k++;
        d2[i] = k--;
        if(i+k > r){ l=i-k-1; r=i+k; }
    }
}

void solve(){
    string A, B;
    cin >> A >> B;
    int n = A.size();
    
    int MA = 0;
    while(MA < n && A[MA] == B[n-1-MA]) MA++;
    int MB = 0;
    while(MB < n && B[MB] == A[n-1-MB]) MB++;
    int M = min(MA, MB);
    
    if(M == 0){
        cout << 0 << "\n";
        return;
    }
    
    vector<int> C(n);
    for(int i=0; i<n; i++) C[i] = (A[i]-'a')*26 + (B[i]-'a');
    
    vector<int> d1, d2;
    manacher(C, d1, d2);
    
    vector<ll> Ddiff(n+2, 0), C1diff(n+2, 0);
    for(int i=0; i<n; i++){
        int od = d1[i];
        Ddiff[i]++;
        Ddiff[i + od]--;
        int lo = i - od + 1;
        if(lo < 0) lo = 0;
        C1diff[lo]++;
        C1diff[i + 1]--;
        
        int ev = d2[i];
        if(ev >= 1){
            Ddiff[i]++;
            Ddiff[i + ev]--;
            int lo2 = i - ev;
            if(lo2 < 0) lo2 = 0;
            C1diff[lo2]++;
            C1diff[i]--;
        }
    }
    
    vector<ll> D(n+1, 0), C1(n+1, 0);
    ll acc = 0;
    for(int e=0; e<n; e++){ acc += Ddiff[e]; D[e] = acc; }
    acc = 0;
    for(int s=0; s<n; s++){ acc += C1diff[s]; C1[s] = acc; }
    
    ll ans = 0;
    for(int q=1; q<=M && q<=n; q++){
        ll c = (q < n) ? C1[q] : 0;
        ans += 1 + c;
    }
    for(int p=1; p<=M && p<=n-1; p++){
        int r = n - 1 - p;
        if(r >= 0) ans += D[r];
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}