// Makoto Ushizaki - RA10769688
// Pedro Henrique Lima Souza - RA10770044
// Eduarda Joseane Cocurulli - RA10769494

// Projeto ADAS - Safedrive - Processamento de telemetria veicular

#include <stdio.h> // Padrão de entrada e saída
#include <stdlib.h> // Geração de números aleatórios
#include <time.h> // Alimenta a semente de aleatoriedade (srand(time(NULL)))
#include <locale.h> // Permite acentuação (ex. pt_BR)

#define MAX_AMOSTRAS 100

int inicializarDados(float velocidades[][2], float frontais[][3], float laterais[][2], int sensibilidade) {
    for(int i = 0; i < 50; i++) { // 0 ~ 49
        if (sensibilidade == 1) { 
            // Modo Esportivo
            velocidades[i][0] = 120.0 + (rand() % 181); // 120 ~ 300
            velocidades[i][1] = 100.0 + (rand() % 250); // 100 ~ 349
        } else if (sensibilidade == 2) {
            // Modo Normal
            velocidades[i][0] = 60.0 + (rand() % 60); // 60 ~ 119
            velocidades[i][1] = 50.0 + (rand() % 50); // 50 ~ 99
        } else {
            // Modo Seguro
            velocidades[i][0] = 40.0 + (rand() % 40); // 40 ~ 79
            velocidades[i][1] = 30.0 + (rand() % 40); // 30 ~ 69
        }
        
        // Geração de leituras dos sensores frontais (baseado em uma distância aleatória)
        float distanciaBase = 15.0 + (rand() % 80); // Distâncias maiores para comportar altas velocidades (15 ~ 94m)
        frontais[i][0] = distanciaBase + ((rand() % 5) - 2); // Radar
        frontais[i][1] = distanciaBase + ((rand() % 5) - 2); // Lidar
        frontais[i][2] = distanciaBase + ((rand() % 5) - 2); // Câmera
        
        // Geração de leituras dos sensores laterais (0.30 a 1.29m)
        laterais[i][0] = 0.3 + (rand() % 100) / 100.0; // Faixa Esquerda
        laterais[i][1] = 0.3 + (rand() % 100) / 100.0; // Faixa Direita
    }
    return 50; 
}

void calcularFusaoSensores(int total, float frontais[][3], float processamento[][2]) {
    for (int i = 0; i < total; i++) {
        float sensorRadar = frontais[i][0];
        float sensorLidar = frontais[i][1];
        float sensorCamera = frontais[i][2];
        
        float max = (sensorRadar > sensorLidar) ? ((sensorRadar > sensorCamera) ? sensorRadar : sensorCamera) : ((sensorLidar > sensorCamera) ? sensorLidar : sensorCamera);
        float min = (sensorRadar < sensorLidar) ? ((sensorRadar < sensorCamera) ? sensorRadar : sensorCamera) : ((sensorLidar < sensorCamera) ? sensorLidar : sensorCamera);
        
        processamento[i][0] = sensorRadar + sensorLidar + sensorCamera - max - min; // Distância validada
    }
}

void calcularDistanciaSegura(int total, float velocidades[][2], float processamento[][2], int sensibilidade, float atrito) {
    float tempoReacao = 1.0; // Tempo de reação Esportivo
    if (sensibilidade == 2) tempoReacao = 1.5; // Tempo de reação Normal
    else if (sensibilidade == 3) tempoReacao = 2.0; // Tempo de reação Seguro

    for (int i = 0; i < total; i++) {
        float velocidadeMetrosPorSegundo = velocidades[i][0] / 3.6;
        processamento[i][1] = (velocidadeMetrosPorSegundo * tempoReacao) + ((velocidadeMetrosPorSegundo * velocidadeMetrosPorSegundo) / (2.0 * atrito * 9.81));
    }
}

void analisarRiscoFrontal(int total, float velocidades[][2], float processamento[][2], int status[][3]) {
    for (int i = 0; i < total; i++) {
        float velocidadeAtual = velocidades[i][0]; // Carro atual
        float velocidadeFrente = velocidades[i][1]; // Carro da frente
        float velocidadeRelativa = velocidadeAtual - velocidadeFrente;
        
        if (velocidadeRelativa <= 0) {
            status[i][0] = 0; // Status frontal Seguro
        } else {
            float distanciaValidada = processamento[i][0]; // Mediana
            float distanciaSegura = processamento[i][1]; // Frenagem exigida
            
            if (distanciaValidada >= distanciaSegura) {
                status[i][0] = 0; // Seguro
            } else if (distanciaValidada >= (distanciaSegura * 0.5)) {
                status[i][0] = 1; // Atenção
            } else {
                status[i][0] = 2; // Risco
            }
        }
    }
}

void analisarFaixas(int total, float velocidades[][2], float laterais[][2], int status[][3]) {
    for (int i = 0; i < total; i++) {
        float velocidadeAtual = velocidades[i][0];
        float margemSeguranca = 0.50;
        
        // Aumenta a margem em altas velocidades
        if (velocidadeAtual > 80.0) {
            margemSeguranca += (velocidadeAtual - 80.0) * 0.01;
        }
        float margemAtencao = margemSeguranca + 0.20;

        float faixaEsquerda = laterais[i][0];
        float faixaDireita = laterais[i][1];

        if (faixaEsquerda < margemSeguranca) status[i][1] = 2;
        else if (faixaEsquerda < margemAtencao) status[i][1] = 1;
        else status[i][1] = 0;

        if (faixaDireita < margemSeguranca) status[i][2] = 2;
        else if (faixaDireita < margemAtencao) status[i][2] = 1;
        else status[i][2] = 0;
    }
}

void exibirRelatorio(int total, float velocidades[][2], float frontais[][3], 
                     float laterais[][2], float processamento[][2], int status[][3]) {
    
    printf("\n================| RELATÓRIO DE RISCOS ADAS |================\n");
    for (int i = 0; i < total; i++) {
        printf("\nAMOSTRA [%d]\n", i + 1);
        printf("1. Dados de Entrada:\n");
        printf("   - Vel. Atual: %.2f km/h | Vel. Veículo Frente: %.2f km/h\n", velocidades[i][0], velocidades[i][1]);
        printf("   - Sensores Frontais -> Radar: %.2fm | Lidar: %.2fm | Câmera: %.2fm\n", frontais[i][0], frontais[i][1], frontais[i][2]);
        printf("   - Sensores Laterais -> Faixa Esq: %.2fm | Faixa Dir: %.2fm\n", laterais[i][0], laterais[i][1]);
        
        printf("2. Dados Processados:\n");
        printf("   - Distância Frontal Validada: %.2fm\n", processamento[i][0]);
        printf("   - Distância Segura Exigida: %.2fm\n", processamento[i][1]);
        
        printf("3. Alertas:\n");
        
        printf("   - Frontal: ");
        if (status[i][0] == 0) printf("SEGURO\n");
        else if (status[i][0] == 1) printf("ATENÇÃO\n");
        else printf("RISCO DE COLISÃO (AEB ACIONADO)\n");

        printf("   - Faixa Esquerda: ");
        if (status[i][1] == 0) printf("NORMAL\n");
        else if (status[i][1] == 1) printf("ATENÇÃO\n");
        else printf("PERIGO DE INVASÃO\n");

        printf("   - Faixa Direita: ");
        if (status[i][2] == 0) printf("NORMAL\n");
        else if (status[i][2] == 1) printf("ATENÇÃO\n");
        else printf("PERIGO DE INVASÃO\n");

        printf("4. DECISÃO: ");
        if (status[i][0] == 2 || status[i][1] == 2 || status[i][2] == 2) {
            printf("STATUS GERAL: INTERVENÇÃO CRÍTICA EXIGIDA\n");
        } else if (status[i][0] == 1 || status[i][1] == 1 || status[i][2] == 1) {
            printf("STATUS GERAL: ATENÇÃO\n");
        } else {
            printf("STATUS GERAL: NORMAL\n");
        }
        printf("|----------------------------------------------------------|\n");
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    float velocidades[MAX_AMOSTRAS][2];
    float sensores_frontais[MAX_AMOSTRAS][3];
    float sensores_laterais[MAX_AMOSTRAS][2];
    float processamento[MAX_AMOSTRAS][2];
    int status[MAX_AMOSTRAS][3];

    int totalAmostras = 0;
    float atrito;
    int sensibilidade;

    printf("=========| SAFEDRIVE ADAS |=========\n");
    printf("Informe o atrito da via (ex: 0,7 para asfalto seco): ");
    scanf("%f", &atrito);
    
    printf("Informe a sensibilidade (1-Esportivo, 2-Normal, 3-Seguro): ");
    scanf("%d", &sensibilidade);

    int opcao = 0;
    while (opcao != 4) {
        printf("\n===========| MENU |===========\n");
        printf("1. Carregar dados iniciais (50 registros)\n");
        printf("2. Inserir nova amostra\n");
        printf("3. Processar e exibir relatório de riscos\n");
        printf("4. Sair\n");
        printf("-----------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            totalAmostras = inicializarDados(velocidades, sensores_frontais, sensores_laterais, sensibilidade);
            printf("-> 50 amostras aleatórias geradas com sucesso.\n");
        } 
        else if (opcao == 2) {
            if (totalAmostras >= MAX_AMOSTRAS) {
                printf("-> Erro: Limite máximo de amostras (%d) atingido.\n", MAX_AMOSTRAS);
            } else {
                printf("\n--- INSERINDO AMOSTRA [%d] ---\n", totalAmostras + 1);
                printf("Velocidade atual (km/h): ");
                scanf("%f", &velocidades[totalAmostras][0]);
                printf("Velocidade do veículo à frente (km/h): ");
                scanf("%f", &velocidades[totalAmostras][1]);
                
                printf("Leitura do Radar (m): ");
                scanf("%f", &sensores_frontais[totalAmostras][0]);
                printf("Leitura do Lidar (m): ");
                scanf("%f", &sensores_frontais[totalAmostras][1]);
                printf("Leitura da Câmera (m): ");
                scanf("%f", &sensores_frontais[totalAmostras][2]);
                
                printf("Distância da faixa esquerda (m): ");
                scanf("%f", &sensores_laterais[totalAmostras][0]);
                printf("Distância da faixa direita (m): ");
                scanf("%f", &sensores_laterais[totalAmostras][1]);
                
                totalAmostras++;
                printf("-> Amostra registrada com sucesso.\n");
            }
        } 
        else if (opcao == 3) {
            if (totalAmostras == 0) {
                printf("-> Nenhuma amostra na memória. Use a opção 1 ou 2 primeiro.\n");
            } else {
                calcularFusaoSensores(totalAmostras, sensores_frontais, processamento);
                calcularDistanciaSegura(totalAmostras, velocidades, processamento, sensibilidade, atrito);
                analisarRiscoFrontal(totalAmostras, velocidades, processamento, status);
                analisarFaixas(totalAmostras, velocidades, sensores_laterais, status);
                
                exibirRelatorio(totalAmostras, velocidades, sensores_frontais, sensores_laterais, processamento, status);
            }
        }
    }

    printf("Encerrando o simulador Safedrive...\n\n");
    return 0;
}