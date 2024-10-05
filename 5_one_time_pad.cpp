#include<bits/stdc++.h>
using namespace std;

string encrpt(string message, string key){
    string encrypted_message="";
    for(int i=0;i<message.size();i++){
        if(islower(message[i])){
            encrypted_message += (message[i]+key[i]- 2*'a'+1)%26+'a';
        }
        if(isupper(message[i])){
            encrypted_message += (message[i]+key[i]- 2*'A'+1)%26+'A';
        }
    }
    return encrypted_message;
}

string decrypt(string encrypted_msg, string key){
    string decrypted_message;
    for(int i=0;i<encrypted_msg.size();i++){
        int value = (encrypted_msg[i]-key[i]-1);
        if(value<0)
            if(isupper(encrypted_msg[i]))
                decrypted_message+=(value+26+'A');
            else    
                decrypted_message+=(value+26+'a');
        else 
            if(isupper(encrypted_msg[i]))   
                decrypted_message+=(value+'A');
            else    
                decrypted_message+=(value+'a');
    }
    return decrypted_message;
}

int main(){
    freopen("onetimepad.txt","r",stdin);
    string message,key;
    if(getline(cin,message) && getline(cin,key));
    
    string encryption = encrpt(message,key);
    string decryption = decrypt(encryption,key);
    cout <<"Plain text: "<<message<<endl;
    cout <<"Key: "<<key<<endl;
    cout << "Encrypted Message: "<<encryption<<endl;
    cout << "Decrypted Message: "<<decryption<<endl;
}