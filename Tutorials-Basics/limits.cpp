#include <iostream>
using namespace std;
int main() 
{
	
	int lol = -50000;
	float virgola = 2.32;
	bool nonboolean = true;
	const char* stringa = "stringgggg";
	auto nuovavariabile = false;
	auto check = 200.01;

	int over_9000 = INT_MAX;
	int under_9000 = INT_MIN;

// printing some values:
	cout <<"sizeof(int)   " << sizeof(int) << endl;
	cout << "sizeof(short int)   " << sizeof(short int) << endl;
	cout << "sizeof( long int)   " << sizeof(long int) << endl;
	cout << "sizeof( long long int)   " << sizeof(long long int) << endl;
	cout << '\n' << endl;
	cout <<" sizeof(char*)   "<< sizeof(char*) << endl;
	cout <<" sizeof(string)   "<< sizeof(string) << endl;
	cout << '\n' << endl;

// testing unsigned and signed    
	unsigned a = -1; //never be negative no sign
	unsigned b = 1; //never be negative no sign
	unsigned c = 0; //never be negative no sign
	unsigned d = +1; //never be negative no sign
	signed e = -1; //can be negative has sign
	signed f = 1; //can be negative has sign
	signed g = 0; //can be negative has sign
	signed h = +1; //can be negative has sign

	cout << "unsigned a = -1   " << a << endl;
	cout <<"unsigned b = 1   "<< b << endl;
	cout << "unsigned c = 0   " << c << endl;
	cout << "unsigned d = +1   " << d << endl;
	cout << "signed e = -1   " << e << endl;
	cout << "signed f = 1   " << f << endl;
	cout << "signed g = 0   " << g << endl;
	cout << "signed h = +1  " << h << endl;

	//http://www.cplusplus.com/reference/climits/
	cout << '\n' << endl;
	cout << "INT_MIN   " << INT_MIN << endl;
	cout << "INT_MAX   " << INT_MAX << endl;
	cout << "SHRT_MIN   " << SHRT_MIN << endl;
	cout << "SHRT_MAX   " << SHRT_MAX << endl;
	cout << "LONG_MIN   " << LONG_MIN << endl;
	cout << "LONG_MAX   " << LONG_MAX << endl;
	cout << "UINT_MAX   " << UINT_MAX << endl;//min is zero
	cout << "ULONG_MAX   " << ULONG_MAX << endl;//unsigned starts from zero
	cout << "ULLONG_MAX   " << ULLONG_MAX << endl;//min is zero
	cout << '\n' << endl;
	unsigned short int usi = -1;
	cout << "unsigned short int usi = -1   " << usi << endl;
	unsigned long long int ulli = -1;
	cout << "unsigned long long int ulli = -1   " << ulli << endl;
	long double uld = -1;//can't be unsigned
	cout << "unsigned !error! long double uld = -1   " << uld << endl;

return 0;
}