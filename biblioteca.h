#ifndef PROJETO_1_BIBLIOTECA_H
#define PROJETO_1_BIBLIOTECA_H


typedef struct tarefa { // struct com as variaveis para cada tarefa
  int prioridade; // variavel para armazenar o conteudo relacionado a prioridade
  char descricao[300]; // variavel para armazenar o conteudo relacionado a descricao
  char categoria[100]; // variavel para armazenar o conteudo relacionado a categoria
  int estado; // variavel para armazenar o conteudo relacionado a estado
  int num; // variavel para armazenar o conteudo relacionado ao numero da tarefa
} Tarefa;


typedef struct { // struct com a lista de tarefas
  Tarefa t[100]; // lista de tarefas, sendo 100 o limite
  int qtd;       // numero de tarefas na lista
} ListadeTarefas;

int buscaTarefa(ListadeTarefas lt, int numTarefa); // funcao de buscar a tarefa a partir do seu numero

int criarTarefa(ListadeTarefas *lt);   // funcao de criar a tarefa
int deletarTarefa(ListadeTarefas *lt); // funcao de listar as tarefas
int listarTarefas(ListadeTarefas lt);  // funcao de deletar a tarefa
int alterarTarefa(ListadeTarefas *lt); // funcao de alterar a tarefa
int filtrarPrioridade(ListadeTarefas lt); // funcao de filtrar por prioridade
int filtrarEstado(ListadeTarefas lt); // funcao de filtrar por estado
int filtrarCategoria(ListadeTarefas lt); // funcao de filtrar por categoria
int filtrarCategoriaPrioridade(ListadeTarefas lt); // funcao de filtrar por categoria e prioridade
int exportarPorPrioridade(ListadeTarefas lt); // funcao de exportar por prioridade
int exportarPorCategoria(ListadeTarefas lt); // funcao de exportar por categoria
int exportarPorPrioridadeCategoria(ListadeTarefas lt); // funcao de exportar por prioridade e categoria 

void printMenu(); // funcao de imprimir o menu com as opcoes

int salvarLista(ListadeTarefas lt, char nome[]); // funcao de salvar a lista de tarefas

int carregarLista(ListadeTarefas *lt, char nome[]); // funcao de carregar a lista de tarefas

#endif // PROJETO_1_BIBLIOTECA_H