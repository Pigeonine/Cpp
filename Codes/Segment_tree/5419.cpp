#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

//언제나 결과가 overflow일어날지 생각해보기!!!

using namespace std;

vector<pair<int, int>> coor;
vector<int> cond;
int t, n, x, y;

int y_trees[150000]{};

void update(int ind, int val)
{

	while (ind <= n)
	{
		y_trees[ind] += val;
		ind += ind & -ind;
	}
}

int query(int ind)
{
	int sums = 0;
	while (ind > 0)
	{
		sums += y_trees[ind];
		ind -= ind & -ind;
	}
	return sums;
}

bool calc(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}

int main() {
	fastio;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> x >> y; coor.push_back(make_pair(x, y)); // O(n)
			cond.push_back(y);
		}
		sort(cond.begin(), cond.end());
		sort(coor.begin(), coor.end(), calc); // O(nlogn)
		long long ans = 0;
		for (int j = 0; j < n; j++)
		{
			int alt_ind = upper_bound(cond.begin(), cond.end(), coor[j].second) - cond.begin();
			//cout << coor[j].first << ' ' << coor[j].second << ' ' << alt_ind << "\n";
			ans += query(alt_ind); update(alt_ind, 1);
		}
		cout << ans << "\n";
		fill(y_trees, y_trees + n + 1, 0);
		coor.clear();
		cond.clear();
	}
}