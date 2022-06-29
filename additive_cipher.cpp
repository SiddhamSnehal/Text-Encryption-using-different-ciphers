#include<iostream>

using namespace std;

//for a=1,b=2,c=3,.......z=26


int new_pos,position;

char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
			'v','w','x','y','z',' '};

string encrypt(string plain_text,int shift,int len)
{
	string cipher_text, new_letter;
	for(int i=0;i<len;i++)
	{
		position = (plain_text[i] & 31);
		new_pos = (position + shift)%27;
		new_letter = alphabet[new_pos-1];
		cipher_text += new_letter;	
	}
	return cipher_text;	
}

 string decrypt(string cipher_text,int shift,int len)
{
	string plain_text, new_letter;
	for(int i=0;i<len;i++)
	{
		position = (cipher_text[i] & 31);
		
		new_pos = (position - shift)%27;
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
	int shift,len,shift1,len1,choice;
	string encrypted,decrypted;
	string plain_text,cipher_text;
	
	cout<<"1.Additive Encryption.\n2.Additive Decryption.\n "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter plain text: "<<endl;
			cin.clear();
			cin.ignore(100,'\n');
			getline(cin,plain_text);
			cout<<"Enter additive key value: ";
			cin>>shift;
			len=plain_text.length();
		
			encrypted= encrypt(plain_text,shift,len);
			cout<<encrypted<<endl;		
		}
		case 2:
		{
			cout<<"Enter cipher text: "<<endl;
			cin.clear();
			cin.ignore(100,'\n');
			getline(cin,cipher_text);
			cout<<"Enter additive key value: ";
			cin>>shift1;
			len1=cipher_text.length();
			
			decrypted = decrypt(cipher_text,shift1,len1);
		
			cout<<decrypted<<endl;
			break;
		}
		case 3 :
		{
			exit(0);
		}
		default:
		{
			cout<<"Enter valid choice."<<endl;
		}
	return 0;
}
}

