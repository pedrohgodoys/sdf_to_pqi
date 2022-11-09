#include <stdio.h>
#include <stdlib.h>
#include "m2pqi.h"

//o programa principal carrega os dados ou cria o arquivo registro.txt e chama o menu inicial
int main() {

	carregarDados(lerArquivo(),gravarSDF(),gravarMSP());
	return 0;

}
