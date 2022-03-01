#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
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
	void print();
	static vector<Car> openCarFile();
	bool getCarList();
	bool getCarInfo(int car_id);
	bool getBuyCar();

	//getter, setter
};


#endif