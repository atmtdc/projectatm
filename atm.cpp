//file .cpp lop ATM
#include <string>
#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "nguoidung.h"
#include "ATM.h"
#include "giaodien.h"
using namespace std;

//bien toan cuc luu du lieu khach hang dang su dung atm
extern nguoidung user;

//ham khoi tao mac dinh lop ATM
ATM::ATM()
{}
//ham ruttien
void ATM::ruttien()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	inheader2();
	cout << "  >>Rut tien" << endl;
	//Rut tien
    int du;
    int temp, rut;
    char buffer[33];
    user.laythongtin();					//Lay lai thong tin nguoi su dung
    //Nhap so tien muon rut cho den khi chinh xac(< so du tai khoan)
	string temp1;
    temp1 = user.getbalance();
    temp = atoi(temp1.c_str());
	do
    {
        cout << endl << "  Nhap so tien ban muon rut:";
		rut = nhaptien();
		if(rut > ATMmoney())
		{
			cout << endl << "  Rat tiec, so tien ban can rut nhieu hon so tien ATM co.";
		}
		else
		{
    		if(rut <= temp)
    		{
    			du = temp - rut;
    			itoa(du,buffer,10);
    			user.setbalance(buffer);
    			user.ghidtbase();
    			cout << "  Xin nhan tien o khe tra tien: "; 
				itoa(rut,buffer,10);
				int i=0;
				while(buffer[i]!='\0')
				{
					cout << buffer[i];
					i++;
					Sleep(150);
				}
				cout << " Dong";
    		} 
			else{cout << endl << "  So tien ban vua nhap lon hon so du!";}
		}
    } while(rut > temp  || rut > ATMmoney());
    //Thay doi so tien ATM
    changeATM(-1,rut);
	//Ghi vao nhat ky
    ofstream ofile("log.txt", ios::app);
    ofile << "-------------------------------" << endl
		  << thoigian() << endl
    	  << "Tai khoan " << user.getID()
    	  << " rut " << rut << " Dong khoi tai khoan." << endl
    	  << "So du sau khi rut:" << du << endl;
    ofile.close();
	//In hoa don
	hoadon(1,rut);
}
//Ham kiem tra so du
void ATM::kiemtrasodu()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	inheader2();
	cout << "  >>Kiem tra so du" << endl;
	user.laythongtin();					//lay lai thong tin nguoi su dung
    cout << endl << "  Quy khach co:" << user.getbalance() << " Dong" << endl;
    
	//Ghi vao nhat ky
    ofstream ofile("log.txt", ios::app);
    ofile << "-------------------------------" << endl
		  << thoigian() << endl
    	  << "Tai khoan " << user.getID()
    	  << " kiem tra so du tai khoan."<< endl
    	  << "So du khi kiem tra:" << user.getbalance() << endl;
    ofile.close();
    
	//In hoa don
    hoadon(2);
}
//Ham nap tien
void ATM::naptien()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	inheader2();
	cout << "  >>Nap tien" << endl;
    int nap;
    int temp, du;
    char buffer[33];
    user.laythongtin();					//Lay lai thong tin nguoi su dung		
	
	//Nap tien
    cout << endl << "  Dua so tien ban muon nap vao khe:";
    nap = nhaptien();
    string temp1;
    temp1 = user.getbalance();
    temp = atoi(temp1.c_str());
    du = temp + nap;
    itoa(du,buffer,10);
    user.setbalance(buffer);
    
	//ghi vao file dtbase
    user.ghidtbase();
	cout << endl << "  Ban vua nap " << nap << " Dong vao tai khoan";
    
	//thay doi so tien ATM
    changeATM(1,nap);
	
	//Ghi vao nhat ky
    ofstream ofile("log.txt", ios::app);
    ofile << "-------------------------------" << endl
		  << thoigian() << endl
    	  << "Tai khoan " << user.getID()
    	  << " nap " << nap << " Dong vao tai khoan." << endl
    	  << "So du sau khi nap:" << du << endl;
    ofile.close();	  
	
	//In hoa don
    hoadon(3,nap);
}
//doi mat khau
void ATM::doimk()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	inheader2();
	cout << "  >>Thay doi mat khau" << endl;
    //lay thong tin
	user.laythongtin();
    string tempPass;						//mat khau hien tai
    string tempPass1;						//mat khau moi lan 1
    string tempPass2;    					//mat khau moi lan 2
	
	//Nhap mat khau cu
	do
	{
		cout << endl << "  Mat khau cu:"; 	
        tempPass = laypass();
        if(tempPass != user.getpass())
        {
			cout << endl <<"  Sai mat khau, nhap lai!";
		}
	}while(tempPass != user.getpass()); 	//neu pass cu khong dung thi nhap lai
	cout << endl << endl << "  Hay nhap vao mat khau moi."
		 << endl << "  Mat khau: Yeu cau dai hon hoac bang 6 chu so";
	
	//Nhap mat khau moi lan 1	 
	do
	{
		cout << endl << "  Mat khau moi:";
		fflush(stdin);
   		tempPass1 = laypass();
   		if(tempPass1.size() <6)
		{
			cout << endl << "  Mat khau qua ngan!";
		}
	}while(tempPass1.size() <6);
	
	//Nhap mat khau moi lan 2
    cout << endl << "  Xac nhan:"; 	
    fflush(stdin);
	tempPass2 = laypass();
    if(tempPass1 == tempPass2)
    
	//Neu mat khau moi khop nhau thi thuc hien doi pass
    {
		//gia lap qua trinh xu ly
		cout << endl << "  Dang xu ly";
		for( int i = 0; i <5 ; i++)
		{
			cout << '.';
			Sleep(150);
		}
			
       	user.setpass(tempPass1);
       	user.ghidtbase();					//ghi de pass moi vao database
       	cout << endl << "  Doi mat khau thanh cong!"<<endl;
       	//Doi mat khau thanh cong, ghi vao nhat ky
       	ofstream ofile("log.txt", ios::app);
    	ofile << "-------------------------------" << endl
			  << thoigian() << endl
    		  << "Tai khoan " << user.getID()
    	  	  << " thay doi mat khau." << endl;
       	ofile.close();
    
		//In hoa don
    	hoadon(4);
	}
	else
	{
		cout << endl << "  Mat khau khong khop nhau. Huy thao tac." ;       
    }
}
//ham chuyen tien
void ATM::chuyentien()
{
	//Chuyen man hinh
	system("cls");
	inheader1();
	inheader2();
	cout << "  >>Chuyen tien" << endl;
	
	//so tien chuyen
	int chuyen; 
	
	//nguoi nhan tien
    nguoidung user1;
	cout << endl << "   Nhap ma so tai khoan nhan:";
	string tempID;
	fflush(stdin);												//dam bao ko bi lan lon du lieu nhap
	cin >> tempID;
	user1.setID(tempID);
	user1.laythongtin();
	
	//Kiem tra tai khoan chuyen sang co ton tai hay khong
	if(tempID == user1.getID() )
	{	
		//Ma so nhap hop le
		system("cls");
		inheader1();
		inheader2();
        int _balance, _balance1;
        char buffer[33], buffer1[33];
        user.laythongtin();
        string temp = user.getbalance();
        _balance = atoi(temp.c_str());
		do
    	{
        	cout << endl << "  Nhap so tien ban muon chuyen:";
			chuyen = nhaptien();
    		if(chuyen > _balance)
    			cout << endl <<"  So tien ban can chuyen lon hon so du";
    	} while(chuyen > _balance);
		
		//Xac nhan lai xem co muon chuyen tien hay khong
        cout << "  Ban co muon chuyen " << chuyen << " Dong den tai khoan cua " 
             << user1.getname() 
             << " hay khong?" << endl 
             << "  (Y/N):";
        bool check = true;
		char choice;
        fflush(stdin);
		cin >> choice;
		if(toupper(choice) == 'Y')check = true;
		else check = false;
	    
		if(check == true)//Xac nhan co chuyen tien, thuc hien chuyen tien
		{
			//lay so du user 1
          	temp = user1.getbalance();
           	_balance1 = atoi(temp.c_str());
           	
			//Thay doi so du cua 2 user
            _balance -= chuyen;
            _balance1 += chuyen;
            itoa(_balance,buffer,10);
           	user.setbalance(buffer);
            user.ghidtbase();		//sau khi chuyen khoan, ghi lai so du cho user
            itoa(_balance1,buffer1,10);
            user1.setbalance(buffer1);
            user1.ghidtbase();		//sau khi nhan tien, ghi lai so du user1
            
            //Gia lap qua trinh xu ly
            cout << endl << "  Dang chuyen tien";
			for(int i=0; i <5; i++)
			{
				cout << '.';
				Sleep(100);
			}
            cout << endl << "  Ban vua chuyen " << chuyen 
				 << " Dong cho tai khoan " << user1.getID();
			
			//co chuyen tien, ghi vao nhat ky	 
			ofstream ofile("log.txt", ios::app);
    		ofile << "-------------------------------" << endl
				  << thoigian() << endl
    		 	  << "Tai khoan " << user.getID()
    	  	  	  << " chuyen " << chuyen << " Dong cho tai khoan " << user1.getID() << endl
    	  	 	  << "So du sau khi chuyen:" << _balance << endl;
 			ofile.close();
 			
			 //In hoa don
    		hoadon(5,chuyen,user1.getID());
		}
    	else //Khong muon chuyen tien, thoat
        {
                cout << endl << "  Da huy giao dich chuyen tien.";
                Sleep(1000); 
        }
         	  
	}else{ 
           cout << endl << "  Ma so tai khoan nhan khong ton tai! " << endl;
           Sleep(1000);}
}

//Kiem tra tien ATM
int ATM::ATMmoney()
{
	string temp;
	int money;
	ifstream ifile("budget.txt");
	ifile >> temp;
	money = atoi(temp.c_str());
	ifile.close();
	return money;
}

//thay doi tien ATM, unit = 1 khi cong them, -1 khi tru di
void ATM::changeATM(int unit, int change)
{
	int money;
	money = ATMmoney();
	int newmoney;
	newmoney = money + unit*change;
	ofstream ofile("Budget.txt");
	ofile << newmoney;
	ofile.close();
}

//admin nap tien ATM
void ATM::ATMnap()
{
	system("cls");
	inheader1();
	cout << endl << "  ADMIN" << endl
		 << endl << "  Nhap so tien muon nap:";
	int napATM;
	fflush(stdin);
	cin >> napATM;
	changeATM(1,napATM);
	cout << endl << "  Nhap thanh cong " << napATM 
		<< " Dong cho ATM." << endl;
	//Ghi naht ky
	ofstream ofile("log.txt", ios::app);
    ofile << "-------------------------------" << endl
		  << thoigian() << endl
   		  << "ADMIN nap " << napATM 
    	  << " Dong cho ATM" << endl;
 	ofile.close();	
}	 

//admin kiem tra ATM
void ATM::ATMktra()
{
	system("cls");
	inheader1();
	cout << endl << "  ADMIN" << endl;
	cout << "  >>Kiem tra ATM" << endl << endl
		 << "  Hien ATM con:" << ATMmoney()
		 << " Dong" << endl;
	//Ghi nhat ky
	ofstream ofile("log.txt", ios::app);
    ofile << "-------------------------------" << endl
		  << thoigian() << endl
   		  << "ADMIN kiem tra so tien trong ATM"
    	  << endl;
 	ofile.close();
}	 	 	






