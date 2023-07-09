#include "cntrAPTavaliacao.h"

void CntrApresentacaoAvaliacao::executar(string matricula) {
 int campo;
    while(true) {
        CLR_SCR;

        cout << "---------SERVICOS AVALIACOES---------" << endl;
        cout << "1 - Listar todas as avaliacoes." << endl;
        cout << "2 - Pesquisar uma avaliacao pelo codigo." << endl;
        cout << "3 - Cadastrar uma avaliacao." << endl;
        cout << "4 - Editar uma avaliacao." << endl;
        cout << "5 - Descadastrar uma avaliacao." << endl;
        cout << "6 - Listar minhas avaliacoes. " << endl;
        cout << "7 - Servicos de denuncias." << endl;
        cout << "8 - Retorne para tela inicial." << endl;

        campo = getch() - 48;

        switch(campo){
            case 1:
                listarAvaliacoes();
                break;
            case 2:
                listarAvaliacao();
                break;
            case 3:
                cadastrarAvaliacao(matricula);
                break;
            case 4:
                editarAvaliacao(matricula);
                break;
            case 5:
                descadastrarAvaliacao(matricula);
                break;
            case 6:
                listarAvaliacoes(matricula);
                break;
            case 7:
                telaDenuncias(matricula);
                break;
            case 8:
                return;
            }
        }
}
void CntrApresentacaoAvaliacao::descadastrarAvaliacao(string matricula) {
    Estudante estudante;
    estudante = cntr->recuperarEstudante(matricula);
    list<Avaliacao> avaliacoes;
    if(estudante.getAdm()=="usr"){
        avaliacoes = cntr->recuperarAvaliacoes(matricula);
    }else{
        avaliacoes = cntr->recuperarAvaliacoes();
    }
    list<Avaliacao> :: iterator avaliacao;
    string codigo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo da avaliacao que deseja deletar: ";
        getline(cin, codigo);
        for(avaliacao = avaliacoes.begin(); avaliacao!= avaliacoes.end(); ++avaliacao) {
            if((*avaliacao).getCodigo() == codigo){
                cntr->deletarAvaliacao(*avaliacao);
                apresentar = false;
                cout << "Avaliacao deletada com sucesso." << endl;
                cout << "Digite algo para retornar." << endl;
                getch();
                return;
            }
        }
        if(avaliacao == avaliacoes.end()){
            cout << "Avaliacao nao encontrada." << endl;
            cout << "Digite algo para retornar." << endl;
            getch();
            return;
        }
    }
}

void CntrApresentacaoAvaliacao::listarAvaliacoes() {
    list<Avaliacao> avaliacoes = cntr->recuperarAvaliacoes();
    list<Avaliacao> :: iterator avaliacao;
    CLR_SCR;
    cout << "-------------------------LISTA DE AVALIACOES-------------------------" << endl;
    for(avaliacao = avaliacoes.begin(); avaliacao!= avaliacoes.end(); ++avaliacao) {
        mostrarAvaliacao(*avaliacao);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoAvaliacao::listarAvaliacoes(string matricula) {
    list<Avaliacao> avaliacoes = cntr->recuperarAvaliacoes(matricula);
    list<Avaliacao> :: iterator avaliacao;
    CLR_SCR;
    cout << "-------------------------LISTA DE AVALIACOES-------------------------" << endl;
    for(avaliacao = avaliacoes.begin(); avaliacao!= avaliacoes.end(); ++avaliacao) {
        mostrarAvaliacao(*avaliacao);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}
void CntrApresentacaoAvaliacao::descadastrarDenuncia(string matricula) {
    list<Denuncia> denuncias = cntr->recuperarDenuncias(matricula);
    list<Denuncia> :: iterator denuncia;
    string codigo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo da avaliacao cuja denuncia deseja-se deletar: ";
        getline(cin, codigo);
        for(denuncia = denuncias.begin(); denuncia!= denuncias.end(); ++denuncia) {
            if((*denuncia).getCodAvaliacao() == codigo){
                cntr->deletarDenuncia(codigo, matricula);
                apresentar = false;
                cout << "Denuncia deletada com sucesso." << endl;
                cout << "Digite algo para retornar." << endl;
                getch();
                return;
            }
        }
        if(denuncia == denuncias.end()){
            cout << "Proposta nao encontrada." << endl;
            cout << "Digite algo para retornar." << endl;
            getch();
            return;
        }
    }
}

void CntrApresentacaoAvaliacao::listarDenuncias(){
    list<Denuncia> denuncias = cntr->recuperarDenuncias();
    list<Denuncia> :: iterator denuncia;
    CLR_SCR;
    cout << "--------------------LISTA DE AVALIACOES DENUNCIADAS--------------------" << endl;
    for(denuncia = denuncias.begin(); denuncia!= denuncias.end(); ++denuncia) {
        mostrarDenuncia(*denuncia);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoAvaliacao::cadastrarDenuncia(string matricula) {
    string codAvaliacao;
    Denuncia denuncia;

    list<Denuncia> denuncias = cntr->recuperarDenuncias(cntr->recuperarEstudante(matricula));
    list<Denuncia> :: iterator denu;

    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "----------CADASTRO DE DENUNCIA----------" << endl;
        cout << "Codigo da avaliacao a ser denunciada: ";
        getline(cin, codAvaliacao);

        for(denu = denuncias.begin(); denu!= denuncias.end(); ++denu) {
            if((*denu).getCodAvaliacao() == codAvaliacao){
                cout << "Voce ja tem uma denuncia cadastrada para essa avaliacao." << endl;
                apresentar = false;
                cout << "Digite algo para retornar" << endl;
                getch();
                return;
            }
        }

        apresentar = false;
    }

    denuncia.setMatricula(matricula);
    denuncia.setCodAvaliacao(codAvaliacao);

    if (cntr->cadastrarDenuncia(denuncia)){
        cout << "Denuncia cadastrado com sucesso." << endl;
        getch();
        return;
    }
    cout << "Falha no cadastramento da denuncia. Tente novamente." << endl;
    cout << "Digite para retornar." << endl;
    getch();
}

void CntrApresentacaoAvaliacao::telaDenuncias(string matricula) {
    bool apresentar = true;
    int campo_denuncia;
    while(apresentar){
        CLR_SCR;
        cout << "---------SERVICOS DENUNCIAS---------" << endl;
        cout << "1 - Visualizar denuncias." << endl;
        cout << "2 - Efetuar denuncia." << endl;
        cout << "3 - Descadastrar denuncia." << endl;
        cout << "4 - Retorne para tela de avaliacoes." << endl;
        campo_denuncia = getch() - 48;

        switch(campo_denuncia) {
            case 1:
                listarDenuncias();
                break;
            case 2:
                cadastrarDenuncia(matricula);
                break;
            case 3:
                descadastrarDenuncia(matricula);
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoAvaliacao::editarAvaliacao(string matricula) {
    string codigo;
    string matricula_autenticacao;
    string codProfessor;
    string avaliacao;
    Avaliacao avaliacao_entidade;

    int campo;
    bool apresentar = true;

    while(apresentar){
        try {
            CLR_SCR;
            cout << "-----ATUALIZACAO DE DADOS DE AVALIACAO-----" << endl;
            cout << " Codigo da avaliacao a ser alterada:" << endl;
            getline(cin, codigo);
            avaliacao_entidade = cntr->recuperarAvaliacao(codigo);
            matricula = cntr->recuperarDonoAvaliacao(codigo);
            matricula_autenticacao = avaliacao_entidade.getMatricula();
            if (matricula != matricula_autenticacao){
                cout << "Voce nao tem permissao para editar essa avaliacao." << endl;
                getch();
                return;
            }

            cout << "-----AVALIACAO A SER EDITADA-----" << endl;
            mostrarAvaliacao(avaliacao_entidade);


            cout << "Alterar avaliacao: ";
            getline(cin, avaliacao);

            avaliacao_entidade.setAvaliacao(avaliacao);

            apresentar = false;
        } catch(...){
            cout << "Imovel nao existe ou dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }

    if (cntr->alterar(avaliacao_entidade))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(string matricula) {
    string codigo;
    string codProfessor;
    string avaliacao;
    Avaliacao entidade_avaliacao;

    bool apresentar = true;
    while(apresentar) {
        CLR_SCR;
        cout << "----------CADASTRO DE AVALIACAO----------" << endl;
        cout << "Codigo do Professor: " << endl;
        getline(cin, codProfessor);
        cout << "Avaliacao: ";
        getline(cin, avaliacao);

        apresentar = false;
        codigo =avaliacaoGeradorCodigo();
    }

    entidade_avaliacao.setCodigo(codigo);
    entidade_avaliacao.setMatricula(matricula);
    entidade_avaliacao.setCodProfessor(codProfessor);
    entidade_avaliacao.setAvaliacao(avaliacao);

    if (cntr->cadastrarAvaliacao(entidade_avaliacao)){
        cout << "Avaliacao cadastrado com sucesso." << endl;
        cout << "Codigo do avaliacao: " <<entidade_avaliacao.getCodigo() << endl;
        getch();
        return;
    }
    cout << "Falha no cadastramento da avaliacao. Tente novamente." << endl;
    cout << "Digite para retornar." << endl;
    getch();
}

string CntrApresentacaoAvaliacao::avaliacaoGeradorCodigo(){
    list<Avaliacao> avaliacoes = cntr->recuperarAvaliacoes();
    string novo_codigo = "A0000", id;
    id = to_string(stoi(avaliacoes.back().getCodigo().substr(1, 4)) + 1);
    int tam1 = id.length(), tam2 = novo_codigo.length();
    novo_codigo = novo_codigo.substr(0, tam2-tam1)+id;

    return novo_codigo;
}

void CntrApresentacaoAvaliacao::listarAvaliacao(){
    Avaliacao avaliacao;
    string codigo;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo da avaliacao que deseja visualizar: ";
        try {
            getline(cin, codigo);
            avaliacao = cntr->recuperarAvaliacao(codigo);
            apresentar = false;

        } catch(...) {
            cout << "Avaliacao nao registrada." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
    cout << "-----------------------AVALIACAO ENCONTRADA-----------------------" << endl;
    mostrarAvaliacao(avaliacao);
    cout << "Digite algo para retornar" << endl;
    getch();
}

void CntrApresentacaoAvaliacao::mostrarAvaliacao(Avaliacao avaliacao) {
    cout << "Codigo              : " << avaliacao.getCodigo() << endl;
    cout << "Matricula           : " << avaliacao.getMatricula() << endl;
    cout << "Codigo do Professor : " << avaliacao.getCodProfessor() << endl;
    cout << "Avaliacao           : " << avaliacao.getAvaliacao() << endl;
    cout << "---------------------------------------------------------------------"<< endl;
}

void CntrApresentacaoAvaliacao::mostrarDenuncia(Denuncia denuncia) {
    Avaliacao avaliacao = cntr->recuperarAvaliacao(denuncia.getCodAvaliacao());
    cout << "Codigo do Professor      : " << avaliacao.getCodProfessor() << endl;
    cout << "Avaliacao                : " << avaliacao.getAvaliacao() << endl;
    cout << "Matricula do denunciador : " << denuncia.getMatricula() << endl;
    cout << "---------------------------------------------------------------------"<< endl;
}

