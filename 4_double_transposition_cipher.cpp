#include<bits/stdc++.h>
using namespace std;
string encryption(string str,int block_size){
    string encrypted_msg = "";
    int temp;
    for(int i=0;i<block_size;i++){
        temp = i;
        while(temp<str.size()){
            encrypted_msg+=str[temp];
            temp+=block_size;
        }
    }
    return encrypted_msg;
}

string decryption(string str, int block_size){
    string decrypted_msg = "";
    int partition = ceil(str.size()*1.0/block_size);
    int extra = str.size()%block_size;

    for(int i=0;i<partition;i++){
        int temp = i;
        int regulate = 0;
        while(temp<str.size()){
            if(decrypted_msg.size()<str.size())
                decrypted_msg+=str[temp];
            regulate++;
            if(regulate>extra && extra!=0)
                temp += (partition-1);
            else
                temp += partition;
        }
    }
    return decrypted_msg;
}

int main(){
    freopen("transposition_ciper.txt","r",stdin);
    string str;
    getline(cin,str);
    cout <<"Plain text: " <<str<<endl;
    int size = str.size();
    int block_size = 5;

    string encrypted_msg1 = encryption(str,block_size);
    cout <<"Encrypted message: "<< encrypted_msg1<<endl;

    string encrypted_msg2 = encryption(encrypted_msg1,block_size);
    cout <<"Encrypted message: "<< encrypted_msg2<<endl;
    
    string decrypted_msg2 = decryption(encrypted_msg2,block_size);
    string decrypted_msg = decryption(decrypted_msg2,block_size);
    cout <<"Decrypted message: "<<decrypted_msg<<endl;
}