#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int scores_sum[3]{};
int scores[3][3]{};

int main() {
    fastio;
    int n, f, s, t; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> f >> s >> t;
        scores_sum[0]+=f; scores_sum[1] += s; scores_sum[2] += t;
        scores[0][f-1]++; scores[1][s-1]++; scores[2][t-1]++;
    }

    if(scores_sum[0] > scores_sum[1] && scores_sum[0] > scores_sum[2])
        cout << 1 << ' ' << scores_sum[0];
    else if(scores_sum[1] > scores_sum[0] && scores_sum[1] > scores_sum[2])
        cout << 2 << ' ' << scores_sum[1];
    else if(scores_sum[2] > scores_sum[1] && scores_sum[2] > scores_sum[0])
        cout << 3 << ' ' << scores_sum[2];
    else if(scores_sum[0] == scores_sum[1] && scores_sum[1] == scores_sum[2])
    {
        if(scores[0][2] > scores[1][2] && scores[0][2] > scores[2][2]) cout << 1 << ' ' << scores_sum[0];
        else if(scores[1][2] > scores[0][2] && scores[1][2] > scores[2][2]) cout << 2 << ' ' << scores_sum[1];
        else if(scores[2][2] > scores[1][2] && scores[2][2] > scores[1][2]) cout << 3 << ' ' << scores_sum[2];
        else if(scores[1][2] == scores[0][2] && scores[0][2] == scores[2][2])
        {
            if(scores[0][1] > scores[1][1] && scores[0][1] > scores[2][1]) cout << 1 << ' ' << scores_sum[0];
            else if(scores[1][1] > scores[0][1] && scores[1][1] > scores[2][1]) cout << 2 << ' ' << scores_sum[1];
            else if(scores[2][1] > scores[1][1] && scores[2][1] > scores[1][1]) cout << 3 << ' ' << scores_sum[2];
            else if(scores[1][1] == scores[0][1] && scores[0][1] == scores[2][1]) cout << 0 << ' ' << scores_sum[0];
            else if(scores[1][1] == scores[0][1] && scores[0][1] > scores[2][1]) cout << 0 << ' ' << scores_sum[0];
            else if(scores[2][1] == scores[0][1] && scores[0][1] > scores[1][1]) cout << 0 << ' ' << scores_sum[0];
            else if(scores[1][1] == scores[2][1] && scores[1][1] > scores[0][1]) cout << 0 << ' ' << scores_sum[1];
        }
        else if(scores[1][2] == scores[0][2] && scores[0][2] > scores[2][2])
        {
            if(scores[0][1] > scores[1][1]) cout << 1 << ' ' << scores_sum[0];
            else if(scores[0][1] < scores[1][1]) cout << 2 << ' ' << scores_sum[1];
            else cout << 0 << ' ' << scores_sum[0];
        }
        else if(scores[2][2] == scores[0][2] && scores[0][2] > scores[1][2])
        {
            if(scores[0][1] > scores[2][1]) cout << 1 << ' ' << scores_sum[0];
            else if(scores[0][1] < scores[2][1]) cout << 3 << ' ' << scores_sum[2];
            else cout << 0 << ' ' << scores_sum[0];
        }
        else if(scores[2][2] == scores[1][2] && scores[1][2] > scores[0][2])
        {
            if(scores[2][1] > scores[1][1]) cout << 3 << ' ' << scores_sum[2];
            else if(scores[2][1] < scores[1][1]) cout << 2 << ' ' << scores_sum[1];
            else cout << 0 << ' ' << scores_sum[1];
        }
    }
    else if(scores_sum[0] == scores_sum[1] && scores_sum[0] > scores_sum[2])
    {
        if(scores[0][2] > scores[1][2]) cout << 1 << ' ' << scores_sum[0];
        else if(scores[0][2] < scores[1][2]) cout << 2 << ' ' << scores_sum[1];
        else
        {
            if(scores[0][1] > scores[1][1]) cout << 1 << ' ' << scores_sum[0];
            else if(scores[0][1] < scores[1][1]) cout << 2 << ' ' << scores_sum[1];
            else cout << 0 << ' ' << scores_sum[0];
        }
    }
    else if(scores_sum[0] == scores_sum[2] && scores_sum[0] > scores_sum[1])
    {
        if(scores[0][2] > scores[2][2]) cout << 1 << ' ' << scores_sum[0];
        else if(scores[0][2] < scores[2][2]) cout << 3 << ' ' << scores_sum[2];
        else
        {
            if(scores[0][1] > scores[2][1]) cout << 1 << ' ' << scores_sum[0];
            else if(scores[0][1] < scores[2][1]) cout << 3 << ' ' << scores_sum[2];
            else cout << 0 << ' ' << scores_sum[0];
        }
    }
    else if(scores_sum[1] == scores_sum[2] && scores_sum[1] > scores_sum[0])
    {
        if(scores[2][2] > scores[1][2]) cout << 3 << ' ' << scores_sum[2];
        else if(scores[2][2] < scores[1][2]) cout << 2 << ' ' << scores_sum[1];
        else
        {
            if(scores[2][1] > scores[1][1]) cout << 3 << ' ' << scores_sum[2];
            else if(scores[2][1] < scores[1][1]) cout << 2 << ' ' << scores_sum[1];
            else cout << 0 << ' ' << scores_sum[1];
        }
    }
}