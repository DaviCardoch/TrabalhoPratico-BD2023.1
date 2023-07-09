#include "cntrAPTautenticacao.h"

bool CntrApresentacaoAutenticacao::autenticar(string *matricula) {
    char texto1[]="Digite a matricula: ";
    char texto2[]="Digite a senha: ";

    string campo1;

    string senha;
    bool apresentar=true;
    while(apresentar) {
        CLR_SCR;

        cout << texto1;
        getline(cin, campo1);
        cout << texto2;
        getline(cin, senha);
    *matricula=campo1;
    apresentar=false;
    }
    return (cntr->autenticar(*matricula, senha));
}
