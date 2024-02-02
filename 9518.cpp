#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool seats[52][52]{};

int main() {
    fastio;
    int r, s;
    string str;
    cin >> r >> s;
    int people_count = 0;
    for(int i = 1; i <= r; i++)
    {
        cin >> str;
        for(int j = 1; j <= s; j++)
        {
            if(str[j-1] == 'o') 
            {
                seats[i][j] = true;
                people_count++;
            }
        }
    }
    int shake_count = 0;
    int max_add = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            if(seats[i][j])
            {
                if(seats[i+1][j]) shake_count++;
                if(seats[i][j+1]) shake_count++;
                if(seats[i+1][j+1]) shake_count++;
                if(seats[i-1][j+1]) shake_count++;
            }
            
            if(!seats[i][j])
            {
                int temp = 0;
                if(seats[i+1][j]) temp++;
                if(seats[i][j+1]) temp++;
                if(seats[i+1][j+1]) temp++;
                if(seats[i-1][j+1]) temp++;
                if(seats[i-1][j]) temp++;
                if(seats[i][j-1]) temp++;
                if(seats[i-1][j-1]) temp++;
                if(seats[i+1][j-1]) temp++;
                max_add = max(max_add, temp);
            }
        }
    }
    cout << shake_count + max_add;
}