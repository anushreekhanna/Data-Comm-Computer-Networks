#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int i,j,noframes,x,x2,x1=10 ;
	for(i=0 ; i<200 ; i++){
		rand() ;
	}
	noframes = rand()/200 ;
	i=1 ;
	j=1 ;
	noframes = noframes/8 ;
	cout<<"\nNumber of frames is : "<<noframes ;
	getch() ;
	while(noframes>0){
		cout<<"\nSending frames "<<i ;
		srand(x1++) ;
		x = rand()%10 ;
		if(x%2==0){
			for(x2=1 ; x2<2 ; x2++){
				cout<<"\nWaiting for "<<x2<<" seconds\n" ;
				//sleep(x2) ;
			}
			cout<<"Sending frames "<<i ;
			srand(x1++) ;
			x = rand()%10 ;
		}
		cout<<"\nAcknowledgement for frame "<<i ;
		noframes = noframes - 1 ;
		i++ ;
		j++ ;
	}
	cout<<"\nEnd of Stop & Wait Protocol..." ;
	getch() ;
	return 0 ;
}

