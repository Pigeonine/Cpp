#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define TREEMAX 50001

using namespace std;

int n,m;

int trees[4*TREEMAX]{};//max seg tree, 인덱스를 node 값에 넣기
int years[TREEMAX]{}, rains[TREEMAX]{};

int init(int start, int end, int node)
{
    if(end <= start) 
    {
        trees[node] = end;
        return end;
    }

    int lind = init(start, (start+end)/2, 2*node),
    rind = init((start+end)/2 + 1, end, 2*node+1);
    if(rains[lind] >= rains[rind])//Z들의 값은 X보다 작아야함-> Z값과 X값이 같으면 Z를 올림
    {
        trees[node] = lind;
    }
    else 
        trees[node] = rind;

    return trees[node];
}


int query(int start, int end, int node, int left, int right)
{
    if(end < left || start > right) return 0;

    if(end <= right && start >= left) return trees[node];

    if(end >= left && start <= right) 
    {
        int lind = query(start, (start+end)/2, 2*node, left, right);
        int rind = query((start+end)/2+1, end, 2*node + 1, left, right);
        if(rains[lind] >= rains[rind])//Z들의 값은 X보다 작아야함-> Z값과 X값이 같으면 Z를 올림
            return lind;
        else 
            return rind;
    }

}

//둘다 없는 경우는 무조건 maybe, 한쪽이 없는 경우는 고려 해봐야 할듯.

int main()
{
    fastio;
    cin >> n;
    int y, r,Y,X;
    for(int i = 1; i <= n; i++) cin >> years[i] >> rains[i];
    cin >> m;
    init(1,n,1);
    //for(int i = 1; i < 4*n; i++) cout << trees[i] << ' ';
    cout << "\n";
    for(int i = 0; i < m; i++)// Y~X에서 최대는 Y, Y+1~X까지 최대는 X, 이에 해당되는 경우에는 index 사이가 모두 채워져야함
    {
        cin >> Y >> X;
        int Y_ind = lower_bound(years, years+n+1, Y) - years;
        int X_ind = lower_bound(years, years+n+1, X) - years;
        int YtoX = query(1,n,1,Y_ind,X_ind);
        int YptoX = query(1,n,1,Y_ind+1,X_ind);
        if(YtoX == Y_ind && YptoX == X_ind)
        {
            if(X_ind - Y_ind == X - Y) cout << "true"<< "\n";
            else cout << "maybe" << "\n";
        }
        else cout << "false" << "\n";
    }
}