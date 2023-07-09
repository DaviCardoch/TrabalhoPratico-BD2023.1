#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <list>
#include "acessoDB.h"
#include "entidades.h"


class IServicoAutenticacao {
public:
    virtual bool autenticar(string matricula, string senha) = 0;
    virtual ~IServicoAutenticacao(){}
};

class IServicoEstudante {
public:
    virtual bool cadastrar(Estudante) = 0;
    virtual bool descadastrar(string matricula) = 0;
    virtual bool alterar(Estudante) = 0;
    virtual Estudante recuperar(string matricula) = 0;
    virtual ~IServicoEstudante(){}
};

class IServicoAvaliacao {
public:
    virtual bool cadastrarAvaliacao(Avaliacao avaliacao) = 0;
    virtual bool alterar(Avaliacao avaliacao) = 0;
    virtual Avaliacao recuperarAvaliacao(string) = 0;
    virtual list<Avaliacao> recuperarAvaliacoes() = 0;
    virtual list<Avaliacao> recuperarAvaliacoes(string matricula) = 0;
    virtual string recuperarDonoAvaliacao(string) = 0; //retorna matricula
    virtual bool deletarAvaliacao(Avaliacao) = 0;

    virtual bool deletarDenuncia(string codAvaliacao, string matricula) = 0;
    virtual bool cadastrarDenuncia(Denuncia) = 0;
    virtual list<Denuncia> recuperarDenuncias() = 0;
    virtual list<Denuncia> recuperarDenuncias(Estudante estudante) = 0;
    virtual list<Denuncia> recuperarDenuncias(string codigo) = 0;
    virtual list<string> recuperarCodigosDenuncias(string matricula) = 0;
    virtual ~IServicoAvaliacao(){}

    virtual Estudante recuperarEstudante(string matricula) = 0;
};

class IApresentacaoAutenticacao {
public:
    virtual bool autenticar(string*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoEstudante {
public:
    virtual void cadastrar(string adm) = 0;
    virtual bool executar(string) = 0;
    virtual void setCntrServicoEstudante(IServicoEstudante*) = 0;
    virtual ~IApresentacaoEstudante(){}
};

class IApresentacaoAvaliacao {
public:
    virtual void executar(string matricula) = 0;
    virtual void setCntrServicoAvaliacao(IServicoAvaliacao*) = 0;
    virtual ~IApresentacaoAvaliacao(){}
};


#endif // INTERFACES_H_INCLUDED

