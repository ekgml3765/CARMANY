#include <iostream>
#include "header/car.h"
#include "header/user.h"
#include "header/manager.h"
using namespace std;

int active_user_id = -1;
string username;
userLinkedList userlist;

vector<Manager> managerVector;
vector<buyList> buyListVector;


int main(){
   
    vector<string> menu_list = {"차량 구매", "차량 추천", "마이페이지"};

    /*데이터 세팅 및 파일 경로설정*/
    Car car;
    string carfile_path = "C:\\Users\\user\\Documents\\GitHub\\data\\car.txt";
    string buyList_file = "C:\\Users\\user\\Documents\\GitHub\\data\\buyList.txt";
    string userfile_path = "C:\\Users\\user\\Documents\\GitHub\\data\\user.txt";
    //string carfile_path = "./car.txt";
    //string buyList_file = "./buyList.txt";
    //string buyList_file = "./user.txt";
    Car::openCarFile(carfile_path);
    
    
    int menu_num = 0;
    active_user_id = 2; //로그인한 유저
    username = "황다희";

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
                
                //data
                vector<Car> list = car.car_list_v; //페이징 처리를 위해 담을 리스트 초기화
                int sub_menu_num;
                int car_menu_num = 1;
                string engine[] = {"전기", "가솔린", "디젤", "하이브리드", "수소", "LPG"};
                string type[] = {"세단", "SUV", "RV", "해치백", "트럭"};
                while(car_menu_num != 8){
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
                        list = car.car_list_v;
                        car.getCarList(1, list);
                        cout << "전체 자동차 리스트 입니다. ";
                       
                    }
                    //차종별
                    else if(car_menu_num == 2){
                        cout << "검색할 차종 번호를 입력해주세요. (1.세단, 2.SUV, 3.RV, 4.해치백, 5.트럭):";
                        cin >> sub_menu_num;
                        if(sub_menu_num < 1 || sub_menu_num > 5)
                            cout << "잘못된 차종 번호입니다." << endl;
                        car.getCarList(2, list, type[sub_menu_num-1]);
                        cout << "차종별 자동차 리스트 입니다. ";
                        
                    }
                    //엔진별
                    else if(car_menu_num == 3){
                        cout << "검색할 엔진 번호를 입력해주세요. (1.전기, 2.가솔린, 3.디젤, 4.하이브리드, 5.수소, 6.LPG):";
                        cin >> sub_menu_num;
                        if(sub_menu_num < 1 || sub_menu_num > 5)
                            cout << "잘못된 엔진 번호입니다." << endl;
                        car.getCarList(3, list, engine[sub_menu_num-1]);
                        cout <<  "엔진별 자동차 리스트 입니다. ";
                        
                    }
                    //자동차명
                    else if(car_menu_num == 4){
                        cin.ignore();
                        cout << "검색할 자동차명을 입력해주세요:";
                        string carname;
                        getline(cin, carname);
                        car.getCarList(4, list, carname);
                        cout << "자동차명 검색 리스트 입니다. ";
                    }
                    //필터
                    else if(car_menu_num == 5){
                        cout << "적용하실 필터 번호를 입력해주세요. (1. 출시순, 2.낮은 가격순, 3.높은 가격순, 4.인기순):";
                        int filter;
                        cin >> filter;
                        car.getCarList(5, list, "", 1, filter);
                    }
                    //페이지 이동
                    else if(car_menu_num == 6){
                        cout << "이동하실 페이지 번호를 입력해주세요: ";
                        int page;
                        cin >> page;
                        bool flag = car.getCarList(6, list, "", page);
                        if(!flag)
                            cout << "잘못된 페이지 접근입니다. " <<endl;
                    }
                    //자동차 구매
                    else if(car_menu_num == 7){
                        if(active_user_id == -1){
                            cout << "로그인한 유저만 구매가 가능합니다." << endl;
                        }
                        string car_id;
                        cout << "구매할 자동차 번호를 입력하세요:";
                        cin >> car_id;
                        bool flag = car.getBuyCar(car_id, active_user_id, username, buyList_file);
                        if(!flag)
                            cout << "구매가 취소되었습니다." << endl;
                    }
                    //잘못된 입력
                    else{
                        cout << "메뉴 번호를 잘못 입력하셨습니다.";
                    }
                    cout << "메뉴를 선택해주세요 (0.상세보기 1.전체, 2.차종별, 3.엔진별, 4.자동차명, 5.필터적용, 6. 페이지 이동, 7.차량 구매. 8.메인으로 돌아가기) >>" << endl;
                    cin >> car_menu_num;         
                }
                break;
            }


            //2. 차량 추천
            case 2:{
                int reco_menu_num = 1;
                vector<Car> list = car.car_list_v; //페이징 처리를 위해 담을 리스트 초기화
                string brand[] = {"KIA", "HYUNDAI", "GENESIS"};
                string age[] = {"10대", "20대", "30대", "40대", "50대"};
                cout << "메뉴를 선택해주세요 (0.상세보기. 1. 연령별 추천, 2. 성별 추천, 3.브랜드별 추천 4. 페이지 이동 5.메인으로 돌아가기) >>" << endl;      
                cin >> reco_menu_num;
                while(reco_menu_num != 5){
                    //상세보기
                    if(reco_menu_num == 0){
                        string car_id;
                        cout << "조회할 자동차 번호를 입력하세요:";
                        cin >> car_id;
                        if(!car.getCarInfo(car_id))
                            cout << "해당 번호는 없는 번호입니다." << endl;
                    }
                    //연령별 추천
                    else if(reco_menu_num == 1){
                        cout << "추천받으실 연령대를 고르세요. (1.10대, 2.20대, 3.30대 4.40대 5.50대):";
                        int age_no;
                        cin >> age_no;
                        car.getRecoListByAge(age[age_no-1], list, buyList_file, userfile_path);
                    }
                    //성별 추천
                    else if(reco_menu_num == 2){

                    }
                    //브랜드별 추천
                    else if(reco_menu_num == 3){
                        cout << "추천받으실 브랜드를 고르세요. (1.KIA, 2.HYUNDAI, 3.GENESIS):";
                        int brand_no;
                        cin >> brand_no;
                        car.getRecoListByBrand(brand[brand_no-1], list);
                    }
                    //페이지 이동
                    else if(reco_menu_num == 4){
                        cout << "이동하실 페이지 번호를 입력해주세요: ";
                        int page;
                        cin >> page;
                        bool flag = car.getCarList(6, list, "", page);
                        if(!flag)
                            cout << "잘못된 페이지 접근입니다. " <<endl;
                    }
                    cout << "메뉴를 선택해주세요 (0.상세보기. 1. 연령별 추천, 2. 성별 추천, 3.브랜드별 추천 4. 페이지 이동 5.메인으로 돌아가기) >>" << endl; 
                    cin >> reco_menu_num;
                }
               break; 
            }


            //3. 마이페이지
            case 3:{
                
               break; 
            }
        }
        cin >> menu_num; //사용자 입력
    }
    Car::writeCarFile(carfile_path);
    cout << "로그아웃. 종료합니다!" << endl;

    return 0;
}