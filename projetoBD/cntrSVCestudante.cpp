#include "cntrSVCestudante.h"

bool CntrServicoEstudante::cadastrar(Estudante estudante) {
    ComandoCadastrarEstudante cadastrarEstudante(estudante);
    return cadastrarEstudante.executar();
}

Estudante CntrServicoEstudante::recuperar(string matricula) {
    ComandoPesquisarEstudante pesquisarEstudante(matricula);
    pesquisarEstudante.executar();
    Estudante estudante;
    estudante = pesquisarEstudante.getResultado();

    return estudante;
}

bool CntrServicoEstudante::alterar(Estudante estudante) {
    ComandoAtualizarEstudante atualizarEstudante(estudante);
    return atualizarEstudante.executar();
}

bool CntrServicoEstudante::descadastrar(string matricula) {

    ComandoDeletarAvaliacao deletarMinhasAvaliacoes(matricula);
    deletarMinhasAvaliacoes.executar();

    list<Avaliacao> avaliacoes = recuperarAvaliacoes(matricula);
    Avaliacao avaliacao;
    string codigo;

    while (!avaliacoes.empty()){
        avaliacao = avaliacoes.back();
        avaliacoes.pop_back();
        codigo = avaliacao.getCodigo();
        ComandoDeletarDenuncia deletarDenuncia(avaliacao);
        deletarDenuncia.executar();
        ComandoDeletarAvaliacao deletarAvaliacao(codigo);
        deletarAvaliacao.executar();
    }

    ComandoDeletarEstudante deletarEstudante(matricula);
    return deletarEstudante.executar();
}

list<Avaliacao> CntrServicoEstudante::recuperarAvaliacoes(string matricula) {
    ComandoPesquisarAvaliacoes pesquisarAvaliacoes(matricula);
    pesquisarAvaliacoes.executar();
    return pesquisarAvaliacoes.getResultado();
}
