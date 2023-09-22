# Coleção de filmes
Neste projeto está um programa em linguagem C responsável por controlar o arquivo
de filmes de um colecionador. O progrma interage com o usuário pelo terminal de execução
para tarefas como:
- Inserção de novo filme
- Remoção de um filme
- Modificar nota de um filme
- Listagem do catálogo
- Pesquisa de filmes por chave ou título
- Compactar arquivo de filmes

O objetivo deste projeto é aplicar os conceitos de arquivos e indexação vistos em sala.

## Árvore rubro negra
Foi utilizado algoritmos de árvore rubro-negra, que foram abordados na matéria de Estrutura de Dados I, para armazenar em memória os valores dos índices primários e secundários.

## Lista dinâmica
Assim como a árvore binária, a estrutura de lista dinâmica também foi ensinada nas aulas de Algoritmo e Técnicas de Programação II e utilizada neste projeto.

## Observações
Para garantir o correto funcionamento do programa, é necessário incluir os arquivos, caso existam, na pasta "Files". Além disso, é importante evitar o uso de sinais de acentuação nos valores do filme, pois o programa só pode ler em UTF-8 (sem caracteres especiais).