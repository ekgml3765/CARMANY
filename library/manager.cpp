#include "../header/manager.h"
#include "../header/user.h"
#include "../header/car.h"

#include <string>
#include <algorithm>

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
extern vector<Manager> managerVector;
extern vector<buyList> buyListVector;
extern userLinkedList userlist;
extern int manager_id;


void getManagerList(){
    string line, word;
    istringstream ss;
    vector<string> v;

    ifstream fin("manager.txt");
    // ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\manager.txt");

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

    cout<<"아이디 >>";
    cin>>id;
    cout<<"비밀번호>> ";
    cin>>password;

  for(int i = 0; i < managerVector.size(); i++){
        if ((strcmp(id, managerVector[i].id)==0)&&(strcmp(password, managerVector[i].password)==0)){
            manager_id = managerVector[i].manager_id;
            cout<<"관리자 로그인 되었습니다."<<endl;
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
	// fout.open("C:\\Users\\user\\Documents\\GitHub\\data\\car.txt", ios::app);
	fin.open("inputCar.txt");
	// fin.open("C:\\Users\\user\\Documents\\GitHub\\data\\inputCar.txt");

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
    Car::openCarFile("inputCar.txt");
    // Car::openCarFile("C:\\Users\\user\\Documents\\GitHub\\data\\inputCar.txt");
    return appendCarFile();
}

bool readBuyList(){
    string line, word;
    istringstream ss;
    vector<string> v;
    
   ifstream fin("buyList.txt");
    // ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\buyList.txt");

    if(fin.is_open()){
     while(getline(fin, line)) {
        istringstream ss(line);
        v.clear();
        while (getline(ss, word, ' ')){
            v.push_back(word);
        }
        for(int i=0; i<buyListVector.size(); i++){
            if (buyListVector[i].user_id == stoi(v[0]) && buyListVector[i].car_id == stoi(v[1])){
                buyListVector[i].cnt ++;
                return true;
            }
        }

        buyList* buylist = new buyList;
        buylist->user_id = stoi(v[0]);
        buylist->car_id = stoi(v[1]);
        buylist->buyer = v[2];
        buylist->carname = v[3];
        buylist->brand = v[4];
        buylist->carType = v[5];
        buylist->engine= v[6];
        buylist->color= v[7];
        buylist->price = v[8];
        buylist->cnt = 1;
        buyListVector.push_back(*buylist);
     }
     return true;
    }

    return false;
}

bool outputBuyList(){
    if (buyListVector.empty()){
        return false;
    }

    for(int i=0; i<buyListVector.size(); i++){
        //네모에 출력될 내용
        cout<<"|"<<to_string(i+1)<<" "<<buyListVector[i].buyer<<" "<<buyListVector[i].carname<<" "<<buyListVector[i].brand<<" "<<buyListVector[i].engine<<" "<<buyListVector[i].color<<" "<<buyListVector[i].price<<"|"<<endl;
    }
    return true;
}

bool buyListCarcnt(int& total_sales){
    if (buyListVector.empty()) return false;
    for(int i=0; i<buyListVector.size(); i++){
        total_sales += buyListVector[i].cnt;
    }
    return true;
}

bool carListcnt(int& total){
    vector<Car> tmp = Car::car_list_v;
    if (tmp.empty()) return false;

    for(int i=0; i<=tmp.size(); i++){
        total += tmp[i].getStock();
    }
    return true;
}

bool stockOutput(int m_choice){
    if (m_choice == 1){
        
        int total =0, total_sales=0;
        // if (carListcnt(total)){
            cout<<"|            현재 재고 수량:     "<<total<<"|"<<endl;
            if (buyListCarcnt(total_sales)){
                cout<<"|         총 판매 수량:      "<<total_sales<<"|"<<endl;
            }
            return true;
        // }
        
        return false;
    }
    else if (m_choice == 2){
        vector<Car> tmp = Car::car_list_v;
        for(int i=0; i<tmp.size(); i++){
            cout<<i+1<<tmp[i].getName()<<tmp[i].getBrand()<<tmp[i].getTotalStock()<<tmp[i].getStock()<<endl;
        }
        return true;
    }
    return false;
}

bool find_By_param_buyList(int m_choice, string param){
    cout << "|--------------------------------------------------------------------------|" << endl;
    cout<<  "|        구매자   차량 이름   브랜드   차종  엔진  색상                      |"<<endl;
    cout << "| --------------------------------------------------------------------------|" << endl;

    bool flag = false;
    if (m_choice == 0){
        for(int i=0; i<buyListVector.size(); i++){
            if (buyListVector[i].buyer == param){
                flag = true;
                cout<<"|"<<buyListVector[i].buyer<<" "<<buyListVector[i].carname<<" "<<buyListVector[i].brand<<buyListVector[i].carType<<" "<<buyListVector[i].engine<<" "<<buyListVector[i].color<<"|"<<endl;
            }
        }

        if (!flag){
            return false;
        }

        return true;

    }
    else{
        for(int i=0; i<buyListVector.size(); i++){
            if (buyListVector[i].brand == param){
                flag = true;
                cout<<"|"<<buyListVector[i].buyer<<" "<<buyListVector[i].carname<<" "<<buyListVector[i].brand<<buyListVector[i].carType<<" "<<buyListVector[i].engine<<" "<<buyListVector[i].color<<"|"<<endl;
            }
        }

        if (!flag){
            return false;
        }

        return true;
    }

    return false;
}
bool buyListOutput(int m_choice){

    if (m_choice == 1){
        return outputBuyList();
    }
    else if (m_choice == 2){
        cout<<  "|                                                                           |"<<endl;
        cout << "|--------------------------------------------------------------------------|" << endl;

        string name;
        cout<<"검색할 회원명을 입력하세요. >>";
        cin>>name;

        if (!find_By_param_buyList(0, name)){
            cout<<"해당 회원은 구매한 이력이 없습니다."<<endl;
            return false;
        }

    }
    else if (m_choice == 3){
        cout<<  "|                                                                           |"<<endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        string brandname;
        cout<<"검색할 브랜드명을 입력하세요.:";
        cin>>brandname;

        if (!find_By_param_buyList(1, brandname)){
            cout<<"해당 브랜드의 구매 이력은 없습니다."<<endl;
            return false;
        }
    }
    
    return true;
}

void billingBybrand(){
    string brand[3] = {"KIA", "HYNDAI", "GENESIS"};

    for(int i=0; i<3; i++){
        int tot = 0;
        for (int j=0; j<buyListVector.size(); j++){
           if (buyListVector[j].brand == brand[i]){
                string line = buyListVector[j].price.substr(0, buyListVector[j].price.length()-2);
                tot += stoi(line)*buyListVector[j].cnt;
           }
        }
        cout<<"|"<<brand[i]<<" "<<tot<<" 만원|"<<endl;
    }
}
bool billing(int m_choice){
    if (m_choice == 1){

        int tot = 0;
        for (int i=0; i<buyListVector.size(); i++){
           string line = buyListVector[i].price.substr(0, buyListVector[i].price.length()-2);
           tot += stoi(line)*buyListVector[i].cnt;
        }

        cout<<"|                총 매출 금액: "<<tot<<" 만원           |"<<endl;
        return true;
    }
    else if (m_choice == 2){
        billingBybrand();
        return true;
    }
  
    return true;
}

int compare(const pair<int, int>& a, const pair<int, int>& b){
    if (a.first == b.first){
        return a.second<b.second;
    }
    return a.first > b.first;
}

bool statistics(){
    vector<Car> tmp = Car::car_list_v;
    cout << tmp.size() << endl;
    cout<<"|                 통계 선택하셨습니다.                 |"<<endl;
    cout<<"|    성별에 따라 최다 판매된 상품 10개를 출력해드립니다. | "<<endl;
    cout << "|--------------------------------------------------------------------------|" << endl;

    int gender, get_gender;
    int man[100]={0,};
    int woman[100] = {0,};

    cout<<"성별을 선택하세요\n 0. 남성 1. 여성";
    cin>>gender;
    if (gender != 0 && gender != 1) return false;

    for(int i=0; i<buyListVector.size(); i++){
        userlist.getGender(buyListVector[i].user_id, get_gender);
        if (get_gender == 0){
            man[buyListVector[i].car_id]++;
        }
        else{
            woman[buyListVector[i].car_id]++;
        }
    }

    vector<pair<int, int>> statistics_gender;


    if (gender == 0){
        for (int i=0; i<100; i++){
            if (man[i]!=0){
                statistics_gender.push_back(make_pair(man[i], i));
            }
        }

        cout<<"|                         남성 TOP 10 입니다!                               |"<<endl;

    }
    else if (gender == 1){
         for (int i=0; i<100; i++){
            if (woman[i]!=0){
                statistics_gender.push_back(make_pair(i, woman[i]));
            }
        } 
        cout<<"|                       여성 TOP 10 입니다!                                  |"<<endl;

    }

    sort(statistics_gender.begin(), statistics_gender.end(), compare);
    int end;

    if (statistics_gender.size() < 10) end = statistics_gender.size();
    else end = 10;

    for(int i=0; i<end; i++){
        cout<<statistics_gender[i].second<<endl;
        for (int j=0; j<tmp.size(); i++){
            if (tmp[i].getCarId() == statistics_gender[i].second){
                cout<<tmp[i].getName()<<tmp[i].getBrand()<<tmp[i].getType()<<tmp[i].getEngine()<<tmp[i].getMaxPrice()<<tmp[i].getColor()<<endl;
            }
        }
    }

    return true;
}