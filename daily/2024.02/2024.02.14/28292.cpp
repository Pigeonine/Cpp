#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

priority_queue<int> q;

int main() {
    fastio;
    int n; cin >> n;
    if(n >= 6) cout << 3;
    else if(n >= 3) cout << 2;
    else cout << 1;

    // string target = "1";
    // int max_num = 1;
    
    // for(int i = 0; i < n-1; i++)
    // {
    //     string temp;
    //     int tar_size = target.length();
    //     char ex_num = target[0]; int ex_counts = 1;
    //     for(int i = 1; i < tar_size; i++)
    //     {
    //         if(ex_num != target[i]) 
    //         {
    //             if((int) ex_num - '0' > max_num) max_num = ex_num-'0';
    //             if(ex_counts > max_num) max_num = ex_counts;
    //             temp.push_back(ex_num); temp.append(to_string(ex_counts));
    //             ex_num = target[i]; ex_counts = 1;
    //         }
    //         else {ex_counts++;}
    //     }
    //     if((int) ex_num - '0' > max_num) max_num = ex_num-'0';
    //     if(ex_counts > max_num) max_num = ex_counts;
    //     temp.push_back(ex_num); temp.append(to_string(ex_counts));
    //     target = temp;
        
    // }
    // cout << target << endl;
    // cout << max_num;
}