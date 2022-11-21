#include<iostream> 
#include<stdio.h>
#include<conio.h>
#include<string.h> 
#include<math.h>

using namespace std;
// XAY DUNG STRUCT
struct hotel{
	string hoTen, gioiTinh, diachi;
	int  maKH, namSinh, sophong, gioBatDau, gioKetThuc;
	char sdt[10];
	int tongTien;
};
// NODE
struct node{
	hotel data;
	node *next;
};
void init(node *&head){ //khoi tao 1 dslk
	head=NULL;
}
node* createNode(hotel x){ //tao node
	node *p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
node *addFirst(node *&head, hotel x){
	node *p= createNode(x);
	if(head==NULL)
		head=p;
	else{
	p->next=head;
	head=p;
	}
}
// NHAP THONG TIN KHACH HANG
void NhapKH(hotel h, int n, node *&head){
		node *p=head;
		int dem=0, dem1;
	    for(int i = 0; i < n; i++){
	        cout<<"\n	*	Khach hang thu  "<<i+1<<"	*"<<endl;
	        cout<<"\n	Nhap so phong: ";
	        cin>>h.sophong;
	        if (h.sophong > 0){
	        cout<<"\n	Nhap cccd/cmnd cua khach hang: ";
	        cin>>h.maKH; 
	    }
	        else
	        cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
	        if (h.maKH<0){
	        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
	   		}
	        else{
	        	if(h.maKH>0){
		    		dem1=0;
				for(node*p=head;p!=NULL;p=p->next){
					if(p->data.maKH==h.maKH){
		        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
		        	dem1=1;
		    		}
		    	}
		    	if(dem1!=1){
			        fflush(stdin);
			        cout<<"\n	Nhap ho va ten:	";
			        getline(cin,h.hoTen);
					cout<<"\n	Nhap gioi tinh (nam / nu): ";
			        getline(cin,h.gioiTinh);
			   		}
			   		cout<<"\n	Nhap nam sinh: ";
			        cin>>h.namSinh;
			        if(h.namSinh<=0)
			        cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
					while(h.gioiTinh=="Nam" || h.gioiTinh=="Nu"){
						cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
						cout<<"\n	Nhap gioi tinh:		";
						fflush(stdin);
			       		getline(cin,h.gioiTinh);
					}
				        fflush(stdin);
				        cout<<"\n	Nhap dia chi: ";
				        getline(cin,h.diachi);
				        fflush(stdin);
				        cout<<"\n	Nhap so dien thoai: ";
				        cin>>h.sdt;
				        cout<<"\n	Nhap gio bat dau: ";
				        fflush(stdin);
						cin>>h.gioBatDau;
						if(h.namSinh<=0)
				        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
				        	else{
					        fflush(stdin);
							dem=dem+1;
					        cout<<"\n	DA NHAP THANH CONG "<<dem<<" KHACH HANG"<<endl;
					  		cout<<"--------------------------------------------------------------------------------------"<<endl;
					  		addFirst(head, h);
					  		cout<<"\n Press any key to continue.....!!";
							getch();
					  		}
						}
	 				}
	  			}
}
// HAM IN THONG TIN KHACH HANG
void printfhotel(hotel e){
	system("cls");
	cout<<"\t\t\tDANH SACH KHACH HANG"<<endl;
	cout<<"\t****************************"<<endl;
	cout<<"So Phong:\t\t"<<e.sophong<<endl;
	cout<<"CCCD/CMND:\t\t"<<e.maKH<<endl;
	cout<<"Ho Ten:\t\t\t"<<e.hoTen<<endl;
	cout<<"Gioi Tinh:\t\t"<<e.gioiTinh<<endl;
	cout<<"Nam Sinh:\t\t"<<e.namSinh<<endl;
	cout<<"Dia Chi:\t\t"<<e.diachi<<endl;
	cout<<"So Dien Thoai:\t\t"<<e.sdt<<endl;
	cout<<"Gio Bat Dau:\t\t"<<e.gioBatDau<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"\n Press any key to continue.....!!"<<endl;
	getch();
}

void printf(node*head){
	node *p = head;
	while(p != NULL){
		printfhotel(p->data);
		p = p->next;
	}
}
// HAM TIM KIEM THONG TIN KHACH HANG (MA KH, SO PHONG, TEN)
node *searchMaKH(node *head, int makh){
	node *kq;
	init(kq);
	node *p=head;
	while(p!=NULL){
		if(p->data.maKH==makh)
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}
node *searchSoPhong(node *head, int soPhong){
	node *kq;
	init(kq);
	node *p=head;
	while(p!=NULL){
		if(p->data.sophong==soPhong)
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}
node *searchTen(node *head, string ten){
	node *kq;
	init(kq);
	node *p=head;
	string tolower(p->data.hoTen);
	while(p!=NULL){
		if(p->data.hoTen.find(ten) != string::npos)
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}

// MENU
void menu(){
		system("cls");
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\t\t\t\t    HOTEL MANAGEMENT ";
		cout<<"\n\t\t\t\t      * MAIN MENU *";
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\n\n\t\t\t1.DAT PHONG";
		cout<<"\n\t\t\t2.DANH SACH KHACH HANG";
		cout<<"\n\t\t\t3.TIM KHACH HANG THEO YEU CAU";
		cout<<"\n\t\t\t4.HOA DON PHONG";
		cout<<"\n\t\t\t5.THOAT";
}
void menu1(){
	cout<<"\t1.	Tim khach hang theo ten "<<endl;
	cout<<"\t2.	Tim khach hang theo cccd/cmnd"<<endl;
}
// HAM MAIN
int main(){
	node *head;
	init(head);
	hotel h;
	int option;
	
	while(1){
		do{
			cout<<"\n\n";
			menu();
			cout<<"\n			NHAP LUA CHON:	";
			cin>>option;
			
		}while(option <= 0);	
			
		switch(option){
			
			// NHAP THONG TIN KHACH HANG
			case 1:{
				system("cls");
				int n;
				cout<<"\n\t\t	THEM N KHACH HANG\n"<<endl;
				cout<<"\n	Moi nhap so khach hang muon dat phong:		";
				cin>>n;
				createNode(h);
				NhapKH(h, n, head);
				break;
			}
			
			// DANH SACH KHACH HANG
			case 2:{
				system("cls");
				cout<<"\n________________________DANH SACH KHACH HANG________________________"<<endl;
				printf(head);
				if(head==NULL)
					cout<<"\n		  	  DANH SACH RONG"<<endl;
					cout<<"\n Press any key to continue.....!!";
					getch();
				break;
			}
			
			// TIM KHACH HANG THEO YEU CAU
			case 3:{
				system("cls");
				int option1;
				cout<<"\n\n";
				cout<<"\n\t\t	TIM KHACH HANG THEO YEU CAU\n"<<endl;
				menu1();
				cout<<"\n	NHAP LUA CHON:	";
				cin>>option1;
				if (head == NULL)
					cout<<"\n	*	DANH SACH DANG RONG 	*"<<endl;
				else{
					switch(option1){
						
						// TIM KHACH HANG THEO TEN
						case 1:{
							string timTen;
							cin.ignore();
							cout<<"\n	NHAP TEN CAN TIM: 	";
							cout<<"	";
							cin>>timTen;
							node *kqTen=searchTen(head,timTen);
							printf(kqTen);
							if (kqTen == NULL)
								cout<<"\n	KHONG TIM THAY KHACH HANG"<<endl;
							break;
						}
						
						// TIM KHACH HANG THEO CMND/CCCD
						case 2:{
							int timMaKH;
							cin.ignore();
								cout<<"\n	NHAP CCCD/CMND CUA KHACH HANG:	";
								cout<<"	";
								cin>>timMaKH;
								node *kqMaKH=searchMaKH(head,timMaKH);
								printf(kqMaKH);
								if (kqMaKH == NULL)
									cout<<"\n	KHONG TIM THAY KHACH HANG"<<endl;
								
								break;
						}
					}
				}
				break;
			}
			
			
			// THANH TOAN PHONG
			case 4:{
				int timSoPhong;
				cin.ignore();
				cout<<"\n	NHAP SO PHONG CAN THANH TOAN:	"<<endl;
				cout<<"	";
				cin>>timSoPhong;
				node *kqSoPhong=searchSoPhong(head,timSoPhong);
				printf(kqSoPhong);
				if (kqSoPhong == NULL)
				cout<<"\n	KHONG TIM THAY PHONG"<<endl;
				cout<<"Nhap gio bat dau: ";
				cin>>h.gioBatDau;
				cout<<"Nhap gio ket thuc: ";
				cin>>h.gioKetThuc;
				int soGio = h.gioKetThuc - h.gioBatDau;
				h.tongTien = soGio * 70000;
				cout<<"So tien can thanh toan: "<<h.tongTien<<" dong"<<endl;
				cout<<"Press any key to continue.....!!";
				getch();
				break;
			}
			
			// EXIT
			case 5:{
				return 0;
				break;
			}
			
			
			default:{
				system("cls");
				cout<<"\n\n\t\t\tLUA CHON KHONG HOP LE. VUI LONG LUA CHON LAI!!!";
				cout<<"\n\t\t\tPress any key to continue....!!";
				getch();
			}
		}
	}
}	
