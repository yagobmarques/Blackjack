#include "mesa.h"
#include "colors.h"
Mesa::Mesa()
{
  this->valor_chave = 0;
}
Mesa::~Mesa()
{
}
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
string Mesa::analisaParados(vector<Jogador> jogadores)
{
  vector<Jogador> aux;
  Jogador aux1;
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
void Mesa::adicionaJogador()
{
  Jogador j;
  string nome;
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
void Mesa::removeJogador()
{
  string nome;
  cout << "Digite o nome do jogador a ser removido: ";

  getline(cin, nome);
  if (verificaNome(nome) == 1)
  {
    for (unsigned int j = 0; j < this->jogadores.size(); j++)
    {
      if (jogadores[j].getNome() == nome)
      {
        this->jogadores.erase(jogadores.begin() + j);
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
std::__cxx11::string Mesa::iniciaPartida(std::vector<Jogador> jogadores)
{
  string choice;
  int aux = -2;
  cout << BOLDBLUE << "===== Partida iniciada! =====\n"
       << RESET << endl;
  cout << "O valor chave da partida eh " << BOLDYELLOW << this->valor_chave << RESET << endl;
  cout << endl;
  int v = 0; //variavel que faz a condição de parada da partida
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
          cout<<jogadores[j].jogarDados()<<" esta com "<<jogadores[j].getSoma_acumulada()<<endl;
        }
        if (jogadores[j].getSoma_acumulada() > this->valor_chave)
        {
          jogadores[j].setStatus(-1);
          //jogadores.erase(jogadores.begin()+j);
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
  return analisaParados(jogadores);
}

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
int Mesa::run()
{
  this->aux = 1;
  string resposta, vencedor;
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