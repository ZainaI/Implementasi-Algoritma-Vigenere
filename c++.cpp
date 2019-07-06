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
	 else if(a==2)
     {
         fileOri.getkey();

         cout << "Masukkan nama file: ";
         cin >> namaFile;

         strcat(namaFile,".txt");
		 
        enc(fileOri);

        getch();

        return 0;

     }
     else if(a==3)
     {
         fileOri.getkey();

         cout << "Masukkan nama file: ";
         cin >> namaFile;

         strcat(namaFile,".txt");

        dec(fileOri);

        getch();

        return 0;

     }

     else if (a==4)
     {
         return 0;
     }
	 else
	 {
		 return main();
	 }
}

void enc(lock file)
{
    char encnamaFile[50] = "enc_";
    strcat(encnamaFile,namaFile);

    int n;

    srand(file.key);

    ifstream OutputData(namaFile);

    char ch[50] = "";

    ofstream InputData(encnamaFile);

    OutputData.getline(ch,49);
    do
    {
        n= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] + n;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File berhasil di Enkripsi"  << endl;
    cout << "Teks hasil enkripsi disimpan ke dalam: " << encnamaFile << endl;
}

void dec(lock file)
{
    char decnamaFile[50] = "dec_";
    strcat(decnamaFile,namaFile);

    int m;

    srand(file.key);

    ifstream OutputData(namaFile);

    char ch[50] = "";

    ofstream InputData(decnamaFile);

    OutputData.getline(ch,49);
    do
    {
        m= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] - m;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File berhasil di deskripsikan" << endl;
    cout << "Teks hasil deskripsi disimpan ke dalam: " << decnamaFile << endl;
}

