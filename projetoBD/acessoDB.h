#ifndef ACESSODB_H_INCLUDED
#define ACESSODB_H_INCLUDED
//---------------------------------------------------------------------------
#include "entidades.h"
#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;


//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};
//---------------------------------------------------------------------------
//Classe ElementoResultado.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        bool conectar();
        bool desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "ProjetoBD.db";
        }
        bool executar();
};


//---------------------------------------------------------------------------


class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(string matricula);
        string getResultado();
};

//---------------------------------------------------------------------------


class ComandoPesquisarEstudante:public ComandoSQL {
public:
        ComandoPesquisarEstudante(string matricula);
        Estudante getResultado();
};

//---------------------------------------------------------------------------


class ComandoCadastrarEstudante:public ComandoSQL {
public:
        ComandoCadastrarEstudante(Estudante estudante);
};

//---------------------------------------------------------------------------


class ComandoAtualizarEstudante:public ComandoSQL {
public:
        ComandoAtualizarEstudante(Estudante);
};
//---------------------------------------------------------------------------


class ComandoPesquisarAvaliacoes:public ComandoSQL {
public:
        ComandoPesquisarAvaliacoes();
        ComandoPesquisarAvaliacoes(string matricula);
        list<Avaliacao> getResultado();
};

//---------------------------------------------------------------------------

class ComandoPesquisarAvaliacao:public ComandoSQL {
public:
    ComandoPesquisarAvaliacao(string codigo);
    Avaliacao getResultado();
};
//---------------------------------------------------------------------------

class ComandoPesquisarDonoAvaliacao:public ComandoSQL {
public:
    ComandoPesquisarDonoAvaliacao(string codigo);
    string getResultado(); //retorna matricula
};

//---------------------------------------------------------------------------

class ComandoCadastrarAvaliacao:public ComandoSQL {
public:
    ComandoCadastrarAvaliacao(Avaliacao);
};

//---------------------------------------------------------------------------

class ComandoAtualizarAvaliacao:public ComandoSQL {
public:
    ComandoAtualizarAvaliacao(Avaliacao);
};

//---------------------------------------------------------------------------

class ComandoCadastrarDenuncia:public ComandoSQL {
public:
    ComandoCadastrarDenuncia(Denuncia);
};

class ComandoPesquisarDenuncias:public ComandoSQL {
public:
    ComandoPesquisarDenuncias();
    ComandoPesquisarDenuncias(string matricula);
    ComandoPesquisarDenuncias(Avaliacao Avaliacao);
    list<Denuncia> getResultado();
};

class ComandoPesquisarCodigosAvaliacoesDenunciadas: public ComandoSQL {
public:
    ComandoPesquisarCodigosAvaliacoesDenunciadas(string matricula);
    list<string> getResultado(); //retorna codigo da avaliacao
};

class ComandoDeletarDenuncia: public ComandoSQL {
public:
    ComandoDeletarDenuncia(string codAvaliacao, string matricula);
    ComandoDeletarDenuncia(Avaliacao avaliacao);
    ComandoDeletarDenuncia(string matricula);
};

class ComandoDeletarAvaliacao: public ComandoSQL {
public:
    ComandoDeletarAvaliacao(string codigo);
};


class ComandoDeletarEstudante: public ComandoSQL {
public:
    ComandoDeletarEstudante(string matricula);
};


#endif // ACESSODB_H_INCLUDED

