#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;


vector<long long> arrs;
vector<long long> trees;

void init(vector<long long> &a, vector<long long>& tree, int node, int start, int end)
{
    if(start == end) 
    {
        tree[node] = a[start];
    }
    else 
    {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] +tree[node*2 + 1];
    }

}


long long calc(vector<long long> &a, vector<long long>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) 
    {
        return 0;
    }
    else if(left <= start && end <= right)
    {
        return tree[node];
    }
    
    long long lsum = calc(a, tree, 2*node, start, (end+start)/2, left, right);
    long long rsum = calc(a, tree, 2*node + 1, (end+start)/2+1, end, left, right);
    return lsum + rsum;


}


void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
    if(index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end)
    {
        update(tree, 2*node, start, (start+end)/2, index, diff);
        update(tree, 2*node+1, (start+end)/2+1, end, index, diff);  
    }
}

void update(vector<long long> &a, vector<long long>& tree, int n, int index, long long val)
{
    long long diff = val - a[index];
    a[index] = val;
    update(tree, 1, 0, n-1, index, diff);
}


int main() {
    fastio;
    long long n, m, k, temp, a, b, c; cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp);
    }   
    long long height = ceil(log2(n));
    trees.resize((1<<(height+1))+1);
    init(arrs,trees, 1, 0, n-1);
    for(int i = 0; i < m+k; i++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            update(arrs, trees, n, b-1, c);
        }
        else if(a ==2) {
            cout << calc(arrs, trees, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}