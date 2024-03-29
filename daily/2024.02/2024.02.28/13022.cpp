#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    string s; cin >> s;
    char pre = '*'; int pre_num = 0, word_num = 0;
    if(s.length() == 0) {cout << 0; return 0;}
    for(int i = 0; i < s.length(); i++)
    {
        //cout << "test" << endl;
        switch (s[i])
        {
        case 'w':
            if(pre == '*' || pre == 'w')
            {
                pre_num++; pre = 'w';
            }
            else if(pre == 'f')
            {
                if(pre_num == word_num) {word_num = 0; pre_num = 1; pre = 'w';}
                else{cout << 0; return 0;}
            }
            else{
                cout << 0; return 0;
            }
            break;
        
        case 'o':
            if(pre == 'w')
            {
                word_num = pre_num; 
                pre_num = 1; 
                pre = 'o';
                
            }
            else if(pre == 'o')
            {
                pre_num++;
            }
            else{
                cout << 0; return 0;
            }
            break;

        case 'l':
            if(pre == 'o')
            {
                if(pre_num == word_num) {pre_num = 1; pre = 'l';}
                else{cout << 0; return 0;}
            }
            else if(pre == 'l')
            {
                pre_num++;
            }
            else{
                cout << 0; return 0;
            }
            break;
        case 'f':
            if(pre == 'l')
            {
                if(pre_num == word_num) {pre_num = 1; pre = 'f';}
                else{cout << 0; return 0;}
            }
            else if(pre == 'f')
            {
                pre_num++;
            }
            else{
                cout << 0; return 0;
            }
            break;

        default:
            cout << 0; return 0;
            break;
        }
        //cout << pre_num << ' ' << word_num << ' ' << pre << endl ;
    }
    if(pre == 'f' && pre_num == word_num){cout << 1;} 
    else cout << 0;

}