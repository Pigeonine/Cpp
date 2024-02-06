#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

struct customer {
    int id;
    int t_x, ar_time;
    customer(int p, int t, int c) : id(p), t_x(t), ar_time(c) {}    // 생성자 정의

    // 그냥 점수에 상관 없이 학번기준 학번이 작은것이 Top 을 유지 한다
    bool operator<(const customer s) const {
        return this->ar_time > s.ar_time;
    }
};

priority_queue<customer> later_customer;

queue<pair<int, int>> arrs;

int main() {
    fastio;
    int n, t, w, m, p_n, t_n, p_m, t_m, c_m;
    cin >> n >> t >> w;
    for(int i = 0; i < n; i++)
    {
        cin >> p_n >> t_n;
        arrs.push(make_pair(p_n,t_n));
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> p_m >> t_m >> c_m;
        later_customer.push(customer(p_m,t_m,c_m));
    }
    int cur_p = arrs.front().first;
    int cur_cus_t = arrs.front().second;
    int cur_rem_t = t;
    arrs.pop();
    for(int i = 0; i < w; i++)
    {
        if(later_customer.top().ar_time == i)
        {
            arrs.push(make_pair(later_customer.top().id,later_customer.top().t_x));
            later_customer.pop();
        }
        if(cur_cus_t == 0)
        {
            cur_p = arrs.front().first;
            cur_cus_t = arrs.front().second;
            arrs.pop();
            cur_rem_t = t;
        }
        else if(cur_rem_t == 0)
        {
            arrs.push(make_pair(cur_p, cur_cus_t));
            cur_p = arrs.front().first;
            cur_cus_t = arrs.front().second;
            arrs.pop();
            cur_rem_t = t;
        }
        cout << cur_p << "\n";
        cur_rem_t--; cur_cus_t--;
        
    }
}