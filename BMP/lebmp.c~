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
	

}
