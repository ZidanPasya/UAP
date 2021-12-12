#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std; //mempersingkat penulisan std

void gotoxy(short x, short y){ //fungsi ini digunakan untuk menentukan posisi
	COORD koordinat = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

void timer(){ //untuk memberi selang waktu (menjeda)
	Sleep(3000);
}

void border(){ //fungsi ini digunakan untuk membuat kotak (batas)
	for (int i=20; i<=80; i++){
		gotoxy(i, 2);
		cout << char(220);
		gotoxy(i, 26);
		cout << char(220);
	}
	for (int i=3; i<=26; i++){
		gotoxy(20, i);
		cout << char(219);
		gotoxy(80, i);
		cout << char(219);
	}
}


void judul(){ //fungsi ini digunakan untuk memberi judul
	int i=39, j=48, k=57, l=6;
	
	gotoxy(i, l);
	cout << "******";
	gotoxy(i, l+1);
	cout << "*     ";
	gotoxy(i, l+2);
	cout << "*  ***";
	gotoxy(i, l+3);
	cout << "*    *";
	gotoxy(i, l+4);
	cout << "******";
	gotoxy(38, l+5);
	cout << "GUNTING";
	
	gotoxy(j, l);
	cout << "******";
	gotoxy(j, l+1);
	cout << "*    *";
	gotoxy(j, l+2);
	cout << "*  ***";
	gotoxy(j, l+3);
	cout << "*    *";
	gotoxy(j, l+4);
	cout << "******";
	gotoxy(49, l+5);
	cout << "BATU";
	
	gotoxy(k, l);
	cout << "*   * ";
	gotoxy(k, l+1);
	cout << "*  *  ";
	gotoxy(k, l+2);
	cout << "***  ";
	gotoxy(k, l+3);
	cout << "*  *  ";
	gotoxy(k, l+4);
	cout << "*   *";
	gotoxy(57, l+5);
	cout << "KERTAS";
}

void opsi(){ //fungsi ini digunakan untuk memilih opsi mulai atau keluar
	int i=45, j=16;
	
	gotoxy(i, j);
	cout << "1. Mulai";
	gotoxy(i, j+2);
	cout << "2. Keluar";
}

void mulai(){ //fungsi ini digunakan untuk memulai permainan
	string pemain, komputer;
	int a, random, b, i=25, j=15;
	
	srand(time(0));
	string tangan_pemain[3]={"Gunting", "Batu", "Kertas"};
	string tangan_komputer[3]={"Gunting", "Batu", "Kertas"};
	
	judul();
	gotoxy(i, j);
	cout << "Masukkan nama pemain: ";
	cin >> pemain;
	system("cls");
	
	border();
	judul();
	gotoxy(i, j);
	cout << "0 = Gunting";
	gotoxy(i, j+1);
	cout << "1 = Batu";
	gotoxy(i, j+2);
	cout << "2 = Kertas";
	gotoxy(i, j+3);
	cout << "Pilihlah bentuk tangan: ";
	cin >> a;
	
	if (a >= 0 && a <=2) {
		for(b = 0; b <=2; b++) {
			random = rand()%3;
		}
		system("cls");
		border();
		judul();
		gotoxy(i, j);
		cout << pemain << " memilih: " << tangan_pemain[a] << endl;
		gotoxy(i, j+1);
		cout << "Komputer memilih: ";
		timer();
		cout << tangan_komputer[random] << endl;
		
		if (a == random) {
			gotoxy(i, j+2);
			cout << "Anda Seri";
		}
		else if (tangan_pemain[0] == tangan_komputer[1]) {
			gotoxy(i, j+2);
			cout << "Anda Kalah";
		}
		else if (tangan_pemain[1] == tangan_komputer[2]) {
			gotoxy(i, j+2);
			cout << "Anda Kalah";
		}
		else if (tangan_pemain[2] == tangan_komputer[0]) {
			gotoxy(i, j+2);
			cout << "Anda Kalah";
		}
		else {
			gotoxy(i, j+2);
			cout << "Selamat Anda Menang";
		}
		getch();
		system("cls");
		border();
		gotoxy(i, j-4);
		cout << "Apakah ingin bermain ga?";
		gotoxy(i, j-3);
		cout << "1. Iya";
		gotoxy(i, j-2);
		cout << "2. Tidak";
		gotoxy(i, j-1);
		cout << "Masukkan angka: ";
		cin >> a;
		if (a==1){ //untuk bermain lagi
			system("cls");
			border();
			mulai();
		}
		else if (a==2){ //untuk keluar dari permainan
			system("cls");
			border();
			gotoxy(38, 14);
			cout << "Terima kasih telah bermain!";
		}
		else{
			system("cls");
			border();
			gotoxy(38, 14);
			cout << "Masukkan angka yang benar!";
		}
	}
	else {
		system("cls");
		border();
		gotoxy(i+14, j-1);
		cout << "Masukkan angka yang benar!";
	}
}

void rules(){ //fungsi ini digunakan untuk menampilkan cara bermain
	int i=23, j=6;
	
	system("cls");
	border();
	gotoxy(i, j-2);
	cout << "Cara Bermain:";
	gotoxy(i, j);
	cout << "1. Jika pemain memilih gunting dan komputer memilih";
	gotoxy(i+3, j+1);
	cout << "batu, maka komputer dinyatakan menang.";
	gotoxy(i, j+2);
	cout << "2. Jika pemain memilih gunting dan komputer memilih";
	gotoxy(i+3, j+3);
	cout << "kertas, maka pemain dinyatakan menang.";
	gotoxy(i, j+4);
	cout << "3. Jika pemain memilih batu dan komputer memilih";
	gotoxy(i+3, j+5);
	cout << "gunting maka pemain dinyatakan menang.";
	gotoxy(i, j+6);
	cout << "4. Jika pemain memilih batu dan komputer memilih";
	gotoxy(i+3, j+7);
	cout << "kertas, maka komputer dinyatakan menang.";
	gotoxy(i, j+8);
	cout << "5. Jika pemain memilih kertas dan komputer memilih";
	gotoxy(i+3, j+9);
	cout << "batu, maka pemain dinyatakan menang.";
   	gotoxy (i, j+10);
	cout << "6. Jika pemain memilih kertas dan komputer memilih";
	gotoxy (i+3, j+11);
   	cout << "gunting,maka pemain dinyatakan menang.";
   	gotoxy (i, j+12);
   	cout << "7. Jika pemain memilih kertas dan komputer memilih";
   	gotoxy (i+3, j+13);
   	cout << "kertas, maka dinyatakan seri.";
   	gotoxy (i, j+14);
   	cout << "8. Jika pemain memilih gunting dan komputer memilih";
   	gotoxy (i+3, j+15);
	cout << "gunting, maka dinyatakan seri.";
	gotoxy (i, j+16);
	cout << "9. Jika pemain memilih batu dan komputer memilih";
	gotoxy (i+3, j+17);
	cout << "batu, maka dinyatakan seri.";
	gotoxy (i+3, j+19);

}

int main() {
	border();
	judul();
	opsi();
	int a;
	
	gotoxy(42, 22);
	cout << "Masukkan angka: ";
	cin >> a;
	if (a==1){ //untuk memulai permainan
		rules();
		cout << "Tekan apa saja untuk mulai";
		getch();
		system("cls");
		border();
		mulai();
	}
	else if (a==2){ //untuk keluar dari permainan
		system("cls");
		border();
		gotoxy(38, 14);
		cout << "Terima kasih telah bermain!";
	}
	getch();
}
