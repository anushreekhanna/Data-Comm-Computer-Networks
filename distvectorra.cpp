#include<stdio.h>
#include<iostream>
using namespace std ;

struct node
{
	unsigned dist[6] ;
	unsigned from[6] ;
} DVR[10] ;
int main()
{
	cout<<"\n\n PROGRAM TO IMPLEMENT DISTANCE VECTOR ROUTING ALGORITHM" ;
	int costmat[6][6] ;
	int nodes,i,j,k ;
	cout<<"\nEnter the number of nodes : " ;
	cin>>nodes ;
	cout<<"\nEnter the cost matrix : \n" ;
	for(i=0 ; i<nodes ; i++){
		for(j=0 ; j<nodes ; j++){
			cin>>costmat[i][j] ;
			costmat[i][i] = 0 ;
			DVR[i].dist[j] = costmat[i][j] ;
			DVR[i].from[j] = j ;
		}
	}
	for(i=0 ; i<nodes ; i++)
		for(j=i+1 ; j<nodes ; j++)
			for(k=0 ; k<nodes ; k++)
				if(DVR[i].dist[j]>costmat[i][k]+DVR[k].dist[j])
				{
					DVR[i].dist[j] = DVR[i].dist[k] + DVR[k].dist[j] ;
					DVR[j].dist[i] = DVR[i].dist[j] ;
					DVR[i].from[j] = k ;
					DVR[j].from[i] = k ;
				}
	for(i=0 ; i<nodes ; i++)
	{
		cout<<"\n\nFor router : "<<(i+1) ;
		for(j=0 ; j<nodes ; j++)
			cout<<"\t\n node "<<(j+1)<<" via "<<(DVR[i].from[j]+1)<<" Distance "<<DVR[i].dist[j] ;
	}
	cout<<"\n\n" ;
	return 0 ;
}
