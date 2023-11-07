#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
// 06/11/2023 15:43

int buscaTarefa(
    ListadeTarefas lt,
    int numTarefa) { // funcao de buscar a tarefa a partir do seu numero
  for (int index = 0; index < 100; index++) { // percorre por toda a lista de tarefas ate achar o numero digitado
    if (lt.t[index].num == numTarefa) {
      return index; // retorna o index da tarefa
    }
  }
  return -1; // caso nao encontre, retorna -1
}

int criarTarefa(ListadeTarefas *lt) {
  printf("\nCriar tarefa\n");
  printf("\nPrioridade da Tarefa (0 - 10): ");
  scanf("%d", &lt->t[lt->qtd].prioridade); // escanea a prioridade que o usuario digitou
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {} // limpa o buffer
  printf("\nCategoria da Tarefa: ");
  fgets(lt->t[lt->qtd].categoria, 100, stdin); // escanea a categoria que o usuario digitou
  lt->t[lt->qtd].categoria[strcspn(lt->t[lt->qtd].categoria, "\n")] = '\0'; // substitui o "\n" no final da sentenca por um "\0"
  // while ((c = getchar()) != '\n' && c != EOF) { }
  printf("\nDescricao da Tarefa: ");
  fgets(lt->t[lt->qtd].descricao, 300, stdin); // escanea a descricao que o usuario digitou
  lt->t[lt->qtd].descricao[strcspn(lt->t[lt->qtd].descricao, "\n")] == '\0'; // substitui o "\n" no final da sentenca por um "\0"
  printf("\nEstado da Tarefa (1 = Completo | 2 = Em andamento | 3 = Nao iniciado): ");
  scanf("%d", &lt->t[lt->qtd].estado); // escanea o estado que o usuario digitou
  lt->t[lt->qtd].num = lt->qtd + 1; // iguala o numero do lembrete a 1 a mais que seu index na lista

  lt->qtd = lt->qtd + 1; // aumenta em 1 a quantidade de tarefas na lista
  return 0;
}

int deletarTarefa(ListadeTarefas *lt) {
  printf("\nDeletar tarefa\n");
  if (lt->qtd == 0) { // caso a quantidade de tarefas na lista for 0, imprime a mensagem de lista vazia
    printf("A lista de tarefas esta vazia. Nao ha nada para deletar.\n");
    return 0;
  }
  printf("\nDigite o numero do lembrete: ");
  int numLembrete;
  scanf("%d", &numLembrete); // escanea qual o lembrete (a tarefa) que o usuarion deseja deletar

  if (numLembrete < 1 ||
      numLembrete > lt->qtd) { // caso o numero do lembrete nao for encontrado, imprime a mensagem de numero invalido
    printf("\nNumero invalido!\n");
  } else { // caso o numero do lembrete é encontrado
    for (int i = numLembrete - 1; i < lt->qtd - 1; i++) { // seleciona todos os lembretes a partir do numero escolhido
      lt->t[i] = lt->t[i + 1]; // substitui todos os lembretes criados apos o lembrete do numero digitado pelo lembrete posterior a eles
    }
    lt->qtd--; // diminui em 1 a quantidade de tarefas na lista de tarefas
    printf("\nLembrete %d deletado com sucesso!\n", numLembrete); // imprime a mensagem de sucesso ao deletar o lembrete (tarefa)
  }
  return 0;
}

int listarTarefas(ListadeTarefas lt) {
  printf("\nListar tarefas\n");
  for (int i = 0; i < lt.qtd; i++) { // para cada struct de tarefa, imprime cada uma de suas variaveis com seus valores
    printf("\nLembrete %d:\n", lt.t[i].num);
    printf("Prioridade: %d\n", lt.t[i].prioridade);
    printf("Categoria: %s\n", lt.t[i].categoria);
    printf("Descricao: %s", lt.t[i].descricao);
    if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
      printf("Estado: Completo\n");
    } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
      printf("Estado: Em andamento\n");
    } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
      printf("Estado: Nao iniciado\n");
    }
  }
  return 0;
}

int alterarTarefa(ListadeTarefas *lt) {
  printf("\nAlterar tarefa\n");
  int numTarefa;
  printf("\nDigite o numero da tarefa que deseja alterar: ");
  scanf("%d", &numTarefa);

  int index = buscaTarefa(*lt, numTarefa);
  if (index == -1) { // caso o numero da tarefa nao seja encontrado, imprime a mensagem de numero invalido
    printf("\nNumero invalido!\n");
  } else {
    int opcao;
    printf("\n[1] Alterar prioridade\n[2] Alterar categoria\n[3] Alterar descricao\n[4] Alterar estado\n[0] Sair\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    if (opcao == 0) {
      return 0;
    } else if (opcao == 1) {
      printf("\nDigite a nova prioridade: ");
      scanf("%d", &lt->t[index].prioridade);
    } else if (opcao == 2) {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("\nDigite a nova categoria: ");
      fgets(lt->t[index].categoria, 100, stdin);
      lt->t[index].categoria[strcspn(lt->t[index].categoria, "\n")] = '\0';
    } else if (opcao == 3) {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("\nDigite a nova descricao: ");
      fgets(lt->t[index].descricao, 300, stdin);
      lt->t[index].descricao[strcspn(lt->t[index].descricao, "\n")] = '\0';
    } else if (opcao == 4) {
      printf("\nDigite o novo estado (1 = Completo | 2 = Em andamento | 3 = Nao iniciado): ");
      scanf("%d", &lt->t[index].estado);
    } else {
      printf("\nOpcao invalida!\n");
    }
  }
  printf("\nTarefa alterada com sucesso!\n");
  return 0;
}

int filtrarPrioridade(ListadeTarefas lt) {
  printf("\nFiltrar por Prioridade\n");
  int numPrioridade;
  printf("Digite a prioridade: ");
  scanf("%d", &numPrioridade);
  for (int i = 0; i < lt.qtd; i++) {
    if (lt.t[i].prioridade == numPrioridade) {
      printf("\nLembrete %d:\n", lt.t[i].num);
      printf("Prioridade: %d\n", lt.t[i].prioridade);
      printf("Categoria: %s\n", lt.t[i].categoria);
      printf("Descricao: %s", lt.t[i].descricao);
      if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
        printf("Estado: Completo\n");
      } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
        printf("Estado: Em andamento\n");
      } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
        printf("Estado: Nao iniciado\n");
      }
    }
  }
  return 0;
}

int filtrarEstado(ListadeTarefas lt) {
  printf("\nFiltrar por Estado\n");
  int numEstado;
  printf(
      "Digite o estado (1 = Completo | 2 = Em andamento | 3 = Nao iniciado): ");
  scanf("%d", &numEstado);
  for (int i = 0; i < lt.qtd; i++) {
    if (lt.t[i].estado == numEstado) {
      printf("\nLembrete %d:\n", lt.t[i].num);
      printf("Prioridade: %d\n", lt.t[i].prioridade);
      printf("Categoria: %s\n", lt.t[i].categoria);
      printf("Descricao: %s", lt.t[i].descricao);
      if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
        printf("Estado: Completo\n");
      } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
        printf("Estado: Em andamento\n");
      } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
        printf("Estado: Nao iniciado\n");
      }
    }
  }
  return 0;
}

int filtrarCategoria(ListadeTarefas lt) {
  printf("\nFiltrar por Categoria\n");
  char categoria[100];
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("\nDigite a categoria: ");
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int j = 10; j > -1; j--) {
    for (int i = 0; i < lt.qtd; i++) {
      int verificarCat = strcmp(lt.t[i].categoria, categoria);
      if (lt.t[i].prioridade == j) {        
        if (verificarCat == 0) {
          printf("\nLembrete %d:\n", lt.t[i].num);
          printf("Prioridade: %d\n", lt.t[i].prioridade);
          printf("Categoria: %s\n", lt.t[i].categoria);
          printf("Descricao: %s", lt.t[i].descricao);
          if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
            printf("Estado: Completo\n");
          } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
            printf("Estado: Em andamento\n");
          } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
            printf("Estado: Nao iniciado\n");
          }
        }
      }
    }
  }
  return 0;
}

int filtrarCategoriaPrioridade(ListadeTarefas lt) {
  int prioridade;
  printf("\nFiltrar por Categoria e Prioridade\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nDigite a categoria: ");
  char categoria[100];
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  printf("\nTarefas com prioridade %d e categoria %s:\n", prioridade, categoria);
  for (int i = 0; i < lt.qtd; i++) {
    if (lt.t[i].prioridade == prioridade && strcmp(lt.t[i].categoria, categoria) == 0) {
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt.t[i].prioridade);
      printf("Categoria: %s\n", lt.t[i].categoria);
      printf("Descricao: %s", lt.t[i].descricao);
      if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
        printf("Estado: Completo\n");
      } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
        printf("Estado: Em andamento\n");
      } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
        printf("Estado: Nao iniciado\n");
      }
    }
  }
  return 0;
}

int exportarPorPrioridade(ListadeTarefas lt) {
  FILE *f = fopen("export.txt", "w");
  printf("\nExportar por Prioridade\n");
  int numPrioridade;
  printf("\nDigite a prioridade: ");
  scanf("%d", &numPrioridade);
  for (int i = 0; i < lt.qtd; i++) {
    if (lt.t[i].prioridade == numPrioridade) {
      fprintf(f, "Lembrete %d:\n", lt.t[i].num);
      fprintf(f, "Prioridade: %d\n", lt.t[i].prioridade);
      fprintf(f, "Categoria: %s\n", lt.t[i].categoria);
      fprintf(f, "Descricao: %s", lt.t[i].descricao);
      if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
        fprintf(f, "Estado: Completo\n");
      } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
        fprintf(f, "Estado: Em andamento\n");
      } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
        fprintf(f, "Estado: Nao iniciado\n");
      }
      fprintf(f, "\n");
    }
  }

  fclose(f);
  return 0;
}

int exportarPorCategoria(ListadeTarefas lt){
  FILE *f = fopen("export.txt", "w");
  printf("\Exportar por Categoria\n");
  char categoria[100];
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("\nDigite a categoria: ");
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int j = 10; j > -1; j--){
    for (int i = 0; i < lt.qtd; i++){
      int verificarCat = strcmp(lt.t[i].categoria, categoria);
      if (verificarCat == 0) {
        if (lt.t[i].prioridade == j) {
          fprintf(f, "Lembrete %d:\n", lt.t[i].num);
          fprintf(f, "Prioridade: %d\n", lt.t[i].prioridade);
          fprintf(f, "Categoria: %s\n", lt.t[i].categoria);
          fprintf(f, "Descricao: %s", lt.t[i].descricao);
          if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
            fprintf(f, "Estado: Completo\n");
          } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
            fprintf(f, "Estado: Em andamento\n");
          } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
            fprintf(f, "Estado: Nao iniciado\n");
          }
          fprintf(f, "\n");
        }
      }
    }
  }
  fclose(f);
  return 0;
}

int exportarPorPrioridadeCategoria(ListadeTarefas lt){
  FILE *f = fopen("export.txt", "w");
  int prioridade;
  printf("\Exportar por Categoria e Prioridade\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nDigite a categoria: ");
  char categoria[100];
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int i = 0; i < lt.qtd; i++) {
    if (lt.t[i].prioridade == prioridade && strcmp(lt.t[i].categoria, categoria) == 0) {
      fprintf(f, "\nLembrete %d:\n", lt.t[i].num);
      fprintf(f, "Prioridade: %d\n", lt.t[i].prioridade);
      fprintf(f, "Categoria: %s\n", lt.t[i].categoria);
      fprintf(f, "Descricao: %s", lt.t[i].descricao);
      if (lt.t[i].estado == 1) { // se o estado for igual a 1, imprime como completo
        fprintf(f, "Estado: Completo\n");
      } else if (lt.t[i].estado == 2) { // se o estado for igual a 2, imprime como em andamento
        fprintf(f, "Estado: Em andamento\n");
      } else if (lt.t[i].estado == 3) { // se o estado for igual a 3, imprime como nao iniciado
        fprintf(f, "Estado: Nao iniciado\n");
      }
      fprintf(f, "\n");
    }
  }
  fclose(f);
  return 0;
}

void printMenu() { // imprime o menu com as opcoes
  printf("\nMenu:\n[1] Criar Tarefa\n[2] Deletar Tarefa\n[3] Listar Tarefas\n[4] Alterar Tarefa\n[5] Filtrar por Prioridade\n[6] Filtrar por Estado\n[7] Filtrar por Categoria\n[8] Filtrar por Categoria e Prioridade\n[9] Exportar Tarefa por Prioridade\n[10] Exportar Tarefa por Categoria\n[11] Exportar Tarefa por Prioridade e Categoria\n[0] Sair\nEscolha uma opcao: ");
}

int salvarLista(ListadeTarefas lt, char arquivo[]) {
  FILE *f = fopen(arquivo, "wb"); // abre o arquivo em binario com a funcao de digitar
  if (f == NULL) { // caso o arquivo nao consiga ser aberto ou criado, retorna a mensagem de erro
    return 1;
  }
  fwrite(&lt, sizeof(ListadeTarefas), 1, f); // escreve a lista de tarefas no arquivo
  fclose(f); // fecha o arquivo
  return 0;
}

int carregarLista(ListadeTarefas *lt, char arquivo[]) {
  FILE *f = fopen(arquivo, "rb"); // abre o arquivo em binario com a funcao de ler
  if (f == NULL) { // caso o arquivo nao consiga ser aberto, retorna o valor para zerar a quantidade de tarefas
    return 1;
  }
  fread(lt, sizeof(ListadeTarefas), 1, f); // le a lista de tarefas no arquivo
  fclose(f); // fecha o arquivo
  return 0;
}
