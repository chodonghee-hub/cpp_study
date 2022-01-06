#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1, num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2) { this->ShowSimpleData(); }
	SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2) {
		cout << "*** Called SoSimple(SoSImple &copy)" << endl;
		this->ShowSimpleData();
	}
	void ShowSimpleData() {
		cout << "*** now object : " << this << endl;
		cout << "*** num1 num2 : " << num1 << " " << num2 << endl << endl;
	}
};

int main(void) {
	cout << "생성 및 초기화 직전" << endl;
	SoSimple s1(15, 30);

	cout << "생성 및 초기화 직후" << endl;
	SoSimple s2(s1);
	return 0;
}