//다희



//준식




//연진
#include "../header/user.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

extern int active_user_id;
extern string username;
extern userLinkedList userlist;

void appendInFile(int userid, string id, string password, string phone, string name, string age, int sex){
	ofstream fout;

	fout.open("user.txt", ios::app);
	if (fout.is_open()){
		fout<<"\n"<<userid<<" "<<id<<" "<<password<<" "<<phone<<" "<<name<<" "<<age<<" "<<sex;
	}
	fout.close();
}

bool userLogin(){
	int choice;

	while(true){
		cout<<"회원과 비회원 중 선택하세요"<<endl;
		cout<<"메인으로 가려면 -1을 입력하세요"<<endl;
		cout<<"!! 비회원은 검색만 가능합니다"<<endl;
		cout<<endl;

		cout<<"1.회원 2. 비회원 >>";
		cin>>choice;

		if (choice == 1){
			string id, password;

			cout<<"회원 로그인을 선택하였습니다."<<endl;
			cout<<"아이디와 비밀번호를 입력해주세요."<<endl;

			cout<<"아이디>>";
			cin>>id;

			cout<<"비밀번호>>";
			cin>>password;

			if (userlist.searchLoginValue(id, password)){
				cout<<username<<"님 환영합니다!"<<endl;;
			}
			else{
				cout<<"회원정보가 없습니다."<<endl;
				cout<<"다시 입력하세요!"<<endl;
				continue;
			}

			return true;
		}
		else if (choice == 2){
			cout<<"비회원 로그인 선택하셨습니다"<<endl;
			cout<<"비회원은 검색만 가능합니다!"<<endl;
			return true;
		}
		else if (choice == -1){
			return false;
		}
		else{
			cout<<"잘못 입력하셨습니다"<<endl;
		}
	}
	
}

bool userLogout(){
	cout<<"로그아웃 선택하셨습니다."<<endl;
	cout<<"다음에 또 방문해주세요!"<<endl;
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

	userlist.updateNode(choice, change);
	cout<<"업데이트 되었습니다.";
	return true;
}

bool createUser(){

	while(1){

		cout<<"회원 가입 선택하셨습니다"<<endl;
		cout<<"계정 생성을 위한 정보 입력입니다."<<endl;

		string id, password, phone, name, age;
		int sex;
		cout<<"아이디";
		cin>>id;

		if (id == "-1") break;

		if (!userlist.searchId(id)) {
			cout<<"이미 존재하는 아이디입니다!"; 
			continue;
		}
		else{
			cout<<"비밀번호:";
			cin>>password;
			cout<<"전화번호:";
			cin>>phone;
			cout<<"이름:";
			cin>>name;
			cout<<"연령대(20대, 30대, 40대, 50대, 60대)";
			cin>>age;
			cout<<"성별(남:0, 여:1)";
			cin>>sex;
			
			int userid = userlist.lastUserId() +1;
			userlist.addNode(userid, id, password, phone, name, age, sex);
			appendInFile(userid, id, password, phone, name, age, sex);
			return true;
		}
	}

	return false;
}