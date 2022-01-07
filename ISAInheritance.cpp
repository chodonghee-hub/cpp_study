#include <iostream>
#include <cstring>

using namespace std;

class Computer {
private :
	char owner[50];
public :
	Computer(char* name) { strcpy_s(owner, 50, name); }
	void Calculate() { cout << "now calc !! " << endl; }
};

class NotebookComp : public Computer {
private : 
	int Battery;
public :
	NotebookComp(char *name, int initChag) : Computer(name), Battery(initChag) {}
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "now need charge it !! " << endl;
			return;
		}
		cout << "now move ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery;  }
};

class TabletNotebook : public NotebookComp {
private : 
	char regstPenModel[50];
public :
	TabletNotebook(char *name, int initChag, char *pen) 
		: NotebookComp(name, initChag) { strcpy_s(regstPenModel, 50, pen); }
	void Write(char *penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "now need charge it !!" << endl;
			return;
		}
		if (strncmp(regstPenModel, penInfo, 50) != 0) {
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(void) {
	NotebookComp nc((char*)"lee", 5);
	TabletNotebook tn((char*)"jung", 5, (char*)"ISE-241-242");
	nc.MovingCal();
	tn.Write((char*)"ISE-241-242");
	return 0;
}