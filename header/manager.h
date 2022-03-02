#ifndef MANAGER_H
#define MANAGER_H

struct Manager{
    int manager_id;
    char id[256];
    char password[256];
};

struct buyList{
    int user_id;
    int car_id;
    char carname[1026];
    char brand[1026];
    char carType[1026];
    char engine[1026];
    char color[256];
    char price[256];
};

void getManagerList();
bool managerLogin();
bool managerLogout();
bool inputCarList();

bool stockOutput();

//C
int outputCarList();
int buyListOutput();
int billling();
int statistics();

#endif