#include "../header/car.h"

//전역변수
extern string menu_name; 
extern string id;
extern int login;

//연령별 추천
bool Car::getRecoListByAge(string age, vector<Car> &list, string buyList_file, string userfile_path, int page){
    
    map<string, string> user_map; //key-user_id, value - age
    map<string, int> car_map; //key-car_id, value - count (default:1)
    vector <pair<string, int>> v; //car_map을 vector로 변경
    vector<Car> tmp; 
    
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
        auto it = car_map.find(car_id);
        if(it != car_map.end())
            car_map[car_id]++;
        else
            car_map[car_id] = 1;

	}
    fin2.close();

    //car_map을 vector로 변경해 value기준 정렬
    copy(car_map.begin(), car_map.end(), back_inserter<vector<pair<string, int>>>(v));
    sort(v.begin(), v.end(), [ ]( pair<string, int> left , pair<string, int> right ){
        return left.second > right.second;
    });

  
    for(int i = 0; i < v.size(); i++){
        //cout << v[i].first << " " << v[i].second;
        tmp.push_back(car_list_m[v[i].first]);
    }

    list = tmp;
    int total_cnt = list.size();    
    navbarPrint(login, menu_name, id);
    cout << "|   연령대별 추천       성별 추천       브랜드별 추천        개인화 추천   |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;
                   
    
    
    //페이징
    int item = 10;
    int total_page = (total_cnt % item == 0)? total_cnt / item : (total_cnt / item)+1; //전체 페이지 수
	int start_idx = (page - 1 ) * item; //시작 인덱스
	int end_idx = start_idx + item - 1; //끝 인덱스

    //페이지에 해당되는 리스트 출력
    cout << endl;
    cout << "| 총 " << total_cnt << "건 조회";
    cout << "               필터 [인기순/출시순/낮은 가격순/높은 가격순]  |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "| n  brand    name          price     type      engine   date    sales     |" << endl;

    end_idx = (end_idx < total_cnt)? end_idx : total_cnt-1;
	if(start_idx < total_cnt) {
		for (int i = start_idx; i <= end_idx; i++) {
			cout << "| " ; 
            list[i].print(v[i].second);
            cout << "|" << endl;

		}
        //페이지 번호 출력
        cout << endl;
        cout << "              [                   " ;
        for(int i = 1; i <= total_page; i++){ 
            if(i == page){
                cout << "'" << i  << "'"<< "  ";
            }else{
                cout << i << "  ";
            }
        }
        cout << "                    ]" << endl;
        cout << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << endl;
	}else{
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << endl;
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

    navbarPrint(login, menu_name, id);
    cout << "|   연령대별 추천       성별 추천       브랜드별 추천        개인화 추천   |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;
     
    
    //페이징
    int item = 10;
    int total_page = (total_cnt % item == 0)? total_cnt / item : (total_cnt / item)+1; //전체 페이지 수
	int start_idx = (page - 1 ) * item; //시작 인덱스
	int end_idx = start_idx + item - 1; //끝 인덱스

    //페이지에 해당되는 리스트 출력
    cout << endl;
    cout << "| 총 " << total_cnt << "건 조회";
    cout << "               필터 [인기순/출시순/낮은 가격순/높은 가격순]  |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "| n  brand    name          price     type      engine   date    sales     |" << endl;

    end_idx = (end_idx < total_cnt)? end_idx : total_cnt-1;
	if(start_idx < total_cnt) {
		for (int i = start_idx; i <= end_idx; i++) {
			cout << "| " ; 
            list[i].print(list[i].total_stock-list[i].stock);
            cout << "|" << endl;

		}
        //페이지 번호 출력
        cout << endl;
        cout << "              [                   " ;
        for(int i = 1; i <= total_page; i++){ 
            if(i == page){
                cout << "'" << i  << "'"<< "  ";
            }else{
                cout << i << "  ";
            }
        }
        cout << "                    ]" << endl;
        cout << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << endl;
	}else{
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << endl;
        return false;
    }
    return true;
};