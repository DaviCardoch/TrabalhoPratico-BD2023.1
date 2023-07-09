#ifndef CNTRAPTAUTENTICACAO_H_INCLUDED
#define CNTRAPTAUTENTICACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
private:
    IServicoAutenticacao *cntr;
public:
    bool autenticar(string*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}


#endif // CNTRAPTAUTENTICACAO_H_INCLUDED
