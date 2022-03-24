/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
//#include<vector>

#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
vector<string> v;

	//trys to open filename, and return its contents in contents
	//it will strip out only \n's (char return\line feed)
	//returns:
	//SUCCESS all worked, contents string contains all in the file
	//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream openFile;
	openFile.open(filename.c_str());

	if(!openFile.is_open())
	  {
	    return COULD_NOT_OPEN_FILE_TO_READ;
	  }

		while(!openFile.eof()){
			string line;
			getline(openFile, line);
			contents += line;
		}

		openFile.close();

	return SUCCESS;

}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputfile;
	outputfile.open(filename.c_str());

	if (!outputfile.is_open())
	{
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	for (v = myEntryVector.begin(); v != myEntryVector.end(); v++)
	{
		outputfile << *v;
	}

	outputfile.close();

	return SUCCESS;


}


