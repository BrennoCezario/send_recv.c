# Programação Paralela com MPI em C

Este repositório apresenta um exemplo de programação paralela em C utilizando a biblioteca MPI (Message Passing Interface). A MPI é uma ferramenta poderosa para desenvolver aplicações de alto desempenho em ambientes distribuídos, permitindo a comunicação entre processos e a execução de cálculos de forma paralela.

## Funcionalidades Principais

- **Inicialização do ambiente MPI:** Inicie o ambiente MPI usando `MPI_Init` e obtenha informações sobre o número de processos e a identificação de cada processo com `MPI_Comm_size` e `MPI_Comm_rank`.
  
- **Leitura de Argumentos:** O programa lê argumentos da linha de comando para configurar seu comportamento, como o valor de entrada e o nome do arquivo de saída.

- **Comunicação entre Processos:** Demonstra a comunicação entre processos por meio de troca de mensagens, utilizando as funções `MPI_Send` e `MPI_Recv`.

- **Computação Distribuída:** Realiza uma operação simples em computação distribuída, onde cada processo adiciona seu rank a um valor e repassa o resultado para o próximo processo.

- **Escrita em Arquivos:** Exemplo de entrada/saída de dados em ambiente paralelo, escrevendo informações em um arquivo.

## Como Usar

1. **Clone o Repositório:**
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   
2. **Compile o código usando um compilador MPI, por exemplo:**
   ```bash
   mpicc exemplo_mpi.c -o exemplo_mpi

3. **Execute o programa MPI com os argumentos necessários, por exemplo:**
   ```bash
   mpiexec -np 4 ./exemplo_mpi 10 arquivo_saida.txt

# Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para enviar pull requests, relatar problemas ou sugerir melhorias para este exemplo de programação paralela com MPI em C.

# Licença
Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para obter mais detalhes.

