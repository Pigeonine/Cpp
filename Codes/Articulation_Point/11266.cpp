#include <iostream>
#include <vector>
#include <queue>
#define VMAX 10002
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)


using namespace std;

vector<int> adlist[VMAX];
queue<int> q;
int discovered[VMAX];	

int numb = 1;

bool iscut[VMAX];

int dfs(int point, bool isroot)
{
	discovered[point] = numb++;

    int ret = discovered[point];

    int child = 0;
    for(auto next : adlist[point])
    {
        if(discovered[next])
        {
            ret = min(ret, discovered[next]);
            continue;
        }

        child++;
        int prev = dfs(next, false);

        if(!isroot && prev >= discovered[point]) iscut[point] = true;

        ret = min(ret, prev);
    }

    if(isroot && child >= 2) iscut[point] = true; 

    return ret;
}



int main() {
	fastio;
	int v, e, a, b; cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		adlist[a].push_back(b); adlist[b].push_back(a);
	}
	for(int i = 1; i <= v; i++)
        if(!discovered[i]) dfs(i, true);
    
    int counts = 0;
    for(int i = 1; i <= v; i++)
        if(iscut[i]) counts++;
    
    cout << counts << "\n";

    for(int i = 1; i <= v; i++)
        if(iscut[i]) cout << i << ' ';
	

	
}