#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "m2pqi.h"

int contarLinhas(FILE *fpi){
    int cont = 0;
    char aux[999];
    while(fgets(aux, sizeof(aux), fpi)) {
        cont++;
    }
    fclose(fpi);
    return cont;
}

FILE *gravarSDF(){

    //cria ou abre um arquivo existente na mesma pasta do programa para gravacao
	FILE *fpo = fopen("output.sdf","w");
    return fpo;
	}

FILE *gravarMSP(){

    //cria ou abre um arquivo existente na mesma pasta do programa para gravacao
	FILE *fpo = fopen("output.msp","w");
    return fpo;
	}

FILE *lerArquivo(){

    //abre um arquivo existente na mesma pasta do programa para leitura
	FILE *fpi=fopen("input.txt","r");
    return fpi;
}

void carregarDados(FILE *fpi,FILE *sdf,FILE *msp) {

    char aux[999],*p,strCopia[999];
    int flag = 0, np = 0, numeroLinhas = contarLinhas(lerArquivo(fpi)), cont = 0;
    while(fgets(aux, sizeof(aux), fpi)) {
        /* note como não precisamos especificar uma nova linha, o fgets já a inclui na string linha quando a encontra */
        cont++;
//        system("cls");
        printf("Gravando arquivo SDF e MSP: %d total de linhas / %d linhas processadas\n",numeroLinhas,cont);
        if(strncmp(aux,">  <NAME>",9) == 0){
            fprintf(sdf,"%s\n","M  END");
            fprintf(msp,"\n%s\n","Name: ");
            fprintf(sdf,"\n%s\n","> <GENERIC_NAME>");
        }
        else if(strncmp(aux,">  <ID>",7) == 0){
            fprintf(sdf,"%s\n","> <DATABASE_ID>");
            fprintf(msp,"%s","DATABASE_ID: ");
            flag++;
        }
        else if(strncmp(aux,"SMILES",6) == 0){
            p=&aux[7];
            p[strlen(p)-1]='\0';
            strcpy(strCopia,p);
        }
        else if(strncmp(aux,">  <PRECURSOR TYPE>",19) == 0){
            fprintf(sdf,"%s\n","> <PRECURSOR TYPE>");
            fprintf(msp,"%s","Precursor_type: ");
            flag++;
        }
        else if(strncmp(aux,">  <NUM PEAKS>",14) == 0){
            //imprime smiles copiado da sessao coments
            fprintf(sdf,"\n%s","> <SMILES>");
            fprintf(sdf,"\n%s\n\n",strCopia);
            //imprime numero de picos
            fprintf(sdf,"%s\n","> <NUM PEAKS>");
            fprintf(msp,"%s","Num Peaks: ");
            flag--;
        }
        else if(strncmp(aux,">  <PRECURSOR M/Z>",18) == 0){
            fprintf(sdf,"%s\n","> <PRECURSOR M/Z>");
            fprintf(msp,"%s","PrecursorMZ: ");
            flag++;
        }
        else if(strncmp(aux,">  <FORMULA>",12) == 0){
            fprintf(sdf,"%s\n","> <FORMULA>");
            fprintf(msp,"%s","Formula: ");
            flag++;
        }
        else if(strncmp(aux,">  <MASS SPECTRAL PEAKS>",24) == 0){
            flag = np;
        }
        else{
            fprintf(sdf,"%s",aux);
            if(flag > 0){
                fprintf(msp,"%s",aux);
                flag--;
            }
            if(flag < 0){
                fprintf(msp,"%s",aux);
                np = atoi(aux);
                flag++;
            }
        }
    }
	//fecha o arquivo
	fclose(fpi);
	fclose(sdf);
	fclose(msp);
}
