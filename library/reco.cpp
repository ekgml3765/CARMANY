#include "../header/car.h"


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