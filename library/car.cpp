#include "../header/car.h"


/*다희*/

//전역변수
extern int menu_no; 
extern string id;
extern int login;

//static 변수 선언
vector<Car> Car::car_list_v;
map<string, Car> Car::car_list_m;

//생성자
Car::Car(){};

//상단바 출력


void Car::navbarPrint(int login, int menu_no, string id){
string menu_name[] = {"CARMANY", "CARLIST", "CAR Recommend", "MYPAGE", "MANAGER"};
cout << endl;
cout << endl;
cout << "+--------------------------------------------------------------------------+" << endl;
        cout << '|';
        int t = 0;
        if (menu_name[menu_no].length() % 2 == 0)
        {
            t = 34 - menu_name[menu_no].length() / 2 + 1;
            for (int i = 0; i < 34 - menu_name[menu_no].length() / 2 + 1; i++)
            {
                cout << ' ';
            }
        }
        else
        {
            t = 34 - menu_name[menu_no].length() / 2;
            for (int i = 0; i < 34 - menu_name[menu_no].length() / 2; i++)
            {
                cout << ' ';
            }
        }
        cout << menu_name[menu_no];
        if (login == 1) // 로그인 안했을 때
        {
            for (int i = 0; i < 21 - menu_name[menu_no].length() / 2; i++)
            {
                cout << ' ';
            }
            cout << "회원가입 / 로그인 |" << endl;
        }
        else  // 로그인 했을 때
        {
            for (int i=0; i < 74 - t - 10 - menu_name[menu_no].length(); i++)
            {
                cout << ' ';
            }
            cout << id << " 님 |"<< endl;
        }

        cout << "|--------------------------------------------------------------------------|" << endl;
}

//상세보기 출력
void Car::detailPrint(int sales){
    // cout << car_id << " " << brand << "  " << name << "  " << min_price
    // << "  " << max_price << "  " << type << "  " << engine << "  " << date
    // << "  " << color << "  " << size << "  " << efficency
    // << " " << people << " " << sales;

    cout << "     Car_id:         " << car_id << endl;
    cout << "     Brand:          " << brand << endl;
    cout << "     Name:           " << name << endl;
    cout << "     Minimum price:  " << min_price << "만원" << endl;
    cout << "     Maximum price:  " << max_price << "만원" << endl;
    cout << "     Type:           " << type << endl;
    cout << "     Engine:         " << engine << endl;
    cout << "     Release date:   " << date << endl;
    cout << "     Color:          " << color << endl;
    cout << "     Size:           " << size << endl;
    cout << "     Efficiency:     " << efficency << endl;
}


//리스트 출력
void Car::print(int sales){
    cout << car_id;
    for (int i=0; i < 3 - to_string(car_id).length(); i++)
    {
        cout << " ";
    }
    cout << brand;
    for (int i=0; i < 9 - brand.length(); i++)
    {
        cout << " ";
    }
    cout << name;
    for (int i=0; i < 14 - name.length(); i++)
    {
        cout << " ";
    }
    cout << min_price;
    for (int i=0; i < 5 - to_string(min_price).length(); i++)
    {
        cout << " ";
    }
    cout << max_price;
    for (int i=0; i < 5 - to_string(max_price).length(); i++)
    {
        cout << " ";
    }
    cout << type;
    for (int i=0; i < 10 - type.length(); i++)
    {
        cout << " ";
    }
    cout << engine;
    for (int i=0; i < 9 - engine.length(); i++)
    {
        cout << " ";
    }
    cout << date;
    for (int i=0; i < 8 - date.length(); i++)
    {
        cout << " ";
    }
    cout << sales;
    for (int i=0; i < 10 - to_string(sales).length(); i++)
    {
        cout << " ";
    }
}

//자동차 파일 읽어서 자료구조 vector, map에 저장
bool Car::openCarFile(string carfile_path){

    // 파일 열기 실패
    ifstream fin(carfile_path);
    if(!fin) { 
		cout << "Can't Open Car File";
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

//자료구조 다시 car.txt에 저장 -> 구매 등 변경사항 파일에 적용
bool Car:: writeCarFile(string carfile_path){
    
    // 파일 열기 실패
    ofstream fout(carfile_path, ios::out | ios::trunc); //쓰기모드, 다 지우고 다시 쓰기
    if(!fout) {
        cout << "car.txt 파일 열기 오류";
        return false;
    }
    if (fout.is_open()){
        for(int i = 0; i < car_list_v.size(); i++){
            fout << car_list_v[i].car_id <<" " << car_list_v[i].brand << " " << car_list_v[i].name << " " << car_list_v[i].min_price 
            << " " << car_list_v[i].max_price << " " << car_list_v[i].type << " "
            << car_list_v[i].engine << " " << car_list_v[i].date << " " << car_list_v[i].color << " " << car_list_v[i].size
            << " " << car_list_v[i].efficency << " " << car_list_v[i].people << " " << car_list_v[i].stock << " " << car_list_v[i].total_stock << endl;
        }
	}
    fout.close();
    return true;
}

//자동차 리스트
bool Car::getCarList(int category,  vector<Car> &list, string keyword, int page, int filter, bool is_reco){
     
     int total_cnt;
     vector<Car> tmp;

     switch(category){
        //1.전체
        case 1:{
            tmp = car_list_v;
            break;
        }
        //2.차종별
        case 2:{
            for(int i = 0; i < car_list_v.size(); i++){
                if(car_list_v[i].type == keyword)
                    tmp.push_back(car_list_v[i]);
            }
            break;
        }
        //3.엔진
        case 3:{
            for(int i = 0; i < car_list_v.size(); i++){
                if(car_list_v[i].engine == keyword)
                    tmp.push_back(car_list_v[i]);
            }
            break;
        }
        //4.자동차명
        case 4:{
            for(int i = 0; i < car_list_v.size(); i++){
                if(car_list_v[i].name.find(keyword) != string::npos)
                    tmp.push_back(car_list_v[i]);
            }
            break;
        }
        //5.필터
        case 5:{
            switch(filter){
                //출시순 정렬
                case 1:{
                    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
                        string a_date = a.getDate();
                        string b_date = b.getDate();
                        int a_year = stoi(a.date.substr(0, 4));
                        int a_month = stoi(a.date.substr(5));
                        int b_year = stoi(b.date.substr(0, 4));
                        int b_month = stoi(b.date.substr(5));
                        if(a_year == b_year)
                            return a_month > b_month;
                        return a_year > b_year;
                    });
                    break;
                }
                //낮은 가격순 정렬
                case 2:{
                    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
                        return a.getMinPrice() < b.getMinPrice();
                    });
                    break;
                }
                //높은 가격순 정렬
                case 3:{
                    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
                        return a.getMaxPrice() > b.getMaxPrice();
                    });
                    break;
                }
                //인기순 정렬
                case 4:{
                    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
                        int a_dif_stock = a.getTotalStock()-a.getStock();
                        int b_dif_sock = b.getTotalStock()-b.getStock();
                        return  a_dif_stock > b_dif_sock;
                    });
                    break;
                }
            }
        }
    }

    //리스트 변경할 경우
    if(1 <= category && category <= 4){
        list = tmp;
        total_cnt = tmp.size();
    }else{ //리스트 그대로
        total_cnt = list.size();
    }

    //페이징
    int item = 10;
    int total_page = (total_cnt % item == 0)? total_cnt / item : (total_cnt / item)+1; //전체 페이지 수
	int start_idx = (page - 1 ) * item; //시작 인덱스
	int end_idx = start_idx + item - 1; //끝 인덱스

    //상단바 - 출력
    navbarPrint(login, menu_no, id);
    if(is_reco == true){
        cout << "|              연령대별 추천               브랜드별 추천                   |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|                                                                          |" << endl;
        cout << "| 총 " << total_cnt << "건 조회" << endl;
    }else{
        cout << "|      전체            차종별            엔진            차 이름 검색      |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|                                                                          |" << endl;
        cout << "| 총 " << total_cnt << "건 조회";
        if (to_string(total_cnt).length() == 2)
        {
        cout << "               필터 [출시순/낮은 가격순/높은 가격순/인기순]  |" << endl;
        }
        else if (to_string(total_cnt).length() == 1)
        {
        cout << "                필터 [출시순/낮은 가격순/높은 가격순/인기순]  |" << endl;
        }
        cout << "|                                                                          |" << endl;
    }
   


    //페이지에 해당되는 리스트 출력 
    cout << "| n  brand    name          price     type      engine   date    sales     |" << endl;
    cout << "|                                                                          |" << endl;
    end_idx = (end_idx < total_cnt)? end_idx : total_cnt-1;
	if(start_idx < total_cnt) {
		for (int i = start_idx; i <= end_idx; i++) {
			cout << "| " ; 
            list[i].print(list[i].total_stock-list[i].stock);
            cout << "|" << endl;
		}
        //페이지 번호 출력
        cout << "|                                                                          |" << endl;
        cout << "|    " ;
        int cnt=0;
        for(int i = 1; i <= total_page; i++){ 
            if(i == page){
                cout << "'" << i  << "'"<< "  ";
                cnt+=4;
            }else{
                cout << i << "  ";
                cnt+=3;
            }
        }
        for (int i = 0; i < 69 - cnt; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
        cout << "+--------------------------------------------------------------------------+" << endl;
        cout << endl;
	}else{
        cout << "+--------------------------------------------------------------------------+" << endl;
        cout << endl;
        return false;
    }
    return true;
}

//자동차 상세보기
bool Car::getCarInfo(string car_id, bool is_reco){
    if(car_list_m.find(car_id) == car_list_m.end()) 
            return false;
    else{
        Car car = car_list_m[car_id];
        //상단바 출력
        navbarPrint(login, menu_no, id);
        if(is_reco == true){
            cout << "|              연령대별 추천               브랜드별 추천                   |" << endl;
            cout << "|--------------------------------------------------------------------------|" << endl;   
        }else{
            cout << "|      전체            차종별            엔진            차 이름 검색      |" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        }
     
        
        
        car.detailPrint(car.total_stock-car.stock);
        cout << "----------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    return true;
}

//자동차 구매
bool Car::getBuyCar(string car_id, int user_id, string username, string buyList_file){
    if(car_list_m.find(car_id) == car_list_m.end()){
        cout << "*해당 번호는 없는 번호입니다." << endl;
        return false;
    }else{
        Car car = car_list_m[car_id];
        //재고 없으면 구매 불가
        if(car.stock == 0){
            cout << "*해당 차량은 재고가 다 소진되어 구매가 불가능합니다." << endl;
            return false;
        }

        vector<string> color_list;
        istringstream ss(car.color);
        string color;
        while (getline(ss, color, ',')){
            color_list.push_back(color);
        } 

        while(true){
            cout << "*구매하실 색상을 입력해주세요. ";
            cout << "(";
            for(int i = 0; i < color_list.size(); i++){
                cout <<i+1 << "." << color_list[i] << " ";
            }
            cout << ") :";
            int color_num;
            cin >> color_num;
            if(color_num < 1 || color_num > color_list.size()){
                cout << "*해당 색상은 존재하지 않습니다." << endl;
            }else{
                color = color_list[color_num-1];
                cout << car.name << "의 하위 모델은 최저 " << car.min_price << "만원이며, 상위 모델은 최고 " << car.max_price << "만원 입니다. " << endl; 
                cout << "*구매하실 모델을 선택해주세요. (1. 하위, 2. 상위): ";
                string model_num;
                cin >> model_num;
                int price = (model_num == "1")? car.min_price : car.max_price;
                
                //파일 쓰기
                ofstream fout(buyList_file, ios::app); //쓰기모드, 파일 끝에 추가
                if(!fout) {
                    cout << "*구매리스트 파일 열기 오류";
                    return false;
                }
                if (fout.is_open()){
		            fout << user_id <<" " << car_id << " " << username << " " << car.name << " " << car.brand << " " << car.type << " "
                    << car.engine << " " << color << " " << price << "만원" << endl;
	            }
                fout.close();
                //자료구조에서 남은재고 수량-1
                //vector
                for(auto it = car_list_v.begin(); it != car_list_v.end(); it++){
                    if(it->car_id == stoi(car_id)){
                        it->stock--;
                        break;
                    }
                }
                //map
                car.stock--;
                car_list_m[car_id] = car;
                cout << car.name << " " << color << "색상 차량 구매가 성공적으로 이루어졌습니다 !!" << endl;
                break;
            }
         }
         cout << endl;
    }
    return true;
}

//준식




//연진