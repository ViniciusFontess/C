#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Constantes */
#define ERROR_FILE_MSG "Nao foi possivel abrir o arquivo!\n"
#define INVALID_OPTION "Opcao invalida! Tente novamente!"

/* Definicoes de tipo */
enum boolean
{
	FALSO = 0,
	VERDADEIRO = 1
};

/* Prototipos */
FILE *carregue(char quadro[9][9]);
FILE *carregue_continue_jogo(char quadro[9][9], char *nome_arquivo);
void carregue_novo_jogo(char quadro[9][9], char *nome_arquivo);
FILE *crie_arquivo_binario(char quadro[9][9]);
int determine_quadrante(int x, int y);
int eh_valido(const char quadro[9][9], int x, int y, int valor);
int eh_valido_na_coluna(const char quadro[9][9], int y, int valor);
int eh_valido_no_quadrante3x3(const char quadro[9][9], int x, int y, int valor);
int eh_valido_na_linha(const char quadro[9][9], int x, int valor);
int existe_posicao_vazia(const char quadro[9][9]);
void imprima(const char quadro[9][9]);
void jogue();
void resolve_completo(FILE *, char quadro[9][9]);
void resolve_um_passo(char quadro[9][9]);
void salve_jogada_bin(FILE *fb, char quadro[9][9]);

/* Funcoes auxiliares */
int fim_x(int quadr);
int fim_y(int quadr);
int leia_opcao();
void gen_random(char *s, const int len);
int ini_x(int quadr);
int ini_y(int quadr);
void menu();
void menu_arquivo();

/* -----------------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 * MAIN
 * /////////////////////////////////////////////////////////////////////////////
 */
int main()
{

	// inicia o jogo
	jogue();

	return 0;
}

/* -----------------------------------------------------------------------------
 * CARREGAR
 * Inicializa o SUDOKU a partir de um novo jogo ou estado de jogo anterior
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
FILE *carregue(char quadro[9][9])
{

	int opcao;
	char padrao[40] = "carregar/", nome_arquivo[20], padrao2[40] = "bin/", nome_arquivo2[20];
	FILE *arq = NULL;

	menu_arquivo();
	opcao = leia_opcao();

	switch (opcao)
	{

	case 1:
		printf("Digite o nome do arquivo txt que deseja carregar : ");
		scanf("%s", nome_arquivo);
		strcat(padrao, nome_arquivo);

		carregue_novo_jogo(quadro, padrao);

		break;

	case 2:
		printf("Digite o nome do arquivo binário que deseja continuar: ");
		scanf("%s", nome_arquivo2);
		strcat(padrao2, nome_arquivo2);

		arq = carregue_continue_jogo(quadro, padrao2);
		return arq;

	case 9:
		break;

	default:
		printf(INVALID_OPTION);
		return carregue(quadro);
	}
	return arq;
}

/* -----------------------------------------------------------------------------
 * CARREGAR CONTINUAR JOGO
 * Carrega um estado de jogo a partir de um arquivo binario
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
FILE *carregue_continue_jogo(char quadro[9][9], char *nome_arquivo)
{
	// TODO
	FILE *arquivo;
	arquivo = fopen(nome_arquivo, "rb+");

	if (arquivo == NULL)
	{
		printf(ERROR_FILE_MSG);
	}
		int numero_jogadas;
	fseek(arquivo, 0, SEEK_SET);
	fread(&numero_jogadas, sizeof(int), 1, arquivo);
	printf("O total do número de jogadas foi de: %d\n", numero_jogadas);

	// Variável para iterar sobre cada quadro salvo e mostrar na tela
	int jogada_atual = 0;

	// Leitura e exibição de todos os quadros
	while (fread(quadro, sizeof(char), 81, arquivo) == 81)
	{
		printf("\nQuadro da Jogada %d:\n", jogada_atual);
		imprima(quadro);
		jogada_atual++;
	}

	return arquivo;

	
	}


/* -----------------------------------------------------------------------------
 * CARREGAR NOVO JOGO
 * Carrega um novo jogo do Sudoku
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void carregue_novo_jogo(char quadro[9][9], char *nome_arquivo)
{
	// TODO

	// TODO
	FILE *arquivo;
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf(ERROR_FILE_MSG);
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fscanf(arquivo, "%d", (int *)&quadro[i][j]);
			}
		}

	}
}

/* -----------------------------------------------------------------------------
 * CRIAR ARQUIVO BINARIO
 * Criar arquivo binario
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
FILE *crie_arquivo_binario(char quadro[9][9])
{
	// TODO

	char juntar[10], local[40] = "bin/";
	gen_random(juntar, 4);
	strcat(local, juntar);	
	strcat(local, ".dat");
	int n_jogadas = 0;

	FILE *f = fopen(local, "wb+");

	if (f == NULL)
	{
		printf(ERROR_FILE_MSG);
		return NULL;
	}
	else
	{
		fseek(f, 0, SEEK_SET);
		fwrite(&n_jogadas, sizeof(int), 1, f);
		fseek(f, 4, SEEK_SET);
		fwrite(quadro, sizeof(char), 81, f);
		
	}
	return f;
}

/* -----------------------------------------------------------------------------
 * DETERMINAR QUADRANTE
 * Dado as posicoes x e y, determina o quadrante do quadro
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int determine_quadrante(int x, int y)
{
	if (x < 3 && y < 3)
		return 1;
	else if (x < 3 && y < 6)
		return 2;
	else if (x < 3 && y < 9)
		return 3;
	else if (x < 6 && y < 3)
		return 4;
	else if (x < 6 && y < 6)
		return 5;
	else if (x < 6 && y < 9)
		return 6;
	else if (x < 9 && y < 3)
		return 7;
	else if (x < 9 && y < 6)
		return 8;
	else
		return 9;
}

/* -----------------------------------------------------------------------------
 * E VALIDO
 * Determina se um valor na posicao x e y eh valido
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int eh_valido(const char quadro[9][9], int x, int y, int valor)
{

	// verifica as tres condicoes
	if (!eh_valido_na_coluna(quadro, y, valor))
		return FALSO;
	if (!eh_valido_na_linha(quadro, x, valor))
		return FALSO;
	if (!eh_valido_no_quadrante3x3(quadro, x, y, valor))
		return FALSO;

	return VERDADEIRO;
}

/* -----------------------------------------------------------------------------
 * E VALIDO NA COLUNA
 * Verifica se um valor na coluna y e valido
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int eh_valido_na_coluna(const char quadro[9][9], int y, int valor)
{	//// FINALIZADO
	// TODO
	for (int i = 0; i <= 8; i++)
	{
		if (quadro[i][y] == valor){
			return FALSO;}
	}
	return VERDADEIRO;
	
}

/* -----------------------------------------------------------------------------
 * E VALIDO NA LINHA
 * Verifica se um valor na linha x e valido
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int eh_valido_na_linha(const char quadro[9][9], int x, int valor)
{ //// FINALIZADO
	// TODO
	for (int i = 0; i <= 8; i++)
	{
		if (quadro[x][i] == valor){
			return FALSO;}
	}
	return VERDADEIRO;
	
}

/* -----------------------------------------------------------------------------
 * E VALIDO NO QUADRO 3X3
 * Verifica se um valor e valido no quadrante da posicao x, y
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int eh_valido_no_quadrante3x3(const char quadro[9][9], int x, int y, int valor)
{ //// FINALIZADO
	// TODO
	int quad = determine_quadrante(x, y);
	for (int i = ini_x(quad); i <= fim_x(quad); i++)
	{
		for (int j = ini_y(quad); j <= fim_y(quad); j++)
		{
			if (quadro[i][j] == valor)
			{
				return FALSO;
			}
		}
	}
	return VERDADEIRO;
}
/* -----------------------------------------------------------------------------
 * EXISTE CAMPO VAZIO
 * Verifica se existe um campo nao preenchido
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int existe_posicao_vazia(const char quadro[9][9])
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (quadro[i][j] == 0)
				return VERDADEIRO;
		}
	}

	return FALSO;
}

/* -----------------------------------------------------------------------------
 * IMPRIMIR
 * Imprime o quadro recebido do sudoku
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void imprima(const char quadro[9][9])
{
	int i, j;

	//	puts("~~~~~~~~ SUDOKU ~~~~~~~~");
	puts("    1 2 3   4 5 6   7 8 9");
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			puts("  -------------------------");
		for (j = 0; j < 9; j++)
		{

			if (j == 0)
				printf("%d | ", i + 1);
			else if (j % 3 == 0)
				printf("| ");

			if (quadro[i][j] == 0)
				printf("- ");
			else
				printf("%d ", quadro[i][j]);
		}
		puts("|");
	}
	puts("  -------------------------");
}

/* -----------------------------------------------------------------------------
 * JOGAR
 * Realiza toda a logica do jogo
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void jogue()
{
	int opcao;
	char quadro[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0}};
	FILE *fb = NULL;

	opcao = 0;

	while (opcao != 9)
	{
		// imprima na tela o quadro atual
		imprima(quadro);

		// apresente um menu com as opcoes
		menu();
		opcao = leia_opcao();

		switch (opcao)
		{

		// carregue sudoku
		case 1:
			fb = carregue(quadro);

			if (fb == NULL)
			{
				fb = crie_arquivo_binario(quadro);
			}
			break;

		// preencha quadro com um valor
		case 2:
		{
			int x, y, valor;

			printf("Entre com a posicao e o valor (linha, coluna, valor): ");
			scanf("%d %d %d", &x, &y, &valor);

			if (eh_valido(quadro, x-1, y-1, valor))
			{
				quadro[x-1][y-1] = valor;
				salve_jogada_bin(fb, quadro);
			}
			else
				puts("Valor ou posicao incorreta! Tente novamente!");
		}
		break;

		// resolva 1 passo
		case 3:
			resolve_um_passo(quadro);
			salve_jogada_bin(fb, quadro);
			puts("Um passo resolvido!");
			break;

		// resolva o sudoku completo
		case 4:
			resolve_completo(fb, quadro);
			break;

		case 9:
			puts("Programa finalizado ..");
			fclose(fb);
			break;

		default:
			puts(INVALID_OPTION);
			break;
		}
	}
}

/* -----------------------------------------------------------------------------
 * RESOLVER
 * Resolve o sudoku
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void resolve_completo(FILE *fb, char quadro[9][9])
{
	while (existe_posicao_vazia(quadro))
	{
		resolve_um_passo(quadro);
		salve_jogada_bin(fb, quadro);
	}
}

/* -----------------------------------------------------------------------------
 * RESOLVER UM PASSO
 * Preenche apenas um campo vazio
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void resolve_um_passo(char quadro[9][9])

{
	// TODO


	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (quadro[i][j] == 0){
				int contador = 0;
				int aux = 0;
				for (int k = 1; k <= 9; k++){
					if (eh_valido(quadro, i, j, k) == VERDADEIRO){
						contador += 1;
						aux = k;
						}
					}
					if (contador == 1){
						quadro[i][j] = aux;
						return;
					}

		}
	}
}
}

/* -----------------------------------------------------------------------------
 * SALVAR JOGADA BINARIO
 * Salva o estado atual do quadro no arquivo binario
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void salve_jogada_bin(FILE *fb, char quadro[9][9])
{ 	
	int n_jogadas = 0;
    fseek(fb, 0, SEEK_SET);
    fread(&n_jogadas, sizeof(int), 1, fb);
    n_jogadas += 1;
    fseek(fb, 0, SEEK_SET);
    fwrite(&n_jogadas, sizeof(int), 1, fb);
    fseek(fb, 0, SEEK_END);
    fwrite(quadro, sizeof(char), 81, fb);    
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 							FUNCOES AUXILIARES
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/* -----------------------------------------------------------------------------
 * FIM X
 * Indice final da linha para o quadrante recebido como parametro
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int fim_x(int quadr)
{
	switch(quadr) {
		case 1:
		case 2:
		case 3:
			return 2;

		case 4:
		case 5:
		case 6:
			return 5;

		default:
			return 8;
	}
}

/* -----------------------------------------------------------------------------
 * FIM Y
 * Indice final da coluna para o quadrante recebido como parametro
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int fim_y(int quadr)
{
	switch(quadr) {
		case 1:
		case 4:
		case 7:
			return 2;

		case 2:
		case 5:
		case 8:
			return 5;

		default:
			return 8;
}
}
/* -----------------------------------------------------------------------------
 * GEN_RANDOM
 * Gera uma cadeia de caracteres randomica de tamanho len
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void gen_random(char *s, const int len)
{
	srand(time(NULL));
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; i < len; ++i)
	{
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

/* -----------------------------------------------------------------------------
 * INI X
 * Indice inicial da linha para o quadrante recebido como parametro
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int ini_x(int quadr)
{
	switch(quadr) {
		case 1:
		case 2:
		case 3:
			return 0;

		case 4:
		case 5:
		case 6:
			return 3;

		default:
			return 6;
	}
}

/* -----------------------------------------------------------------------------
 * INI Y
 * Indice inicial da coluna para o quadrante recebido como parametro
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int ini_y(int quadr)
{
	switch(quadr) {
		case 1:
		case 4:
		case 7:
			return 0;

		case 2:
		case 5:
		case 8:
			return 3;

		default:
			return 6;
	}
}

/* -----------------------------------------------------------------------------
 * LE OPCAO
 * Imprime a mensagem a faz a leitura da opcao
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int leia_opcao()
{
	int opcao;

	printf("Opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

/* -----------------------------------------------------------------------------
 * MENU
 * Imprime o menu de opcoes
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void menu()
{
	puts("\n~~~~~~~~ SUDOKU ~~~~~~~~");
	puts("[1] - Carregar jogo");
	puts("[2] - Jogar");
	puts("[3] - Resolver um passo");
	puts("[4] - Resolver");
	puts("[9] - Finalizar");
	puts("--------");
}

/* -----------------------------------------------------------------------------
 * MENU ARQUIVO
 * Imprime o menu de opcoes do arquivo
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void menu_arquivo()
{
	puts("\n~~~~~ MENU ARQUIVO ~~~~~");
	puts("[1] - Novo jogo");
	puts("[2] - Continuar jogo");
	puts("[9] - Retornar ao menu anterior");
	puts("--------");
}
