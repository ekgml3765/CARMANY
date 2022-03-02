#include <iostream>
#include <vector>
#include<string>
#include "./header/manager.h"
#include "./header/user.h"

using namespace std;

int active_user_id = -1;
int manager_id = -1;
vector<Manager> managerVector;
string username;
userLinkedList userlist;

int main(){
    //관리자 자료구조 호출
    getManagerList();

    int choice;

    cout<<"(1) 로그인: ";
    cin>>choice;
    
    if (choice == 1){
    //관리자 로그인
        managerLogin();
    }

    cout<<"원하시는 항목을 선택하세요\n";
    cout<<"1. 입출고 관리 2. 재고 현황 관리 3. 구매내역 조회 4 매출 관리 5. 통계 6. 로그아웃 : ";
    cin>>choice;

    if (choice <1 || choice >6 ) return 0;
    else if (choice == 1){
        int m_choice;

        cout<<"입출고 관리 중 어떤 항목을 선택하시겠습니까?";
        cout<<"1. 차량 입고 2. 차량 출고: ";
        cin>>m_choice;
        
        switch(m_choice){
            case 1:
                cout<<"차량 입고 선택하셨습니다.\n";
                cout<<"새로운 차량 목록이 담긴 inputCar.txt를 읽어 차량 정보 업데이트 시작합니다.\n";
                if (inputCarList()){
                    cout<<"차량 목록이 성공적으로 업데이트 되었습니다.\n";
                }
                else{
                    cout<<"차량 목록 업데이트에 실패하였습니다. inputCar.txt와 car.txt를 확인하세요.\n";
                }
                break;

            case 2:
                return 0;
            deafult:
                cout<<"잘못입력하셨습니다\n";
                break;
        }
        return 0;

    }
    else if (choice == 2){
        return 0;

    }
    else if (choice == 3){
        return 0;

    }
    else if (choice == 4){
        return 0;
        
    }
    else if (choice == 5){
        return 0;
    }
    else if (choice == 6){        
        //관리자 로그아웃
        managerLogout();
    }

    return 0;
}
