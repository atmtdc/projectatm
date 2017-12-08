//cpp file cho giao dien cua chuong trinh gia lap ATM
#include<iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <stdexcept>								//cho ham lay password bao mat
#include <sstream>								    //string stream
#include "ATM.h"
#include "nguoidung.h"
#include "giaodien.h"

using namespace std;

extern nguoidung user;								//Bien toan cuc luu thong tin nguoi su dung, da khai bao o main.cpp
extern ATM atm;                                     //Bien toan cuc cho doi tuong ATM

//tra ve string thoi gian hien tai cua he thong
string thoigian()
{
    string current;
    time_t rawtime;
	time(&rawtime);
	current = ctime(&rawtime);
	//bo dau '\n' o cuoi xau ky tu
	current[current.size()-1] = '\0';
	return current;
}
//in header
void inheader1()
{
	cout << "NHOM I"
		<< setw(68) <<"(-_-)(-_-)(-_-) "
		 << endl;	 
}	 
void inheader2()
{
	cout << endl << " Khach hang: " << user.getname() << endl;
}
//in ra man hinh cho
void manhinhcho()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	//In noi dung trang
	//for(int i=0; i<10; i++)
	//	cout << endl;
	cout << endl << endl;
	cout << "          " << "-----------------------------$$-----------------------------" << endl
		 << "          " << "|--------------------------$$$$$$---------------------------|" << endl
		 << "          " << "||  *             *       $$$ $$ $$$     **************    ||" << endl
		 << "          " << "||  * *           *      $$$  $$  $$$    **************    ||" << endl
		 << "          " << "||  *   *         *      $$$  $$  $$          ***          ||" << endl
		 << "          " << "||  *     *       *         $$$$              ***          ||" << endl
		 << "          " << "||  *       *     *         $$$$              ***          ||" << endl
		 << "          " << "||  *         *   *          $$$$             ***          ||" << endl
		 << "          " << "||  *           * *       $$  $$ $$$          ***          ||" << endl
		 << "          " << "||  *             *      $$$  $$  $$$     *************    ||" << endl
		 << "          " << "||                        $$$ $$ $$$      *************    ||" << endl
		 << "          " << "|--------------------------$$$$$$---------------------------|" << endl
		 << "          " << "-----------------------------$$-----------------------------" << endl
		 << endl; 	
	cout << setw(47) << "NGAN HANG NHOM I" << endl
		 << setw(60) << "Chao mung quy khach den voi dich vu ATM"<<endl
		 << setw(55) << "<<<<<ENTER DE DANG NHAP>>>>>";
	fflush(stdin);												//dam bao ko bi lan lon du lieu nhap
	cin.get();
	Sleep(1000);
}
//dang nhap
void dangnhap()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	//dang nhap
	for(int i=0; i< 3; i++) cout << endl;
	cout << "  Dang nhap thong tin tai khoan" << endl
		 << endl << "   Nhap ma so tai khoan:";
	//can kiem tra cho nay xem dang nhap co dung hay ko
	string tempID;
	fflush(stdin);												//dam bao ko bi lan lon du lieu nhap
	cin >> tempID;
	user.setID(tempID);
	user.laythongtin();
	//neu nhap ID sai, ID sau khi lay thong tin se la 0
	//su dung dieu nay de kiem tra 
	if(tempID == user.getID() )
	{	
		//Ma so nhap hop le
		int i=0;
		bool check = true;
		while(i<3)
		{
			cout << endl << "   - Nhap mat khau:";
			string tempPass;
			tempPass = laypass();
			if(tempPass == user.getpass())
			{
				cout << endl << "   - Dang nhap thanh cong!" << endl;
				check = true;
				Sleep(1000);
				break;
			}
			else
			{
				cout << endl <<"    - Sai mat khau! Ban con " << 2-i << " lan dang nhap." << endl;
				i++;
				check = false;
			}
		}
		if(check == false)
		{
			//dang nhap 3 lan sai, khoa tai khoan:
			//Sua password thanh mot password random, muon lay tai khoan lien he ngan hang	
			cout << endl << "  Nhap mat khau 3 lan sai, dang nhap that bai" << endl
				 << endl << "  Mat khau cua ban da bi thay doi, lien he ngan hang de su dung lai!" << endl << endl; 
			string randtemp;
			randtemp = randompass();
			user.setpass(randtemp);
			user.ghidtbase();
			Sleep(4000);
		}
		else if(check == true)
		{
			if(user.getID() == "0000")menu2();
			
		}
	}
	else // Ma so nhap khong hop le
	{
		cout << endl << "  Ma so tai khoan khong hop le!" << endl;
		Sleep(1000);
	}
	
}
//lay password bao mat, ham lay tu cplusplus.com 
string laypass()
{
  string result;
  // Set the console mode to no-echo, not-line-buffered input
  DWORD mode, count;
  HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
  HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
  if (!GetConsoleMode( ih, &mode ))
    throw runtime_error(
      "getpassword: You must be connected to a console to use this program.\n"
      );
  SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  // Get the password string
  char c;
  while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
    {
    if (c == '\b')
      {
      if (result.length())
        {
        WriteConsoleA( oh, "\b \b", 3, &count, NULL );							//Xoa mot ky tu tren man hinh
        result.erase( result.end() -1 );
        }
      }
    else
      {
      WriteConsoleA( oh, "*", 1, &count, NULL );
      result.push_back( c );
      }
    }
  // Restore the console mode
  SetConsoleMode( ih, mode );
  return result;
}
//ham tao pass random
string randompass()
{
	srand(time(0));
	int temp = 0;
	int a =0;
	string temp1;
	for(int i=0;i<6;i++)
	{
		a = rand()%10;
		temp +=a;
		temp*=10;
	}
	temp/=10;
	stringstream convert;
	convert << temp;
	temp1 = convert.str();
	return temp1;
}
void tambiet()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	//In ra tam biet khac hang
	for(int i=0; i<10; i++)
		cout << endl;
	string str = "Tam biet " + user.getname();
	cout << setw(37 + str.size()/2) << str << endl
		 << setw(52) << "Chuc quy khach mot ngay vui ve";
	Sleep(1500);
}
//Hoi xem co thuc hien giao dich tiep khong??
void yes_no()
{
    char c;
    cout << endl << "  Ban co muon thuc hien giao dich khac khong?"
    	 << endl << "  (Y/N):";
    fflush(stdin);
	cin >> c;
    if(toupper(c)=='N')
    {
        tambiet();               
    }
    else if(toupper(c) == 'Y')menu2();
    else menu2();
}
//Kiem tra nhap vao co phai so hay khong
bool isdigit(string test)
{
	for(int i=0;i<test.size();i++)
	{
		if(test[i] > '9' || test[i] < '0') return false;
	}
	return true;
}
//ham nhap so tien cho dich vu
int nhaptien()
{
	bool check = true;
	do
	{
		string test;
		cin >> test;
		check = isdigit(test);
		if(check)return atoi(test.c_str());
		else cout << endl << "  Xin hay nhap dung so tien! Nhap lai:";
	}while(check==false);
} 
//admin menu
void menu2()
{
	system("cls");
	inheader1();
	cout << endl << "  ADMIN menu" << endl;
	cout << endl << "  Chao ADMIN, ban muon lam gi?" << endl
		 << " Danh sach dich vu cung cap" << endl << endl
		 << "     1."  << "Rut tien                                   4.Doi mat khau" << endl << endl
		 << "     2."  << "Kiem tra so du tai khoan                   5.Chuyen khoan" << endl << endl
		 << "     3."  << "Nap Tien                                   6.Thoat" << endl << endl;
	
	cout << " Quy khach lua chon:";
	int choice = 0;
	fflush(stdin);
	cout << endl << "  Chon:";
	while(1)
	{
		cin >> choice;
		if(choice <= 6) break;
		else cout << " Lua chon khong hop le, xin chon lai:";
	}
	switch(choice)
	{
		case 1:
			//Rut tien
			atm.ruttien();
			yes_no();
			break;
		case 2:	
			//Kiem tra so du
			atm.kiemtrasodu();
			yes_no();
			break;
    	case 3:
			//Nap tien
			atm.naptien();
			yes_no();
			break;
		case 4:
			//Thay doi thong tin
			atm.doimk();
			yes_no();
			break;
		case 5:
			//Chuyen tien
			atm.chuyentien();
			yes_no();
			break;	
		case 6:
			//Thoat, ve man hinh cho
			tambiet();
			break;
		default:
			break;
	}
}
//admin yes_no
void adminyn()
{
    char c;
    cout << endl << "  Ban co muon tiep tuc?"
    	 << endl << "  (Y/N):";
    fflush(stdin);
	cin >> c;
    if(toupper(c)=='N')
    {
        system("cls");
		inheader1();
		for(int i=0; i<10; i++)cout << endl;
		cout << endl 
			 << setw(42) << "Bye!"; 
		Sleep(1500);	               
    }
    else if(toupper(c) == 'Y')menu2();
    else menu2();
}
//in hoa don
void hoadon(int dvu, int stien , string dtuong)
{
	cout << endl << "  Ban co muon in hoa don?" 
		 << endl << "  (Y/N)";
	char choice;
	fflush(stdin);
	cin >> choice;
	if(toupper(choice) == 'Y')
	{
		system("cls");
		inheader1();
		inheader2();
		cout << endl
			 << "                 ****  Hoa don  ****" << endl
			 << "            -------------------------------" << endl
			 << "                     Ngan hang T&V" << endl
			 << "            " << thoigian() << endl
			 << "            Khach hang: " << user.getname() << endl
	  		 << "            Ma so tai khoan: " << user.getID() << endl;
		switch(dvu)
		{
			case 1:
				//rut tien
				cout << "            Rut: " << stien << " Dong tu tai khoan" << endl
	  				 << "            -------------------------------" << endl;
	  			break;
			case 2:
				//ktra so du
				cout << "            Kiem tra so du tai khoan" << endl
				  	 << "            Tai khoan con: " << user.getbalance() << endl
	  		 		 << "            -------------------------------" << endl;
	  		 		 break;
			case 3:
				//nap tien
				cout << "            Nap: " << stien << " Dong vao tai khoan" << endl
	  		 		 << "            -------------------------------" << endl;
	  		 	break;
		
			case 4:
				//thay doi mat khau
				cout << "            Thay doi mat khau tai khoan" << endl
	  				 << "            -------------------------------" << endl;
				break;
			case 5:
				//chuyen tien
				cout << "            Chuyen: " << stien << " Dong cho tai khoan " << dtuong << endl
	  				 << "            -------------------------------" << endl;
				break;
			default:
				break;	
		}
	
	}
}					
	
