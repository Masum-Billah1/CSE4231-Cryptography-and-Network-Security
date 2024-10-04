#include <bits/stdc++.h>
using namespace std;

string endc(string text, int shift){
    for(int i=0;i<text.size();i++){
        if(isupper(text[i])){
            text[i] = (text[i]+shift-'A')%26+'A';
        }
        if(islower(text[i])){
            text[i] = (text[i]+shift-'a')%26+'a';
        }
    }
    return text;
}

int main(){
    string text;
    freopen("caesar.txt","r",stdin);
    getline(cin, text);

    cin >> text;
    int shift =3;
    // cin >> shift;

    cout <<"Original text: "<< text<<endl;
    string encrypted_file = endc(text,shift);
    cout<<"Encrypted text: " << encrypted_file<<endl;

    string decrypted_file = endc(encrypted_file,26-shift);
    cout <<"Decrypted text: "<< decrypted_file<<endl;
}