// Implement Framing technique - Byte Stuffing or Character Stuffing

#include<iostream>
#include<vector>
using namespace std;

string byteStuffing(string str, char flag, char esc)
{
	string res;
	res.push_back(flag);
	for(int i=0; i<str.length(); i++)
	{
		if(str[i] == flag or str[i] == esc)
			res.push_back(esc);
		res.push_back(str[i]);
	}
	res.push_back(flag);
	return res;
	
}

int main()
{
	char flag,esc;
	cout<<"Enter the character to be used as flag: ";
	cin>>flag;
	cout<<"Enter the character to be used as esc: ";
	cin>>esc;
	
	string str;
	cout<<"Enter the data in the form of character string:\n";
	cin>>str;
	
	string res = byteStuffing(str, flag, esc);
	cout<<"The data after Byte Stuffing is:\n"<<res;
	
}