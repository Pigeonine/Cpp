// #5573 산책
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool paths[1001][1001];

int paths_passed[1001][1001];


int main() {
	fastio;
	int h, w, n; cin >> h >> w >> n;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> paths[i][j];
		}
	}
    paths_passed[1][1] = n - 1;
    
	for(int k = 2; k <= h + w; k++)
    {
        //cout << "test" << endl;
        for(int i = max(1, k - w); i <= min(k - 1, h); i++)
        {
            int r = i, c = k - i;
            if(paths_passed[r][c] % 2 == 0)
            {
                if(r+1 <= h) paths_passed[r+1][c] += paths_passed[r][c] / 2;
                if(c+1 <= w) paths_passed[r][c+1] += paths_passed[r][c] / 2;
            }
            else {
                if(paths[r][c])
                {
                    if(r+1 <= h) paths_passed[r+1][c] += paths_passed[r][c] / 2;
                    if(c+1 <= w) paths_passed[r][c+1] += paths_passed[r][c] / 2 + 1;
                }
                else{
                    if(r+1 <= h) paths_passed[r+1][c] += paths_passed[r][c] / 2 + 1;
                    if(c+1 <= w) paths_passed[r][c+1] += paths_passed[r][c] / 2;
                }
            }
        }
    }
	
    // for (int i = 1; i <= h; i++)
	// 	{
	// 		for (int j = 1; j <= w; j++)
	// 		{
	// 			cout << paths_passed[i][j] << ' ';
	// 		}
	// 		cout << "\n";
	// 	}

    int r = 1, c = 1;
    while(r <= h && c <= w)
    {
        //cout << r << ' ' << c << endl;
        if(paths_passed[r][c] % 2 == 0)
        {
            if(paths[r][c]) c++;
            else r++;
        }
        else 
        {
            if(paths[r][c]) r++;
            else c++;
        }
    }
    cout << r << ' ' << c;
}