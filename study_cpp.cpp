#include <iostream>
using namespace std;

class TwoNumber {
private:
	int num1, num2;
public:

	// Initialize 
	// TwoNumber(int _n1, int _n2) : num1(_n1), num2(_n2) {}

	TwoNumber(int _n1, int _n2) {
		this->num1 = _n1;
		this->num2 = _n2;
	}

	void ShowTwoNumber() {
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void) {
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}