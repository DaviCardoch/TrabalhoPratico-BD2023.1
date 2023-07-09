#ifndef CNTRSVCAVALIACAO_H_INCLUDED
#define CNTRSVCAVALIACAO_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include <list>

#include "entidades.h"
#include "interfaces.h"

#include "acessoDB.h"

class CntrServicoAvaliacao: public IServicoAvaliacao {
public:
    list<Avaliacao> recuperarAvaliacoes();
    list<Avaliacao> recuperarAvaliacoes(string matricula);
    bool cadastrarAvaliacao(Avaliacao);
    Avaliacao recuperarAvaliacao(string codigo);
    string recuperarDonoAvaliacao(string codigo);
    bool alterar(Avaliacao);
    bool deletarAvaliacao(Avaliacao);

    bool deletarDenuncia(string codAvaliacao, string matricula);
    bool cadastrarDenuncia(Denuncia);
    list<Denuncia> recuperarDenuncias();
    list<Denuncia> recuperarDenuncias(Estudante estudante);
    list<Denuncia> recuperarDenuncias(string codigo);
    list<string> recuperarCodigosDenuncias(string matricula); //lista de codigos

    Estudante recuperarEstudante(string matricula);
};

#endif // CNTRSVCAVALIACAO_H_INCLUDED
