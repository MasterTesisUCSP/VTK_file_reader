#include<iostream>
#include <string>
using namespace std;
#include "ReadUnstructuredGrid2.h"


int main(int argc, char* argv[]) {


	//DicomReader();
	string filename = argv[1];
	execute(filename);
	exportMNOdes(filename);
	
	return 1;

}
