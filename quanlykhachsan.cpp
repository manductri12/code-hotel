#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//XAY DUNG CLASS

class hotel {
		int room_no;
		char id[20];
		char name[20];
		char sex[5];
		char address[50];
		char phone[10];

	public:

		void main_menu();		//MENU
		void add();				//DAT PHONG
		void display(); 		//DANH SACH KHACH HANG
		void rooms();			//DANH SACH PHONG DA DAT
		void edit();			//CHINH SUA BAN GHI
		int check(int);			//TINH TRANG PHONG
		void modify(int);		//SUA DOI BAN GHI
		void delete_rec(int);	//XOA BAN GHI
		void bill(int);         //HOA DON
};

//MENU

void hotel::main_menu() {

	int choice;
	while(choice!=5) {

		system("cls");
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\t\t\t\t    HOTEL MANAGEMENT ";
		cout<<"\n\t\t\t\t      * MAIN MENU *";
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\n\n\t\t\t1.DAT PHONG";
		cout<<"\n\t\t\t2.DANH SACH KHACH HANG";
		cout<<"\n\t\t\t3.DANH SACH PHONG";
		cout<<"\n\t\t\t4.CHINH SUA BAN GHI";
		cout<<"\n\t\t\t5.THOAT";
		cout<<"\n\n\t\t\tNHAP LUA CHON: ";
		cin>>choice;

		switch(choice) {

			case 1:
				add();
				break;

			case 2:
				display();
				break;

			case 3:
				rooms();
				break;

			case 4:
				edit();
				break;

			case 5:
				break;

			default: {

				cout<<"\n\n\t\t\tLUA CHON KHONG HOP LE.....!!!";
				cout<<"\n\t\t\tPress any key to   continue....!!";
				getch();
			}

		}

	}

}

//HAM DAT PHONG
void hotel::add() {

	system("cls");
	int r,flag;
	ofstream fout("Record.dat",ios::app);
	cout<<"\n SO PHONG";
	cout<<"\n ----------------------";
	cout<<"\n Tong so phong - 50";
	cout<<"\n Phong thuong 1 - 30";
	cout<<"\n Phong hang sang 31 - 45";
	cout<<"\n Phong vip 46 - 50";
	cout<<"\n\n Phong so: ";
	cin>>r;

	flag=check(r);

	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";

	else {

		room_no=r;
		cout<<" ID: ";
		cin>>id;
		cout<<" Name: ";
		cin>>name;
		cout<<" Sex: ";
		cin>>sex;
		cout<<" Address: ";
		cin>>address;
		cout<<" Phone No: ";
		cin>>phone;

		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Room is booked...!!!";

	}

	cout<<"\n Press any key to continue.....!!";

	getch();
	fout.close();

}

//HAM CAI DAT DANH SACH KHACH HANG
void hotel::display() {

	system("cls");

	ifstream fin("Record.dat",ios::in);
	int r,flag;

	cout<<"\n NHAP PHONG MA BAN MUON BIET THONG TIN CU THE :- "<<endl;
	cin>>r;

	while(!fin.eof()) {

		fin.read((char*)this,sizeof(hotel));
		if(room_no==r) {

			system("cls");
			cout<<"\n THONG TIN KHACH HANG";
			cout<<"\n ----------------";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n ID: "<<id;
			cout<<"\n Name: "<<name;
			cout<<"\n Sex: "<<sex;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			flag=1;
			break;

		}

	}

	if(flag==0)
		cout<<"\n Xin loi phong nay bo trong hoac khong tim thay....!!";
	cout<<"\n\n Press any key to continue....!!";

	getch();
	fin.close();
}

//HAM CAI DAT DANH SACH PHONG
void hotel::rooms() {

	system("cls");

	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t        DANH SACH PHONG";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n Room No.\tID\t\t\tName\t\t\tSex\t\tAddress\t\t\tPhone No.\n";

	while(!fin.eof()) {

		fin.read((char*)this,sizeof(hotel));
		cout<<"\n\n "<<room_no<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<sex<<"\t\t"<<address<<"\t\t\t"<<phone;
	}

	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();

}

//HAM CHING SUA BAN GHI VA XUAT HOA DON
void hotel::edit() {

	system("cls");

	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.CHINH SUA HO SO KHACH HANG";
	cout<<"\n 2.XOA BAN GHI";
	cout<<"\n 3.XUAT HOA DON";
	cout<<"\n NHAP LUA CHON: ";

	cin>>choice;
	system("cls");

	cout<<"\n NHAP SO PHONG: " ;
	cin>>r;

	switch(choice) {

		case 1:
			modify(r);
			break;

		case 2:
			delete_rec(r);
			break;

		case 3:
			bill(r);
			break;

		default:
			cout<<"\n LUA CHON KHONG HOP LE.....!!";

	}
	cout<<"\n Press any key to continue....!!!";

	getch();
}


int hotel::check(int r) {

	int flag=0;

	ifstream fin("Record.dat",ios::in);

	while(!fin.eof()) {

		fin.read((char*)this,sizeof(hotel));
		if(room_no==r) {

			flag=1;
			break;

		}

	}

	fin.close();
	return(flag);

}

//HAM CHINH SUA HO SO KHACH HANG


void hotel::modify(int r) {

	long pos,flag=0;

	fstream file("Record.dat",ios::in|ios::out|ios::binary);

	while(!file.eof()) {

		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));

		if(room_no==r) {

			cout<<"\n THONG TIN KHACH HANG MOI";
			cout<<"\n -----------------";
			cout<<"\n ID:";
			cin>>id;
			cout<<"\n Name: ";
			cin>>name;
			cout<<"\n Sex: ";
			cin>>sex;
			cout<<" Address: ";
			cin>>address;
			cout<<" Phone no: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n BAN GHI DA DUOC CHINH SUA....!!";
			flag=1;
			break;

		}

	}

	if(flag==0)
		cout<<"\n Xin loi phong nay bo trong hoac khong tim thay...!!";
	file.close();

}

//HAM XOA BAN GHI
void hotel::delete_rec(int r) {

	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);

	while(!fin.eof()) {

		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)

		{
			cout<<"\n ID: "<<id;
			cout<<"\n Name: "<<name;
			cout<<"\n Sex: "<<sex;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone No: "<<phone;
			cout<<"\n\n BAN CO MUON XOA BAN GHI NAY KHONG?(y/n): ";
			cin>>ch;

			if(ch=='n')
				fout.write((char*)this,sizeof(hotel));
			flag=1;

		}

		else
			fout.write((char*)this,sizeof(hotel));

	}

	fin.close();
	fout.close();

	if(flag==0)
		cout<<"\n Xin loi phong nay bo trong hoac khong tim thay...!!";

	else {

		remove("Record.dat");
		rename("temp.dat","Record.dat");

	}

}

//HAM XUAT HOA DON
void hotel::bill(int r) {

	hotel h1;
	ifstream f1;
	f1.open("record.dat",ios::in|ios::binary);

	if(!f1)
		cout<<"cannot open";

	else {

		f1.read((char*)&h1,sizeof (hotel));
		while(f1)

		{

			f1.read((char*)&h1,sizeof(hotel));

		}

		if (h1.room_no == r) {

			if(h1.room_no>=1&&h1.room_no<=30)
				cout<<"your bill = 2000";

			else if (h1.room_no>=35&&h1.room_no<=45)
				cout<<"your bill = 5000" ;

			else
				cout<<"your bill = 7000";

		}

		else {
			cout<<"KHONG TIM THAY SO PHONG";
		}

	}

	f1.close();
	getch();

}

//HAM MAIN
int main() {

	hotel h;

	system("cls");
	h.main_menu();
	return 0;
}