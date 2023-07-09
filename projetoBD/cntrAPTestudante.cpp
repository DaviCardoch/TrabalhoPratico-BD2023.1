#include "cntrAPTestudante.h"

bool CntrApresentacaoEstudante::executar(string matricula) {
    Estudante estudante;
    estudante = cntrServicoEstudante->recuperar(matricula);
    if(estudante.getAdm()=="usr"){
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar dados pessoais.";
    char texto3[] = "2 - Editar dados pessoais.";
    char texto4[] = "3 - Excluir meu usuario.";
    char texto5[] = "4 - Retornar.";

    int campo;

    bool apresentar = true;


    while(apresentar) {

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;
         switch(campo){
            case 1:
                consultarDadosEstudante(matricula);
                break;
            case 2:
                editarDadosEstudante(matricula);
                break;
            case 3:
                if(excluirEstudante(matricula)){
                    cout << "Usuario excluido com sucesso. Voce nao ira conseguir logar novamente." << endl;
                    getch();
                    return false;
                }
                break;
            case 4:
                apresentar = false;
                break;
            }
        }
        return true;
    }else{

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar dados pessoais.";
    char texto3[] = "2 - Editar dados pessoais.";
    char texto4[] = "3 - Excluir usuario.";
    char texto5[] = "4 - Retornar.";

    int campo;

    bool apresentar = true;


    while(apresentar) {

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;
         switch(campo){
            case 1:
                consultarDadosEstudante(matricula);
                break;
            case 2:
                editarDadosEstudante(matricula);
                break;
            case 3:
                if(excluirEstudante()){
                    cout << "Estudante excluido com sucesso. Voce nao ira conseguir logar novamente." << endl;
                    getch();
                    return false;
                }
                break;
            case 4:
                apresentar = false;
                break;
            }
        }
    }
    return true;
}
bool CntrApresentacaoEstudante::excluirEstudante(string matricula) {
    int campo;
    CLR_SCR;
    cout << "Tem certeza que deseja excluir seu estudante?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao tenho certeza." << endl;
    campo = getch() - 48;
    if (campo == 2){
        cout << "Processo cancelado." << endl;
        getch();
        return false;
    }
    if(cntrServicoEstudante->descadastrar(matricula))
        return true;

    cout << "Falha na exclusao. Tente novamente." << endl;
    getch();
    return false;
}


bool CntrApresentacaoEstudante::excluirEstudante() {
    string campo;
    CLR_SCR;
    cout << "Digite a matricula do estudante a ser excluida." << endl;
    getline(cin, campo);

    if(cntrServicoEstudante->descadastrar(campo))
        return true;

    cout << "Falha na exclusao. Tente novamente." << endl;
    getch();
    return false;
}


void CntrApresentacaoEstudante::cadastrar(string adm) {
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Matricula       :";
    char texto3[] = "Email           :";
    char texto4[] = "Curso           :";
    char texto5[] = "Senha           :";
    char texto6[] = "Nome            :";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";
    string campo1, campo2, campo3, campo4, campo5;


    bool apresentar = true;

    while(apresentar){
        CLR_SCR;
        cout << "-----CADASTRO DE ESTUDANTE-----" << endl;
        cout << texto1 << endl;
        cout << texto2 << " ";
        getline(cin, campo1);
        cout << texto3 << " ";
        getline(cin, campo2);
        cout << texto4 << " ";
        getline(cin, campo3);
        cout << texto5 << " ";
        getline(cin, campo4);
        cout << texto6 << " ";
        getline(cin, campo5);

        apresentar=false;
    }

    Estudante estudante;

    estudante.setMatricula(campo1);
    estudante.setEmail(campo2);
    estudante.setCurso(campo3);
    estudante.setSenha(campo4);
    estudante.setNome(campo5);
    estudante.setAdm(adm);


    if(cntrServicoEstudante->cadastrar(estudante)) {
        cout << texto7 << endl;
        getch();
        return;
    }

    cout << texto8 << endl;
    getch();

    return;
}

void CntrApresentacaoEstudante::consultarDadosEstudante(string matricula) {
    Estudante estudante;
    estudante = cntrServicoEstudante->recuperar(matricula);

    CLR_SCR;
    cout << "DADOS DO USUARIO" << endl;
    cout << "Matricula : " << estudante.getMatricula() << endl;
    cout << "Email     : " << estudante.getEmail() << endl;
    cout << "Curso     : " << estudante.getCurso() << endl;
    cout << "Senha     : " << estudante.getSenha() << endl;
    cout << "Nome      : " << estudante.getNome() << endl;

    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoEstudante::editarDadosEstudante(string matricula) {
    string email;
    string curso;
    string senha;
    string nome;
    Estudante estudante;
    estudante = cntrServicoEstudante->recuperar(matricula);

    bool apresentar = true;

    while(apresentar){
        CLR_SCR;
        cout << "-----ATUALIZACAO DE DADOS-----" << endl;
        cout << "---------DADOS ATUAIS---------" << endl;
        cout << "Matricula : " << estudante.getMatricula() << endl;
        cout << "Email     : " << estudante.getEmail() << endl;
        cout << "Curso     : " << estudante.getCurso() << endl;
        cout << "Senha     : " << estudante.getSenha() << endl;
        cout << "Nome      : " << estudante.getNome() << endl;
        cout << "------------------------------" << endl;
        cout << "---------NOVOS DADOS----------" << endl;

        cout << "Alterar email: ";
        getline(cin, email);

        cout << "Alterar curso: ";
        getline(cin, curso);

        cout << "Alterar senha: ";
        getline(cin, senha);

        cout << "Alterar nome: ";
        getline(cin, nome);

        estudante.setEmail(email);
        estudante.setCurso(curso);
        estudante.setSenha(senha);
        estudante.setNome(nome);

            apresentar = false;
    }


    if (cntrServicoEstudante->alterar(estudante))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getch();
}
