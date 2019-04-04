#include <stdio.h>

typedef struct
{
	char nome[50];
	int tamanho;
}App;
int main(){
FILE *dados;
 App test[15], app[15] = {
{"facebook", 32}, 
{"twiter", 20},		
{"messenger", 5},		
{"whatsapp", 10},		
{"github", 55},
{"stackoverflow", 42},
{"instagram", 16},
{"Google", 60},
{"tech-in", 100},
{"pytube", 13},
{"crunchyroll", 18},
{"Udemy", 23},
{"Linkedln", 32},
{"Jers687", 687},
{"legends", 200}
};
dados = fopen("dados.txt", "wb");
fwrite(&app,sizeof(App),15, dados);
fclose(dados);
	return 0;}