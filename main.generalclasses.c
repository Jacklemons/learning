#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SUCESSO 0
#define AJUSTE_INDICE 1
#define DIASNOANO 365
#define MESESNOANO 12
#define IMCh 72.7
#define IMCf 62.1
#define LIMITEimpar 100
#define LIMITEtabuada 10
#define LIMITE_PAGINAS 11 + AJUSTE_INDICE

void clrscr(){
    system("@cls||clear");
}

int diaAtual(){
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  return tm.tm_mday;
}

int mesAtual(){
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  return tm.tm_mon;
}

int anoAtual(){
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  return tm.tm_year + 1900;
}

void dadosBasicos(){
  printf("+--------------------------------------+\n");
  printf("| Leia e imprima o nome, idade e sexo  |\n");
  printf("+--------------------------------------+\n");        
  char nome1[40] = "";
  char sexo[10] = "";
  int idade = 0;
  printf("Informe o nome: ");
  scanf("%s", nome1);
  printf("Informe a idade: ");
  scanf("%d", &idade);
  printf("Informe seu sexo: ");
  scanf("%s", sexo);
  printf("\nSeu nome é %s ", nome1);
  printf("\nVocê é do sexo %s ", sexo);
  printf("\nE tem %d anos \n\n", idade);
  return;
}

float calculaMedia(int quantidade){
  float notas[quantidade];
  float media = 0;
  for (int i = 1; i<= quantidade; i++){
    printf("Informe o %3d° valor: ", i);
    scanf("%f", &notas[i]);
    media += notas[i];
  }
  media = media / quantidade;

  return media;  
}

void mediaFinal(){
  printf("+----------------------------------------------+\n");
  printf("| Leia e imprima o nome, as notas e a media  |\n");
  printf("+----------------------------------------------+\n");
  char nome2[40] = "";
  int qtdnotas = 1, media = 0;
  printf("Informe o nome: ");
  scanf("%s", nome2);
  printf("Informe quantas notas existem ");
  scanf("%d", &qtdnotas);
  media = calculaMedia(qtdnotas);
  printf("A media  do aluno %s é %d \n\n", nome2, media);
  return;
}

void divisao2Numeros(){
  printf("+-------------------------------+\n");
  printf("| Faça a divisão de 2 inteiros  |\n");
  printf("+-------------------------------+\n");
  float denominador = 0, numerador = 0, decimal = 0;
  printf("Informe o numerador: ");
  scanf("%f", &numerador);
  printf("Informe o denominador: ");
  scanf("%f", &denominador);
  if (denominador == 0){
    printf("Não existe divisão por 0\n\n");
    return;
  }
  else
    decimal = numerador / denominador;
  printf("A divisão de %.0f por %.0f é %.2f \n\n",     numerador, denominador, decimal);
  return;
}

float realizaOperacao(float n1, float n2, char op){
  float r = 0;
  switch(op){
    case '+': r = n1+n2; break;
    case '-': r = n1-n2; break;
    case '*': r = n1*n2; break;
    case '/': r = n1/n2; break;
  }
  return r;
}

void operacao2Numeros(){
  printf("+----------------------------------------+\n");
  printf("| Informe 2 numeros e faça uma operação  |\n");
  printf("+----------------------------------------+\n");
  float numero1 = 0, numero2 = 0, resultado = 0;
  char operacao;
  printf("Informe o 1o numero: ");
  scanf("%f", &numero1);
  printf("Informe o 2o numero: ");
  scanf("%f", &numero2);
  printf("Informe a operação (+,-,*,/): ");
  scanf("%s", &operacao);
  resultado = realizaOperacao(numero1, numero2, operacao);
  printf("\nO resultado de %.0f %c %.0f é %.2f\n\n", numero1, operacao, numero2, resultado);
  return;  
}

int verificaTriangulo(float a, float b, float c){
  if(a < (b + c))
    if (b < (a + c))
      if (c < (a + b))
        return 1;
  return 0;
}

void eTriangulo(){
  printf("+---------------------+\n");
  printf("| Veja se é Triangulo |\n");
  printf("+---------------------+\n");
  float ladoa = 0, ladob = 0, ladoc = 0;
  printf("Informe o 1o lado: ");
  scanf("%f", &ladoa);
  printf("Informe o 2o lado: ");
  scanf("%f", &ladob);
  printf("Informe o 3o lado: ");
  scanf("%f", &ladoc);
  if (verificaTriangulo(ladoa, ladob, ladoc) == 1)
    printf("Existe um triangulo com esses 3 lados\n\n");
  else
    printf("Não existe um triangulo com esses 3 lados\n\n");
  return;  
}

float IMC(float h, char s){
  if(s == 'M')
    return (IMCh * h) - 58;
  return (IMCf * h) - 44.7;
 
}

void pesoIdeal(){
  printf("+---------------------+\n");
  printf("| Ache seu peso ideal |\n");
  printf("+---------------------+\n");
  float altura = 0, pesoIdeal = 0, peso = 0;
  char sexo;
  printf("Informe sua altura: ");
  scanf("%f", &altura);
  printf("Informe seu peso: ");
  scanf("%f", &peso);
  printf("Informe seu sexo (M/F): ");
  scanf("%s", &sexo);
  pesoIdeal = IMC(altura, sexo);
  printf("\nO seu peso ideal é %.2f \n\n", pesoIdeal);
  printf("Você está ");
  if(pesoIdeal < peso)
    printf("acima ");
  else
    printf("abaixo ");
  printf("do peso\n\n");
  return;  
}

void imprimeImpar(){
  printf("+---------------------+\n");
  printf("| Imprimindo Impares  |\n");
  printf("+---------------------+\n");  
  for(int i = 0; i <= LIMITEimpar; i++){
      if(i%2 == 1)
        printf("| %2i |", i);
      if(i%10 == 0)
        printf("\n------------------------------\n");
  }
  printf("\n\n");
  return;
}

void imprimeTabuadaDeitada(int n){
  printf("\n------------------------------------------------------------\n");
    for(int j = 1; j <= LIMITEtabuada; j++){
    printf("|%2i*%2i|", n, j);
  }
  printf("\n------------------------------------------------------------\n");
  for(int i = 1; i <= LIMITEtabuada; i++){
    printf("| %3i |", (n * i));
  }
  printf("\n------------------------------------------------------------\n");
}

void imprimeTabuadaEmPe(int n){
  printf("\n+-----+-----+\n");
  for(int i = 1; i <= LIMITEtabuada; i++){
    printf("|%2i*%2i| %3i |\n", n, i, (n * i));
    printf("+-----+-----+\n");
  }
}

void tabuada(){
  printf("+---------------------+\n");
  printf("| Montando a tabuada  |\n");
  printf("+---------------------+\n");  
  int numero = 0, posicao = 0;
  printf("Informe qual tabuada quer ver: ");
  scanf("%i", &numero);
  printf("Como deseja ver a tabela(em pe 1, deitado 2):");
  scanf("%i", &posicao);
  switch(posicao){
    case 1: imprimeTabuadaDeitada(numero); break;
    case 2: imprimeTabuadaEmPe(numero); break;
  }
  printf("\n\n");
  return;
 
}

void multiplicaSemFim(){
  printf("+-----------------------+\n");
  printf("| Multiplicando sem fim |\n");
  printf("+-----------------------+\n");

  float entrada = 1, final = 1;

  for(int i = 1; entrada != 0; i++){
    final = final * entrada;
    printf("\nInforme o %i numero para multiplicar: ", i);
    scanf("%f", &entrada);
  }
  printf("O resultado final é %.0f\n\n", final);
 
}

void imprimeDivisorRecursivo(int t, int a){
  if(a == 1){
    printf("%i ", a);
    return;
  }
  else{
    if(t % a == 0)
      printf("%i, ", a);
    imprimeDivisorRecursivo(t, a - 1);
    return;
  }
}

void imprimeDivisor(int t){
  for(int i = t; i > 0; i--){
    if(i == 1){
      printf("%i", i);
    }
    else if(t % i == 0){
      printf("%i, ", i);
    }
  }
  return;
}

void mostraDivisores(){
    printf("+---------------------+\n");
    printf("| Mostrando divisores |\n");
    printf("+---------------------+\n");

  int tamanho = 0;
  printf("\nInforme o numero para encontrar seus divisores: ");
  scanf("%i", &tamanho);
  printf("\nEstrutura recursiva: ");
  imprimeDivisorRecursivo(tamanho, tamanho);
  printf("\nEstrutura repetitiva: ");
  imprimeDivisor(tamanho);
  printf("\n\n");
}

void notaFinal(){
    printf("+---------------------+\n");
    printf("| Nota Final da Turma |\n");
    printf("+---------------------+\n");

  int tamanho = 0, aprovados = 0;
  printf("\nInforme quantos alunos tem na turma: ");
  scanf("%i", &tamanho);
  float notas[tamanho], aprovacao = 0, porcentagem = 0;
  printf("\nInforme qual a nota de aprovação: ");
  scanf("%f", &aprovacao);
 
  for(int l = 0; l < tamanho; l++){
    printf("\nInforme a nota do %i aluno: ", (l + AJUSTE_INDICE));
    scanf("%f", &notas[l]);
    if(notas[l] >= aprovacao){
      aprovados ++;
    }
  }
  porcentagem = (aprovados/tamanho)*100;
  printf("\nNa turma de %i alunos, tem aprovação de %.2f%%", tamanho, porcentagem);
  printf("\nHouveram %i alunos aprovados e %i alunos reprovados", aprovados, (tamanho - aprovados));
 
  printf("\n\n");
}

void somaInteiros(){
  int qtdLimite = 0;
  float somaFinal = 0;
  printf("+--------------------+\n");
  printf("| Somando n inteiros |\n");
  printf("+--------------------+\n");

  printf("\nInforme a quantidade de numeros a somar: ");
  scanf("%i", &qtdLimite);

  float num[qtdLimite];
  int i = 0;
  for(i = 0; i < qtdLimite; i++){
    printf("\nInforme o %iº: ", (i+1));
    scanf("%f", &num[i]);
    somaFinal += num[i];
  }

  printf("\nA soma dos numeros:\n");
  for(i = 0; i < qtdLimite; i++){
    printf("%.1f ", num[i]);
  }
  printf("\nFoi de %.1f", somaFinal);

  printf("\n\n");
}

void mediaReais(){
 
  printf("+-------------------+\n");
  printf("| Media de n reais  |\n");
  printf("+-------------------+\n");
  int qtd = 0;
  float media = 0;
  printf("Informe quantos numeros: ");
  scanf("%d", &qtd);
  media = calculaMedia(qtd);
  printf("A media dos numeros é %.2f \n\n", media);
 
  printf("\n\n");
}

void somaUmporN(){
  printf("+------------------+\n");
  printf("| Soma de H = 1/N  |\n");
  printf("+------------------+\n");
  int qtd = 0, i = 0;
  float somaUmN = 0;
  printf("Informe até que N: ");
  scanf("%d", &qtd);

  printf("\n A soma de:\n");
  for (i = 0; i < qtd; i++){
    somaUmN += 1.0/(i+1);
    printf("1/%2i\n", i + AJUSTE_INDICE);
  }
  printf("\nÉ de %.20f", somaUmN);

  printf("\n\n");
}

void calculaAumento(){
  float salario = 0, aumento = 0, salarioFinal = 0;
 
  printf("+---------------------+\n");
  printf("| Aumento de salario  |\n");
  printf("+---------------------+\n");
 
  printf("\nInforme o salário do funcionário: \nR$");
  scanf("%f", &salario);
  printf("\nInforme o aumento do salário do funcionário (de 0 a 1): ");
  scanf("%f", &aumento);
 
  salarioFinal = realizaOperacao(salario, aumento + 1, '*');

  printf("\nO aumento é de: R$%.2f", salarioFinal - salario);
 
  printf("\nO salario novo do funcionário é R$%.2f", salarioFinal);

  printf("\n\n");
}

float mediaPonderada(int tamanho, float notas[tamanho], float pesos[tamanho]){
  int i = 0, peso = 0;
  float mediaP = 0, somaP = 0;
  for (i = 0; i < tamanho; i++){
    somaP += (notas[i] * pesos[i]);
    peso += pesos[i];
  }
  mediaP = somaP / peso;
  return mediaP;     
}

void notaFinalPonderada(){
  printf("+-----------------------------------------+\n");
  printf("| Calculo de nota final (Media Ponderada) |\n");
  printf("+-----------------------------------------+\n");
  int qtd = 0;
  printf("\nInforme a quantidade de notas para calcular a média: ");
  scanf("%d", &qtd);

  float notas[qtd], pesos[qtd], media = 0;

  int i = 0;
  for (i = 0; i < qtd; i++){
    printf("\nInforme a %iº nota: ", (i+1));
    scanf("%f", &notas[i]);
    printf("\nInforme o peso da %iº nota: ", (i+1));
    scanf("%f", &pesos[i]);
  }
  media = mediaPonderada(qtd, notas, pesos);

  printf("\nA nota final é de %.2f", media);
  printf("\n\n");
}

void imparPar(){
  int numero = 0;
  char resto[5];  
  
  printf("+----------------------------+\n");
  printf("| Descubra se é par ou impar |\n");
  printf("+----------------------------+\n");

  printf("\n\nInforme o numero para descubrir se é impar ou par: ");
  scanf("%i", &numero);

  if(numero % 2 == 0){
    resto[0] = 'p';
    resto[1] = 'a';
    resto[2] = 'r';
  }
  else{
    resto[0] = 'i';
    resto[1] = 'm';
    resto[2] = 'p';
    resto[3] = 'a';
    resto[4] = 'r';
  }
  
  printf("\nO numero %i é %s\n", numero, resto);
  printf("\n\n");
}

void qualMaior(){
  int quantidade = 0, i = 0, j = 0, posicao = 0;
  float maior = 0, temporario = 0;
  
  printf("+------------------------------+\n");
  printf("| Descubra qual o maior numero |\n");
  printf("+------------------------------+\n");

  printf("\nInforme quantos numeros quer comparar: ");
  scanf("%i", &quantidade);

  float numeros[quantidade];

  for(i = 0; i < quantidade; i++){
    printf("\nInforme %io numero: ", (i + AJUSTE_INDICE));
    scanf("%f", &numeros[i]);
    if(i == 0){
      maior = numeros[i];
      posicao = 0;
    }
    else if(numeros[i] > maior){
      maior = numeros[i];
      posicao = i;
    }
  }
  for(i = 0; i < quantidade; i++){
    for(j = 0; j < quantidade; j++){
      if (i != j){
        if(numeros[i] > numeros[j]){
          temporario = numeros[i];
          numeros[i] = numeros[j];
          numeros[j] = temporario;
        }
      }
    }
  }
  
  if(numeros[0] == numeros[quantidade - 1])
    printf("\nTodos os numeros são iguals: %.2f ", numeros[0]);
  else{
    printf("\nOs numeros ordenados do maior para menor são: \n");
    for(i = 0; i < quantidade; i++)
      printf("%.2f \n", numeros[i]);
  }
  printf("\n\n");
}

void diaSemana(){
  int entrada = 0;
  char saida[7];
  
  printf("+----------------------+\n");
  printf("| Qual o dia da semana |\n");
  printf("+----------------------+\n");

  printf("\nInforme qual dia da semana deseja saber: ");
  scanf("%i", &entrada);

  switch(entrada){
    case 1: 
      saida[0] = 'd';
      saida[1] = 'o';
      saida[2] = 'm';
      saida[3] = 'i';
      saida[4] = 'n';
      saida[5] = 'g';
      saida[6] = 'o';
      break;
    case 2: 
      saida[0] = 's';
      saida[1] = 'e';
      saida[2] = 'g';
      saida[3] = 'u';
      saida[4] = 'n';
      saida[5] = 'd';
      saida[6] = 'a';
      break;
    case 3: 
      saida[0] = 't';
      saida[1] = 'e';
      saida[2] = 'r';
      saida[3] = 'c';
      saida[4] = 'a';
      break;
    case 4: 
      saida[0] = 'q';
      saida[1] = 'u';
      saida[2] = 'a';
      saida[3] = 'r';
      saida[4] = 't';
      saida[5] = 'a';
      break;
    case 5: 
      saida[0] = 'q';
      saida[1] = 'u';
      saida[2] = 'i';
      saida[3] = 'n';
      saida[4] = 't';
      saida[5] = 'a';
      break;
    case 6: 
      saida[0] = 's';
      saida[1] = 'e';
      saida[2] = 'x';
      saida[3] = 't';
      saida[4] = 'a';
      break;
    case 7: 
      saida[0] = 's';
      saida[1] = 'a';
      saida[2] = 'b';
      saida[3] = 'a';
      saida[4] = 'd';
      saida[5] = 'o';
      break;
    default:
      entrada = 0;
      printf("\nO numero informado não é um dia valido da semana");
  }
  if (entrada != 0)
    printf("\nO %i dia da semana é %s", entrada, saida);

  printf("\n\n");
}

long int calculaFatorial(int numero){
  long int soma = 1;
  for(int i = numero; i > 0; i--)
    soma *= i;
  return soma;
}

long int calculaFatorialRecursivo(int numero){
  if (numero == 1)
    return 1;
  return numero * calculaFatorialRecursivo(numero - 1);  
}

void fatorial(){
  int numero = 0;
  long int fatorial = 0, fatorialr = 0;
  
  printf("+--------------------+\n");
  printf("| Calcule N fatorial |\n");
  printf("+--------------------+\n");

  printf("\nQual fatorial que deseja calcular: ");
  scanf("%i", &numero);

  fatorial = calculaFatorial(numero);
  fatorialr = calculaFatorialRecursivo(numero);
  
  printf("\nO calculo do fatorial de %i é", numero);
  printf("\nEstrutura de Repetição: %li\nEstrutura Recursiva: %li", fatorial, fatorialr);
  
  printf("\n\n");
}

void somaUmporNFatorial(){
  printf("+-------------------+\n");
  printf("| Soma de H = 1/N!  |\n");
  printf("+-------------------+\n");
  int qtd = 0, i = 0;
  float somaUmN = 0;
  printf("Informe até que N: ");
  scanf("%d", &qtd);

  printf("\n A soma de:\n");
  for (i = 0; i < qtd; i++){
    somaUmN += 1.0/calculaFatorialRecursivo(i + AJUSTE_INDICE);
    printf("1/%i! = 1/%i\n", (i + AJUSTE_INDICE), calculaFatorialRecursivo(i + AJUSTE_INDICE));
  }
  printf("\nÉ de %.20f", somaUmN);

  printf("\n\n");
}

void maiorMenor(){
  int maior = 0, menor = 0, entrada = 0;
  
  printf("+-----------------------------+\n");
  printf("| Qual o maior e menor numero |\n");
  printf("+-----------------------------+\n");

  printf("\nInforme os numeros (informe 0 para terminar)\n");

  for (int i = 0; i >= 0; i++){
    printf("\nInforme o %i numero ", (i + AJUSTE_INDICE));
    scanf("%i",&entrada);
    if(i == 0){
      maior = entrada;
      menor = entrada;
    }
    if(entrada == 0)
      i = -2;
    else if(entrada > maior)
      maior = entrada;
    else if(entrada < menor)
      menor = entrada;
  }  

  printf("\nO maior numero é %i", maior);
  printf("\nO menor numero é %i", menor);
  
  printf("\n\n");
}

int somaFibonacciN(int posicao){
  if(posicao == 0)
    return 0;
  else if(posicao == 1)
    return 1;
  else if (posicao == 2)
    return 1;
  return somaFibonacciN(posicao-1) + somaFibonacciN(posicao - 2);
}

void imprimeFibonacciN(int posicao){
  printf("%i ",somaFibonacciN(posicao));
}

void imprimeFibonacci(){
  int posicao = 0, linha = 1;
  
  printf("+----------------------------------+\n");
  printf("| Imprimindo a sequencia Fibonacci |\n");
  printf("+----------------------------------+\n");

  printf("\nAté qual termo N deseja ver: ");
  scanf("%i", &posicao);

  printf("\nOs termos são:\n");
  for(int i = 1; i <= posicao; i++){
    imprimeFibonacciN(i);
  }
  
  printf("\n\n");
}

float celciusFahrenheit(float celcius){
  return (celcius / 9) * 5 + 32;
}

float fahrenheitCelcius(float fahrenheit){
  return 9 * (fahrenheit - 32) / 5;
}

void tabelaCelciusF(){
  float celcius = 50, fahrenheit = 50; 
  int quantidade = 0;
  printf("+-------------------------------------------------------+\n");
  printf("| Imprimindo a tabela de conversão Celcius x Fahrenheit |\n");
  printf("+-------------------------------------------------------+\n");

  printf("\nA partir de qual temperatura deseja ver ");
  scanf("%f", &celcius);
  fahrenheit = celcius;
  
  printf("\nQuantas linhas deseja ver ");
  scanf("%i", &quantidade);
  
  printf("\nAs temperaturas são convertida pelo calculo: \nC = 9 * (F - 32) / 5\nF = (C / 9) * 5 + 32\n\n");

  printf("*---*------*---*------*\n");
  printf("| C |F=f(C)| F |C=f(F)|\n");
  for(int i = 0; i <= quantidade ; i++){
    printf("*---*------*---*------*\n");
    printf("|%3.0f|%3.2f|%3.0f|%3.2f|\n", celcius, celciusFahrenheit(celcius), fahrenheit, fahrenheitCelcius(fahrenheit));
    celcius++;
    fahrenheit++;
  }
  printf("*---*------*---*------*\n");
  
  printf("\n\n");
}

float soma(float numero1, float numero2){
  return numero1 + numero2;
}

float multiplica(float numero1, float numero2){
  return numero1 * numero2;
}

float quociente(float numero1, float numero2){
  return numero1 / numero2;
}

void realizaOperacaoEscolha(){
  int operacao = 0;
  char opera = "";
  float numero1 = 0.0, numero2 = 0.0, resultado = 0.0;
  
  printf("+--------------------------------+\n");
  printf("| Escolha operação para calcular |\n");
  printf("+--------------------------------+\n");

  do{
    printf("\nEscolha uma opção de cálculo para dois números:\n\n");
    printf("01) Soma\n");
    printf("02) Produto\n");
    printf("03) Quociente\n");
    printf("04) Sair\n");
    
    printf("\n--> ");
    scanf("%i",&operacao);

    switch(operacao){
      case  1:
      case  2:
      case  3:
        printf("\nInforme o 1o numero: ");
        scanf("%f", &numero1);
        printf("\nInforme o 2o numero: ");
        scanf("%f", &numero2);
        break;
    }

    switch(operacao){
      case  1: resultado = soma(numero1, numero2); opera = '+'; break;
      case  2: resultado = multiplica(numero1, numero2); opera = '*'; break;
      case  3: resultado = quociente(numero1, numero2); opera = '/'; break;
    }

    switch(operacao){
      case  1:
      case  2:
      case  3:
        printf("\nO resultado da operação é ");
        printf("\n%.2f %c %.2f = %.2f", numero1, opera, numero2, resultado);
        break;
    }

  printf("\n\n");
  } while (operacao != 4);
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

void calculaAnosMesDiaparaDias(){
  int ano = 0, mes = 0, dia = 0;
  int anoinicial = 0, qtd_dias = 0;
  
  printf("+-------------------------------+\n");
  printf("| Calcule quantos dias você tem |\n");
  printf("+-------------------------------+\n");

  printf("\nInforme a sua idade em anos, meses e dias (AAAA MM DD): ");
  scanf("%i/%i/%i", &ano, &mes, &dia);

  anoinicial = anoAtual() - ano;

  qtd_dias = ano * DIASNOANO + calculaBisexto(anoinicial, anoAtual());
  qtd_dias += dia;
  for (int i = 0; i < mes; i++){
    if (mesAtual() - i < 1)
      qtd_dias += diasdoMes(MESESNOANO + mesAtual() - i, anoAtual());
    else
      qtd_dias += diasdoMes(mesAtual() - i, anoAtual());
  }

  printf("\nA quantidade de dias é %i", qtd_dias);
  
  
  printf("\n\n");
}

int calculaHoras(long long int segundos){
  return segundos / 3600;
}

int calculaMinutos(long long int segundos){
  return (segundos % 3600) / 60;
}

int calculaSegundos(long long int segundos){
  return segundos % 60;
}

void quantoTempo(){
  long long int segundosinformados = 0;
  int horas = 0, minutos = 0, segundos = 0;
  
  printf("+-------------------------------------+\n");
  printf("| Calcule quantas horas e minutos são |\n");
  printf("+-------------------------------------+\n");

  printf("\nInforme quantos segundos você quer converter: \n");
  scanf("%lli", &segundosinformados);

  horas = calculaHoras(segundosinformados);
  minutos = calculaMinutos(segundosinformados);
  segundos = calculaSegundos(segundosinformados);

  printf("\nEssa quantidade de segundos %lli", segundosinformados);
  printf("\nÉ %i horas %i minutos e %i segundos", horas, minutos, segundos);
  
  printf("\n\n");
}

int quantosDivisores(long int primo){
  int divisores = 0;
  for (int i = 1; i <= primo; i++){
    if (primo % i == 0)
      divisores ++;
  }
  return divisores;
}

void verificaPrimo(){
  long long int primo = 0;
  
  printf("+-------------------------------+\n");
  printf("| Verifique se é primo o numero |\n");
  printf("+-------------------------------+\n");

  printf("\nInforme qual numero deseja verificar: \n");
  scanf("%lli", &primo);

  if (quantosDivisores(primo) != 2)
    printf("\nO numero não é primo");
  else{
    printf("\nO numero é primo");
  }    
  printf("\n\n");
}

void qualMaiorOrdenado(){
  int quantidade = 20, i = 0, j = 0, posicao = 0;
  
  printf("+------------------------------------------+\n");
  printf("| Descubra qual o maior numero de um vetor |\n");
  printf("+------------------------------------------+\n");

  float numeros[quantidade];

  for(i = 0; i < quantidade; i++){
    printf("\nInforme %io numero: ", (i + AJUSTE_INDICE));
    scanf("%f", &numeros[i]);
    if(i == 0){
      posicao = 0;
    }
    else if(numeros[i] < numeros[posicao]){
      posicao = i;
    }
  }
  
  if(numeros[0] == numeros[quantidade - 1])
    printf("\nTodos os numeros são iguals: %.2f ", numeros[0]);
  else{
    printf("\nOs menor numero do vetor é %.2f na posição %i", numeros[posicao], posicao + AJUSTE_INDICE);
  }
  printf("\n\n"); 
}

void multiplicacaoEscalarVetor(){
  int quantidade = 0, i = 0, j = 0, posicao = 0;
  float escalar = 0.0;
  
  printf("+--------------------------------+\n");
  printf("| Multiplicação escalar do vetor |\n");
  printf("+--------------------------------+\n");

  printf("\nInforme quantos numeros tem seu vetor: ");
  scanf("%i", &quantidade);

  float numeros[quantidade];

  for(i = 0; i < quantidade; i++){
    printf("\nInforme %io numero: ", (i + AJUSTE_INDICE));
    scanf("%f", &numeros[i]);
  }

  printf("\nInforme o escalar para multiplicar: ");
  scanf("%f", &escalar);
  
  for(i = 0; i < quantidade; i++)
    numeros[i] *= escalar;

  printf("\nO vetor escalado é: \n");
  for(i = 0; i < quantidade; i++)
    printf("%.2f ", numeros[i]);
  
  printf("\n\n");
}

void multiplicacaoEscalarEntreVetor(){
  int quantidade = 10, i = 0, j = 0, posicao = 0;
  float escalar = 0.0;
  
  printf("+-------------------------------------+\n");
  printf("| Multiplicação escalar entre vetores |\n");
  printf("+-------------------------------------+\n");

  /*printf("\nInforme quantos numeros tem seu vetor: ");
  scanf("%i", &quantidade);*/

  float numeros[quantidade], numeros2[quantidade];

  for(i = 0; i < quantidade; i++){
    printf("\nInforme %io numero: ", (i + AJUSTE_INDICE));
    scanf("%f", &numeros[i]);
  }

  for(i = 0; i < quantidade; i++){
    printf("\nInforme %io numero: ", (i + AJUSTE_INDICE));
    scanf("%f", &numeros2[i]);
  }
  
  for(i = 0; i < quantidade; i++)
    numeros[i] *= numeros2[i];

  printf("\nO vetor escalado é: \n");
  for(i = 0; i < quantidade; i++)
    printf("%.2f ", numeros[i]);
  
  printf("\n\n");
}

int comparaCaracter(char frase[], int tamanhoFrase, char texto[], int tamanho){
  int quantidade = 0, palavra = 0;
  for(int i = 0; i < tamanhoFrase; i++){
    for(int t = 0; t < tamanho; t++){
      if(frase[i] == texto[t]){
        palavra = 0;
        for(int c = 0; c < tamanho; c++){
          if(frase[i + c] == texto[t + c])
            palavra++;
        }
        if(palavra == tamanho)
          quantidade++;
      }
    }
  }
  return quantidade;
}

void contaEspacosString(){
  int tamanho = 101, quantidade = 0;
  char palavra[tamanho], texto = ' ';
  
  printf("+-----------------------------------+\n");
  printf("| Contador de espaços em uma string |\n");
  printf("+-----------------------------------+\n");

  printf("\n Digite um texto para contar os espaços contidos nele:\n");
  //gets(palavra);

  quantidade = comparaCaracter(palavra, tamanho, texto, 1);
  
  printf("\nA quantidade de '%c' na frase é %i\n", texto, quantidade);

  printf("\n\n");
}

void imprimeMatriz(int linha, int coluna, float matriz[linha][coluna]){
  for(int l = 0; l < linha; l++){
    for(int c = 0; c < coluna; c++){
      printf("%4.2f ", matriz[l][c]);
    }
    printf("\n");
  }
}

void imprimeMatrizTransposta(int linha, int coluna, float matriz[linha][coluna]){
  for(int l = 0; l < linha; l++){
    for(int c = 0; c < coluna; c++){
      printf("%4.2f ", matriz[c][l]);
    }
    printf("\n");
  }
}

void matrizESuaTransposta(){
  int tamanho1 = 5, tamanho2 = 5;
  float matriz[tamanho1][tamanho2];
  
  printf("+----------------------------------------------+\n");
  printf("| Informe uma matriz 5x5 e veja sua transposta |\n");
  printf("+----------------------------------------------+\n");

  for(int l = 0; l < tamanho1; l++){
    for(int c = 0; c < tamanho2; c++){
      printf("\nInforme a posição %i %i ", l + AJUSTE_INDICE, c + AJUSTE_INDICE);
      scanf("%f", &matriz[l][c]);
    }
  }

  printf("\nA matriz é: \n");
  imprimeMatriz(tamanho1, tamanho2, matriz);

  printf("\nA matriz transposta é: \n");
  imprimeMatrizTransposta(tamanho1, tamanho2, matriz);
  
  printf("\n\n");
}

void somandoElementosMatriz(){
  int tamanho1 = 0, tamanho2 = 0;
  
  printf("+------------------------------------+\n");
  printf("| Somando os elementos de uma matriz |\n");
  printf("+------------------------------------+\n");

  printf("\nInforme qual o tamanho da matriz (n X n): ");
  scanf("%i X %i", &tamanho1, &tamanho2);
  
  float matriz[tamanho1][tamanho2], soma = 0;

  for(int l = 0; l < tamanho1; l++){
    for(int c = 0; c < tamanho2; c++){
      printf("\nInforme a posição %i %i ", l + AJUSTE_INDICE, c + AJUSTE_INDICE);
      scanf("%f", &matriz[l][c]);
    }
  }

  printf("\nA soma da matriz: \n");
  for(int l = 0; l < tamanho1; l++){
    for(int c = 0; c < tamanho2; c++){
      printf("%.2f ", matriz[l][c]);
      soma += matriz[l][c];
    }
    printf("\n");
  }
  printf("\nÉ: %.2f \n", soma);
  
  printf("\n\n");
}

void multiplicaMatrizxVetor(){
  int tamanho1 = 0, tamanho2 = 0;
  
  printf("+-------------------------------------+\n");
  printf("| Multiplique uma matriz por um vetor |\n");
  printf("+-------------------------------------+\n");

  printf("\nInforme qual o tamanho da matriz (n X n): ");
  scanf("%i X %i", &tamanho1, &tamanho2);
  
  float matriz[tamanho1][tamanho2], fatores[tamanho1];
  float resultado[tamanho1][tamanho2];

  for(int p = 0; p < tamanho1; p++){
    for(int l = 0; l < tamanho2; l++){
      matriz[p][l] = 0;
      resultado[p][l] = 0;
    }
    fatores[p] = 0;
  }
  
  for(int l = 0; l < tamanho1; l++){
    for(int c = 0; c < tamanho2; c++){
      printf("\nInforme a posição %i %i ", l + AJUSTE_INDICE, c + AJUSTE_INDICE);
      scanf("%f", &matriz[l][c]);
    }
  }
  for(int l = 0; l < tamanho1; l++){
      printf("\nInforme o fator da posição %i ", l + AJUSTE_INDICE);
      scanf("%f", &fatores[l]);
  }

  printf("\nA multiplicação da matriz: \n");
  imprimeMatriz(tamanho1, tamanho2, matriz);
  
  printf("\n\nPelos fatores: \n\n");
  for(int l = 0; l < tamanho1; l++){
      printf("%.2f ", fatores[l]);
  }
  printf("\n\nÉ: \n\n");
  imprimeMatriz(tamanho1, tamanho2, resultado);
  
  printf("\n\n");
}

void totaisProdutosLojas(){
  int produtos = 5, lojas = 7, menor = 0;
  
  printf("+--------------------------------------------+\n");
  printf("| Calcule os totais de 5 produtos em 7 lojas |\n");
  printf("+--------------------------------------------+\n");
  
  float matriz[produtos][lojas], totalProdutos[produtos], totalProdutosLojas[lojas];

  for(int p = 0; p < produtos; p++){
    for(int l = 0; l < lojas; l++){
      matriz[p][l] = 0;
      totalProdutosLojas[l] = 0;
    }
    totalProdutos[p] = 0;
  }
  
  for(int p = 0; p < produtos; p++){
    for(int l = 0; l < lojas; l++){
      printf("\nInforme quantos produtos %i a loja %i tem ", p + AJUSTE_INDICE, l + AJUSTE_INDICE);
      scanf("%f", &matriz[p][l]);
      totalProdutos[p] += matriz[p][l];
      totalProdutosLojas[l] += matriz[p][l];
    }
  }

  printf("\nOs totais dos produtos são: \n");  
  for(int p = 0; p < produtos; p++){
    printf("\nProduto %i: %.2f ", p + AJUSTE_INDICE, totalProdutos[p]);
  }

  for(int l = 0; l < lojas; l++){
    if(totalProdutosLojas[l] < totalProdutosLojas[menor])
      menor = l;
  }
  printf("\n\nA loja que menos possui produtos é a loja %i \n", menor + AJUSTE_INDICE);
  
  printf("\n\n");
}

//Separação entre funções e paginas #separa

int pagina1(int pagina){
  int programa = 0;  
  for (int inf = 1; inf > 0; inf++){
    printf("+---------------------------------------------------+\n");
    printf("| Aula 01 - Introdução aos Algoritmos e Fluxogramas |\n");
    printf("+---------------------------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Leia e imprima o nome, idade e sexo\n");
    printf("02) Leia e imprima o nome, as notas e a media\n");
    printf("03) Faça a divisão de 2 inteiros\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
  
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: dadosBasicos(); break;
      case  2: mediaFinal(); break;
      case  3: divisao2Numeros(); break;
      case  7: pagina--; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina++; return pagina;
      default: break;
    }
  }
}

int pagina2(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+-----------------------------------+\n");
    printf("| Aula 02 - Estruturas Condicionais |\n");
    printf("+-----------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) O numero é par ou impar\n");
    printf("02) Qual o maior numero\n");
    printf("03) Dia da Semana\n");
    printf("04) Informe 2 numeros e faça uma operação\n");
    printf("05) Ver se é triangulo\n");
    printf("06) Ache seu peso ideal\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
  
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: imparPar(); break;
      case  2: qualMaior(); break;
      case  3: diaSemana(); break;
      case  4: operacao2Numeros(); break;
      case  5: eTriangulo(); break;
      case  6: pesoIdeal(); break;
      case  7: pagina --;
      case  8: pagina = SUCESSO;
      case  9: pagina ++;
        return pagina;
      default: break;
    }
  }
}

int pagina3(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+-----------------------------------+\n");
    printf("| Aula 03 - Estruturas de Repetição |\n");
    printf("+-----------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Descubra se é impar ou par\n");
    printf("02) Descubra qual o maior numero\n");
    printf("03) Descubra qual o dia da semana\n");
    printf("04) Informe 2 numeros e faça uma operação\n");
    printf("05) Mostrando seus divisores\n");
    printf("06) Nota final da turma\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: imparPar(); break;
      case  2: qualMaior(); break;
      case  3: diaSemana(); break;
      case  4: operacao2Numeros(); break;
      case  5: eTriangulo(); break;
      case  6: pesoIdeal(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina4(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+----------------------------------------+\n");
    printf("| Aula 04 - Construindo um programa em C |\n");
    printf("+----------------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Soma N inteiros\n");
    printf("02) Media de N reais\n");
    printf("03) Soma de H = 1/N\n");
    printf("04) Calculo de aumento\n");
    printf("05) Calculo de nota final (Media Ponderada)\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: somaInteiros(); break;
      case  2: mediaReais(); break;
      case  3: somaUmporN(); break;
      case  4: calculaAumento(); break;
      case  5: notaFinalPonderada(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina5(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+-----------------------------------+\n");
    printf("| Aula 05 - Estruturas Condicionais |\n");
    printf("+-----------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Descubra se é impar ou par\n");
    printf("02) Descubra qual o maior numero\n");
    printf("03) Descubra qual o dia da semana\n");
    printf("04) Informe 2 numeros e faça uma operação\n");
    printf("05) Mostrando seus divisores\n");
    printf("06) Nota final da turma\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: imparPar(); break;
      case  2: qualMaior(); break;
      case  3: diaSemana(); break;
      case  4: operacao2Numeros(); break;
      case  5: eTriangulo(); break;
      case  6: pesoIdeal(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina6(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+-----------------------------------+\n");
    printf("| Aula 06 - Estruturas de Repetição |\n");
    printf("+-----------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Calcule N!\n");
    printf("02) Soma de E = 1/N!\n");
    printf("03) Qual o maior e menor de uma sequencia terminada em 0\n");
    printf("04) Mostre a sequencia Fibonacci\n");
    printf("05) As temperaturas de Celsius em Fahrenheit\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: fatorial(); break;
      case  2: somaUmporNFatorial(); break;
      case  3: maiorMenor(); break;
      case  4: imprimeFibonacci(); break;
      case  5: tabelaCelciusF(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina7(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+---------------------------------------+\n");
    printf("| Aula 07 - Explorando os tipos básicos |\n");
    printf("+---------------------------------------+\n");
    
    printf("\n\n Essa aula não tiveram exercicios\n\n");
    
    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina8(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+---------------------------------------------+\n");
    printf("| Aula 08 - Rotinas (Funções e Procedimentos) |\n");
    printf("+---------------------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Escolha operação para calcular\n");
    printf("02) Calcule quantos dias você tem\n");
    printf("03) Calcule quantas horas e minutos são\n");
    printf("04) Verifique se é primo o numero\n");
    printf("05) Calcule N!\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: realizaOperacaoEscolha(); break;
      case  2: calculaAnosMesDiaparaDias(); break;
      case  3: quantoTempo(); break;
      case  4: verificaPrimo(); break;
      case  5: fatorial(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina9(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+-------------------+\n");
    printf("| Aula 09 - Vetores |\n");
    printf("+-------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Verifique qual o maior numero em ordem\n");
    printf("02) Faça uma multiplicação escalar do vetor\n");
    printf("03) Faça uma multiplicação escalar entre vetores\n");
    printf("04) Media de N reais\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
    
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: qualMaiorOrdenado(); break;
      case  2: multiplicacaoEscalarVetor(); break;
      case  3: multiplicacaoEscalarEntreVetor(); break;
      case  4: mediaReais(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina10(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+---------------------------------+\n");
    printf("| Aula 10 - Cadeias de Caracteres |\n");
    printf("+---------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Calcule o numero de espaços em uma string\n");
    printf("02) Questão\n");
    printf("03) Questão\n");
    printf("04) Questão\n");
    printf("05) Questão\n");
    printf("06) Questão\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
  
    printf("\n0) Sair do Programa\n\n");
  
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: /*contaEspacosString();*/ break;
      case  2: break;
      case  3: break;
      case  4: break;
      case  5: break;
      case  6: break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int pagina11(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+--------------------+\n");
    printf("| Aula 11 - Matrizes |\n");
    printf("+--------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Mostrando uma trasnposta de uma matriz 5x5\n");
    printf("02) Somando os elementos de uma matriz\n");
    printf("03) Multiplique uma matriz por um vetor\n");
    printf("04) Calcule os totais de 5 produtos em 7 lojas\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
  
    printf("\n0) Sair do Programa\n\n");
  
    printf("\n--> ");
    
    scanf("%i",&programa);

    clrscr();
    switch(programa){
      case  1: matrizESuaTransposta(); break;
      case  2: somandoElementosMatriz(); break;
      case  3: multiplicaMatrizxVetor(); break;
      case  4: totaisProdutosLojas(); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int paginagenerica(int pagina){
  int programa = 0;  

  for (int inf = 1; inf > 0; inf++){
    printf("+--------------------------------------------------+\n");
    printf("| Aula X - Conteudo |\n");
    printf("+--------------------------------------------------+\n");
    
    printf("\n\nQual programa deseja ver:\n\n");
    printf("01) Questão\n");
    printf("02) Questão\n");
    printf("03) Questão\n");

    printf("\n");

    if (pagina - 1 != 0)
      printf("07) Aula %i\n", pagina - 1);
    printf("08) Voltar ao menu anterior\n");
    printf("09) Aula %i\n", pagina + 1);
  
    printf("\n0) Sair do Programa\n\n");
  
    printf("\n--> ");
    
    scanf("%i",&programa);

    switch(programa){
      case  1: paginagenerica(pagina); break;
      case  2: paginagenerica(pagina); break;
      case  3: paginagenerica(pagina); break;
      case  7: pagina --; return pagina;
      case  8: pagina = SUCESSO; return pagina;
      case  9: pagina ++; return pagina;
      default: break;
    }
  }
}

int main() {
  char fim;
  int programa = 0;
  for (int inf = 1; inf > 0; inf++){
    //printf("Pressione qualquer tecla para continuar\n\n");
    //system("pause");
    clrscr();
    printf("+---------------------+\n");
    printf("| Programas das aulas |\n");
    printf("+---------------------+\n");

    printf("\n\nQual aula deseja ver:\n\n");
    printf("01) Aula 01 - Introdução aos Algoritmos e Fluxogramas\n");
    printf("02) Aula 02 - Estruturas Condicionais\n");
    printf("03) Aula 03 - Estruturas de Repetição\n");
    printf("04) Aula 04 - Construindo um programa em C\n");
    printf("05) Aula 05 - Estruturas Condicionais\n");
    printf("06) Aula 06 - Estruturas de Repetição \n");
    printf("06) Aula 07 - Explorando os tipos básicos \n");
    printf("08) Aula 08 - Rotinas (Funções e Procedimentos)\n");
    printf("09) Aula 09 - Vetores\n");
    printf("10) Aula 10 - Cadeias de Caracteres\n");
    printf("11) Aula 11 - Matrizes\n");

    printf("\n0) Sair do Programa\n\n");

    printf("\n--> ");
    
    scanf("%i",&programa);
    clrscr();

    do{
      switch(programa){
        case  0: inf = -1; break;
        case  1: programa = pagina1(programa); break;
        case  2: programa = pagina2(programa); break;
        case  3: programa = pagina3(programa); break;
        case  4: programa = pagina4(programa); break;
        case  5: programa = pagina5(programa); break;
        case  6: programa = pagina6(programa); break;
        case  7: programa = pagina7(programa); break;
        case  8: programa = pagina8(programa); break;
        case  9: programa = pagina9(programa); break;
        case 10: programa = pagina10(programa); break;
        case 11: programa = pagina11(programa); break;
      }
    } while (programa > SUCESSO && programa < LIMITE_PAGINAS);
  }
  printf("O programa está sendo finalizado!\n");
  scanf("");
  return SUCESSO;
}







