#include<iostream>
#include"validation.h"
using namespace std;

//for a=1,b=2,c=3,.......z=26


int new_pos,position,flag=0;

char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
			'v','w','x','y','z',' '};


int checkCoPrime(int shift1)
{
	for(int i=0;i<27;i++)
	{
		if((i*shift1)%27 == 1)
		{
			return 1;
		}

	}
}

int inverse(int shift1)
{
	for(int i=0;i<27;i++)
	{
		if((i*shift1)%27 == 1)
		{
			return i;
		}
		
	}
}
string encrypt(string plain_text,int key1,int key2,int len)
{
	string cipher_text,new_letter;
	for(int i=0;i<len;i++)
	{
		position = (plain_text[i] & 31);
		new_pos = ((position * key1 )+ key2) % 27;
		new_letter = alphabet[new_pos-1];
		cipher_text += new_letter;	
	}
	return cipher_text;	
}

 string decrypt(string cipher_text,int inv,int shift2, int len)
{
	string plain_text,new_letter;
	for(int i=0;i<len;i++)
	{
		position = (cipher_text[i] & 31);
		new_pos = ((position- shift2) * inv) % 27;
		if(new_pos<0){
			new_pos=new_pos+27;
		}
		new_letter = alphabet[new_pos-1];
		plain_text += new_letter;	
	}	
	return plain_text;	
}


int main()
{
	int key1,len,key2,len1,inv,shift1,shift2;
	string plain_text,cipher_text, new_letter;
	string encrypted,decrypted;
	
	cout<<"Enter plain text: "<<endl;
	getline(cin,plain_text);
	cout<<"Enter Multiplicative key value: ";
	cin>>key1;
	cout<<"Enter additive key value: ";
	cin>>key2;
	len=plain_text.length();

	encrypted= encrypt(plain_text,key1,key2,len);
	cout<<encrypted<<endl;
	
	cout<<"Enter cipher text: "<<endl;
	cin.clear();
	cin.ignore(100,'\n');
	getline(cin,cipher_text);
	cout<<"Enter Multiplicative key value: ";
	cin>>shift1;
	cout<<"Enter additive key value: ";
	cin>>shift2;
	if(checkCoPrime(shift1)== 1)
	{
		inv=inverse(shift1);
		len1=cipher_text.length();
		decrypted = decrypt(cipher_text,inv,shift2,len1);
		cout<<decrypted<<endl;
	}
	else
	{
		cout<<"Enter valid Multiplicative key";
	}

}
