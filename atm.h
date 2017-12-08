//file .h cho lop ATM

using namespace std;

#ifndef ATM_H
#define ATM_H

class ATM
{
   public :
        //ham khoi tao mac dinh cho lop ATM
        ATM();
        //rut tien
        void ruttien();
        //kiem tra so du
        void kiemtrasodu();
        //naptien
		void naptien();
		//doi mk
        void doimk();
        //chuyen tien
        void chuyentien();
        
        //admin
        //tra lai tien ATM
        int ATMmoney();
        //Thay doi tien ATM
        void changeATM(int, int);
        //admin nap tien cho ATM
        void ATMnap();
        //admin ktra so tien cua ATM
        void ATMktra();             
};


#endif // ATM_H
