#include "cntrSVCavaliacao.h"

list<Avaliacao> CntrServicoAvaliacao::recuperarAvaliacoes() {
    ComandoPesquisarAvaliacoes pesquisarAvaliacoes;
    pesquisarAvaliacoes.executar();
    return pesquisarAvaliacoes.getResultado();
}

list<Avaliacao> CntrServicoAvaliacao::recuperarAvaliacoes(string matricula) {
    ComandoPesquisarAvaliacoes pesquisarAvaliacoes(matricula);
    pesquisarAvaliacoes.executar();
    return pesquisarAvaliacoes.getResultado();
}

Avaliacao CntrServicoAvaliacao::recuperarAvaliacao(string codigo) {
    ComandoPesquisarAvaliacao pesquisarAvaliacao(codigo);
    pesquisarAvaliacao.executar();
    return pesquisarAvaliacao.getResultado();
}

bool CntrServicoAvaliacao::cadastrarAvaliacao(Avaliacao avaliacao){
    ComandoCadastrarAvaliacao cadastrarAvaliacao(avaliacao);
    return cadastrarAvaliacao.executar();
}

string CntrServicoAvaliacao::recuperarDonoAvaliacao(string codigo) {
    ComandoPesquisarDonoAvaliacao pesquisarDonoAvaliacao(codigo);
    pesquisarDonoAvaliacao.executar();
    return pesquisarDonoAvaliacao.getResultado();
}

bool CntrServicoAvaliacao::alterar(Avaliacao avaliacao) {
    ComandoAtualizarAvaliacao atualizarAvaliacao(avaliacao);
    return atualizarAvaliacao.executar();
}

bool CntrServicoAvaliacao::cadastrarDenuncia(Denuncia denuncia) {
    ComandoCadastrarDenuncia cadastrarDenuncia(denuncia);
    return cadastrarDenuncia.executar();
}

list<Denuncia> CntrServicoAvaliacao::recuperarDenuncias() {
    ComandoPesquisarDenuncias pesquisarDenuncias;
    pesquisarDenuncias.executar();
    return pesquisarDenuncias.getResultado();
}

list<Denuncia> CntrServicoAvaliacao::recuperarDenuncias(Estudante estudante) {
    ComandoPesquisarDenuncias pesquisarDenuncias(estudante.getMatricula());
    pesquisarDenuncias.executar();
    return pesquisarDenuncias.getResultado();
}

list<Denuncia> CntrServicoAvaliacao::recuperarDenuncias(string codigo) {
    ComandoPesquisarDenuncias pesquisarDenuncias(codigo);
    pesquisarDenuncias.executar();
    return pesquisarDenuncias.getResultado();
}

    list<string> CntrServicoAvaliacao::recuperarCodigosDenuncias(string matricula) {
    ComandoPesquisarCodigosAvaliacoesDenunciadas codigosAvaliacoes(matricula);
    codigosAvaliacoes.executar();
    return codigosAvaliacoes.getResultado();
}

bool CntrServicoAvaliacao::deletarDenuncia(string codAvaliacao, string matricula) {
    ComandoDeletarDenuncia deletardenuncia(codAvaliacao,matricula);
    return deletardenuncia.executar();
}

bool CntrServicoAvaliacao::deletarAvaliacao(Avaliacao avaliacao) {
    string codigo;
    codigo = avaliacao.getCodigo();
    ComandoDeletarAvaliacao deletarAvaliacao(codigo);
    ComandoDeletarDenuncia deletarDenuncia(avaliacao);
    deletarDenuncia.executar();
    return deletarAvaliacao.executar();
}

Estudante CntrServicoAvaliacao::recuperarEstudante(string matricula) {
    ComandoPesquisarEstudante pesquisarEstudante(matricula);
    pesquisarEstudante.executar();
    Estudante estudante;
    estudante = pesquisarEstudante.getResultado();

    return estudante;
}
