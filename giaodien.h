//File .h cho giao dien cua chuong trinh gia lap ATM
#include<string>
#include "ATM.h"
#include "nguoidung.h"

#ifndef GIAODIEN_H
#define GIAODIEN_H

//tra ve string thoi gian hien tai cua he thong
string thoigian();

//in header1 = thoigin hien tai + thong tin 
void inheader1();

//in header2 = ten khach hang
void inheader2();

//in ra man hinh cho
void manhinhcho();

//dang nhap thong tin 
void dangnhap();

//lay password bao mat
string laypass();

//ham tao password random gom 6 chu so
string randompass();

//menu1: cac dich vu co ban
void menu1();

//tambiet, ve man hinh cho
void tambiet();

//hoi xem co thuc hien giao dich nua khong??
void yes_no();

//Ham kiem tra xem tien nhap vao co phai so hay khong
bool isdigit(string);

//Ham nhap tien cho dich vu
int nhaptien();

//admin menu
void menu2();

//admin yes-no
void adminyn();

//in hoa don
//dvu: hoa don cho dich vu(1-5), stien: so tien, dtuong: doi tuong(chuyen tien)
void hoadon(int dvu, int stien =0, string dtuong = "UNDEFINED");
 
#endif // GIAODIEN_H
