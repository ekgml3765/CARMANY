#include <iostream>
#include "header/car.h"
#include "header/user.h"
using namespace std;

int active_user_id = -1;
string username;
userLinkedList userlist;
int user_id = -1;


int main(){
   
    
    vector<string> menu_list = {"차량 구매", "차량 추천", "마이페이지"};

    //자동차
    Car car;
    Car::openCarFile();
    user_id = 1;
    int menu_num = 0;
    while(menu_num != -1){
        //상단 메뉴 출력        
        switch(menu_num){
            //메인화면
            default:{
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    cout << "|      ";
                    for (int i = 0; i < menu_list.size(); i++)
                    {
                        cout << menu_list[i] << " ";   
                    }
                    cout << "|" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    cout << "|                                                                          |" << endl;
                    cout << "|                                                                          |" << endl;
                    cout << "|  .d8008b.  .d8008b.  .d8008b.  .d888888b.  .d8008b.  .d8008b.  dP    dP  |" << endl;
                    cout << "|  88        88    88  88    88  88  88  88  88    88  88    88  dP    dP  |" << endl;
                    cout << "|  88        88    88  8800808P  88  88  88  88    88  88    88  dPYYYYdP  |" << endl;
                    cout << "|  88        88YYYY88  8800      88  88  88  88YYYY88  88    88     00     |" << endl;
                    cout << "|  88        88    88  88  00    88  88  88  88    88  88    88     00     |" << endl;
                    cout << "|  888008b.  88    88  88   000  88  88  88  88    88  88    88     00     |" << endl;
                    cout << "|                                                                          |" << endl;
                    cout << "|                        _____.-------__            신차 살 땐             |" << endl;
                    cout << "|                      /                '--.               카매니          |" << endl;
                    cout << "|             ________/                     '--.                           |" << endl;
                    cout << "|            /*    __                  __       |  ~~~@@@@                 |" << endl;
                    cout << "|           |____ /  \\ ______________ /  \\ ____--  ~~~@@                   |" << endl;
                    cout << "|                 \\__/                \\__/                                 |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    cout << endl;
                    cout << "대한민국 No.1 자동차 플랫폼 CARMANY 입니다.\n";
                    cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지)" << endl;
                break;
            }

            //1. 차량 구매
            case 1:{
                menu_list = {"전체", "차종별", "엔진", "자동차명"};
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    cout << "|      ";
                    for (int i = 0; i < menu_list.size(); i++)
                    {
                        cout << menu_list[i] << " ";   
                    }
                    cout << "|" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;           
                
                int car_menu_num = 1;
                string ment = "";
                while(car_menu_num != -1){
                    //상세보기
                    if(car_menu_num == 0){
                        string car_id;
                        cout << "조회할 자동차 번호를 입력하세요:";
                        cin >> car_id;
                        if(!car.getCarInfo(car_id))
                            cout << "해당 번호는 없는 번호입니다." << endl;
                    }
                    //전체
                    else if(car_menu_num == 1){
                        car.getCarList(1, 1);
                        ment = "전체 자동차 리스트 입니다. ";
                       
                    }
                    //차종별
                    else if(car_menu_num == 2){
                        car.getCarList(2, 1);
                        ment = "차종별 자동차 리스트 입니다. ";
                        
                    }
                    //엔진별
                    else if(car_menu_num == 3){
                        car.getCarList(3, 1);
                        ment = "엔진별 자동차 리스트 입니다. ";
                        
                    }
                    //자동차명
                    else if(car_menu_num == 4){
                        car.getCarList(4, 1);
                        ment = "자동차명 자동차 리스트 입니다. ";
                    }
                    //필터
                    else if(car_menu_num == 5){
                        car.getCarList(5, 1);
                    }
                    //페이지 이동
                    else if(car_menu_num == 6){
                    
                    }
                    //자동차 구매
                    else{
                        string car_id;
                        cout << "구매할 자동차 번호를 입력하세요:";
                        cin >> car_id;
                        if(!car.getBuyCar(car_id))
                            cout << "구매가 취소되었습니다." << endl;
                    }
                    cout << ment << "메뉴를 선택해주세요 (0.상세보기 1.전체, 2.차종별, 3.엔진별, 4.자동차명, 5.필터적용, 6. 페이지 이동, 7.차량 구매) >>" << endl;
                    cin >> car_menu_num;             
                }
                break;
            }


            //2. 차량 추천
            case 2:{
                
               break; 
            }


            //3. 마이페이지
            case 3:{
                
               break; 
            }
        }
        cin >> menu_num; //사용자 입력
    }
    cout << "로그아웃. 종료합니다!" << endl;

    return 0;
}