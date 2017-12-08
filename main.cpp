/*
  Name:NHOM I(HĐT)
  Copyright: TDC
  Author: 
  MAI VAN PHAT
  PHAM MINH HIEN
  HA MINH QUAN
  TRAN LE HOANG PHONG
  NGUYEN CHINH TRUC
  Date: 1/12/2017 
  Description: Chuong trinh gia lap ATM
*/
#include <windows.h> 
#include <cstdlib>
#include <iostream>
#include "giaodien.h"
using namespace std;
//bien toan cuc luu du lieu nguoi dang su dung atm
nguoidung user;
//bien toan cuc, ATM
ATM atm;										

int main(int argc, char *argv[])
{
	//Vong lap vo han de luon san sang su dung dich vu
	while(true)
	{
		manhinhcho();
		dangnhap();
		cin.get();
		user = nguoidung();						//Xoa toan bo du lieu sau khi su dung
	}
    cin.get();
}
