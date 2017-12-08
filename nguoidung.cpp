#include "nguoidung.h"
#include <string>
#include <fstream>
#include <vector>
//ham khoi tao mac dinh
nguoidung::nguoidung()
: ID("-1"), name("UNKNOWN"), password("UNKNOWN"), balance("-1")
{}
		
//Lay thong tin tu database
void nguoidung::laythongtin()
{
	ifstream file("database.txt");
	string temp;
	while(!file.eof())
	{
		getline(file,temp);
		if(temp == ID)break;
	}
	if(!file.eof())
	{
		//lay name
		getline(file, temp);						//line 3
		getline(file, temp);						//line 4
		name = temp;
		//lay pass
		getline(file, temp);						//line 5	
		getline(file, temp);						//line 6
		password = temp;
		//lay balance
		getline(file, temp);						//line 7
		getline(file, temp);						//line 8 
		balance = temp;
	}
	else
	{
		ID = "0";
		name = "UNKNOWN";
		password = "UNKNOWN";
		balance = "0";
	} 
	//Da lay xong du lieu, dong file
	file.close();
}

//Ham Ghi thong tin nguoi dung vao file database
void nguoidung::ghidtbase()
{
	ifstream ifile("database.txt");
	//Doc file vao vector buffer
	vector<string> buffer;
	string temp;
	while(!ifile.eof())
	{
		getline(ifile, temp);
		buffer.push_back(temp);
	}
	ifile.close();
	//ghi user vao buffer
	int i = 0;
	for(i = 0; i < buffer.size(); i++)
	{
		if( buffer[i] == ID)break;
	}
	//Thay the thong tin user(da thay doi vao buffer)
	buffer[i+0] = ID;
	buffer[i+2] = name;
	buffer[i+4] = password;
	buffer[i+6] = balance;
	//ghi buffer vao file
	ofstream ofile("database.txt");
	for(int j = 0; j < buffer.size(); j++ )
	{
		ofile << buffer[j] 
			  << endl;
	}
	ofile.close();
}

