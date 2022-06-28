#include <iostream>

using namespace std;

char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
			'v','w','x','y','z',' '};
int position;
string new_word;
char encrypt[27];
	
		
string new_keyword(string keyword,int keylength)
{
	int pos[27]={0};
	for(int i=0;i<keylength;i++)
	{	
		position = (keyword[i] & 31);
		pos[position]++;
		if(pos[position]==1)
		{
			new_word+=keyword[i];
		//	cout<<new_word[j]<<" "<<j<<endl;
		}	
	}
	return new_word;
}

string encryption(string plain_text,string new_word, char keyletter)
{
	position=(keyletter & 31);
	int j=0,count=0;
	int len=new_word.length()+position;
	for(int i=position;i<len;i++)
	{
		encrypt[i]+=new_word[j];
		cout<<encrypt[i]<<" "<<i<<endl;
		j++;
	}
	for(int i=len;i<27;i++)
	{
		cout<<i<<endl;
		for(int j=0;j<new_word.length();j++)
		{
			if(alphabet[i]!=new_word[j])
			{
				count++;
				if(count!=0)
				{
					encrypt[i]+=alphabet[j];
					cout<<encrypt[i]<<" "<<i<<endl;
				}
				
				}	
		}
	
	}
}


int main()
{
	string keyword,plain_text;
	char keyletter;
	int keylength;
	
	cout<<"Enter the Plain Text: ";
	getline(cin,plain_text);

	cout<<"Enter the Keyword: ";
	getline(cin,keyword);
	keylength= keyword.length();
	
	cout<<"Enter the Keyletter: ";
	cin>>keyletter;
	
	new_word=new_keyword(keyword,keylength);
	encryption(plain_text,new_word,keyletter);
	return 0;
}
