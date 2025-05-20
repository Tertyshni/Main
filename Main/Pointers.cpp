#include <iostream>
using namespace std;

int main() {
	/*int var;
	cout << "Enter number";
	cin >> var;
	int* var_ptr = nullptr;
	var_ptr = &var;
	*var_ptr *= var;
	cout << "VARIABLE ADRESS:" << *var_ptr<<endl;*/

	int arr[] = {1,2,3,4,5};
	int size1 =sizeof(arr)/sizeof(arr[0])
	ar_ptr = arr;
	for (int i = 0; i < size1; ++i) {
		printf("{%i}", *(ar_ptr++));
		ar_ptr++;

	}

	
	return 0;
}