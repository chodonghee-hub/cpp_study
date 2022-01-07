#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	int age;
	char name[50];
public : 
	Person(int myage, char* myname) : age(myage) { strcpy_s(name, 50, myname); }
	void Name() const { cout << "**name : " << name << endl; }
	void Age() const { cout << "**age : " << age << endl; }
};

class UnivStudent : public Person {
private: 
	char major[50];
public : 
	UnivStudent(char *myname, int myage, char* mymajor) 
		: Person(myage, myname) { strcpy_s(major, 50, mymajor); }

	void StuInfo() const {
		Name();
		Age();
		cout << "**major : " << major << endl;
	}
};

int main(void) {
	UnivStudent ustd1((char*) "lee", 22, (char*) "computer eng.");
	ustd1.StuInfo();
	return 0;
}