
#include<iostream>
#include<cmath>
#include<sstream>
#include<iomanip>
using namespace std;

class Quadratic {
	friend Quadratic add(Quadratic& q1, Quadratic& q2);
	friend Quadratic subtract(Quadratic& q1, Quadratic& q2);
public:
	Quadratic(double a, double b, double c);
	std::string toString();       // ax^2+bx+c=0 format의 string 리턴
	void solve();                 // 이차방정식의 해를 구해서 출력
private:
	double a{ 1 };
	double b{ 0 };
	double c{ 0 };
};

Quadratic::Quadratic(double a, double b, double c)
{
	if (a != 0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	else throw invalid_argument("2차항의 계수는 0이 아니어야합니다."); // 예외처리는 <stdexcept>를 굳이 안불러와도 된다. 근데 왜 메시지는 안뜨지?
}

std::string Quadratic::toString()
{
	ostringstream output; // <sstream> 라이브러리의 ostringstream 타입은 출력하고자 하는 문자열을 변수에 저장할 수 있다. 해당 변수를 호출하면 자동 출력!

	if(b < 0 && (c > 0 || c == 0))
		output << a << "x^2" << b << "x" << "+" << c << "=" << "0";
	else if(b > 0 && c < 0)
		output << a << "x^2" << "+" << b << "x" << c << "=" << "0";
	else if(b<0 && (c<0 || c == 0))
		output << a << "x^2" << b << "x" << c << "=" << "0";
	else
		output << a << "x^2" << "+" << b << "x" << "+" << c << "=" << "0";
	
	return output.str();
}

void Quadratic::solve()
{
	double solved = (-b + sqrt(b * b - 4 * a * c)) * 1 / 2 * a;
	double val = b * b - 4 * a * c;
	if (val < 0)
		cout << "No real roots\n";
	else if (val == 0)
		cout << fixed << setprecision(2) << "x=" << (-b / a) / 2 << '\n';
	else if (val > 0)
		cout <<fixed << setprecision(2) << "x=" << ((-b + sqrt(b * b - 4 * a * c)) / a) / 2 << " or " << ((-b - sqrt(b * b - 4 * a * c)) / a) / 2 << "\n";
}



Quadratic add(Quadratic& q1, Quadratic& q2)

{
	double addA = q1.a + q2.a;
	double addB = q1.b + q2.b;
	double addC = q1.c + q2.c;
	Quadratic added(addA, addB, addC);
	
	return added;
}



Quadratic subtract(Quadratic& q1, Quadratic& q2)
{
	double subA = q1.a - q2.a;
	double subB = q1.b - q2.b;
	double subC = q1.c - q2.c;
	Quadratic subed(subA, subB, subC);

	return subed;
}

int main() {
	double num1, num2, num3, num4, num5, num6{ 0 };
	cout << "Enter 3 coefficients of the first quadratic equation: ";
	cin >> num1 >> num2 >> num3;
	Quadratic a(num1, num2, num3);
	cout << "First equation: " << a.toString() << '\n';

	cout << "Enter 3 coefficients of the second quadratic equation: ";
	cin >> num4 >> num5 >> num6;
	Quadratic b(num4, num5, num6);
	cout << "Second equation: " << b.toString() << "\n\n";

	cout << "Solution of " << a.toString() << ": "; 
	a.solve();
	cout << "Solution of " << b.toString() << ": "; 
	b.solve();
	cout << '\n';

	cout << "(" << a.toString() << ")+(" << b.toString() << ")" << "=" << add(a, b).toString() << '\n';
	cout << "(" << a.toString() << ")-(" << b.toString() << ")" << "=" << subtract(a, b).toString() << '\n';

	return 0; // 왜 자꾸 return 0을 빼먹냐ㅑ.. main 함수는 값을 리턴해야 합니다 오류 뜨자나
}
