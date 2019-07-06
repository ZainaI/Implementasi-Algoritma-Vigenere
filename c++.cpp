#include<iostream>
#include<conio.h> 
#include<string> 
#include<string.h>
#include<fstream>
#include<cstdlib>

using namespace std;

class lock
{
private:
    int key;
public:
    void getkey();
    int checkkey(int );
    friend void enc(lock);
    friend void dec(lock);
}fileOri;

void lock::getkey()
{
    cout << "Masukkan kunci untuk enkripsi/dekripsi: ";
    cin >> key;
}

int lock::checkkey(int a)
{
    if(a==key)
        return 1;
    else
        return 0;
}

char namaFile[40];

int main()
{
     int a, pw, x;
     string c;

        cout << "Masukkan sandi: ";
		cin>>pw;
        if(pw!= 261)
        {
            cout << "Sandi salah, coba masukkan ulang sandi yang benar\n" << endl;
            getch();
            return main();
        }

     cout << "1. Enkripsi Input\n2. Enkripsi txt\n3. Dekripsi\n4. Keluar" << endl;
	 cout << "Pilih Nomor : ";
     cin>> a;
     if(a==1)
     {
         fileOri.getkey();

         cout << "Nama file baru: ";
         cin >> namaFile;

         strcat(namaFile,".txt");

        cout << "Masukkan data yang akan di enkripsi ke dalam file "<< namaFile << ": " << endl;

        ofstream InputData(namaFile);

        while(cin >> c)
        {
            InputData << c << " ";
        }

        InputData.close();

        enc(fileOri);

        getch();

        return 0;

     }
