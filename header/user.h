#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

extern int active_user_id;
extern string username;

struct userNode{
	int user_id;      //사용자 식별번호
	string id;           //사용자 아이디
	string password;  //사용자 비밀번호
	string phone;     //사용자 전화번호
	string name;      //사용자 이름
	string age;       //사용자 연령대 (10대, 20대, 30대 등)
	int sex;          //사용자 성별 (0-남자, 1-여자)
	struct userNode* next;
};
bool openFile();
bool userLogin();
bool userLogout();
bool userUpdate();
bool createUser();
void appendInFile(int userid, string id, string password, string phone, string name, string age, int sex);

class userLinkedList{
	userNode *HEAD;
	userNode *TAIL;
	int size;

	public:
		userLinkedList() : HEAD(nullptr), TAIL(nullptr){}
		~userLinkedList() {deleteList();}

		void addNode(int user_id, string id, string password, string phone, string name, string age, int sex){
			userNode *user = new userNode;

			size++;
			user->user_id = user_id;
			user->id = id;
			user->password = password;
			user->phone = phone;
			user->name = name;
			user->age = age;
			user->sex = sex;
			user->next = nullptr;

			if (HEAD == nullptr){
				HEAD = TAIL = user;
			}
			else{
				TAIL->next = user;
				TAIL = user;
			}
		}

		void show(){
			userNode* tmp = HEAD;

			while(tmp!=nullptr){
				cout<<tmp->id<<tmp->name<<endl;
				tmp = tmp->next;
			}
		}

		void deleteList(){
			userNode* ptr = HEAD;
			while(ptr != nullptr){
				HEAD = ptr->next;
				delete ptr;
				ptr = HEAD;
			}

			delete HEAD;
			size =0;
		}

		bool searchLoginValue(string id, string password){
			userNode* ptr = HEAD;
			bool isFind = false;

			while(ptr!=nullptr){
				if (ptr->id == id && ptr->password == password ){
					isFind = true;
					active_user_id = ptr->user_id;
					username = ptr->name;
					return true;
				}
				ptr = ptr->next;
			}

			if (isFind == false){
				// cout<<"못찾음"<<endl;
				return false;
			}
			return false;
		}

		bool searchId(string id){
			userNode* ptr = HEAD;
			bool isFind = false;

			while(ptr!=nullptr){
				if (ptr->id == id){
					isFind = true;
					return false;
				}
				ptr = ptr->next;
			}
			return true;
		}

		int lastUserId(){
			return TAIL->user_id;
		}

		void showCurInfo(){
			userNode* ptr = HEAD;

			while(ptr!=nullptr){
				if (ptr->user_id == active_user_id ){
					break;
				}
				ptr = ptr->next;
			}
			//네모 안에 띄워줄 내용
			cout<<"아이디"<<ptr->id<<endl;
			cout<<"비밀번호"<<ptr->password<<endl;
			cout<<"전화번호"<<ptr->phone<<endl;
			cout<<"이름"<<ptr->name<<endl;
			cout<<"연령대"<<ptr->age<<endl;
			cout<<"성별";
			if (ptr->sex == 0) cout<<"남"<<endl;
			else cout<<"여"<<endl;

		}

		void updateFile(){
			userNode* tmp = HEAD;
			ofstream fout;

			fout.open("user.txt");
			// fout.open("C:\\Users\\user\\Documents\\GitHub\\data\\user.txt");
			
			while(tmp!=nullptr){
				if (fout.is_open()){
					fout<<tmp->user_id<<" "<<tmp->id<<" "<<tmp->password<<" "<<tmp->phone<<" "<<tmp->name<<" "<<tmp->age<<" "<<tmp->sex<<"\n";
				}
				tmp = tmp->next;
			}
			fout.close();
		}

		void updateNode(int choice, string change){
			userNode* ptr = HEAD;

			while(ptr!=nullptr){
				if (ptr->user_id == active_user_id ){
					break;
				}
				ptr = ptr->next;
			}

			if (choice==1){
				ptr->password = change;
			}
			else if (choice == 2){
				ptr->phone = change;
			}
			else if (choice == 3){
				ptr->name = change;
			}
			else if (choice == 4){
				ptr->age = change;
			}

			updateFile();

		}

		void getGender(int user_id, int& get_gender){
			userNode* ptr = HEAD;

			while(ptr!=nullptr){
				if (ptr->user_id == user_id){
					// cout<<ptr->sex<<"ptr->sex"<<endl;
					get_gender = ptr->sex;
					break;
				}
				ptr = ptr->next;
			}		
		}
};
#endif