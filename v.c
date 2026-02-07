#include <stdio.h>

#define TAM_PILHA 5
#define TAM_FILA 10
#define TAM_TEMP 4

// ---------------- PILHA ----------------
typedef struct {
    int dados[TAM_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

void empilhar(Pilha *p, int valor){
    p->dados[++p->topo] = valor;
}

int pilhasIguais(Pilha p1, Pilha p2){
    if(p1.topo != p2.topo)
        return 0;

    for(int i=0;i<=p1.topo;i++){
        if(p1.dados[i] != p2.dados[i])
            return 0;
    }
    return 1;
}

// ---------------- FILA ----------------
typedef struct {
    int dados[TAM_FILA];
    int ini, fim;
} Fila;

void inicializarFila(Fila *f){
    f->ini = 0;
    f->fim = 0;
}

void enfileirar(Fila *f, int x){
    f->dados[f->fim++] = x;
}

void mostrarFila(Fila f){
    for(int i=f.ini;i<f.fim;i++){
        printf("%d ", f.dados[i]);
    }
    printf("\n");
}

void dividirFila(Fila *origem, Fila *f1, Fila *f2){
    for(int i=origem->ini;i<origem->fim;i++){
        if(i % 2 == 0)
            enfileirar(f1, origem->dados[i]);
        else
            enfileirar(f2, origem->dados[i]);
    }
}

// ---------------- LISTA (Temperaturas) ----------------
void analisarTemperaturas(float temp[], int n){
    float soma = 0, media;

    for(int i=0;i<n;i++){
        soma += temp[i];
    }

    media = soma / n;

    printf("\nMédia das temperaturas = %.2f\n", media);
    printf("Temperaturas acima da média:\n");

    for(int i=0;i<n;i++){
        if(temp[i] > media){
            printf("%.2f\n", temp[i]);
        }
    }
}

// ---------------- MAIN ----------------
int main(){

    // --------- QUESTÃO 1 - PILHA ---------
    Pilha p1, p2;
    inicializarPilha(&p1);
    inicializarPilha(&p2);

    int x;
    printf("=== PILHA ===\n");
    printf("Digite 5 valores da Pilha 1:\n");
    for(int i=0;i<TAM_PILHA;i++){
        scanf("%d", &x);
        empilhar(&p1, x);
    }

    printf("Digite 5 valores da Pilha 2:\n");
    for(int i=0;i<TAM_PILHA;i++){
        scanf("%d", &x);
        empilhar(&p2, x);
    }

    if(pilhasIguais(p1, p2))
        printf("As pilhas são IGUAIS\n");
    else
        printf("As pilhas são DIFERENTES\n");

    // --------- QUESTÃO 2 - FILA ---------
    Fila f, f1, f2;
    inicializarFila(&f);
    inicializarFila(&f1);
    inicializarFila(&f2);

    printf("\n=== FILA ===\n");
    printf("Digite 10 valores da fila:\n");
    for(int i=0;i<TAM_FILA;i++){
        scanf("%d", &x);
        enfileirar(&f, x);
    }

    dividirFila(&f, &f1, &f2);

    printf("Fila com índices pares:\n");
    mostrarFila(f1);

    printf("Fila com índices ímpares:\n");
    mostrarFila(f2);

    // --------- QUESTÃO 3 - LISTA ---------
    float temperaturas[TAM_TEMP];

    printf("\n=== LISTA (Temperaturas) ===\n");
    printf("Digite as temperaturas médias de Jan a Abril:\n");
    for(int i=0;i<TAM_TEMP;i++){
        scanf("%f", &temperaturas[i]);
    }

    analisarTemperaturas(temperaturas, TAM_TEMP);

    return 0;
}
