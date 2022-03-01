//다희



//준식




//연진
#include "user.h"
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