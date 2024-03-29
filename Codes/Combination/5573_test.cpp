#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool paths[1001][1001];

vector<pair<int, int>> res;

set<pair<int, int>> prs;


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
	int r, c; long long rep = 2000000000;
	for (int i = 1; i <= n; i++)
	{
		r = 1; c = 1;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cout << paths[i][j] << ' ';
			}
			cout << "\n";
		}
			cout << "\n";
		while (r <= h && c <= w)
		{
			if (prs.find({ r,c }) == prs.end()) prs.insert({ r,c });
			else prs.erase({ r,c });
			
			if (paths[r][c])
			{
				paths[r][c] = false; c++; 
			}
			else if (!paths[r][c])
			{
				paths[r][c] = true; r++;
			}
		}
		//cout << r << ' ' << c << endl;
		res.push_back({ r,c });
		if (prs.empty())
		{
			rep = i; cout << rep << "\n"; break;
		}
	}

	cout << res[(n-1) % rep].first << ' ' << res[(n-1)% rep].second;
}