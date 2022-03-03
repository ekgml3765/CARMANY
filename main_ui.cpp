#include <iostream>
#include <string>
#include "header/car.h"
#include "header/user.h"
#include "header/buylist.h"
using namespace std;


int active_user_id = -1;
string username;
userLinkedList userlist;

extern buylist mark[200];
extern int totalBuyList;

int main()
{


    /*자동차 데이터 세팅*/
    Car car;
    // ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\car.txt");
    ifstream fin("./car.txt"); //linux
    // string buyList_file = "C:\\Users\\user\\Documents\\GitHub\\data\\buyList.txt";
    //string buyList_file = "./buyList.txt";
    Car::openCarFile(fin);

    getMyCarList();







    string menu_name; // 최상단 메뉴 이름
    menu_name = "CARMANY";

    string id; // 로그인 했을 때 아이디
    id = "모비스";

    int login; // 로그인시 0, 비회원 1, 종료 -1
    login = 0;

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
            cout << "메뉴를 선택해주세요.(1. 차량구매 2. 차량 추천 3. 마이페이지 4. 프로그램 종료)" << endl;
            
            
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
                car.getCarList(1, 1);
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
            cout << "|      구매 리스트                                        회원정보 수정    |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;
            viewMyCar(1);
            menu_name = "CARMANY";
            
        }

        if (menu_name == "Manager")  // 관리자는 로그아웃하지 않는 이상 이 안에서만 놀게함 -> 얘는 디폴트 화면 -> order2에 20000할당
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
                cout << "|   차량 출고   |  상품별 재고  |  차량별  | 브랜드별 매출 | 연령대별 통계 |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |          |               |               |" << endl;
                cout << "|               |               |  회원별  |               |               |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "+--------------------------------------------------------------------------+" << endl;
                cout << "메뉴 선택 1.입출고 관리 2. 재고 현황 3. 구매 리스트 4. 매출 관리 5. 통계" << endl;
            }
            else
            {
                if (order1 == 1)
                {
                    cout << "|               차량 입고               차량 출고               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 10001)
                    {
                        // 차량 입고 목록 출력하는 함수
                    }
                    else if (order2 == 10002)
                    {
                        // 차량 출고 목록 출력하는 함수
                    }
                }
                else if (order1 == 2)
                {
                    cout << "|               전체 재고               상품별 재고               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 20001)
                    {
                        // 전체 재고 목록 출력하는 함수
                    }
                    else if (order2 == 20002)
                    {
                        // 상품별 목록 출력하는 함수
                    }
                }
                else if (order1 == 3)
                {
                    cout << "|        전체 구매 리스트        차량별 구매 리스트         회원별 구매 리스트               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 30001)
                    {
                        // 전체 구매 리스트 출력하는 함수
                    }
                    else if (order2 == 30002)
                    {
                        // 차량별 구매 리스트 출력하는 함수
                    }
                    else if (order2 == 30003)
                    {
                        // 회원별 구매 리스트 출력하는 함수
                    }
                }
                else if (order1 == 4)
                {
                    cout << "|               전체 매출               브랜드별 매출               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 40001)
                    {
                        // 전체 매출 출력하는 함수
                    }
                    else if (order2 == 40002)
                    {
                        // 브랜드별 매출 출력하는 함수
                    }
                }
                else if (order1 == 5)
                {
                    cout << "|               성별 통계               연령대별 통계               |" << endl;
                    cout << "|--------------------------------------------------------------------------|" << endl;
                    if (order2 == 50001)
                    {
                        // 성별 통계 출력하는 함수
                    }
                    else if (order2 == 50002)
                    {
                        // 연령대별 통계 출력하는 함수
                    }
                }
            }



            while (1)
            {
                cin >> order1;
                if (order1 == 1)
                {
                    cout << "세부 메뉴를 선택해 주세요." << endl;
                    cout << "1. 차량 입고 2. 차량 출고" << endl;
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
                    cout << "1. 전체 구매 리스트 2. 차량별 구매 리스트 3. 회원별 구매 리스트" << endl;
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
                    cout << "1. 성별 통계 2. 연령대별 통계" << endl;
                    while (1)  // 통계 50001, 50002 할당
                    {
                        cin >> order2;
                        if (order2 == 1)
                        {
                            order2 = 50001;
                            break;
                        }
                        else if (order2 == 2)
                        {
                            order2 = 50002;
                            break;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "잘못된 입력입니다! 다시 입력해 주세요." << endl;
                }
            }
            continue;


        }

        // cout << "+--------------------------------------------------------------------------+" << endl;
    }
}