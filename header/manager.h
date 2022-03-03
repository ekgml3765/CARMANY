#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <algorithm>

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Manager{
    int manager_id;
    char id[256];
    char password[256];
};

struct buyList{
    int user_id;
    int car_id;
    string buyer;
    string carname;
    string brand;
    string carType;
    string engine;
    string color;
    string price;
    int cnt;
};

void getManagerList();
bool managerLogin();
bool managerLogout();
bool inputCarList();

bool readBuyList();
bool outputBuyList();

bool stockOutput(int m_choice);
bool buyListCarcnt(int& total_sales);
// bool carListcnt(int& total);

bool find_By_param_buyList(int m_choice, string param);
bool buyListOutput(int m_choice);

void billingBybrand();
bool billing(int m_choice);
int compare(const pair<int, int>& a, const pair<int, int>& b);
bool statistics();

#endif