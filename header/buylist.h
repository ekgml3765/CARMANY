#ifndef BUYLIST_H
#define BUYLIST_H

extern "C" int getMyCarList();
extern "C" int viewMyCar(int user_num);
// extern "C" void AppendNode(Node** List, int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price);
// extern "C" Node* CreateNode(int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price);

typedef struct buyList{
    int user_id;
    int car_id;
    char buyer[20];
    char carname[20];
    char brand[20];
    char carType[20];
    char engine[20];
    char color[20];
    char price[20];
}buylist;



// typedef struct _Node{
//     buylist* data;
//     struct _Node* next_node;
// }Node;



int getMyCarList();
int viewMyCar(int user_num);
// void AppendNode(Node** List, int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price);
// Node* CreateNode(int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price);





#endif

// // int addBookmarkObj();
// int viewMyBookmark(int user_id);
// // int delBookmarkObj();


// #endif



// extern "C" int pepe();



// typedef struct people_information {
//     char name[21];
//     int age;   
// } people_info;

// #endif

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #define file_name "bookmark.txt"
// typedef struct Bookmark 
// {
//     int user_id;  // car.txt에 저장할 때 얘만 추가해서 bookmark.txt에 저장해주기
//     int car_id;
//     char brand[20];
//     char name[20];
//     int min_price;
//     int max_price;
//     char type[20];
//     char engine[20];
//     char date[20];
//     char color[20];
//     char size[20];
//     char efficency[20];
//     int people;
//     int stock;
//     int total_stock;  
// }Bookmark;

// int main(void)
// {
//     Bookmark bookmark[100];
//     FILE* fp = fopen(file_name, "r");// 파일 읽기모드로 열기
//     if (fp == NULL) {
//         printf("찜 목록 불러오기에 실패하였습니다.");
//         return 0;
//     }
//     char buffer[1001],*token; 
 
//     int i = 0;
//     int idx = 0;
//     while (!feof(fp)) {
//         i = 0;//i초기화
//         fgets(buffer, 1001, fp); 
//         token = strtok(buffer, " "); // 
//         while (token != NULL) {
 
//             if (i == 0) {
//                 strcpy(bookmark[idx].name, token);
//             }
//             else if (i == 1) {
//                 bookmark[idx].user_id = atoi(token);
//             }
//             i++;
//             token = strtok(NULL, " ");
//         }
//         idx++;
//     }
//     //읽은 내용이 잘 저장됐는지 출력
//     for (int i = 0; i < idx; i++) {
//         printf("%s %d\n", bookmark[i].name, bookmark[i].user_id);
//     }
//     fclose(fp); // 파일 닫기
 
//     return 0;
// }