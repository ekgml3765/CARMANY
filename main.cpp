#include <iostream>
#include "header/car.h"
using namespace std;

int user_id = 1;

int main(){

    int menu_num = 0;

    cout << "대한민국 No.1 자동차 플랫폼 CARMANY 입니다.\n";
    cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지)" << endl;
    cin >> menu_num;

   Car car;

    switch(menu_num){
        //로그아웃
        case -1:{
            break;
        }
        //차량 구매
        case 1:{
            car.getCarList();
            break;
        }
        //차량 추천
        case 2:{
            break;
        }
        //마이페이지
        case 3:{
            break;
        }
    }

    return 0;
}