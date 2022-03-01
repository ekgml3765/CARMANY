#include <iostream>
#include <string>
#include "header/car.h"
#include "header/user.h"
using namespace std;

int active_user_id = -1;
string username;
userLinkedList userlist;

int main()
{
    string menu_name; // 최상단 메뉴 이름
    menu_name = "CARLIST";

    string id; // 로그인 했을 때 아이디
    id = "관리자";

    int login; // 로그인시 0, 비회원 1
    login = 0;

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
        if (id == "관리자")
        {
            cout << "                             관리자 |" << endl;
        }
        else // UTF-8에서 한글이 3바이트 -> 수정 필요@@ -> 고정된 메뉴들은 글자수 바뀔 일이 없으니까 한글로 하고 아이디같은건 영어로만?
        {
            for (int i=0; i < 40 - id.length() - menu_name.length(); i++)
            {
                cout << ' ';
            }
            cout << id << " 님 |"<< endl;
        }
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
    }
    if (menu_name == "CARLIST")
    {

        // 페이징을 위한 변수들
        int total_cars = 52;                   // 전체 차의 수
        int first_car_id = 35;                  // 리스트 맨 위에 뜰 차의 인덱스
        int page_num = (first_car_id + 7) / 7; // 현재 페이지(앞 뒤 보여줄 인덱스 계산용)
        int now = (first_car_id + 7) / 7;      // 현재 페이지
        int page_cnt = 0;                      // 보여주는 페이지 수 카운트



        cout << "|      전체             차종별             엔진              자동차명      |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|  총 " << total_cars << "건 조회";
        for (int i = 0; i <  33 - to_string(total_cars).size(); i++)
        {
            cout << ' ';
        }
        cout << "필터 [인기순/출시순/가격순]  |" << endl;
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
    }



    if (menu_name == "CAR Recommend")
    {
        cout << "|   연령대별 추천       성별 추천       브랜드별 추천        개인화 추천   |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
    }
    if (menu_name == "MYPAGE")
    {
        if (id == "관리자")
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
        }
        else
        {
            cout << "|      구매 리스트              찜 리스트                 회원정보 수정    |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;
        }
    }

    cout << "+--------------------------------------------------------------------------+" << endl;
}


