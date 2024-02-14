#include <iostream>
using namespace std;
int main() {
    int resp;
    for(int a=1; a<=9; a++){
        // A가 a인지 물어보고 flush를 한다.
        // endl은 자동으로 flush도 해준다.
        std::cout << "? A " << a << std::endl;

        // 채점기의 답변을 입력받는다.
        std::cin >> resp;

        if(resp == 1){
            // 답변이 "예"이므로 A의 값은 a이다.
            // B의 값도 알아내야 하는데, 이 부분은 직접 채워보자.
            int resp_b;
            int b;
            for(b = 1; b <= 9; b++)
            {
                cout << "? B " << b << endl;

                std::cin >> resp_b;
                if(resp_b == 1){break;}
            }
            std::cout << "! " << a + b;
            break;
        }
    }
}