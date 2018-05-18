#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#pragma pack(push,1)
#pragma pack(1)
typedef struct file_header
{
	unsigned short tipo;
	unsigned int tamArquivo;
	unsigned short reservado1;
	unsigned short reservado2;
	unsigned int offset;	
} FH;
//#pragma pack(pop)

typedef struct info_header
{
	unsigned int tamanho_cabecalho;
	unsigned int largura_img;
	unsigned int altura_img;
	unsigned short planos;
	unsigned short bits; //bits por pixel
} IH;

typedef struct pixel
{
    int r;
    int g;
    int b;
} Pixel;

int main(int argc, char **argv)
{
	FH cab_file;
	IH cab_imagem;

	FILE *f = NULL;
	if(argc !=2)
	{
		printf("Numeros de parametros invalido\n");
		exit(0);
	}

	f = fopen(argv[1], "rb");
	
	if(f==NULL)
	{
		printf("Erro na abertura do arquivo\n");
		exit(0);
	}

	fread(&cab_file, sizeof(FH), 1, f);

	fread(&cab_imagem, sizeof(IH),1,f);

	//fread(&tipo, sizeof(unsigned short),1,f);
	//fread(&tamArquivo, sizeof(unsigned int),1,f);
	
	printf("Tam = %u ----  \n", cab_file.tamArquivo);

	printf("Tam = W%u ---- H%u\n", cab_imagem.largura_img, cab_imagem.altura_img);
	printf ("Planos: %u --- bpp: %u\n", cab_imagem.planos, cab_imagem.bits);
	
    //le_cabecalho (entrada, &cabecalho, &imagem);
    //mat = aloca_matriz(imagem);
    //le_pixels(entrada, cabecalho, imagem, mat);
    //converte_tons_cinza(mat, imagem);
    //binarizar_imagem(mat, imagem);
    //grava_arquivo_bmp(saida, cabvecalho, imagem, mat);
    //desaloca_matriz(mat, imagem);
}


int** geraMatriz (int lin, int col, FILE *arq)
{
    int linha = lin;
    int coluna = col;
    int **mat = NULL; //é um ponteiro para uma estrutura de ponteiros
    int i, j;

    printf ("Digite a largura (linhas) e a altura (colunas) : ");
    scanf ("%d %d", &linha, &coluna);

    mat = (int **)malloc(coluna*sizeof(int*));
    for (i=0; i<coluna; i++)
    {
        mat[i] = (int *)malloc(coluna*sizeof(int));
    }

    for (i=0; i<linha; i++)
        for(j=0; j<coluna; j++)
        {
            mat[i][j] = rand()%1000;
        }

    for (i=0; i<linha; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return mat;
}
