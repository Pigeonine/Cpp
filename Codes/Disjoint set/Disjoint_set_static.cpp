int parray[5000];

int parent(const int &target)
{
    if(target != parray[target]) return parray[target] = parent(parray[target]);
    return target;
}

void init(const int &n)
{
    for(int i = 0; i < n; i++) parray[i] = i;
}

void uni(const int &a, const int &b)
{
    int a_p = parent(a); int b_p = parent(b);
    if(a_p > b_p)
    {
        parray[a_p] = b_p;
    }
    else if(a_p < b_p)
    {
        parray[b_p] = a_p;
    }

}