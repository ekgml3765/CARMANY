#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car{
private:
	int car_id;  // 자동차 식별번호
    string name;  // 자동차 이름
	string brand; // 자동차 브랜드
	int price;  // 자동차 가격
	string type;  // 차종(승용, suv, ...)
	string engine;  // 엔진(전기, 가솔린, ...)
	string date;  // 출시 날짜
	string color;  // 색상(red, white, ...)
	string size;  // 규격 사이즈
	string efficency;  // 연비
	int stock;  // 남은 수량
	int total_stock;  // 총 입고 수량
	int num_of_people;  // 탑승 가능 인원수

public:

};


#endif