#include <iostream>
#include <string>
#include "header/car.h"
#include "header/user.h"
#include "header/buylist.h"
#include "header/manager.h"
using namespace std;


int active_user_id = -1;
int manager_id = -1;
vector<Manager> managerVector;
vector<buyList> buyListVector;
userLinkedList userlist;
string username;
int menu_no; 
string id;
int login;

buylistC mark[200];
int totalBuyList;

int main()
{
    //user.txt 열고 userlist 생성
    openFile();

    //관리자 자료구조 호출
    getManagerList();
    //buyList 호출
    readBuyList();
    //carlist도 호출
    Car::openCarFile("car.txt");
    
    menu_no = 0; //0.{"CARMANY", "CARLIST", "CAR Recommend", "MYPAGE", "MANAGER"}
    id = "";
    login = 1;

    int order1 = -1; // 각 페이지에서 세부 기능 고를 때 쓰는 변수
    int order2 = 20000; // 세부 기능의 세부기능을 고를 때 쓰는 변수(디폴트 - 전체보기)


    /*데이터 세팅 및 파일 경로설정*/
    Car car;
    // string carfile_path = "C:\\Users\\user\\Documents\\GitHub\\data\\car.txt";
    // string buyList_file = "C:\\Users\\user\\Documents\\GitHub\\data\\buyList.txt";
    // string userfile_path = "C:\\Users\\user\\Documents\\GitHub\\data\\user.txt";
    string carfile_path = "car.txt";
    string buyList_file = "buyList.txt";
    string userfile_path = "user.txt";
    // Car::openCarFile(carfile_path);


    //CARMANY = 0, CARLIST = , CARRECO = 3, MYPATE = 4 , MANAGER =5
    while(1)
    {
        if (login == -1)
        {
            cout << "이용해 주셔서 감사합니다." << endl;
            break;
        }
        if (id == "관리자")
        {
            menu_no = 4;
        }

        // ui 시작
        if(menu_no != 1 && menu_no != 2){
             car.navbarPrint(login, menu_no, id);
        }
           

        if (menu_no == 0)
        {
            cout << "|      차량 구매                차량 추천                  마이페이지      |" << endl;
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
            cout << "+--------------------------------------------------------------------------+" << endl;

            cout << "대한민국 No.1 자동차 플랫폼 CARMANY 입니다.\n"; 

           if (login == 0) cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지 4. 프로그램 종료)>>";
           else{
                int choice;
                
                cout<<"메뉴를 선택해주세요.(1. 로그인 2. 회원 가입 3. 비회원 로그인 4. 관리자 로그인)>>";
                string chk;
                cin >> chk;
                if (chk == "1" || chk == "2"|| chk=="3" || chk=="4"){
				    choice = stoi(chk);
			    }
                else{
                    cout<<"다시 입력해주세요!"<<endl;
                    continue;
                }
                
                if (choice == 1){
                    if (!userLogin()) continue;
                    else {
                        login = 0;
                        id = username;
                        continue;
                    }

                }
                else if (choice == 2){
                    if (!createUser()){
                        cout<<" 계정 생성이 제대로 되지 않아 다시 시작합니다."<<endl;
                        continue;
                    }
                    else{
                        cout<<endl;
                        cout<<"회원가입이 잘 되었습니다!"<<endl;
                        cout<<username<<"의 계정이 생성되었습니다"<<endl;
                        cout<<"로그인 화면으로 돌아갑니다"<<endl;
                        continue;
                    }
                } 
                else if (choice == 3){
                    cout<<"비회원으로 로그인하셨습니다. !! 비회원 계정은 검색만 가능합니다."<<endl;
                    username = "비회원";
                    menu_no = 1;
                    continue;
                }
                else if (choice == 4){
                    if (!managerLogin()) {
                        continue;
                    }
                    else{
                        menu_no = 4;
                        login = 0;
                        id = "관리자";
                        continue;
                    }
                }
           }
                        
            while (1)
            {

                string chk;
                cin >> chk;
                if (chk == "1" || chk == "2"|| chk=="3" || chk=="4"){
				    order1 = stoi(chk);
			    }
                else{
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                    continue;
                }

                if (order1 == 1)
                {
                    menu_no = 1;
                    break;
                }
                else if (order1 == 2)
                {
                    menu_no = 2;
                    break;
                }
                else if (order1 == 3)
                {
                    menu_no = 3;
                    break;
                }
                else if (order1 == 4)
                {
                    char o;
                    while (1)
                    {
                        cout << "정말 종료하시겠습니까? (y/n)";
                        cin >> o;
                        if (o == 'y' || o == 'Y')
                        {
                            login = -1;
                            break;
                        }
                        else if (o == 'n' || o == 'N')
                        {
                            // cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지 4. 프로그램 종료)" << endl;
                            break;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                            continue;
                        }
                    }
                    break;
                    
                }
            }
            continue;

        }
        if (menu_no == 1)
        {        
                vector<Car> list = car.car_list_v; //페이징 처리를 위해 담을 리스트 초기화
                int sub_menu_num;
                int car_menu_num = 1;
                string engine[] = {"electric", "gasoline", "diesel", "hybrid", "hydrogen", "LPG"};
                string type[] = {"sedan", "SUV", "RV", "hatchback", "truck"};
                while(true){
                    //상세보기
                    if(car_menu_num == 0){
                        string car_id;
                        cout << "*조회할 자동차 번호를 입력하세요: ";
                        cin >> car_id;
                        if(!car.getCarInfo(car_id))
                            cout << "*해당 번호는 없는 번호입니다." << endl;
                    }
                    //전체
                    else if(car_menu_num == 1){
                        list = car.car_list_v;
                        car.getCarList(1, list);
                        cout << "*전체 자동차 리스트 입니다. ";
                       
                    }
                    //차종별
                    else if(car_menu_num == 2){
                        cout << "*검색할 차종 번호를 입력해주세요. (1.세단, 2.SUV, 3.RV, 4.해치백, 5.트럭): ";
                        cin >> sub_menu_num;
                        if(sub_menu_num < 1 || sub_menu_num > 5)
                            cout << "*잘못된 차종 번호입니다." << endl;
                        car.getCarList(2, list, type[sub_menu_num-1]);
                        cout << "*차종별 자동차 리스트 입니다. ";
                        
                    }
                    //엔진별
                    else if(car_menu_num == 3){
                        cout << "*검색할 엔진 번호를 입력해주세요. (1.전기, 2.가솔린, 3.디젤, 4.하이브리드, 5.수소, 6.LPG): ";
                        cin >> sub_menu_num;
                        if(sub_menu_num < 1 || sub_menu_num > 5)
                            cout << "*잘못된 엔진 번호입니다." << endl;
                        car.getCarList(3, list, engine[sub_menu_num-1]);
                        cout <<  "*엔진별 자동차 리스트 입니다. ";
                        
                    }
                    //자동차명
                    else if(car_menu_num == 4){
                        cin.ignore();
                        cout << "*검색할 자동차명을 입력해주세요:";
                        string carname;
                        getline(cin, carname);
                        car.getCarList(4, list, carname);
                        cout << "*자동차명 검색 리스트 입니다. ";
                    }
                    //필터
                    else if(car_menu_num == 5){
                        cout << "*적용하실 필터 번호를 입력해주세요. (1. 출시순, 2.낮은 가격순, 3.높은 가격순, 4.인기순): ";
                        int filter;
                        cin >> filter;
                        car.getCarList(5, list, "", 1, filter);
                    }
                    //페이지 이동
                    else if(car_menu_num == 6){
                        cout << "*이동하실 페이지 번호를 입력해주세요: ";
                        int page;
                        cin >> page;
                        bool flag = car.getCarList(6, list, "", page);
                        if(!flag)
                            cout << "*잘못된 페이지 접근입니다. " <<endl;
                    }
                    //자동차 구매
                    else if(car_menu_num == 7){
                        if(login != 0){
                            cout << "*로그인한 유저만 구매가 가능합니다." << endl;
                            break;
                        }
                        string car_id;
                        cout << "*구매할 자동차 번호를 입력하세요: ";
                        cin >> car_id;
                        bool flag = car.getBuyCar(car_id, active_user_id, username, buyList_file);
                        if(!flag)
                            cout << "*구매가 취소되었습니다." << endl;
                    }
                    //잘못된 입력
                    else{
                        cout << "*메뉴 번호를 잘못 입력하셨습니다.";
                    }
                    cout << "메뉴를 선택해 주세요. (-1. 입력시 홈 화면 이동)" << endl;
                    cout << "*0. 상세보기 1. 전체보기 2. 차종별 보기 3. 엔진별 보기 4. 차 이름 검색 5. 필터\n 6. 페이지 이동, 7. 구매 >>"  ; 
                    cin>>car_menu_num;
                    if(car_menu_num == -1)
                        break;
                } 
                menu_no = 0; 
                continue;

        }



        if (menu_no == 2)
        {
                int reco_menu_num = 9;
                vector<Car> list = car.car_list_v; //페이징 처리를 위해 담을 리스트 초기화
                string brand[] = {"KIA", "HYUNDAI", "GENESIS"};
                string age[] = {"20대", "30대", "40대", "50대"};
                while(true){
                    //초기 현대 브랜드 리스트 뿌리기
                    if(reco_menu_num == 9){
                        list = car.car_list_v;
                        car.getRecoListByBrand(brand[1], list);
                        cout << "*추천 서비스에 오신걸 환영합니다.";
                    }
                    //상세보기
                    else if(reco_menu_num == 0){
                        string car_id;
                        cout << "조회할 자동차 번호를 입력하세요:";
                        cin >> car_id;
                        if(!car.getCarInfo(car_id, true))
                            cout << "해당 번호는 없는 번호입니다." << endl;
                    }
                    //연령별 추천
                    else if(reco_menu_num == 1){
                        cout << "추천받으실 연령대를 고르세요. (1.20대, 2.30대, 3.40대 4.50대):";
                        int age_no;
                        cin >> age_no;
                        car.getRecoListByAge(age[age_no-1], list, buyList_file, userfile_path);
                    }
                    //브랜드별 추천
                    else if(reco_menu_num == 2){
                        cout << "추천받으실 브랜드를 고르세요. (1.KIA, 2.HYUNDAI, 3.GENESIS):";
                        int brand_no;
                        cin >> brand_no;
                        car.getRecoListByBrand(brand[brand_no-1], list);
                    }
                    //페이지 이동
                    else if(reco_menu_num == 3){
                        cout << "이동하실 페이지 번호를 입력해주세요: ";
                        int page;
                        cin >> page;
                        bool flag = car.getCarList(6, list, "", page, 0, true);
                        if(!flag)
                            cout << "잘못된 페이지 접근입니다. " <<endl;
                    }
                    cout << "메뉴를 선택해주세요 (0.상세보기. 1. 연령별 추천, 2.브랜드별 추천 3. 페이지 이동 -1.메인으로 돌아가기) >>" << endl; 
                    cin>>reco_menu_num;
                    if(reco_menu_num == -1)
                        break;
                }
                menu_no = 0;       
                continue;      

        }
        if (menu_no == 3)
        {
            cout << "|      구매 리스트                                        회원정보 수정    |" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
            if (order2 == 20000)
            {
                // 수정 필요 -> order2가 어디서 바뀌어서 이 if문으로 못들어오는듯
                getMyCarList();
                viewMyCar(active_user_id);
            }
            else if (order2 == 20001)
            {
                bool t;
                // 회원정보 수정
                //회원정보 수정하기 - user.cpp에 userUpdate가 있습니다.
                // userUpdate()
                t = userUpdate();
                cout<<t<<endl;
                if (t == 0)
                {
                    menu_no = 0;
                }
            }

            while (1)
            {
                cout << "메뉴를 선택해주세요 (0.구매 리스트 보기. 1. 회원정보 수정 -1.메인으로 돌아가기) >>" ;
                //예외처리
                    string chk;
                    cin >> chk;
                    if (chk == "0" || chk == "1"|| chk=="-1"){
                        order2 = stoi(chk);
                    }
                    else{
                        cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        continue;
                    }
                    //예외처리
                if (order2 == 0)
                {
                    order2 = 20000;
                    break;
                }
                else if (order2 == 1)
                {
                    order2 = 20001;
                    break;
                }
                else if (order2 == -1)
                {
                    menu_no = 0;
                    break;
                }
                else
                {
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                }
            }
        }

        if (menu_no == 4)  // 관리자는 로그아웃하지 않는 이상 이 안에서만 놀게함 -> 얘는 디폴트 화면 -> order2에 20000할당
        {
            if (order2 == 20000)
            {
                cout << "|   입출고 관리      재고 현황      구매 리스트      매출 관리             |" << endl;
                cout << "|--------------------------------------------------------------------------|" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|   차량 입고   |   전체 재고   |   전체   |   전체 매출   |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|   차량 출고   |  상품별 재고  | 브랜드별 | 브랜드별 매출 |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |  회원별  |               |               |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "+--------------------------------------------------------------------------+" << endl;
                cout << "메뉴 선택 (1.입출고 관리 2. 재고 현황 3. 구매 리스트 4. 매출 관리 5. 로그아웃) >>" ;
            }
            else
            {
                if (order1 == 1)
                {
                    cout << "|               차량 입고               차량 출고                          |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 10001)
                        {
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                      차량 입고 선택하셨습니다.                           |"<<endl;
                            cout<<  "|   새로운 차량 목록이 담긴 inputCar.txt를 읽어  정보 업데이트 시작합니다. |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout<<  "|                                                                          |"<<endl;
                            cout << "+--------------------------------------------------------------------------+" << endl;
                        
                            if (inputCarList()){
                                cout<<"차량 목록이 성공적으로 업데이트 되었습니다.\n";
                            }
                            else{
                                cout<<"차량 목록 업데이트에 실패하였습니다. inputCar.txt와 car.txt를 확인하세요.\n";
                            }

                            order2 = 20000;
                            continue;
                        
                    }
                    
                    else if (order2 == 10002)
                    { 
                        // cout<<  "|   No.   구매자   차량 이름   브랜드   차종  엔진  색상    가격(만원)     |"<<endl;
                        // cout << "|--------------------------------------------------------------------------|" << endl;
                        cout << "----------------------------------------------------------------------------" << endl;

                        if (outputBuyList()){
                            cout << "----------------------------------------------------------------------------" << endl;
                            cout<<"차량 출고 리스트입니다.\n";
                        }
                        else{
                            cout << "----------------------------------------------------------------------------" << endl;
                            cout<<"buyList가 없습니다.\n";
                        }

                        order2 = 20000;
                        continue;
                    }
                
                }
                else if (order1 == 2)
                {
                    cout << "|             전체 재고                            상품별 재고             |" << endl;
                    cout << "----------------------------------------------------------------------------" << endl;
                    if (order2 == 20001)
                    {
                        // 전체 재고 목록 출력하는 함수
                        stockOutput(1);
                        cout<<  "----------------------------------------------------------------------------" << endl;
                        cout<<"전체 수량 확인을 선택하셨습니다."<<endl;
  
                    }
                    else if (order2 == 20002)
                    {
                        // 상품별 목록 출력하는 함수
                        // cout<<  "|                                                                          |"<<endl;
                        // cout<<  "|                                                                          |"<<endl;
                        // cout<<  "| No.    차량 이름      전체 수량      남은 수량           판매 수량       |"<<endl;
                        // cout << "----------------------------------------------------------------------------" << endl;
                        stockOutput(2);
                        cout << "----------------------------------------------------------------------------" << endl;
                        cout<<"상품별 재고 현황 확인 선택하셨습니다."<<endl;
                    }
                    order2 = 20000;
                    continue;
                }
                else if (order1 == 3)
                {
                    while(1){
                        cout << "|     전체 구매 리스트     브랜드별 구매 리스트      회원별 구매 리스트    |" << endl;
                        cout << "|--------------------------------------------------------------------------|" << endl;
                        if (order2 == 30001)
                        {
                            // 전체 구매 리스트 출력하는 함수
                            // cout<<  "|No.  구매자   차량 이름   브랜드   차종  엔진  색상    가격(만원)         |"<<endl;
                            // cout << "|--------------------------------------------------------------------------|" << endl;
                            cout << "----------------------------------------------------------------------------" << endl;
                            buyListOutput(1);
                            cout << "----------------------------------------------------------------------------" << endl;
                            cout<<"전체 구매 리스트입니다.\n";
                            break;
                        }
                        else if (order2 == 30002)
                        {   
                            // 브랜드별 구매 리스트 출력하는 함수
                            if (buyListOutput(3)){
                            //  cout<<  "|                                                                          |"<<endl;
                            //  cout<<  "|                                                                          |"<<endl;
                             cout << "----------------------------------------------------------------------------" << endl;
                             break;
                            } 
                            else{
                            //  cout<<  "|                                                                          |"<<endl;
                            //  cout<<  "|                                                                          |"<<endl;
                             cout << "----------------------------------------------------------------------------" << endl;
                            }
                        }
                        else if (order2 == 30003)
                        {
                            // 회원별 구매 리스트 출력하는 함수
                             if (buyListOutput(2)){
                                // cout<<  "|                                                                          |"<<endl;
                                // cout<<  "|                                                                          |"<<endl;
                                cout << "----------------------------------------------------------------------------" << endl;
                                break;
                            } 
                            else{
                                cout << "|--------------------------------------------------------------------------|" << endl;
                            }
                        }
                    }
                    order2 = 20000;
                    continue;
                }
                else if (order1 == 4)
                {

                    cout << "|               전체 매출               브랜드별 매출                      |" << endl;
                    cout << "----------------------------------------------------------------------------" << endl;
                    if (order2 == 40001)
                    {
                        // 전체 매출 출력하는 함수
                        billing(1);
    
                    }
                    else if (order2 == 40002)
                    {
                        // 브랜드별 매출 출력하는 함수
                        billing(2);

                    }
                    order2 = 20000;
                    continue;
                }
     
            }

            while (1)
            {   cout << "메뉴 선택 (1.입출고 관리 2. 재고 현황 3. 구매 리스트 4. 매출 관리 5. 로그아웃) >>" ;
                string chk;
                cin >> chk;
                if (chk == "1" || chk == "2"|| chk=="3" || chk=="4"||chk=="5"){
				    order1 = stoi(chk);
			    }
                else{
                    cout<<"다시 입력해주세요!"<<endl;
                    continue;
                }

                if (order1 == 1)
                {
                    cout << "세부 메뉴를 선택해 주세요. ";
                    while (1)  // 입출고 관리 10001, 10002 할당
                    {   
                        cout << "1. 차량 입고 2. 차량 출고 >>";
                        string chkk;
                        cin >> chkk;
                        if (chkk == "1" || chkk == "2"){
                            order2 = stoi(chkk);
                        }
                        else{
                            cout<<"다시 입력해주세요!"<<endl;
                            continue;
                        }

                        if (order2 == 1)
                        {
                            order2 = 10001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 = 10002;
                            break;
                        }
                    }
                    break;
                }
                else if (order1 == 2)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    while (1)  // 재고 현황은 20001, 20002 할당
                    {   
                        cout << "1. 전체 재고 2. 상품별 재고 >>" ;
                        string chkk;
                        cin >> chkk;
                        if (chkk == "1" || chkk == "2"){
                            order2 = stoi(chkk);
                        }
                        else{
                            cout<<"다시 입력해주세요!"<<endl;
                            continue;
                        }

                        if (order2 == 1)
                        {
                            order2 = 20001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 = 20002;
                            break;
                        }
                    }
                    break;
                }
                else if (order1 == 3)
                {
                    cout << "세부 메뉴를 선택해 주세요.";
                    while (1)  // 구매리스트 30001, 30002, 30003 할당
                    {
                        cout << "(1. 전체 구매 리스트 2. 브랜드별 구매 리스트 3. 회원별 구매 리스트) >>" ;
                        string chkk;
                        cin >> chkk;
                        if (chkk == "1" || chkk == "2" || chkk == "3"){
                            order2 = stoi(chkk);
                        }
                        else{
                            cout<<"다시 입력해주세요!"<<endl;
                            continue;
                        }

                        if (order2 == 1)
                        {
                            order2 = 30001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 = 30002;
                            break;
                        }
                        else if (order2 == 3)
                        {
                            order2 = 30003;
                            break;
                        }
                    }
                    break;
                }
                else if (order1 == 4)
                {
                    cout << "세부 메뉴를 선택해 주세요."; 
                    while (1)  // 매출 관리는 40001, 40002 할당
                    {
                        cout << "(1. 전체 매출 2. 브랜드별 매출) >>";
                        string chkk;
                        cin >> chkk;
                        if (chkk == "1" || chkk == "2"){
                            order2 = stoi(chkk);
                        }
                        else{
                            cout<<"다시 입력해주세요!"<<endl;
                            continue;
                        }

                        if (order2 == 1)
                        {
                            order2 = 40001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 = 40002;
                            break;
                        }
                    }
                    break;
                }
                else if (order1 == 5)
                {
                    managerLogout();

                }
                else{
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                    break;

                }
            }


        }

        //cout << "+--------------------------------------------------------------------------+" << endl;
    }
}