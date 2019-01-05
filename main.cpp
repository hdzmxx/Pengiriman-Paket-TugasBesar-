/*Muhammad Hidzyami 5170411338
M Rifki Pratama 5170411339*/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define Max 10
using namespace std;

struct paket
{
  int ID;
  string pengirim;
  string penerima;
  string tanggal;
  string alamat;
};

struct temp
{
  int ID;
  string pengirim;
  string penerima;
  string tanggal;
  string alamat;
};

struct queue
{
  struct paket mail[Max];
  struct temp temp[Max];
  int awal, akhir;
} qu;

void init()
{
  qu.awal = 0;
  qu.akhir = 0;
}

void linetop()
{
  for(int i = 0; i < 99; i++)
  {
    cout<<"=";
  }
  cout<<endl;
}

void linemid()
{
  for(int i = 0; i < 99; i++)
  {
    cout<<"-";
  }
  cout<<endl;
}

bool full()
{
  if(qu.akhir == Max-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool empty()
{
  if(qu.akhir == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void add(int ID, string pengirim, string penerima, string tanggal, string alamat)
{
  if(!full())
  {
    qu.mail[qu.akhir].ID = ID;
    qu.mail[qu.akhir].pengirim = pengirim;
    qu.mail[qu.akhir].penerima = penerima;
    qu.mail[qu.akhir].tanggal = tanggal;
    qu.mail[qu.akhir].alamat = alamat;
    qu.akhir++;
  }
}

void cari(int ID){
    if (!empty())
	{
		linetop();
		cout<<setiosflags(ios::left)<<setw(5)<<"ID"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Pengirim Paket"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Ditujukan kepada "; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Tanggal masuk"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Alamat tujuan"; cout<<" | "<<endl;
		linemid();

        int awal = 0, akhir = qu.akhir+1, tengah;

        while(awal <= akhir){
            tengah = (awal + akhir)/2;
            if(ID > qu.mail[tengah].ID){
                awal = tengah + 1;
            }else if(ID < qu.mail[tengah].ID){
                akhir = tengah - 1;
            }else{
                awal = akhir + 1;
            }
        }

        if(ID == qu.mail[tengah].ID){
            cout<<setiosflags(ios::left)<<setw(5)<<qu.mail[tengah].ID; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[tengah].pengirim; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[tengah].penerima; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[tengah].tanggal; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[tengah].alamat; cout<<" | "<<endl;
            linetop();
        }else{
            cout<<"Data tidak ditemukan";
        }

	}else{
		cout<<"qu kosong"<<endl<<endl;
	}
}

void del()
{
  int i;
  if(!empty())
  {
    cout<<"Paket sudah dihapus"<<endl;
    for(i=qu.awal; i<qu.akhir; i++)
    {
      qu.mail[i]=qu.mail[i+1];
    }
    qu.akhir--;
  }
  else
  {
    cout<<"Paket Kosong"<<endl;
  }
  getchar();
}

void tampil()
{
  if(!empty())
  {
    int i;
    linetop();
    cout<<setiosflags(ios::left)<<setw(5)<<"ID"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Pengirim Paket"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Penerima Paket"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Tanggal masuk"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Alamat tujuan"; cout<<" | "<<endl;
    for(i = qu.awal; i<qu.akhir; i++)
    {
      linemid();
      cout<<setiosflags(ios::left)<<setw(5)<<qu.mail[i].ID; cout<<" | ";
			cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[i].pengirim; cout<<" | ";
			cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[i].penerima; cout<<" | ";
			cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[i].tanggal; cout<<" | ";
			cout<<setiosflags(ios::left)<<setw(20)<<qu.mail[i].alamat; cout<<" | "<<endl;
    }
    linetop();
    cout<<endl;
  }
  else
  {
    cout<<"Paket Kosong"<<endl<<endl;
  }
}

int main()
{
  int pilihan, ID;
  string pengirim, penerima, tanggal, alamat;
  init();
  do
  {
    system("cls");
    cout<<"MENU PENGIRIMAN PAKET"<<endl;
    cout<<"==================\n"<<endl;
    tampil();
    cout<<"\n[1] Paket Baru \n[2] Hapus Daftar Paket \n[3] Cari\n[4] Keluar"<<endl;
    cout<<"\n==========="<<endl;
    cout<<"Masukkan Pilihan : "; cin>>pilihan;

    switch(pilihan)
    {
      case 1:
          cout<<"\nID Paket \t\t: "; cin>>ID; fflush(stdin);
          cout<<"Pengirim Paket \t\t: "; getline(cin, pengirim); fflush(stdin);
          cout<<"Ditujukan Kepada \t: "; getline(cin, penerima);
          cout<<"Tanggal Masuk \t\t: "; cin>>tanggal; fflush(stdin);
          cout<<"Alamat tujuan \t\t: "; getline(cin, alamat);
          add(ID, pengirim, penerima, tanggal, alamat);
          break;
      case 2:
          del();
          break;
      case 3:
          cout<<"\nMasukan ID = "; cin>>ID;
          cout<<endl;
          cari(ID);
          cout<<"\nTekan ENTER untuk kembali ke Menu"<<endl;
          getch();
          break;
      case 4:
          cout<<"Terima Kasih"<<endl;
          break;
    }
  }
  while(pilihan!=4);
}
