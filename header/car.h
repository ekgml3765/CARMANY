#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iterator>
using namespace std;

class Car{
private:
	int car_id;    // 자동차 식별번호
	string brand;  // 자동차 브랜드
    string name;   // 자동차 이름
	int min_price; // 최저가격
	int max_price; // 최고가격
	string type;   // 차종(승용, suv, ...)
	string engine; // 엔진(전기, 가솔린, ...)
	string date;   // 출시 날짜
	string color;  // 색상(red, white, ...)
	string size;   // 규격 사이즈
	string efficency;  // 연비
	int people;        // 탑승 가능 인원수
	int stock;  	   // 남은 수량
	int total_stock;  // 총 입고 수량

public:
	//static 변수
	static vector<Car> car_list_v;
	static map<string, Car> car_list_m;
	Car();
	void print(int sales);
	void detailPrint(int sales);
	void navbarPrint(int login, string menu_name, string id);
	bool getCarList(int category, vector<Car> &list, string keyword = "", int page=1, int filter=0, bool is_reco=false);
	bool getCarInfo(string car_id);
	bool getBuyCar(string car_id, int user_id, string username, string buyList_file);
	
	//file 관련
	static bool openCarFile(string carfile_path);
	static bool writeCarFile(string carfile_path);
	
	//getter
	int getMinPrice() const{ return min_price;}
	int getMaxPrice() const{ return max_price;}
	string getDate() const{ return date;}
	int getStock() const{ return stock;}
	int getTotalStock() const{ return total_stock;}

	//추천
	bool getRecoListByBrand(string brandname, vector<Car> &list, int page=1);
	bool getRecoListByAge(string age, vector<Car> &list, string buyList_file, string userfile_path, int page=1);
	
};


#endif