
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(int& number);
	bool read(char postal[]);

}
#endif // !SDDS_FILE_H_