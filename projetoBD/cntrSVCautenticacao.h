#ifndef CNTRSVCAUTENTICACAO_H_INCLUDED
#define CNTRSVCAUTENTICACAO_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include "entidades.h"
#include "interfaces.h"

#include "acessoDB.h"

class CntrServicoAutenticacao: public IServicoAutenticacao {
public:
    bool autenticar(string matricula, string senha);
};

#endif // CNTRSVCAUTENTICACAO_H_INCLUDED
