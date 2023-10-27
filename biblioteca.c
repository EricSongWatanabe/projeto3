#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

int criarTarefa(ListadeTarefas *lt) {
    printf("\nCriar tarefa\n");
    printf("\nQual a prioridade (0 - 10): ");
    scanf("%d", &lt->t[lt->qtd].prioridade); //escanea a prioridade que o usuario digitou
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
    printf("\nCategoria da Tarefa: ");
    fgets(lt->t[lt->qtd].categoria, 100, stdin); //escanea a categoria que o usuario digitou
    lt->t[lt->qtd].categoria[strcspn(lt->t[lt->qtd].categoria, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
//    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nDescricao da Tarefa: ");
    fgets(lt->t[lt->qtd].descricao, 300, stdin);//escanea a descricao que o usuario digitou
    lt->t[lt->qtd].descricao[strcspn(lt->t[lt->qtd].descricao, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
    lt->qtd = lt->qtd + 1; //aumenta em 1 a quantidade de tarefas na lista
    return 0;
}

int deletarTarefa(ListadeTarefas *lt) {
    printf("\nDeletar tarefa\n");
    if(lt->qtd == 0){ //caso a quantidade de tarefas na lista for 0, imprime a mensagem de lista vazia
        printf("A lista de tarefas esta vazia. Nao ha nada para deletar.\n");
        return 0;
    }
    printf("\nDigite o numero do lembrete: ");
    int numLembrete;
    scanf("%d", &numLembrete); //escanea qual o lembrete (a tarefa) que o usuario deseja deletar

    if (numLembrete < 1 || numLembrete > lt->qtd){ //caso o numero do lembrete nao for encontrado, imprime a mensagem de numero invalido
        printf("\nNumero invalido!\n");
    } else{ //caso o numero do lembrete é encontrado
        for (int i = numLembrete - 1; i < lt->qtd - 1; i++){ //seleciona todos os lembretes a partir do numero escolhido
            lt->t[i] = lt->t[i + 1];//substitui todos os lembretes criados apos o lembrete do numero digitado pelo lembrete posterior a eles
        }
        lt->qtd--; //diminui em 1 a quantidade de tarefas na lista de tarefas
        printf("\nLembrete %d deletado com sucesso!\n", numLembrete); //imprime a mensagem de sucesso ao deletar o lembrete (tarefa)
    }
    return 0;
}

int listarTarefas(ListadeTarefas lt) {
    printf("\nListar tarefas\n");
    for (int i = 0; i < lt.qtd; i++){ //para cada struct de tarefa, imprime cada uma de suas variaveis com seus valores
        printf("\nLembrete %d:\n", i + 1);
        printf("Prioridade: %d\n", lt.t[i].prioridade);
        printf("Categoria: %s\n", lt.t[i].categoria);
        printf("Descricao: %s\n", lt.t[i].descricao);
    }
    return 0;
}

void printMenu() { //imprime o menu com as opcoes
    printf("\nMenu:\n[1] Criar Tarefa\n[2] Deletar Tarefe\n[3] Listar Tarefas\nEscolha uma opcao: ");
}

int salvarLista(ListadeTarefas lt, char arquivo[]){
    FILE *f = fopen(arquivo, "wb"); //abre o arquivo em binario com a funcao de digitar
    if (f == NULL){ //caso o arquivo nao consiga ser aberto ou criado, retorna a mensagem de erro
        return 1;
    }
    fwrite(&lt, sizeof(ListadeTarefas), 1, f); //escreve a lista de tarefas no arquivo
    fclose(f); //fecha o arquivo
    return 0;
}

int carregarLista(ListadeTarefas *lt, char arquivo[]){
    FILE *f = fopen(arquivo, "rb"); //abre o arquivo em binario com a funcao de ler
    if (f == NULL){ //caso o arquivo nao consiga ser aberto, retorna o valor para zerar a quantidade de tarefas
        return 1;
    }
    fread(lt, sizeof(ListadeTarefas), 1, f); //le a lista de tarefas no arquivo
    fclose(f); //fecha o arquivo
    return 0;
}