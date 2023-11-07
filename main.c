#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

int main() {
  int cod; //
  char arquivo[] = "tarefas";
  ListadeTarefas lt;


  cod = carregarLista(&lt, arquivo); //chama a funcao de carregar a lista de tarefas
  if (cod == 1) //caso a lista estiver vazia, a quantidade é zerada
  lt.qtd = 0;
  int opcao;
  do {
    printMenu(); //imprime o menu com as funcoes
    scanf("%d", &opcao); //escanea qual a opcao que o usuario escolheu
    printf("%d\n", opcao);
    if (opcao == 0) { //caso o usuario digite "0", o loop é encerrado
    } else if (opcao == 1) { //caso o usuario digite "1", a funcao de criar tarefa é chamada
      criarTarefa(&lt);
    } else if (opcao == 2) { //caso o usuario digite "2", a funcao de deletar tarefa é chamada
      deletarTarefa(&lt);
    } else if (opcao == 3) { //caso o usuario digite "3", a funcao de listar as tarefas é chamada
      listarTarefas(lt);
    } else if (opcao == 4) { //caso o usuario digite "4", a funcao de alterar as tarefas é chamada
      alterarTarefa(&lt);
    } else if (opcao == 5) { //caso o usuario digite "5", a funcao de filtrar por prioridade é chamada
      filtrarPrioridade(lt);
    } else if (opcao == 6) { //caso o usuario digite "6", a funcao de filtrar por estado é chamada
      filtrarEstado(lt);
    } else if(opcao == 7){ //caso o usuario digite "7", a funcao de filtrar por categoria é chamada
      filtrarCategoria(lt);
    } else if(opcao == 8){ //caso o usuario digite "8", a funcao de filtrar por categoria e prioridade é chamada
      filtrarCategoriaPrioridade(lt);
    } else if(opcao == 9){ //caso o usuario digite "9", a funcao de exportar por prioridade é chamada
      exportarPorPrioridade(lt);
    } else if(opcao == 10){ //caso o usuario digite "10", a funcao de exportar por categoria é chamada
      exportarPorCategoria(lt);
    } else if(opcao == 11){ //caso o usuario digite "11", a funcao de exportar por prioridade e categoria é chamada
      exportarPorPrioridadeCategoria(lt);
    } else { //caso o usuario digite qualquer outro numero, o loop é reiniciado e imprime a mensagem de opcao inexistemte
      printf("Opcao nao existente!\n");
    }

  } while (opcao != 0); //encerra o loop quando o usuario digita "0"

  cod = salvarLista(lt, arquivo); //chama a funcao de salvar a lista de tarefas
  if (cod != 0) //se a funcao de salvar lista nao retornar 0, imprime a mensagem de erro
    printf("Erro ao salvar as tarefas");
}
