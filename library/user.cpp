//다희



//준식




//연진
#include "../header/user.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

extern int active_user_id;
extern string username;
extern userLinkedList userlist;

void callPrint(string menu_name, string id){
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
		if (menu_name == "CARMANY"){
		if (id == ""){
			for (int i = 0; i < 21 - menu_name.length() / 2; i++)
        {
            cout << ' ';
        }
        cout << "회원가입 / 로그인 |" << endl;
		}
		else{
			for (int i=0; i < 42 - id.length() - menu_name.length(); i++)
            {
                cout << ' ';
            }
            cout << id << " 님 |"<< endl;

		}
        cout << "|--------------------------------------------------------------------------|" << endl;
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
		}
		else if (menu_name == "Manager"){
			for (int i=0; i < 42 - id.length() - menu_name.length(); i++)
            {
                cout << ' ';
            }
            cout <<"관리자님 |"<< endl;
			cout << "|--------------------------------------------------------------------------|" << endl;
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
		}
}

void callManagerPrint(int choice){
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << '|';
	string menu_name = "MANAGER";
	string id = "";

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

	for (int i=0; i < 42 - id.length() - menu_name.length(); i++)
            {
                cout << ' ';
            }
            cout <<"관리자님 |"<< endl;
			cout << "|--------------------------------------------------------------------------|" << endl;
			cout << "|   입출고 관리      재고 현황      구매 리스트      매출 관리      통계   |" << endl;
			cout << "|--------------------------------------------------------------------------|" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			if (choice == 1){
				cout << "|                                                                          |" << endl;
				cout << "|                                                                          |" << endl;
				cout << "|                               1. 입고 관리                               |" << endl;
				cout << "|                                                                          |" << endl;
				cout << "|                               2. 출고 관리                               |" << endl;

			}
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "|                                                                          |" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;

}
bool openFile(){
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

    fin.close();

	return true;
}

void appendInFile(int userid, string id, string password, string phone, string name, string age, int sex){
	ofstream fout;

	fout.open("user.txt", ios::app);
	if (fout.is_open()){
		fout<<"\n"<<userid<<" "<<id<<" "<<password<<" "<<phone<<" "<<name<<" "<<age<<" "<<sex;
	}
	fout.close();
}

bool userLogin(){
		
	string id, password;
	cout<<endl;
	cout<<"회원 로그인을 선택하였습니다. 아이디와 비밀번호를 입력해주세요."<<endl;

	cout<<"아이디>>";
	cin>>id;

	cout<<"비밀번호>>";
	cin>>password;
	if (userlist.searchLoginValue(id, password)){
		cout<<"\n"<<username<<"님 환영합니다!"<<endl;;
	}
	else{
		cout<<"회원정보가 없습니다."<<endl;
		cout<<"다시 입력하세요!"<<endl;
		return false;
	}

	return true;
	

}

bool userLogout(){
	cout<<"로그아웃 선택하셨습니다."<<endl;
	cout<<"다음에 또 방문해주세요!"<<endl;
	active_user_id =-1;
	exit(0);
};

bool userUpdate(){
	cout<<"회원 정보 수정 선택하셨습니다."<<endl;
	cout<<"현재 회원님의 정보입니다."<<endl;
	
	userlist.showCurInfo();
	int choice;
	string change;

	cout<<"수정할 항목을 정하세요."<<endl;
	cout<<"(1)비밀번호 (2) 전화번호 (3) 이름 (4) 연령대(20대, 30대, 40대, 50대, 60대)";
	cin.ignore(1);
	
	cin>>choice;
	if (choice<=1 && choice >=4) return false;

	cout<<"새로운 수정 내용을 입력하세요";
	cin>>change;

	if (choice == 3){ username = change;}
	userlist.updateNode(choice, change);
	cout<<"업데이트 되었습니다.";
	active_user_id = -1;
	return true;
}

bool createUser(){


	cout<<"회원 가입 선택하셨습니다";
	cout<<" 계정 생성을 위한 정보 입력입니다."<<endl<<endl;

	string id, password, phone, name, age;
	int sex;
	cout<<"아이디 >> ";
	cin>>id;

	if (!userlist.searchId(id)) {
		cout<<"이미 존재하는 아이디입니다!"<<endl; 
		return false;
	}
	else{
		cout<<"비밀번호 >>";
		cin>>password;
		cout<<"전화번호 >>";
		cin>>phone;
		cout<<"이름 >>";
		cin>>name;
		cout<<"연령대(20대, 30대, 40대, 50대, 60대) >>";
		cin>>age;
		cout<<"성별(남:0, 여:1) >>";
		cin>>sex;
		
		int userid = userlist.lastUserId() +1;
		userlist.addNode(userid, id, password, phone, name, age, sex);
		appendInFile(userid, id, password, phone, name, age, sex);
		return true;
	}


	return false;
}