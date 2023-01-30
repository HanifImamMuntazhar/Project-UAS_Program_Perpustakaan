// Programmed by Hanif Imam Muntazhar
// Jurusan Teknik Informatika
// Universitas Muhammadiyah Sukabumi
// Matakuliah Dasar Pemrograman


#include <iostream>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct buku
{
	int kodeB,sewa,stock;
	char judul[20];
	int b;
}buku[100];
struct pinjam
{
	int kodepinjam,d,kB,tglpin,tglbalik,dipinjem;
	char namap[40];
	char alamat[40];
	char status;
}pinjembuku[100];

void program_perpustakaan(){
	system("cls");

	int jmlbuk,a,c,e,f,g,h,jmlpin,hs,lp,kodepin,stok;
	int b =-1;
	int d =-1;
	char yn,ch,temp;


	login:
	string user = "";
	string pass = "";
	for (int i = 1; i <= 5; ++i)
    cout << "\n";
	cout << setw(75) << "*========= PERPUSTAKAAN UMMI =========*" << endl;
	for (int i = 1; i <= 2; ++i)
    cout << "\n";
	cout << setw(60) << " Username : "; cin>>user;
	cout << setw(60) << " Password : ";
	ch = _getch();
    while(ch != 13){
    pass.push_back(ch);
    cout << '*';
    ch = _getch();
    }
    cout<<endl;
	if(user == "Hanif" && pass == "007"){
        cout << endl;
		cout << setw(72) << "Selamat anda berhasil login. " << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	}else{
	    cout << endl;
		cout << setw(72) << "Maaf password anda salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}


	mulaimenu:
	int pilihan;
	for (int i = 1; i <= 5; ++i)
    cout << "\n";
	cout << setw(75) << "***** Program Perpustakaan UMMI ***** " << endl;
	cout << endl;
    cout << setw(70) << "-------- Menu ----------\n";
    cout << setw(70) << "|| 1. Input Buku      ||\n";
    cout << setw(70) << "|| 2. Daftar Buku     ||\n";
    cout << setw(70) << "|| 3. Peminjaman      ||\n";
    cout << setw(70) << "|| 4. Pengembalian    ||\n";
    cout << setw(70) << "|| 5. Laporan         ||\n";
    cout << setw(70) << "|| 6. Exit            ||\n";
    cout << setw(70) << "-----------------------\n";
    cout << endl;
    cout << setw(75) << "Masukan Pilihan anda[ 1 s.d. 6 ] = " ; cin >> pilihan;

	if(pilihan ==1){
		inbuk:
		system("cls");
		for (int i = 1; i <= 3; ++i)
        cout << "\n";
        cout << setw(70) << "=================" << endl;
		cout << setw(70)<< "|  Input Buku : |"  << endl;
		cout << setw(70) << "=================" << endl;
		cout << endl;
		b++;
			cout << setw(70) << " Masukan data buku Ke\t: " << b+1 << endl;
			cout << setw(62) << " Kode Buku  \t\t: ";scanf("%d%c", &buku[b].kodeB, &temp);
			cout << setw(62) << " judul Buku \t\t: ";gets(buku[b].judul);
			cout << setw(62) << " Harga Sewa \t\t: ";scanf("%d%c", &buku[b].sewa, &temp);
			cout << setw(62) << " Jumlah Buku\t\t: ";scanf("%d%c", &buku[b].stock, &temp);
			cout << endl;
			cout << setw(85) << "Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :"; cin >> yn;
			if(yn=='y'||yn=='Y'){
				goto inbuk;
			}else{
			    for (int i = 1; i <= 2; ++i)
                cout << "\n";
				cout << setw(70) << "Data Berhasil Disimpan" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}

	}else if( pilihan == 2 ){
		system("cls");
		for (int i = 1; i <= 3; ++i)
        cout << "\n";
		cout << setw(60) <<"Daftar Buku"<< endl;
		cout << setw(60) <<"==========="<< endl;
		cout << endl;
		cout<<"---------------------------------------------------------------------------------------------\n";
		cout<<" No  Kode Buku           Judul Buku             Harga Sewa      Jumlah Buku     Buku Keluar \n";
		cout<<"---------------------------------------------------------------------------------------------\n";
		for(c=0;c<=b;c++){
			stok = buku[c].stock-pinjembuku[c].dipinjem;
			cout<<setw(2)<<c+1<<setw(8)<<buku[c].kodeB<<setw(30)<<buku[c].judul<<setw(15)<<buku[c].sewa<<setw(17)<<stok<<setw(15)<<pinjembuku[c].dipinjem;
			cout<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
		goto mulaimenu;

	}else if(pilihan == 3){
		transaksipinjem:
			d++;
			system("cls");
			for (int i = 1; i <= 3; ++i)
            cout << "\n";
            cout << setw(70) << "==========================" << endl;
			cout << setw(70) << "| Transaksi Peminjaman : |" << endl;
			cout << setw(70) << "==========================" << endl;
			cout << endl;
				cout << setw(70) << " Masukan data Pinjaman Ke \t: " << d+1 << endl;
				cout << setw(60) << " Kode Pinjaman \t\t: ";scanf("%d%c", &pinjembuku[d].kodepinjam, &temp);
				cout << setw(57) << " Kode Buku \t\t\t: ";scanf("%d%c", &pinjembuku[d].kB, &temp);
				cout << setw(64) << " Nama Penyewa Buku \t\t: ";gets(pinjembuku[d].namap);
				cout << setw(61) << " Alamat Penyewa \t\t: ";gets(pinjembuku[d].alamat);
				cout << setw(70) << " Tanggal Pinjam (DDMMYYYY)\t: ";scanf("%d%c", &pinjembuku[d].tglpin, &temp);
				cout << setw(69) << " Tanggal Balik (DDMMYYYY)\t: ";scanf("%d%c", &pinjembuku[d].tglbalik, &temp);
				lp = (pinjembuku[d].tglbalik-pinjembuku[d].tglpin)/1000000;
				cout << setw(60) << " Lama Pinjaman \t\t: " << lp << " Hari" << endl;
				cout << setw(73) << " banyak buku yang di pinjam  \t: ";scanf("%d%c", &pinjembuku[d].dipinjem, &temp);
				hs = pinjembuku[d].dipinjem*buku[d].sewa;
				cout << setw(58) << " Harga Sewa \t\t\t: " << hs;
				cout << endl;
				cout << setw(67) << " Status dipinjam (y) ? \t: "; cin >> pinjembuku[d].status;
				cout << endl;
                cout << setw(85) << "Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) \t:"; cin >> yn;

			if(yn=='y'||yn=='Y'){
				goto transaksipinjem;
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}

	}else if(pilihan == 4){
		system("cls");
		pengembalian:
			cout<<"\n"<<endl;
			cout<<"\t\t\tMasukan kode Peminjaman :";cin>>kodepin; //memasukan kode peminjaman
			cout<<"\t\t\t____________________\n"<<endl;
			cout<<endl;
			for(f=0;f<=d;f++){
				if(pinjembuku[f].kodepinjam==kodepin){
					cout<<" Nama Penyewa Buku \t\t:"<<pinjembuku[f].namap;
					cout<<endl;
					cout<<" Alamat Penyewa \t\t:"<<pinjembuku[f].alamat;
					cout<<endl;
					if(buku[f].kodeB==pinjembuku[f].kB){
						cout<<" Judul Buku \t\t\t:"<<buku[f].judul<<endl;
					}
					cout<<" Tanggal Pinjam (DDMMYYYY)\t:"<<pinjembuku[f].tglpin;
					cout<<endl;
					cout<<" Tanggal Balik (DDMMYYYY)\t:"<<pinjembuku[f].tglbalik;
					cout<<endl;
					lp = (pinjembuku[f].tglbalik-pinjembuku[f].tglpin)/1000000;
					cout<<" Lama Pinjaman \t\t\t:"<<lp<<" Hari"<<endl;
					cout<<endl;
					cout<<" banyak buku yang di pinjam  \t:"<<pinjembuku[f].dipinjem;
					cout<<endl;
					hs = pinjembuku[f].dipinjem*buku[f].sewa;
					cout<<" Harga Sewa \t\t\t:"<<hs<<endl;
					cout<<" Status : "<<pinjembuku[f].status;
					if((pinjembuku[f].status == 'y') || (pinjembuku[f].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<endl;
					cout<<" Sudah di kembalikan ? (y/n) : ";cin>>yn;
					if((yn == 'Y') || (yn == 'y')){
						cout<<" ganti status ( input n ) :";
						cin>>pinjembuku[f].status;
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}else{
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}
				}else{
					cout << "\n\n Data Tidak Di temukan \n" << endl;
					cout<<" Apakah ingin mengulang kembali ? (y/n) : ";cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						goto pengembalian;
					}else{
						system("cls");
						goto mulaimenu;
					}
				}
			}
	}else if(pilihan == 5){
		system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t laporan Perpustakaan\n";
			cout<<"\t\t\t____________________\n"<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
			cout<<" No  Kode Peminjam  Judul Buku  Nama Peminjam    Alamat           Tanggal Pinjam  Tanggal Balik   Status   Buku Keluar \n";
			cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
			for(g=0;g<=b;g++){
				if(pinjembuku[g].kB==buku[g].kodeB){
					cout<<setw(2)<<g+1<<setw(10)<<pinjembuku[g].kodepinjam<<setw(13)<<buku[g].judul<<setw(12)<<pinjembuku[g].namap
					<<setw(14)<<pinjembuku[g].alamat<<setw(20)<<pinjembuku[g].tglpin<<setw(10)<<pinjembuku[g].tglbalik
					<<setw(12)<<pinjembuku[g].status;
					if((pinjembuku[g].status == 'y') || (pinjembuku[g].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<setw(12)<<pinjembuku[g].dipinjem;
					cout<<endl;
				}
			}
		system("pause");
		system("cls");
		goto mulaimenu;


	}else if(pilihan == 6){
		cout<<"-- Anda Telah Logout -- \n";
		cout<<"-- Program Aplikasi Pengelolaan Perpustakaan UMMI \n";
		system("pause");
		system("cls");
		goto login;

	}else{
		system("cls");
		goto mulaimenu;
	}


}

int main()
{
    program_perpustakaan();
}
