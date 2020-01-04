#include <stdio.h>

#define M 4
#define N 4
void road(int n, int m, int i, int j, int pass);

int vert[4] = {-1,0,1,0};
int oriz[4] = {0,1,0,-1};
int table[M][N] = {	{ 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 

int main(){

	printf("Give the initial positions i and j (with a space between them)\n");
	int i,j;
	scanf("%d %d",&i,&j);
	
	if (i == 0  || i == (M-1) || j == 0 || j == (N-1) ) {
				printf("Is already on exit\n");
				for (int i = 0; i < N; i++){
					for (int  j = 0; j < N; j++){
						printf("%d  ",table[i][j]);
					}
					printf("\n");
				}
	}else{

	table[i][j]=-1; //initial position
	road(N,M, i,j,2);	
	}
	return 0;
}	


void road(int n, int m, int i, int j, int pass){
	
	int v, newI, newJ;
	
	for (v = 0; v < 4; v++){
	
		newI = i + vert[v];
		newJ = j + oriz[v];
		
		if (newI >= 0  && newI <m && newJ >=0 && newJ < n && table[newI][newJ] == 1) {
			table[newI][newJ] = pass;
			if (newI == 0  || newI == (m-1) || newJ == 0 || newJ == (n-1) ) {
				printf("---------\n");
				for (int i = 0; i < n; i++){
					for (int  j = 0; j < n; j++){
						printf("%d  ",table[i][j]);
					}
					printf("\n");
				}
			} else {
				road(n,m , newI, newJ, (pass + 1));
				}

			table[newI][newJ] = 0;
			}
}
}
				

