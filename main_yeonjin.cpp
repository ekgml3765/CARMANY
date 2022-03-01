#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "header/user.h"


using namespace std;

int active_user_id = -1;
string username;
userLinkedList userlist;


int main(){
    string line, word;
    istringstream ss;
    vector<string> v;

// user.txt를 읽어오기
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

    userlist.show();
    fin.close();
    int choice;

    // ---------
    while(true){
        cout<<"로그인과 회원 가입 중 선택하세요."<<endl;
        cout<<"1. 로그인 2. 회원 가입 3. 비회원 로그인>>";
        cin>>choice;

        if (choice == 1){
            if (!userLogin()) continue;

        }
        else if (choice == 2){
            if (!createUser()) continue;
            else{
                cout<<"회원가입이 잘 되었습니다!"<<endl;
                cout<<username<<"의 계정이 생성되었습니다"<<endl;
                cout<<"로그인 화면으로 돌아갑니다"<<endl;
                userlist.show();
            }
        }
        else if (choice == 3){
            cout<<"비회원으로 로그인하셨습니다.";
            active_user_id = -1;
        }
        else{
            cout<<"잘못입력하였습니다. 다시 입력바랍니다."<<endl;
        }
    

        while(1){
            if (active_user_id == -1){
            //비회원 검색
            return 0;
            }

            else{
                //회원
                cout<<"차량 검색, 구매, 추천, 혹은 마이페이지 중 원하시는 항목의 번호를 선택하십시오:"<<endl;
                cout<<"(1)차량 검색 (2) 차량 구매 (3) 차량 추천 (4) 마이페이지 (5) 로그아웃";
                cin >> choice;

                if (choice == 1) return 0;
                else if (choice == 2) return 0;
                else if (choice == 3) return 0;
                else if (choice == 4){
                    int m_choice;

                    cout<<"마이페이지 선택하셨습니다."<<endl;
                    cout<<"원하시는 항목의 번호를 선택하십시오"<<endl;
                    cout<<"(1)구매 리스트 확인 (2) 찜 목록 확인 (3) 회원 정보 수정";

                    cin>>m_choice;

                    if (m_choice == 1) return 0;
                    else if (m_choice == 2) return 0;
                    else if (m_choice == 3){
                        if (!userUpdate()) continue;
                        cout<<"회원 정보 수정되었습니다!"<<endl;
                        cout<<"로그인 화면으로 돌아갑니다"<<endl;
                        break;
                    }


                }
                else if (choice == 5){
                    userLogout();
                }
                else{
                    cout<<"잘못입력하셨습니다."<<endl;
                }
            }   
        }
    }


    return 0;
}