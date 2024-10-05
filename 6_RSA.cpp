#include<bits/stdc++.h>
using namespace std;

int to_number(string str){
    int number = 0;

    for(int i=0;i<str.size();i++){
        number*=10;
        number +=(str[i]-'0');
    }
    return number;
}

string to_binary(int number){
    string binary;
    while(number>0){
        binary+=(number%2+'0');
        number/=2;
    }
    return binary;
}

int power_and_mod(int number, string binary,int product){
    int array[binary.size()];
    array[0] = number%product;
    for(int i=1;i<binary.size();i++){
        array[i] = pow(array[i-1],2);
        array[i] %= product;
    }
    int final_result = 1;
    for(int i=0;i<binary.size();i++){
        if(binary[i] == '1'){
            final_result = (final_result*array[i]) % product;
        }
    }
    return final_result;
    
}

int main(){
    string number;
    int product = 3337;
    freopen("rsa.txt","r",stdin);
    getline(cin,number);
    cout <<"Plain text: "<< number<<endl;
    int block_size = 3;
    int mod_result = block_size-(number.size()%block_size);
    string temporary="";

    int e = 79;
    string binary = to_binary(e);

    vector<int>encrypt;
    int index = 0;
    for(int i=0;i<number.size();i+=block_size){
        for(int j=0;j<block_size;j++){
            if(i+j<number.size())
                temporary+=number[i+j];
        }
        if(i == number.size()/block_size*block_size){
             while(mod_result--){
                temporary = '0'+temporary;
            }
        }
        int temporary_number = to_number(temporary);
        encrypt.push_back(power_and_mod(temporary_number,binary,product));
        temporary = "";
    }

    cout <<"Encryption: ";
    for(int i=0;i<encrypt.size();i++){
        cout << encrypt[i];
    }
    cout << endl;

    //Decryption start here
    int inverse = 1019;
    string binary_inverse = to_binary(1019);

    vector<int>decrypt;
    for(int i=0;i<encrypt.size();i++){
        decrypt.push_back(power_and_mod(encrypt[i],binary_inverse,product));
    }
    cout << "Decryption: ";
    for(int i=0;i<decrypt.size();i++){
        cout << decrypt[i];
    }
    cout << endl;
}