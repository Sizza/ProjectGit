#ifndef _TextureReader_h
#define _TextureReader_h
////////////////////////

//#include "stdafx.h"
#include "Matrix.h"
#include <sstream> // stringstream
#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <istream>
#include <algorithm>
#include <vector>

void TextureReader(char* filename, int rows, int columns)
{
	//use constructor to create object of this class to call readtxt function
}

//Read TXT file in
double* readTXT(char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i>sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			// cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	//cout << i;

	return data;
}




/////////////////
#endif