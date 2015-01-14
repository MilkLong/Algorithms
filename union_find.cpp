/*************************************************************************
    > File Name: union_find.cpp
    > Author: Michael
    > Mail:  
	> Des: 并查集
    > Created Time: 2015年01月12日 星期一 15时32分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define N 6
struct Set{
	int parent;
	int rank;
};

int Find( Set *s, int n )
{
	if( s[n].parent == -1 )
		return n;
	else{
		int xRoot = Find( s, s[n].parent );
		s[n].parent = xRoot;
		return xRoot;
	}
}

void Union( Set *s, int m, int n )
{
	int xRoot = Find( s, m );
	int yRoot = Find( s, n );

	if( xRoot == yRoot )
		return;
	//不同根,采用“按秩合并” 
	if( xRoot.rank < yRoot.rank )
		s[xRoot].parent = yRoot;
	else if( xRoot.rank > yRoot.rank )
		s[yRoot].parent = yRoot;
	else {
		s[yRoot].rank += 1;
		s[xRoot].parent = yRoot;
	}

}

void Init( Set *s )
{
	for( int i=0; i<N; ++i ){
		s[i].parent = -1;
		s[i].rank = 0;
	}

}
int main()
{
	Set s[N];

	cout << "1.parentt" << Find( s, 1 ) << endl;
	Union( s, 1, 2 );
	cout << "1.parentt" << Find( s, 1 ) << endl;
	return 0;
}

