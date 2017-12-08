//file .h, lop nguoi dung
#include <string>

using namespace std;

#ifndef NGUOIDUNG_H
#define NGUOIDUNG_H

//thong tin nguoi su dung
class nguoidung{
	private:
		string ID;					//so tai khoan
		string name;				//ten
		string password;			//matkhau
		string balance;				//so du tai khoan
	public:
		nguoidung();
		//cac ham cai dat, lay du lieu nguoi dung
		inline void setID(string id){ID=id;}
		inline void	setname(string str){name = str;}
		inline void setpass(string pas){password = pas;}
		inline void setbalance(string bal){balance = bal;}
		inline string getID(){return ID;}
		inline string getname(){return name;}
		inline string getpass(){return password;}
		inline string getbalance(){return balance;}
		//ham truy cap den data base, lay thong tin user theo ID da nhap
		//Sau khi chay, thong tin user tu file -> chuong trinh theo ID, ke ca ID
		void laythongtin();
        //ghi thong tin user vao file	
        void ghidtbase();
};
#endif // NGUOIDUNG_H
