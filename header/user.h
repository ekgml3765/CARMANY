#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User{
private:
	int user_id;      //사용자 식별번호
	string id;           //사용자 아이디
	string password;  //사용자 비밀번호
	string phone;     //사용자 전화번호
	string name;      //사용자 이름
	string age;       //사용자 연령대 (10대, 20대, 30대 등)
	int sex;          //사용자 성별 (0-남자, 1-여자)
};


#endif