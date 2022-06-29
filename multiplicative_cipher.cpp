#include<iostream>

using namespace std;
// mod 31 ---> a=1,b=2,..      mod30 ---->a=0,b=1,....

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
string encrypt(string plain_text,int shift,int len)
{
	string cipher_text,new_letter;
	for(int i=0;i<len;i++)
	{
		position = (plain_text[i] & 31);
		new_pos = (position* shift)%27;
		new_letter = alphabet[new_pos-1];
		cipher_text += new_letter;
		
	}
	return cipher_text;	
}

 string decrypt(string cipher_text,int shift,int len)
{
	string plain_text,new_letter;
	for(int i=0;i<len;i++)
	{
		position = (cipher_text[i] & 31);
		new_pos = (position * shift)%27;
		new_letter = alphabet[new_pos-1];
		plain_text += new_letter;	
	}
	return plain_text;	
}


int main()
{
	int shift,len,shift1,len1,inv;
	string plain_text,cipher_text, new_letter;
	string encrypted,decrypted;
	
	cout<<"Enter plain text: "<<endl;
	getline(cin,plain_text);
	cout<<"Enter Multiplicative key value: ";
	cin>>shift;
	len=plain_text.length();

	encrypted= encrypt(plain_text,shift,len);
	cout<<encrypted<<endl;
	
	cout<<"Enter cipher text: "<<endl;
	cin.clear();
	cin.ignore(100,'\n');
	getline(cin,cipher_text);
	cout<<"Enter Multiplicative key value: ";
	cin>>shift1;
	if(checkCoPrime(shift1)== 1)
	{
		inv=inverse(shift1);
		len1=cipher_text.length();
		decrypted = decrypt(cipher_text,inv,len1);

		cout<<decrypted<<endl;
	}
	else
	{
		cout<<"Enter valid key";
	}

	
}
