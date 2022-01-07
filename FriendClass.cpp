#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy {
private : 
	int height;
	friend class Girl;

public : 
	Boy(int len) : height(len) {}
	void ShowYourFriendInfo(Girl &frn);
};

class Girl {
private : 
	char phNum[20];
public : 
	Girl(char *num) { strcpy_s(phNum, 20, num); }
	void ShowYourFriendIno(Boy &frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn) { cout << "** phNum : " << frn.phNum << endl; }
void Girl::ShowYourFriendIno(Boy &frn) { cout << "** height : " << frn.height << endl; }

int main(void) {
	Boy boy(170);
	Girl girl((char*)"010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendIno(boy);
	return 0;
}