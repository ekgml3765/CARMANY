#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

#include "../header/manager.h"
using namespace std;
extern vector<Manager> managerVector;
extern int manager_id;

void getManagerList(){
    string line, word;
    istringstream ss;
    vector<string> v;

    ifstream fin("manager.txt");

    if(fin.is_open()){
     while(getline(fin, line)) {
        istringstream ss(line);
        v.clear();
        while (getline(ss, word, ' ')){
            v.push_back(word);
        }
        Manager *manager = new Manager;
        manager->manager_id = stoi(v[0]);
        strcpy(manager->id, v[1].c_str());
        strcpy(manager->password,v[2].c_str());
        managerVector.push_back(*manager); 
     }
    }
}


bool managerLogin(){
    char id[256], password[256];

    cout<<"관리자 로그인 선택하였습니다"<<endl;
    cout<<"아이디와 비밀번호 입력해주세요\n"<<endl;

    cout<<"아이디";
    cin>>id;
    cout<<"비밀번호";
    cin>>password;

  for(int i = 0; i < managerVector.size(); i++){
        if ((strcmp(id, managerVector[i].id)==0)&&(strcmp(password, managerVector[i].password)==0)){
            manager_id = managerVector[i].manager_id;
            cout<<"관리자 로그인 되었습니다."<<endl;
            cout<<id<<"매니저님 환영합니다!"<<endl;
            return true;
        }
    }

    cout<<"존재하지 않는 계정입니다!."<<endl;
    cout<<"아이디 혹은 비밀번호를 다시 확인하세요!"<<endl;
    return false;
}


bool managerLogout(){
    cout<<"로그아웃을 선택하셨습니다.\n";
    cout<<"프로그램을 종료합니다.\n 다음에 또 방문해주세요!";
    exit(0);
}

bool appendCarFile(){
	ofstream fout;
    ifstream fin;
    string line, word;
    vector<string> v;

	fout.open("car.txt", ios::app);
	fin.open("inputCar.txt");

    if (fout.is_open()&&fin.is_open()){
        while(getline(fin,line)){
            istringstream ss(line);
            v.clear();
            while (getline(ss, word, ' ')){
                v.push_back(word);
            } 
            for(int i =0; i<v.size()-1; i++){
                fout<<v[i]<<" ";
            }  
            fout<<v[v.size()-1]<<" "<<"\n";
        }
        fout.close();
        fin.close();
        int res = remove("inputCar.txt");
        if (res) return false;

        return true;
    }
    else{
        fout.close();
        fin.close();
        return false;
    }
}

bool inputCarList(){
    // openCarFile("inputCar.txt");
    return appendCarFile();
}
