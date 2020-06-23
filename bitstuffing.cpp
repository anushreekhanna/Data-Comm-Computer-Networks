#include<bits/stdc++.h>
using namespace std;
int main()
{
	//Bit Stuffing
	string s ;
	cout<<"BIT STUFFING : \nEnter the data bits : " ;
	cin>>s ;
	int set_bits=0,i ;
	string stuffed="",delimiter="01111110" ;
	for(i=0 ; i<s.length() ; i++){
		if(s[i]=='1')
			set_bits++ ;
		else
			set_bits=0 ;
		stuffed += s[i] ;
		if(set_bits==5)
		{
			stuffed+='0' ;
			set_bits=0 ;
		}
	}
	stuffed=delimiter+stuffed+delimiter ;
	string destuffed="" ;
	set_bits=0 ;
	for(i=8 ; i<stuffed.length()-8 ; i++){
		if(stuffed[i]=='1')
			set_bits++ ;
		else
			set_bits=0 ;
		destuffed += stuffed[i] ;
		if(set_bits==5)
		{
			i++ ;
			set_bits=0 ;
		}
	}
	cout<<"Data after stuffing : "<<stuffed<<endl ;
	cout<<"Data after destuffing : "<<destuffed<<endl ;
	
	//Byte Stuffing
	int n ;
	cout<<"\nBYTE STUFFING : \nEnter number of bytes : " ;
	cin>>n ;
	cout<<"Enter the data stream : " ;
	vector<string> input,byte_stuffed,byte_destuffed ;
	for(i=0 ; i<n ; i++){
		cin>>s ;
		input.push_back(s) ;
	}
	for(i=0 ; i<n ; i++){
		byte_stuffed.push_back(input[i]) ;
		if(input[i]=="FLAG" || input[i]=="ESC")
			byte_stuffed.insert(byte_stuffed.end()-1,"ESC") ;			
	}
	for(i=0 ; i<byte_stuffed.size() ; i++){
		if(byte_stuffed[i]=="ESC")
			i++ ;
		byte_destuffed.push_back(byte_stuffed[i]) ;
	}
	cout<<"Data after stuffing : " ;
	for(auto &x:byte_stuffed)
		cout<<x<<" " ;
	cout<<endl ;
	cout<<"Data after destuffing : " ;
	for(auto &x:byte_destuffed)
		cout<<x<<" " ;
	cout<<endl ;
	return 0 ;
}
