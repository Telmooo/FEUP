# Problemas Certos no Exame

- [x] Sistema canonico -> Problema troco, para o sistema ser canonico deve ter a moeda de 1 e 2.

- [x] Invariantes e variantes de ciclos

    Para provar que um ciclo está correto, temos de encontrar um invariante do ciclo -> uma expressão boolean (nas variaveis do ciclo) sempre verdadeira ao longo do ciclo e mostrar que:

        1. é verdadeira inicialmente, i.e, é implicada pela pre-condiçao

        2. é mantida em cada iteraçao, i.e, é verdadeira no fim de cada iteraçao, assumindo que é verdadeira no inicio da iteraçao

        3. quando o ciclo termina, garante (implica) a pos condiçao

    Para provar que um ciclo termina temos de encontrar um variante do ciclo - uma funcao (nas variaveis do ciclo)

    3 Caracteristicas da funcao:
        1. Inteira
        2. Positiva
        3. Estritamente decrescente
    Assim é possivel provar que acaba uma vez que sendo descrescente obrigatorimente atinge 0 (ultimo valor positivo).

- [x] A ordenaçao topoloigica so funciona em DAG's
- [x] É possivel ter mais que uma ordenaçao topologica num grafo DAG
  - vista profundidade (DFS), a pós ordem dá uma ordenaçao topologica inversa
