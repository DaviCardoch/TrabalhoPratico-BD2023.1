#ifndef CNTRAPTESTUDANTE_H_INCLUDED
#define CNTRAPTESTUDANTE_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");
class CntrApresentacaoEstudante:public IApresentacaoEstudante{
private:
    IServicoEstudante *cntrServicoEstudante;
    void consultarDadosEstudante(string matricula);
    void editarDadosEstudante(string matricula);
    bool excluirEstudante(string matricula);
    bool excluirEstudante();
public:
    void cadastrar(string adm);
    bool executar(string matricula);
    void setCntrServicoEstudante(IServicoEstudante*);
};

inline void CntrApresentacaoEstudante::setCntrServicoEstudante(IServicoEstudante *cntr){
    cntrServicoEstudante = cntr;
}

#endif // CNTRAPTESTUDANTE_H_INCLUDED
