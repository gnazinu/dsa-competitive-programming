#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  set<int> present;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    present.insert(x);
  }

  int trades = 0;
  for(int i = 1; i <= n; i++){
    if(present.find(i) == present.end()){
      trades++;
    }
  }

  cout << trades << endl;

  return 0;
}