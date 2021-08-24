/* 
    Define o tamanho do array que uma página pode carregar os dados em memória principal.
    Usado para simular ordenação externa de quantidade de dados que não caberiam na memória
    principal.

    Para definir esse valor deve-se considerar que até 3 páginas podem ter seus dados 
    carregados na memória. Sendo assim esse valor, no contexto da avaliação da disciplina
    de estrutura de dados irá definir o tamanho inicial de uma página.

    Seus valores, no contexto da avaliação irão variar entre 1.000, 10.000, 100.000 e 1.000.000, onde
    pode-se assumir que a memória principal (desconsiderando outras necessidades) comporta até
    3 vezes essa quantidade de dados 
    -- 
*/
#ifndef MEMORIA_TOTAL
#define MEMORIA_TOTAL 500000
#endif