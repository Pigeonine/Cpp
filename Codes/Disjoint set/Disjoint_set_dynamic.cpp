int parent(int *parent_array, const int &target)
{
    if(target != parent_array[target]) return parent_array[target] = parent(parent_array, parent_array[target]);
    return target;
}

void init(int *parent_array, int n)
{
    for(int i = 1; i <= n; i++) parent_array[i] = i;
}

void uni(int *parent_array, const int &a, const int &b)
{
    int a_p = parent(parent_array, a); int b_p = parent(parent_array, b);
    if(a_p > b_p)
    {
        parent_array[a_p] = b_p;
    }
    else if(a_p < b_p)
    {
        parent_array[b_p] = a_p;
    }

}