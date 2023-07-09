#ifndef CNTRAPTAVALIACAO_H_INCLUDED
#define CNTRAPTAVALIACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <iterator>

#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoAvaliacao:public IApresentacaoAvaliacao {
private:
    IServicoAvaliacao *cntr;
    string avaliacaoGeradorCodigo();

    void mostrarAvaliacao(Avaliacao);
    void listarAvaliacoes();
    void listarAvaliacoes(string matricula);
    void listarAvaliacao();
    void cadastrarAvaliacao(string matricula);
    void editarAvaliacao(string matricula);
    void descadastrarAvaliacao(string matricula);

    //void imoveisPropostas(Email);
    //void imovelPropostas(Email);

    void cadastrarDenuncia(string matricula);
    void descadastrarDenuncia(string matricula);
    void listarDenuncias();
    void mostrarDenuncia(Denuncia);
    void telaDenuncias(string matricula);
public:
    void executar(string matricula);
    void setCntrServicoAvaliacao(IServicoAvaliacao*);
};

inline void CntrApresentacaoAvaliacao::setCntrServicoAvaliacao(IServicoAvaliacao *cntr) {
    this->cntr = cntr;
}

#endif // CNTRAPTAVALIACAO_H_INCLUDED
