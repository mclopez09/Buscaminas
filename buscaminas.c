
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Juego buscaminas en C.
//--------------------------------------//
//Creacion de la matriz//
struct casilla
{
	char etiqueta;
	int nMinas;
	char tipo;
};

typedef struct casilla tipoCasilla;

tipoCasilla **crearCuadro(int f,int c){
	tipoCasilla **mat=(tipoCasilla **)malloc(f*sizeof(tipoCasilla*));
	int i;
	for (i=0;i<f; i++){
		
		mat[i]=(tipoCasilla *)malloc(c*sizeof(tipoCasilla));
	}
	return mat;
}

tipoCasilla **llenarCuadro(tipoCasilla **mat, int f, int c){
	int i,j;
	for (i = 0; i<f;i++){
		for (j=0;j<c;j++){
			mat[i][j].etiqueta = 'x'; 	// los cuadros son representados con una x
			mat[i][j].tipo = 'c'; 
			mat[i][j].nMinas = 0;
		}
	}
	return mat;
}

//Imprimir cuadro:
void **imprimir(tipoCasilla **matriz, int f,int c){
	int i,j;
	for (i = 0; i<f;i++){
		for (j=0;j<c;j++){
			printf("%c %c|", matriz[i][j].etiqueta,matriz[i][j].tipo);
		}
		printf("\n");
	}
}

void colocarMinas(int f, int c, tipoCasilla **mat, int n){
	int posFil, posCol, m;
	srand(time(NULL));
	m =0;
	while (m<n){
		posFil = rand() % f;
		posCol = rand() % c;
		mat[posFil][posCol].tipo = 'm';
		m++; 
	}
}

void colocarNumeros(int f, int c, tipoCasilla **mat){
	int i,j;
	for (i = 0; i<f;i++){
		for (j=0;j<c;j++){
			if  (mat[i][j].tipo == 'm'){
				mat[i][j].nMinas = 0;
			}else{
				if(i == 0 && j == 0){      //Esquina superior izq.//
					if(mat[i+1][j].tipo == 'm'){  // abajo
						mat[i][j].nMinas= mat[i][j].nMinas + 1; 
					}else{
						if(mat[i+1][j+1].tipo == 'm'){ //abajo derecha
							mat[i][j].nMinas= mat[i][j].nMinas + 1;
						}else{
							if(mat[i][j+1].tipo == 'm'){  // derecha
								mat[i][j].nMinas= mat[i][j].nMinas + 1;
							}
						}
					}
				}else{
					if(i ==0  && j == c-1){  // esquina superior der.//
						if(mat[i][j-1].tipo == 'm'){  // izq.
							mat[i][j].nMinas= mat[i][j].nMinas + 1; 
						}
						if(mat[i+1][j-1].tipo == 'm'){ //abajo izq.
							mat[i][j].nMinas= mat[i][j].nMinas + 1;
						}
						if(mat[i+1][j].tipo == 'm'){  // abajo
							mat[i][j].nMinas= mat[i][j].nMinas + 1;
						}
							
						
					}else{
						if(i == f-1 && j ==0){ //Esquina inferior izq.//
							if(mat[i-1][j].tipo == 'm'){  // arriba
								mat[i][j].nMinas= mat[i][j].nMinas + 1; 
							}
							if(mat[i-1][j+1].tipo == 'm'){  // arriba der.
								mat[i][j].nMinas= mat[i][j].nMinas + 1; 
							}
							if(mat[i][j+1].tipo == 'm'){ // derecha.
								mat[i][j].nMinas= mat[i][j].nMinas + 1;
							}
						}else{
							if(i == (f-1) && j == (c-1)){ // Esquina inferior der.//
								if(mat[i][j-1].tipo == 'm'){  // izq.
									mat[i][j].nMinas= mat[i][j].nMinas + 1; 
								}
								if(mat[i-1][j-1].tipo == 'm'){  // arriba izq.
									mat[i][j].nMinas= mat[i][j].nMinas + 1; 
								}
								if(mat[i-1][j].tipo == 'm'){ // arriba
									mat[i][j].nMinas= mat[i][j].nMinas + 1;
								}	
							}
						}
					}
				}
			}
		}
}

void main(){
	int f,c, min;
	tipoCasilla **Cuadro;
	tipoCasilla **Cuadro2;
	printf("Ingrese el numero de filas del buscaminas ");
	scanf("%d",&f);
	printf("Ingrese el numero de columnas del buscaminas ");
	scanf("%d",&c);
	printf("Ingrese el numero de Minas ");
	scanf("%d",&min);
	Cuadro = crearCuadro(f,c);
	Cuadro2 =  llenarCuadro(Cuadro, f,c);
	colocarMinas(f,c,Cuadro2,min);
	imprimir(Cuadro2, f,c);

	


}
