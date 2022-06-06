#include <stdio.h>

#define SUCESSO 0
#define ANO_ATUAL 2022
#define MES_ATUAL 5
#define QUANTIDADE_MESES 12
#define DIA_ATUAL 6
#define DIA_NO_ANO 365

void clrscr(){
    system("@cls||clear");
}

int somaXaY(int x, int y){
  int soma = 0;
  for(int i = 0; i <= (y - x); i++){
    soma += (x + i);
  }  
  return soma;
}

void questao1(){
  int x = 0, y = 0, soma = 0;
  
  printf("+---------------------------------+\n");
  printf("|  Somatorio sequencial de X a Y  |\n");
  printf("+---------------------------------+\n");
  
  printf("\n\nInforme o primeiro numero a ser somado: ");
  scanf("%i", &x);
  printf("\n\nInforme o ultimo numero a ser somado: ");
  scanf("%i", &y);

  soma = somaXaY(x,y);
  
  printf("\n\nA somatoria de %i a %i é de %i\n", x, y, soma);

  printf("\n\n");
}

void imprimeLinhaPascal(int linha){
  switch(linha){
    case 1: printf(" 1 \n");break;
    case 2: printf(" 1   1 \n");break;
    case 3: printf(" 1   2   1 \n");break;
    case 4: printf(" 1   3   3   1 \n");break;
    case 5: printf(" 1   4   6   4   1 \n");break;
    case 6: printf(" 1   5  10  10   5   1 \n");break;
    case 7: printf(" 1   6  15  20  15   6   1 \n");break;
    case 8: printf(" 1   7  21  35  35  21   7   1 \n"); break;
    default: break;
  }
  return;
}

void questao2(){
  int linha = 0;
  
  printf("+------------------------------------------------+\n");
  printf("|  Imprima até a linha N do triangulo de pascal  |\n");
  printf("+------------------------------------------------+\n");
  
  printf("\n\nAté que linha do triangulo de pascal deseja ver (1 - 8): ");
  scanf("%i", &linha);

  for (int i = 1; i <= linha; i++)
    imprimeLinhaPascal(i);

  printf("\n\n");
}

float potenciaRecursiva(float x,float y){
  if(y == 1)
    return x;
  return x * potenciaRecursiva(x,y-1);
}

float realizaOperacao(float x,char operacao,float y){
  switch(operacao){
    case '+': return x + y; break;
    case '-': return x - y; break;
    case '*': return x * y; break;
    case '/': return x / y; break;
    case '^': return potenciaRecursiva(x,y); break;
    default: break;
  }
}

void questao3(){
  float x = 0.0, y = 0.0, resultado;
  char operacao = "";
  
  printf("+----------------------------+\n");
  printf("|  Simulador de Calculadora  |\n");
  printf("+----------------------------+\n");
  
  printf("\n\nOperações Suportadas: ");
  printf("\nAdição '+'");
  printf("\nSubtração '-'");
  printf("\nMultiplicação '*'");
  printf("\nDivisão '/'");
  printf("\nPotencia '^'\n");
  printf("\nInforme um calculo a ser efetuado (X operação Y): ");
  scanf("%f %c %f", &x, &operacao, &y);

  resultado = realizaOperacao(x,operacao,y);
  
  printf("\nResultado de %.2f %c %.2f = %.2f", x, operacao, y, resultado);
  
  printf("\n\n");
}

void questao4(){
  int numeroPessoas = 0, entrada = 1;
  float somaTotal = 0.0, item = 0.0, cadaUm = 0.0;
  
  printf("+--------------------------------+\n");
  printf("|  Divide a conta no Happy Hour  |\n");
  printf("+--------------------------------+\n");

  printf("\n");
  
  for(int i = 1; i > 0; i++){
    printf("\nPara acabar com a lista dos itens, insira o valor 0");
    printf("\nInforme o valor do  %iº item: ", i);
    scanf("%f", &item);
    somaTotal += item;
    if(item == 0)
      i = -1;
  }
  
  printf("\nInforme a quantidade de participantes: ");
  scanf("%i", &numeroPessoas);

  cadaUm = somaTotal / numeroPessoas;
  
  printf("\nA conta deu R$%.2f ", somaTotal);
  printf("\nDeu para cada um R$%.2f ", cadaUm);
  
  printf("\n\n");
}

int bisexto(int ano){
  if(ano % 400 == 0)
    return 1;
  else if(ano % 100 == 0)
    return 0;
  else if(ano % 4 == 0)
    return 1;
  return 0;
}

int diasdoMes(int mes,int ano){
  switch(mes){
    case 1: 
    case 3: 
    case 5: 
    case 7:
    case 8:
    case 10:
    case 12: return 31; break;
    case 2: 
      return 28 + bisexto(ano); break;
    case 4: 
    case 6: 
    case 9: 
    case 11: return 30; break;
  }
}

int calculaBisexto(int ano, int anofinal){
  if(ano > anofinal)
    return 0;
  return bisexto(ano) + calculaBisexto(ano + 1, anofinal);
}

int calculaMeses(int mes, int mesfinal, int dia, int diafinal){
  if (mesfinal < mes)
    return QUANTIDADE_MESES - (mes - mesfinal);
  else if(mes == mesfinal){
    if(dia > diafinal)
      return QUANTIDADE_MESES - (mes - mesfinal) - 1;
    return mesfinal - mes;
  }
  else
    return mesfinal - mes;
}

int calculaAnos(int ano, int anofinal, int mes, int mesfinal, int dia, int diafinal){
  if (mes < mesfinal)
    return anofinal - ano;
  else if(mes > mesfinal)
    return anofinal - ano - 1;
  else if(dia <= diafinal)
    return anofinal - ano;
  else
    return anofinal - ano - 1;
  
}

int calculaDias(int dia,int diafinal, int mes,int mesfinal, int anofinal){
  if(dia > diafinal){
    if(mesfinal == 1)
      return diasdoMes(QUANTIDADE_MESES, anofinal) - dia + diafinal;
    else
      return diasdoMes(mesfinal - 1, anofinal) - dia + diafinal;
  }
  else
    return diafinal - dia;
}

void questao5(){
  int dia = 0, mes = 0, ano = 0;
  int dias = 0, meses = 0, anos = 0, bisextos = 0;

  printf("+------------------------+\n");
  printf("|  Calculadora de Idade  |\n");
  printf("+------------------------+\n");
  
  printf("\nInforme a sua data de nascimento (DD/MM/AAAA): ");
  scanf("%i/%i/%i", &dia, &mes, &ano);

  bisextos = calculaBisexto(ano, ANO_ATUAL);
  anos = calculaAnos(ano, ANO_ATUAL, mes, MES_ATUAL, dia, DIA_ATUAL);
  meses = calculaMeses(mes, MES_ATUAL, dia, DIA_ATUAL);
  dias = calculaDias(dia, DIA_ATUAL, mes, MES_ATUAL, ANO_ATUAL);
  
  printf("\nA sua idade é \n%i anos\n%i meses\n%i dias", anos, meses, dias);
  printf("\nO numero de anos bisextos são %i", bisextos);
  
  printf("\n\n");
}

long int calculaDiasEntreDatas(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2){
  int retorno = 0;
  
  retorno = calculaAnos(ano1, ano2, mes1, mes2, dia1, dia2) * DIA_NO_ANO;
  retorno += calculaBisexto(ano1, ano2);

  if(mes1 < mes2){
    for (int m = mes1; m <= mes2; m++){
      retorno += diasdoMes(m,ano2);
    }
  }
  else if(mes1 > mes2){
    for (int m = mes1; m <= QUANTIDADE_MESES; m++){
      retorno += diasdoMes(m,ano2);
    }
    for (int m = 0; m <= mes2; m++){
      retorno += diasdoMes(m,ano2);
    }
  }//somar dias dos meses
  
  retorno += calculaDias(dia1, dia2, mes1, mes2, ano2);

  return retorno;
}

void questao6(){
  int dia1 = 0, mes1 = 0, ano1 = 0;
  int dia2 = 0, mes2 = 0, ano2 = 0;
  long int quantidade = 0;
  
  printf("+--------------------------------+\n");
  printf("|  Numero de dias entre 2 datas  |\n");
  printf("+--------------------------------+\n");
  
  printf("\nInforme as datas para calcular o intervalo de dias (DD/MM/AAAA DD/MM/AAAA):\n");
  scanf("%i/%i/%i %i/%i/%i", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);

  quantidade = calculaDiasEntreDatas(dia1, dia2, mes1, mes2, ano1, ano2);

  printf("\nA quantidade de dias entre %i/%i/%i e %i/%i/%i é de %i", dia1, mes1, ano1, dia2, mes2, ano2, quantidade);
  
  printf("\n\n");
}

int main() {
  char fim;
  int programa = 0;
  for (int inf = 1; inf > 0; inf++){

    printf("+---------------+\n");
    printf("|  1a Prova IP  |\n");
    printf("+---------------+\n");
    
    printf("\n\nQual atividade deseja ver:\n\n");
    printf("01) Somatorio sequencial de X a Y\n");
    printf("02) Imprima até a linha N do triangulo de pascal\n");
    printf("03) Simulador de Calculadora\n");
    printf("04) Divide a conta no Happy Hour\n");
    printf("05) Calculadora de Idade\n");
    printf("06) Conte o numero de dias entre 2 datas\n");


    printf("\n0) Sair do Programa\n\n");

    printf("\n--> ");
    
    scanf("%i",&programa);
    clrscr();

    switch(programa){
      case  0: inf = -1; break;
      case  1: questao1(); break;
      case  2: questao2(); break;
      case  3: questao3(); break;
      case  4: questao4(); break;
      case  5: questao5(); break;
      case  6: questao6(); break;
    }
  }
  printf("O programa está sendo finalizado!\n");
  scanf("");
  return SUCESSO;
}