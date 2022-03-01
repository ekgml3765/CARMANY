#include <iostream>
#include "header/car.h"
#include "header/user.h"
using namespace std;

int active_user_id = -1;
string username;
userLinkedList userlist;
int user_id = -1;
//extern vector<Car> carList = Car::openCarFile();

int main(){

    int menu_num = 0;
    cout << "대한민국 No.1 자동차 플랫폼 CARMANY 입니다.\n";
    cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지)" << endl;
    cin >> menu_num;

    user_id = 1;
    Car car;
    
    switch(menu_num){
        
        
        //로그아웃
        case -1:{
            cout << "로그아웃!" << endl;
            break;
        }


        //차량 구매
        case 1:{
            int num = 0;
            string ment = "";
            string selectMent = "메뉴를 선택해주세요 (0.전체, 1.차종별, 2.엔진별, 3.자동차명, 4. 필터, 5. 페이지 이동, 6.상세보기) >>";
            while(num != -1){
                if(num == 0){
                    car.getCarList(0, 1);
                    ment = "전체 자동차 리스트 입니다. ";
                }else if(num == 1){
                    car.getCarList(1, 1);
                    ment = "차종별 자동차 리스트 입니다. ";
                }else if(num == 2){
                    car.getCarList(2, 1);
                    ment = "엔진별 자동차 리스트 입니다. ";
                }else if(num == 3){
                    car.getCarList(3, 1);
                    ment = "자동차명 리스트 입니다. ";
                }else if(num == 4){
                }
                else if(num == 5){
                }
                else{
                   
                }
                cout << ment << selectMent << endl;
                cin >> num;             
            }
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