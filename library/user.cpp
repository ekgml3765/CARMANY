//다희



//준식




//연진
#include "../header/user.h"

using namespace std;

extern int active_user_id;
extern string username;
extern userLinkedList userlist;

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
	
	//회원정보 보여주기
	userlist.showCurInfo();
	int choice;
	string change;

	//수정할 항목 입력 받기
	cout<<"수정할 항목을 정하세요."<<endl;
	cout<<"(1)비밀번호 (2) 전화번호 (3) 이름 (4) 연령대(20대, 30대, 40대, 50대, 60대)";
	cin.ignore(1);
	
	cin>>choice;
	//1번에서 4번 이외의 값을 받으면 false 반환
	if (choice<=1 && choice >=4) return false;

	//잘 입력했다면 계속해서 진행
	cout<<"새로운 수정 내용을 입력하세요";
	cin>>change;

	if (choice == 3){ username = change;}
	//User들이 담긴 LinkedList의 노드 업데이트
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