#include<iostream>
#include<string>

using namespace std;

char msg[1000],cip[36],enc[1000],decr[1000];
int key[1000];

int findIndex(char ch)
{
    int x;
    for(int i=0;i<36;i++)
    {
        if(cip[i] == ch)
        {
            x = i;
            i = 36;      
        }
    }
    return x;
}

void table(string k,string s)
{
    int i,l=0,x;
    for(i=0;i<10;i++)
    {
        cip[l] = i+48;
        cout << cip[l];
        l++;
    }
    for(i=0;i<26;i++)
    {
        cip[l] = i+97;
        cout << cip[l];
        l++;
    }
    cout << endl;
    cout << "Kode Kunci : " << endl;
    for(i=0;i<s.size();i++)
    {
        x = findIndex(k[i]);
        key[i] = x;
        cout << k[i];
    }
    cout << endl;
}

int encrypt(string s,string k)
{
    int i,l=0,x,y=0;
    for(i=0;i<s.size();i++)
    {
        if((s[i] >47 && s[i]<58) || (s[i] >96 && s[i]<123))
        {
            x = findIndex(s[i]);
            enc[i] = cip[(key[y]+x)%36];
            y++;
            if(y>k.size())
            {
                y = 0;
            }
        }
        cout << enc[i];
    }
    return i;
}

void decrypt(char s[],string k,int j)
{
    int i,l=0,x,z,y=0;
    for(i=0;i<j;i++)
    {
        if((s[i] >47 && s[i]<58) || (s[i] >96 && s[i]<123))
        {
            x = findIndex(s[i]);
            
            z = x - key[y];
            
            if(z<0)
            {
                z = 36+z;
            }
            decr[i] = cip[z];
            y++;
            if(y>k.size())
            {
                y = 0;
            }
        }
        cout<<decr[i];
    }
    return ;
}

int main()
{
    int x;
    string s, k;
    
    cout << "Masukkan data :" << endl;
    getline(cin,s);
    cout << "Masukkan kunci : " << endl;
    cin >> k;
    int i,j,f=0;
    for(i=0;i<s.size();i++)
    {
        if((s[i] >47 && s[i]<58) || (s[i] >96 && s[i]<123))
        {
            k.append(s,i,1);
        }
    }
    table(k,s);
    
        cout << "\nPesan yang sudah di enkripsi : ";
        j = encrypt(s, k);

        cout << "\nPesan yang sudah di dekripsi : ";
        decrypt(enc, k, j);
    return 0;
}