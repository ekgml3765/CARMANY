#include "../header/car.h"
#include <sstream>

/*다희*/
//전역
vector<Car> carList = Car::openCarFile();

//객체 출력
void Car::print(){
    cout << car_id << " " << brand << " " << name << " " << min_price
    << " " << max_price << " " << type << " " << engine << " " << date
    << " " << color << " " << size << " " << efficency
    << " " << people << " " << stock << " " << total_stock <<endl;
}

//자동차 파일 읽어오기
vector<Car> Car::openCarFile(){

    vector<Car> carList;
    //ifstream fin("C:\\Users\\user\\Documents\\GitHub\\data\\car.txt"); //window
    ifstream fin("./car.txt");

    // 파일 열기 실패
    if(!fin) { 
		cout << "Can't Open File";
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
        carList.push_back(car);
	}
    return carList;
}

//자동차 리스트
bool Car::getCarList(int category, int page, bool filter){
    for(int i = 0; i < carList.size(); i++){
        carList[i].print();
    }
    return true;
}



//준식




//연진