#include "cntrSVCautenticacao.h"

bool CntrServicoAutenticacao::autenticar(string matricula, string senha) {
    ComandoLerSenha lerSenha(matricula);
    if (!lerSenha.executar())
        return 0;
    string senhaRecuperada;
    senhaRecuperada = lerSenha.getResultado();
    return (senha == senhaRecuperada);
}
