#include <iostream>
#include <vector>
#include <sstream>
#include "header/manager.h"
#include "header/user.h"
#include "header/car.h"

using namespace std;

int active_user_id = -1;
int manager_id = -1;
vector<Manager> managerVector;
vector<buyList> buyListVector;
userLinkedList userlist;
string username;
// vector<Car> Car::car_list_v;

int main(){
    string line, word;
    istringstream ss;
    vector<string> v;

    ifstream fin("user.txt");
    //ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\user.txt");

    if(fin.is_open()){
     while(getline(fin, line)) {
        istringstream ss(line);
        v.clear();
        while (getline(ss, word, ' ')){
            v.push_back(word);
        } 
        userlist.addNode(stoi(v[0]), v[1], v[2], v[3], v[4], v[5], stoi(v[6]));
     }
    }

    userlist.show();
    //관리자 자료구조 호출
    getManagerList();
    //buyList 호출
    readBuyList();

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
        cout<<"1. 차량 입고 2. 차량 출고 리스트: ";
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
                cout<<"차량 출고 리스트입니다.\n";
                if (outputBuyList()){
                    cout<<"성공적으로 출력!\n";
                }
                else{
                    cout<<"buyList가 없습니다.\n";
                }
                break;
            deafult:
                cout<<"잘못입력하셨습니다\n";
                break;
        }
        return 0;

    }
    else if (choice == 2){
        int m_choice;

        cout<<"재고 현황 관리 선택하셨습니다.\n";
        cout<<"원하시는 항목을 선택하세요.\n\n";
        cout<<"1. 전체 수량 확인 2. 상품별 확인";

        cin>>m_choice;

        if (!stockOutput(m_choice)){
            cout<<"재고 리스트를 읽어드리는 것에 문제가 있습니다."<<endl;
        }
    }
    else if (choice == 3){
        int m_choice;
        cout<<"구매내역 조회 입니다."<<endl;
        cout<<"원하시는 항목을 선택하세요"<<endl;

        cout<<"1. 전체리스트 2.회원별 리스트 3. 차량별 리스트";
        cin>>m_choice;

        if (m_choice < 1 or m_choice >3){
            cout<<"잘못 입력하였습니다.";
        }
        else{
            bool flag = buyListOutput(m_choice);
        }

    }
    else if (choice == 4){
        cout<<"매출 관리 선택하셨습니다."<<endl;
        cout<<"원하시는 항목을 선택하세요."<<endl;

        cout<<"1. 전체 메출리스트 2. 브랜드별 매출 리스트";
        int m_choice;
        cin>>m_choice;

        if (m_choice < 1 or m_choice >2){
            cout<<"잘못 입력하였습니다.";
        }
        else{
            bool flag = billing(m_choice);
        }
        
    }
    else if (choice == 5){
        if (!statistics()) cout<<"잘못 입력하였습니다!"<<endl;
        return 0;
    }
    else if (choice == 6){        
        //관리자 로그아웃
        managerLogout();
    }

    return 0;
}
