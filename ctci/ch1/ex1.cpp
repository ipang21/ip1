#include <iostream>
#include <string>

using namespace std;

int checkUniqueChars(string x)
{
	int i, ret = 0;
	bool check[256] = {false};
	//cout << "Chars received: ";
	for (i = 0; i<x.length(); i++) {
		//cout << x[i] << " ";
		if (check[(int)x[i]] == false)
			check[(int)x[i]] = true;
		else {
			cout << "Non-unique char for: " << x[i] << endl;
			ret = -1;
		}
	}
	cout << endl;
	return ret;
}

int main()
{
	string input;
	int ret;
	cout << "Input string: ";
	getline(cin,input);
	cout << "Entered: " << input << endl;
	
	ret = checkUniqueChars(input);
	if (ret) {
		cout << "Not unique!!" << endl;
	}
	else
		cout << "Unique test passed!" << endl;
	
	return 0;
}
