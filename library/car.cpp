#include "../header/car.h"
#include <sstream>

/*다희*/

//전역변수
//vector<Car> car_list = Car::openCarFile();

//static 변수 선언
vector<Car> Car::car_list_v;
map<string, Car> Car::car_list_m;

//생성자
Car::Car(){};

//객체출력
void Car::print(){
    cout << car_id << " " << brand << " " << name << " " << min_price
    << " " << max_price << " " << type << " " << engine << " " << date
    << " " << color << " " << size << " " << efficency
    << " " << people << " " << stock << " " << total_stock;
}

//자동차 파일 읽어서 vector, map에 저장
bool Car::openCarFile(){

    ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\car.txt"); //window
    //ifstream fin("./car.txt"); //linux

    // 파일 열기 실패
    if(!fin) { 
		cout << "Can't Open File";
        return false;
	}

    string line;
    string word;
	while(getline(fin, line)) {
        istringstream ss(line);
        vector<string> list;
        while (getline(ss, word, ' ')){
            list.push_back(word);
        }  
        //set
        Car car;
        car.car_id = stoi(list[0]);
        car.brand = list[1];  
        car.name = list[2]; 
	    car.min_price = stoi(list[3]);
	    car.max_price = stoi(list[4]);
	    car.type = list[5];   
	    car.engine = list[6];
	    car.date = list[7];  
	    car.color = list[8]; 
	    car.size = list[9];
	    car.efficency = list[10]; 
	    car.people = stoi(list[11]);        
	    car.stock = stoi(list[12]);  	  
	    car.total_stock = stoi(list[13]);
        //자료구조 저장
        car_list_v.push_back(car);
        car_list_m[list[0]] = car;
	}
    fin.close();
    return true;
}

//자동차 리스트
bool Car::getCarList(int category, int page, bool filter){

    int total_cars = car_list_v.size();
    cout << endl;
    cout << "|  총 " << total_cars << "건 조회";
    cout << "필터 [인기순/출시순/가격순]  |" << endl;

    for(int i = 0; i < total_cars; i++){
        cout << "|       " ; 
        car_list_v[i].print();
        cout << "          |" << endl;
    }
    cout << "|--------------------------------------------------------------------------|" << endl;
    return true;
}

//자동차 상세보기
bool Car::getCarInfo(string car_id){
    if(car_list_m.find(car_id) == car_list_m.end()) 
            return false;
    else{
         Car car = car_list_m[car_id];
         car.print();
         cout << endl;
    }
    return true;
}


//준식




//연진