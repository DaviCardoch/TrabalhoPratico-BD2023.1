#ifndef CNTRAPTCONTROLE_H_INCLUDED
#define CNTRAPTCONTROLE_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoControle {
private:
    string matricula;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoEstudante *cntrApresentacaoEstudante;
    IApresentacaoAvaliacao *cntrApresentacaoAvaliacao;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoEstudante(IApresentacaoEstudante*);
    void setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoEstudante(IApresentacaoEstudante *cntr) {
    cntrApresentacaoEstudante = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao *cntr) {
    cntrApresentacaoAvaliacao = cntr;
}

#endif // CNTRAPTCONTROLE_H_INCLUDED
