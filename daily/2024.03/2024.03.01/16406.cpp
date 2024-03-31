#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int k; string mine, friends;
    cin >> k >> mine >> friends;
    int psize = mine.length();
    int same_num = 0;
    for(int i = 0; i < psize; i++)
        if(mine[i] == friends[i]) same_num++;
    cout << min(same_num, k) + min(psize - k, psize - same_num);

}