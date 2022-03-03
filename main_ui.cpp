#include <iostream>
#include <string>
#include "header/car.h"
#include "header/user.h"
#include "header/manager.h"
using namespace std;

int active_user_id = -1;
int manager_id = -1;
vector<Manager> managerVector;
vector<buyList> buyListVector;
userLinkedList userlist;
string username;

int main()
{
    //user.txt 열고 userlist 생성
    openFile();
    //관리자 자료구조 호출
    getManagerList();
    //buyList 호출
    readBuyList();
    //carlist도 호출
    // Car::openCarFile("car.txt");

    string menu_name; // 최상단 메뉴 이름
    menu_name = "MANAGER";

    string id; // 로그인 했을 때 아이디
    id = "";

    int login; // 로그인시 0, 비회원 1, 관리자 2, 종료 -1
    login = 1;

    int order1 = -1; // 각 페이지에서 세부 기능 고를 때 쓰는 변수
    int order2 = 20000; // 세부 기능의 세부기능을 고를 때 쓰는 변수(디폴트 - 전체보기)


    while(1)
    {
        if (login == -1)
        {
            cout << "이용해 주셔서 감사합니다." << endl;
            break;
        }
        if (id == "관리자")
        {
            menu_name = "Manager";
        }

        // ui 시작
        cout << "+--------------------------------------------------------------------------+" << endl;
        cout << '|';
        if (menu_name.length() % 2 == 0)
        {
            for (int i = 0; i < 34 - menu_name.length() / 2 + 1; i++)
            {
                cout << ' ';
            }
        }
        else
        {
            for (int i = 0; i < 34 - menu_name.length() / 2; i++)
            {
                cout << ' ';
            }
        }
        cout << menu_name;
        if (login == 1) // 로그인 안했을 때
        {
            for (int i = 0; i < 21 - menu_name.length() / 2; i++)
            {
                cout << ' ';
            }
            cout << "회원가입 / 로그인 |" << endl;
        }
        else  // 로그인 했을 때
        {
            for (int i=0; i < 42 - id.length() - menu_name.length(); i++)
            {
                cout << ' ';
            }
            cout << id << " 님 |"<< endl;
        }

        cout << "|--------------------------------------------------------------------------|" << endl;


        if (menu_name == "CARMANY")
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

           if (login == 0) cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지 4. 프로그램 종료)" << endl;
           else{
                int choice;
                cout<<"메뉴를 선택해주세요.(1. 로그인 2. 회원 가입 3. 비회원 로그인 4. 관리자 로그인)>>";
                cin>>choice;
                
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
                    menu_name = "CARLIST";
                    continue;
                }
                else if (choice == 4){
                    if (!managerLogin()) {
                        continue;
                    }
                    else{
                        menu_name = "MANAGER";
                        login = 0;
                        id = "관리자";
                        continue;
                    }
                }
           }
                        
            while (1)
            {
                cin >> order1;
                if (order1 == 1)
                {
                    menu_name = "CARLIST";
                    break;
                }
                else if (order1 == 2)
                {
                    menu_name = "CAR Recommend";
                    break;
                }
                else if (order1 == 3)
                {
                    menu_name = "MYPAGE";
                    break;
                }
                else if (order1 == 4)
                {
                    char o;
                    cout << "정말 종료하시겠습니까? (y/n)";
                    cin >> o;
                    if (o == 'y' || o == 'Y')
                    {
                        login = -1;
                        break;
                    }
                    else if (o == 'n' || o == 'N')
                    {
                        cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지 4. 프로그램 종료)" << endl;
                        continue;
                    }
                    else
                    {
                        cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        continue;
                    }
                    
                }
                else
                {
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                }
            }
            continue;

        }
        if (menu_name == "CARLIST")
        {

            // 페이징을 위한 변수들
            int total_cars = 52;                   // 전체 차의 수
            int first_car_id = 35;                  // 리스트 맨 위에 뜰 차의 인덱스
            int page_num = (first_car_id + 7) / 7; // 현재 페이지(앞 뒤 보여줄 인덱스 계산용)
            int now = (first_car_id + 7) / 7;      // 현재 페이지
            int page_cnt = 0;                      // 보여주는 페이지 수 카운트

            string listMenu = "전체";



            cout << "|      전체            차종별            엔진            차 이름 검색      |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;
            
            
            
            // cout << "|  총 " << total_cars << "건 조회";
            // for (int i = 0; i <  33 - to_string(total_cars).size(); i++)
            // {
            //     cout << ' ';
            // }
            // cout << "필터 [인기순/출시순/가격순]  |" << endl;







            if (order2 >= 1 && order2 <= 1000)  // 1000은 자동차 전체 개수로 바꿔주기@@
            {
                // carListMenu번호인 자동차 상세 정보 출력하는 함수
            }
            else if (order2 == 20000)
            {
                // 자동차 전체 리스트 출력하는 함수
            }
            else if (order2 >= 30001 && order2 <= 30005)
            {
                // 차종에 따른 자동차 리스트 출력하는 함수
                // (30001세단 30002RV 30003SUV 30004해치백 30005트럭)
            }
            else if (order2 >= 40001 && order2 <= 40006)
            {
                // 엔진에 따른 자동차 리스트 출력하는 함수
                // (40001부터 전기 가솔린 디젤 하이브리드 수소 LPG 순)
            }










            
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                                                                          |" << endl;
            
            
            // 페이징
            // 두자리 수 페이지로 넘어가면 모양 이상해짐 -> 수정@@
            cout << "|                             ";
            while (1)
            {
                if (page_cnt == 5)
                {
                    cout << "                            |" << endl;
                    break;
                }
                if (page_num - 2 > 0)
                {
                    if (page_num - 2 > total_cars / 7 + 1)
                    {
                        for (int i = 0; i < 45 - page_cnt * 3 - 2; i++)
                        {
                            cout << ' ';
                        }
                        cout << '|' << endl;
                        break;
                    }
                    if (page_num - 2 == now)
                    {
                        cout << " \'" << page_num - 2 << "\' ";
                        page_num++;
                        page_cnt++;
                    }
                    else
                    {
                        cout << ' ' << page_num - 2 << ' ';
                        page_num++;
                        page_cnt++;
                    }
                }
                else
                {
                    page_num++;
                }
                
            }
            cout << "+--------------------------------------------------------------------------+" << endl;
            cout << "***** 자동차 리스트입니다. 메뉴를 선택해 주세요. (-1 입력시 홈 화면 이동)" << endl;
            cout << "1. 상세보기 2. 전체보기 3. 차종별 보기 4. 엔진별 보기 5. 차 이름 검색" << endl;


            while (1)
            {
                cin >> order1;
                if (order1 == 1)
                {
                    cout << "차 번호를 입력해 주세요." << endl;
                    cin >> order2;  // 자동차 상세보기는 (1~차의 총 개수)로 할당
                    menu_name = "CAR Details";
                    break;
                }
                else if (order1 == 2)
                {
                    menu_name = "CARLIST";
                    order2 = 20000; // 자동차 전체보기는 20000으로 할당
                    break;
                }
                else if (order1 == 3)
                {
                    menu_name = "CARLIST";
                    cout << "차종을 선택해 주세요." << endl;
                    cout << "1. 세단 2. SUV 3. RV 4. 해치백 5. 트럭" << endl;
                    while (1)  // 차종은 30001~30005 할당
                    {
                        cin >> order2;
                        if (order2 == 1)
                        {
                            order2 == 30001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 == 30002;
                            break;
                        }
                        else if (order2 == 3)
                        {
                            order2 == 30003;
                            break;
                        }
                        else if (order2 == 4)
                        {
                            order2 == 30004;
                            break;
                        }
                        else if (order2 == 5)
                        {
                            order2 == 30005;
                            break; 
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 4)
                {
                    menu_name = "CARLIST";
                    cout << "엔진을 선택해 주세요." << endl;
                    cout << "1. 전기 2. 가솔린 3. 디젤 4. 하이브리드 5. 수소 6. LPG" << endl;
                    while (1)  // 차종은 40001~40006 할당
                    {
                        cin >> order2;
                        if (order2 == 1)
                        {
                            order2 == 40001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 == 40002;
                            break;
                        }
                        else if (order2 == 3)
                        {
                            order2 == 40003;
                            break;
                        }
                        else if (order2 == 4)
                        {
                            order2 == 40004;
                            break;
                        }
                        else if (order2 == 5)
                        {
                            order2 == 40005;
                            break; 
                        }
                        else if (order2 == 6)
                        {
                            order2 == 40006;
                            break; 
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 5)
                {
                    order2 = 50001;
                    // 차 이름 검색 기능    
                }
                else if (order1 == -1)
                {
                    menu_name = "CARMANY";
                    break;
                }
                else
                {
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                    continue;
                }
            }
            continue;
        }



        if (menu_name == "CAR Recommend")
        {
            cout << "|   연령대별 추천       성별 추천       브랜드별 추천        개인화 추천   |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;
        }
        if (menu_name == "MYPAGE")
        {

            
            cout << "|      구매 리스트              찜 리스트                 회원정보 수정    |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;

            //회원정보 수정하기 - user.cpp에 userUpdate가 있습니다.
            //userUpdate
            
        }

        if (menu_name == "MANAGER")  // 관리자는 로그아웃하지 않는 이상 이 안에서만 놀게함 -> 얘는 디폴트 화면 -> order2에 20000할당
        {
            if (order2 == 20000)
            {
                cout << "|   입출고 관리      재고 현황      구매 리스트      매출 관리      통계   |" << endl;
                cout << "|--------------------------------------------------------------------------|" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|   차량 입고   |   전체 재고   |   전체   |   전체 매출   |   성별 통계   |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|   차량 출고   |  상품별 재고  |  브랜드별  | 브랜드별 매출 |              |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |  회원별  |               |               |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "+--------------------------------------------------------------------------+" << endl;
                cout << "메뉴 선택 1.입출고 관리 2. 재고 현황 3. 구매 리스트 4. 매출 관리 5. 통계 6. 로그아웃" << endl;
            }
            else
            {
                if (order1 == 1)
                {
                    cout << "|               차량 입고               차량 출고                           |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 10001)
                        {
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                      차량 입고 선택하셨습니다.                            |"<<endl;
                            cout<<  "|   새로운 차량 목록이 담긴 inputCar.txt를 읽어  정보 업데이트 시작합니다.  |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout<<  "|                                                                           |"<<endl;
                            cout << "|--------------------------------------------------------------------------|" << endl;
                        
                            if (inputCarList()){
                                cout<<"차량 목록이 성공적으로 업데이트 되었습니다.\n";
                                continue;
                            }
                            else{
                                cout<<"차량 목록 업데이트에 실패하였습니다. inputCar.txt와 car.txt를 확인하세요.\n";
                                continue;
                            }
                        
                    }
                    
                    else if (order2 == 10002)
                    { 
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|   No.   구매자   차량 이름   브랜드   차종  엔진  색상    가격(만원)        |"<<endl;
                        cout << "| --------------------------------------------------------------------------|" << endl;

                        if (outputBuyList()){
                            cout << "| --------------------------------------------------------------------------|" << endl;
                            cout<<"차량 출고 리스트입니다.\n";
                        }
                        else{
                            cout << "| --------------------------------------------------------------------------|" << endl;
                            cout<<"buyList가 없습니다.\n";
                        }

                        order2 = 20000;
                    }
                
                }
                else if (order1 == 2)
                {
                    cout << "|               전체 재고               상품별 재고               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 20001)
                    {
                        // 전체 재고 목록 출력하는 함수
                        stockOutput(1);
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout << "|--------------------------------------------------------------------------|" << endl;
                        cout<<"전체 수량 확인을 선택하셨습니다."<<endl;
                    }
                    else if (order2 == 20002)
                    {
                        // 상품별 목록 출력하는 함수
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "|                                                                           |"<<endl;
                        cout<<  "| No.    차량 이름      전체 수량      남은 수량           판매 수량         |"<<endl;
                        cout << "| --------------------------------------------------------------------------|"<< endl;
                        stockOutput(2);
                        cout<<  "|                                                                           |"<<endl;
                        cout << "|-------------------------------------------------------------------------- |" << endl;
                        cout<<"상품별 재고 현황 확인 선택하셨습니다."<<endl;
                    }
                    order2 = 20000;
                    continue;
                }
                else if (order1 == 3)
                {   
                    while(1){
                        cout << "|       전체 구매 리스트        브랜드별 구매 리스트         회원별 구매 리스트       |" << endl;
                        cout << "|--------------------------------------------------------------------------|" << endl;
                        if (order2 == 30001)
                        {
                            // 전체 구매 리스트 출력하는 함수
                            cout<<  "| No.   구매자   차량 이름   브랜드   차종  엔진  색상    가격(만원)         |"<<endl;
                            cout << "| --------------------------------------------------------------------------|" << endl;
                            cout<<  "|                                                                           |"<<endl;
                            buyListOutput(1);
                            cout << "| --------------------------------------------------------------------------|" << endl;
                            cout<<"전체 구매 리스트입니다.\n";
                            break;
                        }
                        else if (order2 == 30002)
                        {   
                            // 브랜드별 구매 리스트 출력하는 함수
                            if (buyListOutput(3)){
                             cout<<  "|                                                                           |"<<endl;
                             cout<<  "|                                                                           |"<<endl;
                             cout << "|--------------------------------------------------------------------------|" << endl;
                             break;
                            } 
                            else{
                             cout<<  "|                                                                           |"<<endl;
                             cout<<  "|                                                                           |"<<endl;
                             cout << "|--------------------------------------------------------------------------|" << endl;
                            }
                        }
                        else if (order2 == 30003)
                        {
                            // 회원별 구매 리스트 출력하는 함수
                             if (buyListOutput(2)){
                                cout<<  "|                                                                           |"<<endl;
                                cout<<  "|                                                                           |"<<endl;
                                cout << "|--------------------------------------------------------------------------|" << endl;
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

                    cout << "|               전체 매출               브랜드별 매출               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
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
                else if (order1 == 5)
                {
                    cout << "|                                성별 통계                                 |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 50001)
                    {
                        // 성별 통계 출력하는 함수
                         while(1){
                            if (!statistics()) cout<<"잘못 입력하였습니다!"<<endl;
                            else{
                                break;
                            }
                        }
                    }
                    order2 = 20000;
                    continue;
                }
            }

            while (1)
            {
                cin >> order1;
                if (order1 == 1)
                {
                    cout << "세부 메뉴를 선택해 주세요. ";
                    cout << "1. 차량 입고 2. 차량 출고 >>" << endl;
                    while (1)  // 입출고 관리 10001, 10002 할당
                    {
                        cin >> order2;
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
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 2)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    cout << "1. 전체 재고 2. 상품별 재고" << endl;
                    while (1)  // 재고 현황은 20001, 20002 할당
                    {
                        cin >> order2;
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
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 3)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    cout << "1. 전체 구매 리스트 2. 브랜드별 구매 리스트 3. 회원별 구매 리스트" << endl;
                    while (1)  // 구매리스트 30001, 30002, 30003 할당
                    {
                        cin >> order2;
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
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 4)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    cout << "1. 전체 매출 2. 브랜드별 매출" << endl;
                    while (1)  // 매출 관리는 40001, 40002 할당
                    {
                        cin >> order2;
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
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 5)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    cout << "1. 성별 통계 " << endl;
                    while (1)  // 통계 50001, 50002 할당
                    {
                        cin >> order2;
                        if (order2 == 1)
                        {
                            order2 = 50001;
                            break;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else if (order1 == 6)
                {
                    managerLogout();

                }
                else{
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                    break;

                }
            }
            continue;


        }

        cout << "+--------------------------------------------------------------------------+" << endl;
    }
}