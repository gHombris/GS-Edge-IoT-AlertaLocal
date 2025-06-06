# Rio Seguro: Sistema de Alerta Local de Enchentes (Edge Computing & IoT)

Este repositório contém a implementação do sistema de monitoramento e alerta local de enchentes, desenvolvido para a disciplina de Edge Computing & IoT da Global Solution 2025.1 - FIAP.

---

## 1. Problema Específico Escolhido

As enchentes, um desafio recorrente no Brasil, afetam desproporcionalmente populações em áreas de risco, como as de **Blumenau/SC**. Mesmo com sistemas de monitoramento avançados, a falta de alertas locais imediatos em pontos críticos das ruas ou residências pode pegar moradores de surpresa, dificultando a evacuação e aumentando os danos materiais e riscos à vida. Este projeto visa mitigar essa lacuna.

---

## 2. Visão Geral da Solução

O "Rio Seguro - Alerta Local" é um protótipo de sistema de monitoramento que atua na "borda" (Edge Computing), provendo avisos diretos à comunidade em tempo real. Ele utiliza um microcontrolador Arduino para processar dados de um sensor de nível e acionar alertas visuais e sonoros com base em limites de segurança.

**Componentes do Circuito:**
* **Placa Microcontroladora:** Arduino Uno
* **Sensor de Nível de Água (simulado):** Potenciômetro
* **Atuadores de Alerta:**
    * LED Verde (Nível Normal)
    * LED Amarelo (Nível de Atenção)
    * LED Vermelho (Nível Crítico)
    * Buzzer (Alerta Sonoro no nível crítico)
* Protoboard e Resistores

**Lógica de Funcionamento:**
1.  O potenciômetro simula o nível da água do rio, variando de 0 a 3 metros.
2.  O Arduino lê continuamente esse valor.
3.  Com base nos níveis predefinidos:
    * **Abaixo de 1.0m:** Acende o LED Verde.
    * **Entre 1.0m e 1.9m:** Acende o LED Amarelo.
    * **A partir de 2.0m:** Acende o LED Vermelho e o Buzzer toca.
4.  O sistema provê uma resposta imediata no local, complementando os alertas da plataforma central do Rio Seguro.



---

## 3. Guia para Simular o Projeto

Você pode simular este projeto diretamente no seu navegador, utilizando o Tinkercad.

1.  Acesse o link direto do projeto no simulador:
    **[https://www.tinkercad.com/things/9f9319fbnIA/editel?returnTo=%2Fdashboard&sharecode=rz6iQ8zQalZ8fv9cOwZdOT0wyO0qVyzBu2BhFIWR3Ck]**
2.  No simulador, clique no botão "Start Simulation" (Iniciar Simulação).
3.  Interaja com o potenciômetro no circuito virtual (clique nele e gire/arraste o controle).
4.  Observe as luzes dos LEDs e o som do buzzer (se houver) mudarem de acordo com o nível simulado. Você também pode abrir o "Serial Monitor" para ver as leituras do nível da água.

---

## 4. Vídeo Demonstrativo

Assista ao vídeo que demonstra o funcionamento do sistema e explica sua importância:

**[]**


---
## Integrantes

* Felipe Kolarevic Santos - RM: 565230
* Gabriel Hombris - RM : 566553
