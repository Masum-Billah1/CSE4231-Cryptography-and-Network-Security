#include<bits/stdc++.h>
using namespace std;
map<string, string> encoder;
map<string, string> decoder;

string encrypt(string str, int size){
    string temp="",cyper_text;
    for(int i=0;i<str.size();i++){
        temp+=str[i];
        if((i+1)%size == 0){
            cyper_text += encoder[temp];
            temp=""; 
        }
    }
    return cyper_text;
}

string decrypt(string str, int size){
    string temp="",decrypt_text;
    for(int i=0;i<str.size();i++){
        temp+=str[i];
        if((i+1)%size == 0){
            decrypt_text += decoder[temp];
            temp=""; 
        }
    }
    return decrypt_text;
}

int main(){
    int block_size=3;
    string str;
    freopen("polygon.txt","r",stdin);
    getline(cin,str);
    cin.clear();

    freopen("dictionary.txt","r",stdin);
    string s1,s2;
    while(cin >> s1 >> s2){
        encoder[s1] = s2;
        decoder[s2] = s1;
    }

    //Printing dictionary
    // for(const auto &pair: encoder){
    //     cout << pair.first<<" "<<pair.second<<endl;
    // }

    string encrypted_message = encrypt(str,block_size);
    cout <<"Encrypted Message: "<<encrypted_message<<endl;

    string decrypted_message = decrypt(encrypted_message,block_size);
    cout <<"Decrypted Message: "<<decrypted_message<<endl;
}