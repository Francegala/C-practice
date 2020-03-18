#include <iostream>
using namespace std;
int main()
{
	int my_array[2];
	my_array[0] = 0;
	my_array[1] = 1;

	int my_array_2[3]  { 0,1,2 }; //you can omit equal

	int my_array_3[]  {1,2,3,4 }; //it figures out automatically size knowing the elements

	int my_array_4[7]{ 5,8 }; //array not full so all the others are zeros


	/* Print each array index then the value*/
	for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++)       // Because there is not 'lenght' you have to take the size of the array divided of the size of each variable
		cout << i << '-' << my_array[i] << endl;                           // So if there is an array of size 10 and the first variable has lenght 5 there must be only two variables
	cout << "-----------"<<endl;                                           //[first] weight 5; [second] weight 5; total array weight  = 10
	for (int i = 0; i < sizeof(my_array_2) / sizeof(my_array_2[0]); i++)   //total known (size of total) divided by weight of first (size of an element) we know how many elements
		cout << i << '-' << my_array_2[i] << endl;
	cout << "-----------" << endl;
	for (int i = 0; i < sizeof(my_array_3) / sizeof(my_array_3[0]); i++)
		cout << i << '-' << my_array_3[i] << endl;
	cout << "-----------" << endl;
	for (int i = 0; i < sizeof(my_array_4) / sizeof(my_array_4[0]); i++)
		cout << i << '-' << my_array_4[i] << endl;



return 0;
}