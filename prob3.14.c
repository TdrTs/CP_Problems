#include <stdio.h>
void road(int n, int i, int j, int pass);

int oriz[8] = {1,2,2,1,-1,-2,-2,-1};
int vert[8] = {2,1,-1,-2,-2,-1,1,2};
int table[10][10];
int x = 0;

int main(){

	printf("Give the size of the table \n");
	int n;
	scanf("%d",&n);
	
	for (int i = 0; i < 10; i++){
		for (int  j = 0; j < 10; j++){
			table[i][j] = 0;
		}
	}
	
	table[0][0]=1;
	road(n, 0,0,2);	
	printf("There are %d solutions", x);
	return 0;
}

void road(int n, int i, int j, int pass){
	
	int v, newI, newJ;
	
	for (v = 0; v < 8; v++){
	
		newI = i + vert[v];
		newJ = j + oriz[v];
		
		if (newI >= 0  && newI <n && newJ >=0 && newJ < n && table[newI][newJ] == 0) {
			table[newI][newJ] = pass;
			if (pass == (n * n)) {
				printf("---------\n");
				for (int i = 0; i < n; i++){
					for (int  j = 0; j < n; j++){
						printf("%d  ",table[i][j]);
					}
					printf("\n");
				}
				
				x +=1;


			} else {
				road(n , newI, newJ, (pass + 1));
				}

			table[newI][newJ] = 0;
			}
}
}
				
