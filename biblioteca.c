#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

int buscaTarefa(ListadeTarefas lt, int numTarefa){ // funcao de buscar a tarefa a partir do seu numero
  int index = 0;
  for (index; index < 100; index++){ // percorre por toda a lista de tarefas ate achar o numero digitado
    if (lt.t[index].num == numTarefa){
    return index; // retorna o index da tarefa
    }  
  }
  return -1; // caso nao encontre, retorna -1
  }

int criarTarefa(ListadeTarefas *lt) {
  printf("\nCriar tarefa\n");
  printf("\nPrioridade da Tarefa (0 - 10): ");
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
  printf("\nEstado da Tarefa (1 = Completo | 2 = Em andamento | 3 = Nao iniciado): ");
  scanf("%d", &lt->t[lt->qtd].estado); //escanea o estado que o usuario digitou
  
  lt->t[lt->qtd].num = lt->qtd + 1; //iguala o numero do lembrete a 1 a mais que seu index na lista
  
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
    printf("\nLembrete %d:\n", lt.t[i].num);
    printf("Prioridade: %d\n", lt.t[i].prioridade);
    printf("Categoria: %s\n", lt.t[i].categoria);
    printf("Descricao: %s\n", lt.t[i].descricao);
    if (lt.t[i].estado == 1){ //se o estado for igual a 1, imprime como completo
      printf("Estado: Completo\n");
    }
    else if(lt.t[i].estado == 2){ //se o estado for igual a 2, imprime como em andamento
      printf("Estado: Em andamento\n");
    }
    else if(lt.t[i].estado == 3){ //se o estado for igual a 3, imprime como nao iniciado
      printf("Estado: Nao iniciado\n");
    }
  }
  return 0;
}

int alterarTarefa(ListadeTarefas *lt){
  printf("\nAlterar tarefa\n");
  int numTarefa;
  printf("\nDigite o numero da tarefa que deseja alterar: ");
  scanf("%d", &numTarefa);

  int index = buscaTarefa(*lt, numTarefa);
  if (index == -1){ //caso o numero da tarefa nao seja encontrado, imprime a mensagem de numero invalido
    printf("\nNumero invalido!\n");
  }
  else {
    int opcao;
    printf("\n[1] Alterar prioridade\n[2] Alterar categoria\n[3] Alterar descricao\n[4] Alterar estado\n[0] Sair\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    if (opcao == 0){
      return 0;
    }
    else if (opcao == 1){
      printf("\nDigite a nova prioridade: ");
      scanf("%d", &lt->t[index].prioridade);
    }
    else if (opcao == 2){
      int c;
      while ((c = getchar()) != '\n' && c != EOF) { }
      printf("\nDigite a nova categoria: ");
      fgets(lt->t[index].categoria, 100, stdin);
      lt->t[index].categoria[strcspn(lt->t[index].categoria, "\n")] = '\0';
    }
    else if (opcao == 3){
      int c;
      while ((c = getchar()) != '\n' && c != EOF) { }
      printf("\nDigite a nova descricao: ");
      fgets(lt->t[index].descricao, 300, stdin);
      lt->t[index].descricao[strcspn(lt->t[index].descricao, "\n")] = '\0';
    }
    else if (opcao == 4){
      printf("\nDigite o novo estado (1 = Completo | 2 = Em andamento | 3 = Nao iniciado): ");
      scanf("%d", &lt->t[index].estado);
    }
    else{
      printf("\nOpcao invalida!\n");
    }
  }
  printf("\nTarefa alterada com sucesso!\n");
  return 0;
}

int filtrarPrioridade(ListadeTarefas lt){
  int numPrioridade;
  printf("Digite a prioridade: ");
  scanf("%d", &numPrioridade);
  for (int i = 0; i < lt.qtd; i++){
    if (lt.t[i].prioridade == numPrioridade){
      printf("\nLembrete %d:\n", lt.t[i].num);
      printf("Prioridade: %d\n", lt.t[i].prioridade);
      printf("Categoria: %s\n", lt.t[i].categoria);
      printf("Descricao: %s\n", lt.t[i].descricao);
      if (lt.t[i].estado == 1){ //se o estado for igual a 1, imprime como completo
        printf("Estado: Completo\n");
      }
      else if(lt.t[i].estado == 2){ //se o estado for igual a 2, imprime como em andamento
        printf("Estado: Em andamento\n");
      }
      else if(lt.t[i].estado == 3){ //se o estado for igual a 3, imprime como nao iniciado
        printf("Estado: Nao iniciado\n");
    }
    }
  }
}
  
void printMenu() { //imprime o menu com as opcoes
  printf("\nMenu:\n[1] Criar Tarefa\n[2] Deletar Tarefa\n[3] Listar Tarefas\n[4] Alterar Tarefa\n[5] Filtrar por Prioridade\n[0] Sair\nEscolha uma opcao: ");
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

