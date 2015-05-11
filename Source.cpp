#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

// Employee object to put in map
class Employee {
public:
	string firstName;
	string lastName;
	string jobTitle;
	string phoneNum;
};

int main(int argc, char **argv) {
	// Check if there are enough arguments to run
	if (argc != 2) {
		cerr << "not enough args" << endl;
		return -1;
	}

	// Map to read employees into
	map<string, Employee> employees;
	ifstream empFile(argv[1]);
	// Open employee file
	//ifstream empFile("C:\\Users\\Leah\\ClionProjects\\technicaTest"
	// "\\employees.txt");

	// Check if file is open
	if (!empFile.is_open()) {
		cerr << "Can't open file" << endl;
		return -1;
	}

	// Read in employees until the end of the file
	while (!empFile.eof()) {
		// Employee object to read lines into
		Employee newEmp;
		// Read in first name
		empFile >> newEmp.firstName;
		// Read in last name
		empFile >> newEmp.lastName;
		// Read in job title
		empFile >> newEmp.jobTitle;
		// Read in phone number
		empFile >> newEmp.phoneNum;
		// Format phone number
		newEmp.phoneNum.insert(0, "(");
		newEmp.phoneNum.insert(4, ")");
		newEmp.phoneNum.insert(8, "-");
		// Insert employee into map
		employees[newEmp.lastName] = newEmp;
	}
	// Close file
	empFile.close();
	// Iterator to go through map
	map<string, Employee>::iterator it;
	// Print out each employee from the map
	for (it = employees.begin(); it != employees.end(); ++it){
		cout << it->first << ", " << it->second.firstName << " " <<
			it->second.jobTitle << " " << it->second.phoneNum << endl;
	}
	return 0;
}