#include <string.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "interfaces.h"

#include "cntrAPTcontrole.h"
#include "cntrAPTautenticacao.h"
#include "cntrAPTestudante.h"
#include "cntrAPTavaliacao.h"

#include "cntrSVCautenticacao.h"
#include "cntrSVCestudante.h"
#include "cntrSVCavaliacao.h"

using namespace std;

int main() {
    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoEstudante *cntrApresentacaoEstudante;
    IApresentacaoAvaliacao *cntrApresentacaoAvaliacao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoEstudante = new CntrApresentacaoEstudante();
    cntrApresentacaoAvaliacao = new CntrApresentacaoAvaliacao();

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoEstudante *cntrServicoEstudante;
    IServicoAvaliacao *cntrServicoAvaliacao;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoEstudante = new CntrServicoEstudante();
    cntrServicoAvaliacao = new CntrServicoAvaliacao();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoEstudante(cntrApresentacaoEstudante);
    cntrApresentacaoControle->setCntrApresentacaoAvaliacao(cntrApresentacaoAvaliacao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoEstudante->setCntrServicoEstudante(cntrServicoEstudante);
    cntrApresentacaoAvaliacao->setCntrServicoAvaliacao(cntrServicoAvaliacao);

    cntrApresentacaoControle->executar();

    return 0;
}
