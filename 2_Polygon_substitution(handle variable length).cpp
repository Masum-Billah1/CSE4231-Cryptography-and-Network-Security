#include<bits/stdc++.h>
using namespace std;
map<string,string>encoder;
map<string,string>decoder;

string Encryption(string msg,int size){
    string encrypted_msg;
    string temp="";
    for(int i=0;i<msg.size();i++){
        temp+=msg[i];
        if(temp.size()== size){
            if(encoder.find(temp) != encoder.end()){
                encrypted_msg += encoder[temp]; 
            }
            else{
                encrypted_msg += temp;
            }
            temp="";
        }
        if(encoder.find(temp) != encoder.end()) {
            encrypted_msg += encoder[temp];
            temp="";
        }    
    }
    if(temp.size()!=0)
        encrypted_msg += temp;
    return encrypted_msg;
}

string Decription(string cipher,int size){
    string temp="";
    string decrypted_msg;
    for(int i=0;i<cipher.size();i++){
        temp+=cipher[i];
        if(decoder.find(temp) != decoder.end()){
            decrypted_msg+=decoder[temp];
            temp ="";
        }
        else if(temp.size()==size){
            if(decoder.find(temp) != decoder.end())
                decrypted_msg+=decoder[temp];
            else
                decrypted_msg+=temp;
            temp ="";
        }
    }
    decrypted_msg+=temp;
    return decrypted_msg;
}

int main(){
    freopen("polygon.txt","r",stdin);
    string message;
    cin >> message;
    cout <<"Original Message: "<<message<<endl;
    cin.clear();

    freopen("dictionary.txt","r",stdin);
    string s1,s2;
    while(cin>> s1 >> s2){
        encoder[s1] = s2;
        decoder[s2] = s1;
    }
    int block_size = 3;
    string Encrypted_message = Encryption(message,block_size);
    cout << Encrypted_message<<endl;

    string Decrypted_message = Decription(Encrypted_message,block_size);
    cout << Decrypted_message<<endl;
}
