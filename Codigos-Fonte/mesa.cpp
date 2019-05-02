/**
* @file mesa.cpp
* @brief Arquivo .cpp que implementa as funções de mesa.h
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/
#include "mesa.h"
#include "colors.h"
/**
* @brief construtor com valores padrão
* @return Nulo
*/
Mesa::Mesa()
{
  this->valor_chave = 0;
}
/**
* @brief Destrutor
* @return Nulo
*/
Mesa::~Mesa()
{
}
/**
* @brief verifica se um nome já está no vector
* @param nome String digitada pelo usuário
* @return 1 se já existe, 0 se não existe
*/
int Mesa::verificaNome(string nome)
{
  for (unsigned int j = 0; j < this->jogadores.size(); j++)
  {
    if (nome == this->jogadores[j].getNome())
    {
      return 1;
    }
  }
  return 0;
}
/**
* @brief Função que printa na tela todos os jogadores ativos na rodada
* @param jogadores Um vetor do tipo <Jogador>
* @return Se existe alguem jogando 1, senão 0
*/
int Mesa::jogadoresAtivos(vector<Jogador> jogadores)
{
  for (auto j : jogadores)
  {
    if (j.getStatus() == 0)
    {
      return 1;
    }
  }
  return 0;
}
/**
* @brief Analisa os jogadores parados para saber qual chegou mais perto do valor chave
* @param jogadores Vector de jogadores (após o jogo)
* @return String Que é Empate, ou o nome do vencedor!
*/
string Mesa::analisaParados(vector<Jogador> jogadores)
{
  vector<Jogador> aux; /**< Vector do tipo jogador para ordenarmos pelos pontos */
  Jogador aux1; /**< Variável auxiliar para fazermos o swing na hora da comparação */
  for (auto j : jogadores)
  {
    if (j.getStatus() == 1)
    {
      aux.push_back(j);
    }
  }
  for (unsigned int j = 0; j < aux.size(); j++)
  {
    for (unsigned int h = 0; h < aux.size(); h++)
    {
      /**
       * @brief Faz o swing de dois jogadores
       */
      if (aux[j].getSoma_acumulada() < aux[h].getSoma_acumulada())
      {
        aux1 = aux[j];
        aux[j] = aux[h];
        aux[h] = aux1;
      }
    }
  }
  if (aux[aux.size() - 1].getSoma_acumulada() != aux[aux.size() - 2].getSoma_acumulada())
  {
    return aux[aux.size() - 1].getNome();
  }
  else
  {
    return "Empate";
  }
  return "Empate";
}
/**
* @brief Adiciona o jogado com um nome (fornecido pelo usuário) ao vector de jogadores
* @return Void
*/
void Mesa::adicionaJogador()
{
  Jogador j; /**< Variavel do tipo jogador para colocar no vector<Jogador> jogadores */
  string nome; /**< Usado para obter a string digitada pelo usuario */
  cout << "Digite o nome do novo jogador: ";
  getline(cin, nome);
  j.setNome(nome);
  cout << endl;
  if (verificaNome(nome) == 0 && !nome.empty())
  {
    this->jogadores.push_back(j);
    cout << "Jogador(a) " << GREEN << nome << RESET << " adicionado(a)" << endl;
  }
  else
  {
    cout << RED << "O jogador ja esta jogando\nVoltando ao menu..." << RESET << endl;
  }
  cout << endl;
}
/**
* @brief Printa na saida padrão todos os jogadores cadastrados
* @return Void
*/
void Mesa::verJogadores()
{
  cout << "Jogadores ativos:\n"
       << endl;
  for (unsigned int j = 0; j < this->jogadores.size(); j++)
  {
    cout << BOLDBLUE << jogadores[j].getNome() << RESET << endl;
  }
  if (this->jogadores.size() == 0)
  {
    cout << RED << "Ninguem esta na mesa" << RESET << endl;
  }
  cout << endl;
}
/**
* @brief Remove um jogador a partir de um nome fornecido pelo usuário
* @return Void
*/
void Mesa::removeJogador()
{
  string nome; /**< Usado para receber a string digitada pelo usuario */
  cout << "Digite o nome do jogador a ser removido: ";

  getline(cin, nome);
  if (verificaNome(nome) == 1)
  {
    for (unsigned int j = 0; j < this->jogadores.size(); j++)
    {
      if (jogadores[j].getNome() == nome)
      {
        this->jogadores.erase(jogadores.begin() + j); /**< Removendo o jogador a partir do indice */
        cout << "Jogador " << RED << nome << RESET << " removido\n"
             << endl;
        break;
      }
    }
  }
  else
  {
    cout << RED << "Jogador inexiste\n"
         << RESET << endl;
  }
}
/**
* @brief Inicia uma partida
* @param jogadores Vetor do tipo Jogador que tem os jogadores cadastrado pelo usuário
* @return String que contém o nome do vencedor ou "Empate"
*/
string Mesa::iniciaPartida(std::vector<Jogador> jogadores)
{
  string choice; /**< Variavel para capturar a escolha do usuario */
  int aux = -2; /**< Variavel auxiliar para fazer converçoes e garantir o loop de entradas invalidas */
  cout << BOLDBLUE << "===== Partida iniciada! =====\n"
       << RESET << endl;
  cout << "O valor chave da partida eh " << BOLDYELLOW << this->valor_chave << RESET << endl;
  cout << endl;
  int v = 0; /**< variavel que faz a condição de parada da partida */
  while (v == 0)
  {
    for (unsigned int j = 0; j < jogadores.size(); j++)
    {
      if (jogadores[j].getStatus() == 0)
      {
        do
        {
          try
          {
            cout << jogadores[j].getNome() << ", o que desejas fazer?" << endl;
            cout << "1 - Jogar dados" << endl;
            cout << "2 - Parar" << endl;
            cout << "Digite: ";
            getline(cin, choice);
            cout << endl;
            aux = std::stoi(choice);
          }
          catch (const std::exception &e)
          {
            aux = -2;
          }
          if (aux != 1 && aux != 2)
          {
            cout << RED << "Valor invalido\n"
                 << RESET << endl;
            aux = -2;
          }
        } while (aux == -2);
        if (aux == 2)
        {
          jogadores[j].setStatus(1);
        }
        if (jogadores[j].getStatus() == 0)
        {
          jogadores[j].jogarDados();
          cout<<jogadores[j].getNome()<<" esta com "<<jogadores[j].getSoma_acumulada()<<endl;
          cout<<endl;
        }
        if (jogadores[j].getSoma_acumulada() > this->valor_chave)
        {
          jogadores[j].setStatus(-1);
        }
          if (jogadores[j].getSoma_acumulada() == this->valor_chave)
          {
            cout << BLUE << "----- Valores atuais -----" << RESET << endl;
            for (unsigned int j = 0; j < jogadores.size(); j++)
            {
              cout << BOLDBLUE << jogadores[j].getNome() << RESET << ": " << jogadores[j].getSoma_acumulada() << endl;
            }
            cout << endl;
            return jogadores[j].getNome();
          }
      }
    }
    cout << endl;
    cout << "O valor chave da partida eh " << BOLDYELLOW << this->valor_chave << RESET << endl;
    cout << BLUE << "----- Valores atuais -----" << RESET << endl;
    for (unsigned int j = 0; j < jogadores.size(); j++)
    {
      cout << BOLDBLUE << jogadores[j].getNome() << RESET << ": " << jogadores[j].getSoma_acumulada() << endl;
    }
    cout << endl;
    if (jogadoresAtivos(jogadores) == 0)
    {
      v = 1;
    }
  }
  cout << endl;
  Jogador Empate; 
  Empate.setNome("Empate");
  Empate.setStatus(1);
  jogadores.push_back(Empate);
  return analisaParados(jogadores);
}
/**
* @brief Verifica tamanho mínimo dos jogadores para iniciar uma partida
* @return 1 se pode iniciar, ou 0 se não pode
*/
int Mesa::verificaJogadores()
{
  if (this->jogadores.size() > 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
/**
* @brief Inicia os procedimentos da criação de uma mesa
* @return inteiro
*/
int Mesa::run()
{
  /** @brief Variavel que controla o laço do-while e faz as devidas conversoes */
  this->aux = 1; /**< variavel bilbo que controla o laço do while e faz as devidas conversoes */
  string resposta; /**< variavel que auxilia no tratamento da entrada do usuario */
  string vencedor;/**< variavel para printar o vencedor da partida */
  do
  {
    cout << "Entre com o valor chave para o jogo: ";
    try
    {
      getline(cin, resposta);
      this->valor_chave = std::stoi(resposta);
    }
    catch (const std::exception &e)
    {
    }
    if (this->valor_chave == 0 || this->valor_chave < 0)
    {
      cout << RED << "\nEntre com um valor valido!" << RESET << endl;
      cout << endl;
    }

  } while (this->valor_chave == 0 || this->valor_chave < 0);
  cout << endl;
  while (this->aux != 0)
  {
    cout << CYAN << "----- MENU DA MESA ------" << RESET << endl;
    cout << "Escolha uma das funcionalidades: " << endl;
    cout << "1 - Adicionar jogador;" << endl;
    cout << "2 - Remover um jogador;" << endl;
    cout << "3 - Iniciar uma partida;" << endl;
    cout << "4 - Ver jogadores na partida;" << endl;
    cout << "0 - sair;" << endl;
    cout << "Digite: ";
    try
    {
      getline(cin, resposta);
      this->aux = std::stoi(resposta);
    }
    catch (const std::exception &e)
    {
      this->aux = -1;
    }
    cout << endl;
    switch (aux)
    {
    case 0:
      break;
    case 1:
      Mesa::adicionaJogador();
      break;
    case 2:
      Mesa::removeJogador();
      break;
    case 3:
      if (Mesa::verificaJogadores() == 1)
      {
        vencedor = Mesa::iniciaPartida(this->jogadores);
        cout << "O vencedor foi: " << GREEN << vencedor << RESET << endl;
      }
      else
      {
        cout << RED << "Jogadores insificientes :( \n"
             << RESET << endl;
      }
      break;
    case 4:
      Mesa::verJogadores();
      break;
    default:
      cout << RED << "Caractere invalido :(" << RESET << endl;
      break;
    }
  }
  return 0;
}
