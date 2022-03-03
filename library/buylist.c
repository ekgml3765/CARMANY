// #include "../header/bookmark.h"

// int viewMyBookmark(int user_id)
// {
    
// }




// #pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define file_name "buyList.txt"
#include "../header/buylist.h"
buylistC mark[200];
int totalBuyList;





int getMyCarList()
{
    totalBuyList = 0;
    // buylist mark[200];
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("구매 목록 불러오기에 실패하였습니다.");
        return 0;
    }
    char buffer[1001], *token;

    int i = 0, idx = 0;
    while (!feof(fp))
    {
        i = 0;
        fgets(buffer, 1001, fp);
        token = strtok(buffer, " ");
        while (token != NULL)
        {
            if (i == 0)
            {
                mark[idx].user_id = atoi(token);
            }
            else if (i == 1)
            {
                mark[idx].car_id = atoi(token);
            }
            else if (i == 2)
            {
                strcpy(mark[idx].buyer, token);
            }
            else if (i == 3)
            {
                strcpy(mark[idx].carname, token);
            }
            else if (i == 4)
            {
                strcpy(mark[idx].brand, token);
            }
            else if (i == 5)
            {
                strcpy(mark[idx].carType, token);
            }
            else if (i == 6)
            {
                strcpy(mark[idx].engine, token);
            }
            else if (i == 7)
            {
                strcpy(mark[idx].color, token);
            }
            else if (i == 8)
            {
                strcpy(mark[idx].price, token);
            }
            
            i++;
            token = strtok(NULL, " ");
        }
        idx++;
        totalBuyList++;
    }
    return 0;
}

int viewMyCar(int user_num)
{
    int index = 1;
    for (int i = 0; i < totalBuyList; i++)
    {
        if (user_num == mark[i].user_id)
        {
            // printf("%d %s %s %s %s %s %s\n", index, mark[i].brand, mark[i].carname, mark[i].engine, mark[i].color, mark[i].price);
            
            printf("| %d", index);
            if (index >= 10)
            {
                printf(" ");
            }
            else
            {
                printf("  ");
            }
            printf("%s", mark[i].brand);
            for (int j=0; j < 9 - strlen(mark[i].brand); j++)
            {
                printf(" ");
            }
            printf("%s", mark[i].carname);
            for (int j=0; j < 14 - strlen(mark[i].carname); j++)
            {
                printf(" ");
            }
            printf("%s", mark[i].engine);
            for (int j=0; j < 9 - strlen(mark[i].engine); j++)
            {
                printf(" ");
            }
            printf("%s", mark[i].color);
            for (int j=0; j < 13 - strlen(mark[i].color); j++)
            {
                printf(" ");
            }
            printf("%s", mark[i].price);
            printf("    |\n");
            index++;
        }
    }
    printf("+--------------------------------------------------------------------------+");
    return 0;
}






// Node* CreateNode(int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price) {
// 	Node* newNode = (Node*)malloc(sizeof(Node));
// 	newNode->data = (buylist*)malloc(sizeof(buylist));
// 	newNode->next_node = NULL;
// 	newNode->data->user_id = user_id;
// 	newNode->data->car_id = car_id;
//     strcpy(newNode->data->carname, carname);
// 	strcpy(newNode->data->brand, brand);
// 	strcpy(newNode->data->carType, carType);
// 	strcpy(newNode->data->engine, engine);
// 	strcpy(newNode->data->engine, engine);
// 	strcpy(newNode->data->price, price);
	
// 	return newNode;
// }


// void AppendNode(Node** List, int user_id, int car_id, char* carname, char* brand, char* carType, char* engine, char* color, char* price) {
// 	if ((*List) == NULL) {
// 		List = CreateNode(user_id, car_id, carname, brand, carType, engine, color, price);
// 	}
// 	else {
// 		Node* Node_tail = (*List);
// 		while (Node_tail->next_node != NULL) {
// 			Node_tail = Node_tail->next_node;
// 		}
// 		Node_tail->next_node = CreateNode(user_id, car_id, carname, brand, carType, engine, color, price);
// 	}
// }




// buylist mark1;
// int getMyCarList()
// {
//     FILE *fp = fopen(file_name, "r");
//     if (fp == NULL)
//     {
//         printf("구매 목록 불러오기에 실패하였습니다.");
//         return 0;
//     }
//     char buffer[1001], *token;

//     Node* List = CreateNode(mark1.user_id, mark1.car_id, mark1.carname, mark1.brand, mark1.carType, mark1.engine, mark1.color, mark1.price);

//     int i = 0, idx = 0;
//     while (!feof(fp))
//     {
//         i = 0;
//         fgets(buffer, 1001, fp);
//         token = strtok(buffer, " ");
//         while (token != NULL)
//         {
//             if (i == 0)
//             {
//                 mark1.user_id = atoi(token);
//             }
//             else if (i == 1)
//             {
//                 mark1.car_id = atoi(token);
//             }
//             else if (i == 2)
//             {
//                 strcpy(mark1.carname, token);
//             }
//             else if (i == 3)
//             {
//                 strcpy(mark1.brand, token);
//             }
//             else if (i == 4)
//             {
//                 strcpy(mark1.carType, token);
//             }
//             else if (i == 5)
//             {
//                 strcpy(mark1.engine, token);
//             }
//             else if (i == 6)
//             {
//                 strcpy(mark1.color, token);
//             }
//             else if (i == 7)
//             {
//                 strcpy(mark1.price, token);
//             }
            
//             i++;
//             token = strtok(NULL, " ");
//             if (idx == 0)
//             {
//                 Node* List = CreateNode(mark1.user_id, mark1.car_id, mark1.carname, mark1.brand, mark1.carType, mark1.engine, mark1.color, mark1.price);
//             }
//             else
//             {
//                 AppendNode(&List, mark1.user_id, mark1.car_id, mark1.carname, mark1.brand, mark1.carType, mark1.engine, mark1.color, mark1.price);
//             }
//         }
//         idx++;
//     }
//     return 0;
// }

// void viewMyCar(Node** List, int user_num) {
// 	Node* Temp = (*List);
// 	while (1) {
//         if (user_num == mark1.user_id)
//         {
//             printf("%s %s %s %s %s %s\n", Temp->data->carname, Temp->data->brand, Temp->data->carType, Temp->data->engine, Temp->data->color, Temp->data->price);
//         }

// 		Temp = Temp->next_node;
// 		if (Temp == NULL) break;
// 	}
// }










 
// void find_people_name(people_info* people, int size);
// int pepe()
// {
    // people_info people[100];
    // FILE* fp = fopen(file_name, "r");// 파일 읽기모드로 열기
    // if (fp == NULL) {
    //     printf("fail to read file");
    //     return 0;
    // }
    // char buffer[1001],*token; 
 
    // int i = 0;
    // int idx = 0;
    // while (!feof(fp)) {
    //     i = 0;//i초기화
    //     fgets(buffer, 1001, fp); 
    //     token = strtok(buffer, " "); // 
    //     while (token != NULL) {
 
    //         if (i == 0) {
    //             strcpy(people[idx].name, token);
    //         }
    //         else if (i == 1) {
    //             people[idx].age = atoi(token);
    //         }
    //         i++;
    //         token = strtok(NULL, " ");
    //     }
    //     idx++;
    // }
    // //읽은 내용이 잘 저장됐는지 출력
    // for (int i = 0; i < idx; i++) {
    //     printf("%s %d\n", people[i].name, people[i].age);
    // }
    // fclose(fp); // 파일 닫기
    // printf("호출되었습니다!!!!");
 
    // find_people_name(people,idx);
    // return 0;
// }
 
// void find_people_name(people_info* people, int size)
// {
//     printf("찾고싶은 사람의 이름을 입력하세요: ");
//     char find_name[100];
//     scanf("%s", find_name);
//     char* ptr;
//     people_info * p;
//     int line=0;
//     for (p = people; p < people + size; p++,line++) {
//         ptr = strstr(p->name, find_name);
//         if (ptr != NULL) {
//             printf("파일의 [%d]line에 이름 :[%s], 나이:[%d] 발견\n",line, p->name, p->age);
//         }
//     }
// }