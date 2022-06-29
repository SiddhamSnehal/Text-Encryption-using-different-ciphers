#include <iostream>
//for a=1,b=2,c=3,.......z=26

using namespace std;

string alphabet="abcdefghijklmnopqrstuvwxyz ";
int position;
string new_word,new_word1;
char encrypt[27];


string new_word1(string new_word)
{
	int pos[27]={0},count=0;
	for(int i=0;i<27;i++)
	{ 
		
		position = new_word[i] & 31;
		pos[position]++;
	}
	for(int i=0;i<27;i++)
	{
		if(pos[position]==0)
		{
			new_word1+=alphabet[i];
			cout<<new_word1[count]<<" "<<count<<endl;
			count++;
		}	
	}
	cout<<new_word1;
	return new_word1;	
}

		
string new_keyword(string keyword,int keylength)   //find non-repeated letter
{
	int pos[27]={0},count =0;
	for(int i=0;i<keylength;i++)
	{	
		position = (keyword[i] & 31);
		pos[position]++;
		if(pos[position]==1)
		{
			new_word+=keyword[i];
		//	cout<<new_word[count]<<" "<<count<<endl;
			count++;
		}	
		
	}
	//cout<<new_word;
	return new_word;
}

string encryption(string plain_text,string new_word, char keyletter)
{
	position=(keyletter & 31);
	int j=0,count=0;
	int len=new_word.length()+position-1;
	for(int i=position-1;i<len;i++)
	{
		encrypt[i]+=new_word[j];
		cout<<encrypt[i]<<" "<<alphabet[i]<<endl;
		j++;
	}
	new_word1(new_word);
	//cout<<new_word;

//	//	string new_alpha = alphabet-new_word;
//		
//		for(int j=0;j<new_word.length();j++)
//		{
//		//	string new_alpha=alphabet-new_word;
//			if(alphabet[i]!=new_word[j])
//			{
//				count++;
//				if(count!=0)
//				{
//					encrypt[i]+=alphabet[j];
//					cout<<encrypt[i]<<" "<<alphabet[i]<<endl;
//				}
//			}	
//		}
	
//	}
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
