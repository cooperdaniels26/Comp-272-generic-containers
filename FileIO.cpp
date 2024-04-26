#include <fstream>
#include <iostream>
using namespace std;



//create a file a writes data use stream insertion operater then close file
//then re open file and read data from it
void example0()
{
	int numItems = 10;
	//create output file stream
	fstream testFile("sqaures.data", ios::out);
	if (testFile.fail())
	{
		cout << "Error: output file could not be opened!" << endl;
	}
	else
	{
		cout << "The output file opened successfully" << endl;
	}
	//write the first 10 perfect sqaure
	for (int k = 0; k < numItems; k++)
	{
		testFile << k * k << endl;
	}
	//close the file
	testFile.close();
	//reopen file for reading
	testFile.open("sqaures.data", ios::in);
	//echo file content to console
	int val;
	for (int k = 0; k < numItems; k++)
	{
		testFile >> val;
		cout << "item " << k << " is " << val << endl;
	}
	testFile.close();
}



int main()
{
    std::cout << "Hello FileIO!\n";

	example0();
}

