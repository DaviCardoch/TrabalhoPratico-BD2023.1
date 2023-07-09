#ifndef CNTRSVCESTUDANTE_H_INCLUDED
#define CNTRSVCESTUDANTE_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include <list>
#include "entidades.h"
#include "interfaces.h"

#include "acessoDB.h"

class CntrServicoEstudante: public IServicoEstudante {
private:
    list<Avaliacao> recuperarAvaliacoes(string matricula);
public:
    bool cadastrar(Estudante);
    Estudante recuperar(string matricula);
    bool alterar(Estudante);
    bool descadastrar(string matricula);
};

#endif // CNTRSVCESTUDANTE_H_INCLUDED
