#include "../header/car.h"


//연령별 추천
bool Car::getRecoListByAge(string age, vector<Car> &list, string buyList_file, string userfile_path, int page){
    
    map<string, string> user_map;
    set<string> car_set; // -> map으로 바꿔서 구매리스트 카운트 해야해!!!!

    //1. uset.txt파일 오픈
    ifstream fin(userfile_path);
    
    // 파일 열기 실패
    if(!fin) { 
		cout << "Can't Open User File";
        return false;
	}
   
    string user_line;
    string user_word;
    while(getline(fin, user_line)) {
        istringstream ss(user_line);
        vector<string> v;
        while (getline(ss, user_word, ' ')){
            v.push_back(user_word);
        }  
        string user_id = v[0];
        string age = v[5];

        //자료구조 저장
        user_map[user_id]=age;
	}
    
    fin.close();

    //2. buyList.txt 파일 오픈
    ifstream fin2(buyList_file);
    // 파일 열기 실패
    if(!fin2) { 
		cout << "Can't Open buyList File";
        return false;
	}
   
    string buy_line;
    string buy_word;
    while(getline(fin2, buy_line)) {
        istringstream ss(buy_line);
        vector<string> v;
        while (getline(ss, buy_word, ' ')){
            v.push_back(buy_word);
        }  
        
        string user_id = v[0];
        if(user_map[user_id] != age) //입력받은 연령대와 같아야함
            continue;
        string car_id = v[1];

        //자료구조 저장 - 구매리스트에 car_id 중복 제거
        car_set.insert(car_id);
	}
    fin2.close();
    //vector에 carlist 뽑기
    vector<Car> tmp; 
    for(auto it = car_set.begin(); it != car_set.end(); it++){
        string car_id = *it;
        tmp.push_back(car_list_m[car_id]); 
    }

    list = tmp;
    int total_cnt = list.size();    
    
    //판매량 기준 정렬
    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
        int a_dif_stock = a.getTotalStock()-a.getStock();
        int b_dif_sock = b.getTotalStock()-b.getStock();
        return  a_dif_stock > b_dif_sock;
    });    
    
    
    //페이징
    int item = 10;
    int total_page = (total_cnt % item == 0)? total_cnt / item : (total_cnt / item)+1; //전체 페이지 수
	int start_idx = (page - 1 ) * item; //시작 인덱스
	int end_idx = start_idx + item - 1; //끝 인덱스

    //페이지에 해당되는 리스트 출력
    cout << endl;
    cout << "|  총 " << total_cnt << "건 조회";
    cout << "필터 [인기순/출시순/낮은 가격순/높은 가격순]  |" << endl;

    end_idx = (end_idx < total_cnt)? end_idx : total_cnt-1;
	if(start_idx < total_cnt) {
		for (int i = start_idx; i <= end_idx; i++) {
			    cout << "|       " ; 
                list[i].print();
                cout << "          |" << endl;
		}
        //페이지 번호 출력
        cout << "|       " ;
        for(int i = 1; i <= total_page; i++){ 
            if(i == page){
                cout << "'" << i  << "'"<< "  ";
            }else{
                cout << i << "  ";
            }
        }
        cout << "          |" << endl;
        cout << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
	}else{
        return false;
    }
    return true;
}


//브랜드 추천
bool Car::getRecoListByBrand(string brand, vector<Car> &list, int page){
    vector<Car> tmp;
    for(int i = 0; i < car_list_v.size(); i++){
        if(car_list_v[i].brand == brand){
            tmp.push_back(car_list_v[i]);
        }
    }
 
    list = tmp;
    int total_cnt = list.size();

    //정렬 - 판매량 순
    sort( list.begin( ), list.end( ), [ ]( const Car& a, const Car& b ){
        int a_dif_stock = a.getTotalStock()-a.getStock();
        int b_dif_sock = b.getTotalStock()-b.getStock();
        return  a_dif_stock > b_dif_sock;
    }); 

    //페이징
    int item = 10;
    int total_page = (total_cnt % item == 0)? total_cnt / item : (total_cnt / item)+1; //전체 페이지 수
	int start_idx = (page - 1 ) * item; //시작 인덱스
	int end_idx = start_idx + item - 1; //끝 인덱스

    //페이지에 해당되는 리스트 출력
    cout << endl;
    cout << "|  총 " << total_cnt << "건 조회";
    cout << "필터 [인기순/출시순/낮은 가격순/높은 가격순]  |" << endl;

    end_idx = (end_idx < total_cnt)? end_idx : total_cnt-1;
	if(start_idx < total_cnt) {
		for (int i = start_idx; i <= end_idx; i++) {
			    cout << "|       " ; 
                list[i].print();
                cout << "          |" << endl;
		}
        //페이지 번호 출력
        cout << "|       " ;
        for(int i = 1; i <= total_page; i++){ 
            if(i == page){
                cout << "'" << i  << "'"<< "  ";
            }else{
                cout << i << "  ";
            }
        }
        cout << "          |" << endl;
        cout << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
	}else{
        return false;
    }
    return true;
};