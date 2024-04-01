#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int m;
void merge(int* arr, const int& p, const int& q, const int& r)
{
    int n1 = q-p+1, n2 = r - q,i,j,k;
    int* L = new int[n1];int* R = new int[n2];
    for(i = 0; i < n1; i++) L[i] = arr[p+i];
    for(i = 0; i < n2; i++) R[i] = arr[q+i+1];
    i = 0; j = 0;
    for(k = p; k <= r; k++){
        if(i >= n1) {
            arr[k] = R[j];
            j++;
        }
        else if(j >= n2){
            arr[k] = L[i];
            i++;
        }
        else if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
}

void msort(int* arr, const int& p, const int& r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        msort(arr, p, q);
        msort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}
int* merge_sort(int* arr, int n) {
    // implement your algorithm
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    // implement your algorithm
    msort(sorted, 0, n-1);
    return sorted;

}

int main() {
    fastio;
    cin >> m;
    //cout << 0 << ' ' << (m-1)/2 << ' ' << m-1 << ' ' << (m-1)/2 + 1 << ' ' << m - 1 - (m-1)/2;
    int* arrs = new int[m];
    for(int i = 0; i < m; i++) cin >> arrs[i];

    int* res = merge_sort(arrs, m);
    for(int i = 0; i < m; i++) cout << res[i] << "\n";
}