#include<iostream>
#include<string.h>
using namespace std ;
// Function to find out the class
char findClass(char str[])
{
	//storing first octet in arr[] variable
	char arr[4] ;
	int i=0 ;
	while(str[i]!='.'){
		arr[i] = str[i] ;
		i++ ;
	}
	i-- ;
	//converting str[] variable into number for comparison
	int ip=0,j=1 ;
	while(i>=0){
		ip = ip + (str[i]-'0')*j ;
		j = j*10 ;
		i-- ;
	}
	//class A
	if(ip>=1 && ip<=126)
		return 'A' ;
	//class B
	else if(ip>=127 && ip<=191)
		return 'B' ;
	//class C
	else if(ip>=192 && ip<=223)
		return 'C' ;
	//class D
	else if(ip>=224 && ip<=239)
		return 'D' ;
	//class E
	else 
		return 'E' ;
}
// Function to separate Network id as well as Host id and print them
void separate(char str[],char ipClass)
{
	//initializing network and host array to NULL
	char network[12],host[12] ;
	for(int k=0; k<12 ; k++)
		network[k] = host[k] = '\0' ;
		
	//for class A, only first octet is Network id and rest are Host id
	if(ipClass=='A')
	{
		int i=0,j=0 ;
		while(str[j]!='.')
			network[i++]=str[j++] ;
		i=0 ;
		j++ ;
		while(str[j]!='\0')
			host[i++] = str[j++] ;
		cout<<"Network ID : "<<network<<endl ;
		cout<<"Host ID : "<<host<<endl ;
	}
	//for class B, first two octets are Network id and rest are Host id
	else if(ipClass=='B')
	{
		int i=0,j=0,dotCount=0 ;
		//storing in network[] upto two dots
		//dotCount keeps track of number of octets passed
		while(dotCount<2){
			network[i++] = str[j++] ;
			if(str[j]=='.')
				dotCount++ ;
		}
		i=0 ;
		j++ ;
		while(str[j]!='\0')
			host[i++] = str[j++] ;
		cout<<"Network ID : "<<network<<endl ;
		cout<<"Host ID : "<<host<<endl ;
	}
	//for class C, first three octets are Network id and rest are Host id
	else if(ipClass=='C')
	{
		int i=0,j=0,dotCount=0 ;
		//storing in network[] upto three dots
		//dotCount keeps track of number of octets passed
		while(dotCount<3){
			network[i++] = str[j++] ;
			if(str[j]=='.')
				dotCount++ ;
		}
		i=0 ;
		j++ ;
		while(str[j]!='\0')
			host[i++] = str[j++] ;
		cout<<"Network ID : "<<network<<endl ;
		cout<<"Host ID : "<<host<<endl ;
	}
	//classes D and E are not divided into Network and Host id
	else
		cout<<"In this class, IP address is not divided into Network and Host id..\n" ;
}
// Driver Function to test the above function
int main()
{
	char str[] = "192.226.12.11" ;
	char ipClass = findClass(str) ;
	cout<<"Given IP address belongs to class "<<ipClass<<endl ;
	separate(str,ipClass) ;
	return 0 ;
}

