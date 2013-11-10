#include <iostream>
#include <fstream>
using namespace std;

class File_Type {
public:
	void doit() {
	}
//private:
	fstream fs;
};

int main (void) {
	File_Type l_file;
	l_file.fs.open ("example2.txt",ios_base::out);
	l_file.fs << "Writing this to a file" << endl;
	l_file.fs.close();
;
	return 0;
}
