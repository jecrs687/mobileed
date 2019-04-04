#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 15


typedef struct
{
	char nome[50];
	int tamanho;
}App;

typedef struct
{
	char nome[4];
	char original[50];
}Abr;

int remover(App app[MAX], Abr abr[MAX],char nome[50]){
	int x,c,y,t,z;			
		for(z=0;z<strlen(nome);z++){
		nome[z]=tolower(nome[z]);}
	for(x=0;x<MAX;x++){
		if(strcmp(abr[x].nome, nome)==0){
			for(t=0;t<MAX;t++){
			if(strcmp(abr[x].original,app[t].nome)==0){	
			for(c=0;c+t<MAX;c++){
				app[c+t]=app[c+t+1];}
			if(app[MAX-1].tamanho == -1){
					for(y=0;y<MAX;y++){
						if(app[y+1].tamanho == -1){
							app[y].tamanho = -1;
						}
					}
				}else{app[MAX-1].tamanho = -1;}
			return 1;}}}else if(strcmp(nome,app[x].nome)==0)
		{
			for(c=0;c+x<MAX;c++){
				app[c+x]=app[c+x+1];}
				for(y=0;y<MAX;y++){
				if(app[y+1].tamanho == -1){
				app[y].tamanho = -1;
						}
					}
				return 1;}
		}
		return 0;
	}
	
void ler_banco(App app[MAX]){
	int x,y,c,z;
	App temp;
	FILE *dados;
	char banco[30];
	do{do{do{printf("insira o nome do banco de dados:");
	scanf("%s", banco);
	system("cls");
	dados = fopen(banco, "rb");
	if(dados == NULL){printf("Nao existe este arquivo de dados\n");}}while(dados==NULL);
	for(x=0;x<MAX;x++){
		fread(&temp, sizeof(App),1, dados); 
		for(z=0;z<strlen(temp.nome);z++){
		temp.nome[z]=tolower(temp.nome[z]);}
		for(y=0;y<MAX;y++){
			if(temp.tamanho < app[y].tamanho ||  app[y].tamanho ==-1)
			{ 	
			for(c=MAX-1;c>y;c--){
					app[c] = app[c-1];
				}
				app[y] = temp;
				break;
			}
		}
	}
	fread(&temp, sizeof(App), 1,dados);
	if(!feof(dados)){printf("ocorreu um erro na leitura\n");}
	}while(!feof(dados));
	y=0;
	for(x=0;x<MAX;x++){
	if((app[x]).tamanho < 0){printf("O arquivo esta conrrompido com aplicativos de tamanho impossiveis\n por favor inserir novo arquivo\n"); y=1;}}
	}while(y==1);
	fclose(dados);
}

int listar(App app[MAX], Abr abr[MAX], int tamanho){
	int x,y,w=0,d[3],c=0;
	for(x=0;x<MAX;x++){
		abr[x].nome[0]='\0';
	}
	
	
	for(x=0; x<MAX; x++){
		if((app[x]).tamanho != -1){
			for(y=0; y<MAX;y++){
			d[0] = 0; d[1] = 1; d[2] =2;
				if(x!=y){	
					if((app[x]).tamanho>(app[y]).tamanho){
						while((app[x]).nome[d[0]] == (app[y]).nome[0] && (app[x]).nome[d[1]] == (app[y]).nome[0] && (app[x]).nome[d[2]] == (app[y]).nome[0])
						{
						d[2]++;
						}
					}			
			}				
		}
		strncpy((abr[x]).nome, app[x].nome, 3);
		strncpy((abr[x]).original, app[x].nome, 50);
		
		if(tamanho==0){
		    (abr[x]).nome[2] = (app[x]).nome[d[2]];     
			(abr[x]).nome[3] = '\0';                                                                                 
			printf("%s", abr[x].nome);
			printf("\t");
			w++;}else{		    
			(abr[x]).nome[2] = (app[x]).nome[d[2]];     
			(abr[x]).nome[3] = '\0';                                                                                 
			printf("%s-%d", abr[x].nome, (app[x]).tamanho);
			printf("\t");
			w++;}
			if(w==3){w=0;printf("\n");}
				c=1;
		}
		
	}
	if(c==0){printf("nenhum aplicativo");}return c;
}

void inserir(App app[MAX], Abr abr[MAX], char nome[50], App next[MAX],char mensagem[2000]){
		int x, y,c,z;			
		for(z=0;z<strlen(nome);z++){
		nome[z]=tolower(nome[z]);}
		for(x=0;x<MAX;x++){
		for(y=0;y<MAX;y++){
		if(strcmp(nome,next[x].nome)==0){		
		strcpy(mensagem, "O aplicativo ja esta instalado");
		mensagem[sizeof("o aplicativo ja esta instalado")]='\0';
		return;
		}else if(strcmp(abr[x].nome, nome)==0){
		if(strcmp(abr[x].original, next[y].nome)==0){			
		strcpy(mensagem, "O aplicativo ja esta instalado");
		mensagem[sizeof("o aplicativo ja esta instalado")]='\0';
		return;}}}}
		
		for(x=0;x<MAX;x++)
		if(strcmp(abr[x].nome, nome)==0){	
		for(y=0;y<MAX;y++){
			if(app[x].tamanho < next[y].tamanho ||  next[y].tamanho ==-1)
			{ 	
			for(c=MAX-1;c>y;c--){
					next[c] = next[c-1];
				}
				next[y] = app[x];
		strcpy(mensagem, "instalado com sucesso");
		mensagem[sizeof("instalado com sucesso")]='\0';
				return;
			}
		}	

		}else if(nome==app[x].nome)
		{
		for(y=0;y<MAX;y++){
if(app[x].tamanho < next[y].tamanho ||  next[y].tamanho ==-1)
			{ 	
			for(c=MAX-1;c>y;c--){
					next[c] = next[c-1];
				}
				next[y] = app[x];
		strcpy(mensagem, "instalado com sucesso");
		mensagem[sizeof("instalado com sucesso")]='\0';
				return;
			}}}		strcpy(mensagem, "O aplicativo nao existe");
		mensagem[sizeof("o aplicativo nao existe")]='\0';
			return;}


int menu_listar(App StoreED[MAX], App app[MAX], App RunED[MAX], Abr abr[MAX], int x, char mensagem[2000]){
char aplicativo[50];
int c,existir,d;
system("cls");
printf("%s\n", mensagem);
if(x==1){
printf("--------StoreED-------\n");
printf("[3]MeusAppsED [4]AppRumED [5]Sair\n");
printf("----------------------\n");
existir = listar(StoreED, abr,0);
printf("\n-----------------------\n");
if(existir==1){printf("[0]instalar  [1]remover\n");}
printf("\nEscolha uma opcao:");
scanf("%d", &c);
switch(c)
{
case 0:
	if(existir==1){
	printf("Qual aplicativo voce deseja instalar?");
	scanf("%s", aplicativo);
	inserir(StoreED, abr, aplicativo, app, mensagem);
	return 1;}
	break;
case 1:
if(existir==1){
	printf("Qual aplicativo voce deseja remover?");
	scanf("%s", aplicativo);
	d = remover(StoreED, abr, aplicativo);
	if(d==0){strcpy(mensagem, "O aplicativo nao existe");
		mensagem[sizeof("o aplicativo nao existe")]='\0';}
	else if(d==1){strcpy(mensagem, "O aplicativo foi removido com sucesso");
		mensagem[sizeof("o aplicativo doi removido com sucesso")]='\0';}
	remover(app, abr,aplicativo);
	remover(RunED,abr,aplicativo);
	return 1;}
	break;
case 3:
	mensagem[0] = '\0';
	return 2;
case 4:
	mensagem[0] = '\0';
return 3;
case 5:
	exit(0);
default:
	break;
}
}else if(x==2)
{
printf("------------MeusAppsED---------\n");
printf("[2]StoreED [4]AppRumED [5]Sair\n");
printf("-------------------------\n");
existir = listar(app, abr,1);
printf("\n-------------------------");
if(existir==1){printf("\n[0]iniciar [1]remover\n");}
printf("\nEscolha uma opcao:");
scanf("%d", &c);
switch(c)
{
case 0:
	if(existir==1){
	printf("Qual aplicativo voce deseja iniciar?");
	scanf("%s", aplicativo);
	inserir(app, abr, aplicativo, RunED, mensagem);
	return 2;}
	break;
case 1:
	if(existir==1){
	printf("Qual aplicativo voce deseja desinstalar?");
	scanf("%s", aplicativo);
	d = remover(app, abr, aplicativo);
		if(d==0){strcpy(mensagem, "O aplicativo nao existe");
		mensagem[sizeof("o aplicativo nao existe")]='\0';}
	else if(d==1){strcpy(mensagem, "O aplicativo foi removido com sucesso");
		mensagem[sizeof("o aplicativo doi removido com sucesso")]='\0';}
	remover(RunED,abr,aplicativo);
	return 2;}
	break;
case 2:
	mensagem[0] = '\0';
	return 1;
case 4:
	mensagem[0] = '\0';
return 3;
case 5:
	exit(0);
default:
	break;
}}else if(x==3)
{
printf("-----------AppRumED-----------\n");
printf("[2]StoreED [3]MeusAppsED [5]Sair\n");
printf("--------------------------\n");
existir = listar(RunED, abr,0);
printf("\n--------------------------");
if(existir==1){printf("\n[1]remover\n");}
printf("\nEscolha uma opcao:");
scanf("%d", &c);
switch(c)
{

case 1:
	if(existir==1){
	printf("Qual aplicativo voce deseja parar?");
	scanf("%s", aplicativo);
	d = remover(RunED, abr, aplicativo);
		if(d==0){strcpy(mensagem, "O aplicativo nao existe");
		mensagem[sizeof("o aplicativo nao existe")]='\0';}
	else if(d==1){strcpy(mensagem, "O aplicativo foi removido com sucesso");
		mensagem[sizeof("o aplicativo doi removido com sucesso")]='\0';}
	return 3;}
	break;
case 2:
	mensagem[0] = '\0';
	return 1;
case 3:
	mensagem[0] = '\0';
return 2;
case 5:
	exit(0);
default:
	break;
}}
strcpy(mensagem, "Por favor digite um valor valido");
mensagem[sizeof("Por favor digite um valor valido")]='\0';
return x;}

void zerar(App StoreED[MAX],App app[MAX],App RunED[MAX], Abr abr[MAX]){
	int x;
	for(x=0; x<MAX; x++){
		(StoreED[x]).tamanho = -1;
		(app[x]).tamanho = -1;
		(RunED[x]).tamanho = -1;
		(StoreED[x]).nome[0] = '\0';
		(app[x]).nome[0] = '\0';
		(RunED[x]).nome[0] = '\0';
		
	}
	
}


int main(){
	int x=1;
	char mensagem[2000];
	mensagem[0]='\0';
App StoreED[MAX], MeusAppsED[MAX], AppRumED[MAX];
Abr abr[MAX];
zerar(StoreED, MeusAppsED,AppRumED, abr);
ler_banco(StoreED);
while(1){x = menu_listar(StoreED, MeusAppsED, AppRumED, abr,x, mensagem);}


return 0;	
}