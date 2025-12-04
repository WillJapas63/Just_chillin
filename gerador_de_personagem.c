#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_personagens 100
#define max_strings 30


struct personagens {
  int id;
  char nome [max_strings];
  int vida;
  int dano;
  char habilidade[max_strings];
  int ability_lvl;
  int moedas;
  int level;
};

void limpar_buffer();
void lines();
void entrada_personagens(struct personagens *json, int *herois);
void ver_persongens();


int main (){
  struct personagens *json;
  json = calloc(max_personagens, sizeof(struct personagens));

  int herois = 0;
  int opcao;

  do{
    lines();
    printf("\nGerador de personagens\n");
    lines();
    printf("A seguir, faça sua escolha\n\n");
    printf("1. Entrada de personagens\n");
    printf("2. Ver personagens (json)\n");
    printf("3. Sair !\n");
    scanf("%d",&opcao);
    limpar_buffer();

switch(opcao){
  case 1:
  if(herois >= max_personagens){
    printf("Personagens maximos excedidos a historia vai ficar muito grande\n");
  }else{
    entrada_personagens(json, &herois);
  }
  break;

  case 2:
  if(herois == 0){
    printf("Nenhum personagem registrado ainda!");
  }else{
    for (int i = 0; i < herois; i++){
      printf("    {\n");
      printf("        \"id\":%d,\n", json[i].id);
      printf("        \"nome\":\"%s\",\n", json[i].nome);
      printf("        \"vida\":%d,\n", json[i].vida);
      printf("        \"dano\":%d,\n", json[i].dano);
      printf("        \"habilidade\":\"%s\",\n", json[i].habilidade);
      printf("        \"ability_lvl\":%d,\n", json[i].ability_lvl);
      printf("        \"moedas\":%d,\n", json[i].moedas);
      printf("        \"level\":%d,\n", json[i].level);
      printf("    },\n");

    }
  }

}





  }while (opcao != 3);
  return 0;
}


void limpar_buffer(){
  int c;
  while ((c = getchar())!= '\n' && c != EOF);
}

void lines(){
  printf("\n----------------------------\n");
}



void entrada_personagens(struct personagens *json, int *herois){
  int i = *herois;
  
    json[i].id = i + 1;
    printf("Nome: ");
    fgets(json[i].nome, max_strings, stdin);
    json[i].nome[strcspn(json[i].nome, "\n")] = '\0';
    printf("Vida: ");
    scanf("%d", &json[i].vida);
    limpar_buffer();
    printf("Dano: ");
    scanf("%d", &json[i].dano);
    limpar_buffer();
    printf("Habilidade: ");
    fgets(json[i].habilidade, max_strings, stdin);
    json[i].habilidade[strcspn(json[i].habilidade, "\n")] = '\0';
    printf("ability lvl: ");
    scanf("%d", &json[i].ability_lvl);
    limpar_buffer();
    printf("moedas: ");
    scanf("%d", &json[i].moedas);
    limpar_buffer();
    printf("level: ");
    scanf("%d", &json[i].level);
    limpar_buffer();
    printf("Herói registrado com sucesso\n");

    (*herois)++;
}
