//---------------------------------------------------------------------------

#include "acessoDB.h"

//Atributo estático container List.

list<ElementoResultado> ComandoSQL::listaResultado;


//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}


//---------------------------------------------------------------------------
//Classe ComandoSQL.

bool ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
}

bool ComandoSQL::desconectar() {
    rc =  sqlite3_close(bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
}

bool ComandoSQL::executar() {
    if(!conectar())
        return 0;

    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if(rc != SQLITE_OK){
            sqlite3_free(mensagem);
            desconectar();
    }
    desconectar();

    return 1;
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
    NotUsed=0;
    ElementoResultado elemento;
    int i;
    for(i=0; i<argc; i++){
    elemento.setNomeColuna(nomeColuna[i]);
    elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
    listaResultado.push_front(elemento);
    }
    return 0;
}

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(string matricula) {
    comandoSQL = "SELECT senha FROM estudante WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}

string ComandoLerSenha::getResultado() {
    ElementoResultado resultado;
    string senha;

    if (listaResultado.empty())
        return "Erro";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}


ComandoPesquisarEstudante::ComandoPesquisarEstudante(string matricula) {
    comandoSQL = "SELECT * FROM estudante WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}

Estudante ComandoPesquisarEstudante::getResultado() {
    ElementoResultado resultado;
    string matricula;
    string email;
    string curso;
    string senha;
    string nome;
    string adm;
    Estudante estudante;


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula=resultado.getValorColuna();


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    email=resultado.getValorColuna();


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    curso=resultado.getValorColuna();


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha=resultado.getValorColuna();


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    nome=resultado.getValorColuna();


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    adm=resultado.getValorColuna();

    estudante.setMatricula(matricula);
    estudante.setEmail(email);
    estudante.setCurso(curso);
    estudante.setSenha(senha);
    estudante.setNome(nome);
    estudante.setAdm(adm);

    return estudante;
}


ComandoCadastrarEstudante::ComandoCadastrarEstudante(Estudante estudante) {
    comandoSQL = "INSERT INTO estudante VALUES (";
    comandoSQL += "'";
    comandoSQL += estudante.getMatricula();
    comandoSQL += "', '";
    comandoSQL += estudante.getEmail();
    comandoSQL += "', '";
    comandoSQL += estudante.getCurso();
    comandoSQL += "', '";
    comandoSQL += estudante.getSenha();
    comandoSQL += "', '";
    comandoSQL += estudante.getNome();
    comandoSQL += "', '";
    comandoSQL += estudante.getAdm();
    comandoSQL += "')";
}


ComandoAtualizarEstudante::ComandoAtualizarEstudante(Estudante estudante) {
    comandoSQL = "UPDATE estudante ";
    comandoSQL += "SET email = '" + estudante.getEmail();
    comandoSQL += "', curso = '" + estudante.getCurso();
    comandoSQL += "', senha = '" + estudante.getSenha();
    comandoSQL += "', nome = '" + estudante.getNome();
    comandoSQL += "', adm = '" + estudante.getAdm();
    comandoSQL += "' WHERE email = '" + estudante.getMatricula() + "'";
}


ComandoPesquisarAvaliacoes::ComandoPesquisarAvaliacoes() {
    comandoSQL = "SELECT * FROM avaliacao";
}

ComandoPesquisarAvaliacoes::ComandoPesquisarAvaliacoes(string matricula) {
    comandoSQL = "SELECT * FROM avaliacao WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}

list<Avaliacao> ComandoPesquisarAvaliacoes::getResultado() {
    ElementoResultado resultado;
    list<Avaliacao> avaliacoes;
    string codigo;
    string matricula;
    string codProfessor;
    string avaliacao;
    Avaliacao avaliacao_ent;

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo=resultado.getValorColuna();

        resultado = listaResultado.back();
        listaResultado.pop_back();
        matricula=resultado.getValorColuna();

        resultado = listaResultado.back();
        listaResultado.pop_back();
        codProfessor=resultado.getValorColuna();

        resultado = listaResultado.back();
        listaResultado.pop_back();
        avaliacao=resultado.getValorColuna();

        avaliacao_ent.setCodigo(codigo);
        avaliacao_ent.setMatricula(matricula);
        avaliacao_ent.setCodProfessor(codProfessor);
        avaliacao_ent.setAvaliacao(avaliacao);

        avaliacoes.push_back(avaliacao_ent);
    }
    return avaliacoes;
}


ComandoPesquisarAvaliacao::ComandoPesquisarAvaliacao(string codigo) {
    comandoSQL = "SELECT * FROM avaliacao WHERE codigo = '";
    comandoSQL += codigo;
    comandoSQL += "'";
}

Avaliacao ComandoPesquisarAvaliacao::getResultado() {
    ElementoResultado resultado;

    string codigo;
    string matricula;
    string codProfessor;
    string avaliacao;

    Avaliacao avaliacao_ent;


    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo=resultado.getValorColuna();

    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula=resultado.getValorColuna();

    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codProfessor=resultado.getValorColuna();

    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    avaliacao=resultado.getValorColuna();

    avaliacao_ent.setCodigo(codigo);
    avaliacao_ent.setMatricula(matricula);
    avaliacao_ent.setCodProfessor(codProfessor);
    avaliacao_ent.setAvaliacao(avaliacao);

    return avaliacao_ent;
}

ComandoPesquisarDonoAvaliacao::ComandoPesquisarDonoAvaliacao(string codigo) {
    comandoSQL = "SELECT matricula FROM avaliacao WHERE codigo = '";
    comandoSQL += codigo;
    comandoSQL += "'";
}

string ComandoPesquisarDonoAvaliacao::getResultado() {
    ElementoResultado resultado;
    string matricula;

    if (listaResultado.empty())
        throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula=resultado.getValorColuna();

    return matricula;
}


ComandoCadastrarAvaliacao::ComandoCadastrarAvaliacao(Avaliacao avaliacao) {
    comandoSQL = "INSERT INTO avaliacao VALUES (";
    comandoSQL += "'";
    comandoSQL += avaliacao.getCodigo();
    comandoSQL += "', '";
    comandoSQL += avaliacao.getMatricula();
    comandoSQL += "', '";
    comandoSQL += avaliacao.getCodProfessor();
    comandoSQL += "', '";
    comandoSQL += avaliacao.getAvaliacao();
    comandoSQL += "')";
}


ComandoAtualizarAvaliacao::ComandoAtualizarAvaliacao(Avaliacao avaliacao) {
    comandoSQL = "UPDATE avaliacao ";
    comandoSQL += "SET matricula = '" + avaliacao.getMatricula();
    comandoSQL += "', codProfessor = '" + avaliacao.getCodProfessor();
    comandoSQL += "', avaliacao = '" + avaliacao.getAvaliacao();
    comandoSQL += "' WHERE codigo = '" + avaliacao.getCodigo() + "'";
}

ComandoCadastrarDenuncia::ComandoCadastrarDenuncia(Denuncia denuncia) {
    comandoSQL = "INSERT INTO denuncia VALUES (";
    comandoSQL += "'";
    comandoSQL += denuncia.getCodAvaliacao();
    comandoSQL += "', '";
    comandoSQL += denuncia.getMatricula();
    comandoSQL += "')";
}

ComandoPesquisarDenuncias::ComandoPesquisarDenuncias() {
    comandoSQL = "SELECT * FROM denuncia";
}

ComandoPesquisarDenuncias::ComandoPesquisarDenuncias(string matricula) {
    comandoSQL = "SELECT * FROM denuncia WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}

ComandoPesquisarDenuncias::ComandoPesquisarDenuncias(Avaliacao avaliacao) {
    comandoSQL = "SELECT * FROM denuncia WHERE codAvaliacao = '";
    comandoSQL += avaliacao.getCodigo();
    comandoSQL += "'";
}

list<Denuncia> ComandoPesquisarDenuncias::getResultado() {
    ElementoResultado resultado;
    list<Denuncia> denuncias;

    string codAvaliacao;
    string matricula;

    Denuncia denuncia;

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codAvaliacao=resultado.getValorColuna();


        resultado = listaResultado.back();
        listaResultado.pop_back();
        matricula=resultado.getValorColuna();

        denuncia.setCodAvaliacao(codAvaliacao);
        denuncia.setMatricula(matricula);

        denuncias.push_back(denuncia);
    }
    return denuncias;
}

list<string> ComandoPesquisarCodigosAvaliacoesDenunciadas::getResultado() {
    ElementoResultado resultado;
    list<string> codigos;

    string codigo;

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo=resultado.getValorColuna();

        codigos.push_back(codigo);
    }
    return codigos;
}



ComandoPesquisarCodigosAvaliacoesDenunciadas::ComandoPesquisarCodigosAvaliacoesDenunciadas(string matricula) {
    comandoSQL = "SELECT codAvaliacao FROM denuncia WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}


ComandoDeletarDenuncia::ComandoDeletarDenuncia(string codAvaliacao, string matricula) {
        comandoSQL = "DELETE FROM denuncia WHERE codAvaliacao = '";
        comandoSQL += codAvaliacao;
        comandoSQL += "' AND matricula = '";
        comandoSQL += matricula;
        comandoSQL += "'";
}

ComandoDeletarDenuncia::ComandoDeletarDenuncia(Avaliacao avaliacao) {
        comandoSQL = "DELETE FROM denuncia WHERE codAvaliacao = '";
        comandoSQL += avaliacao.getCodigo();
        comandoSQL += "'";
}
ComandoDeletarDenuncia::ComandoDeletarDenuncia(string matricula) {
        comandoSQL = "DELETE FROM denuncia WHERE matricula = '";
        comandoSQL += matricula;
        comandoSQL += "'";
}


ComandoDeletarAvaliacao::ComandoDeletarAvaliacao(string codigo) {
    comandoSQL = "DELETE FROM avaliacao WHERE codigo = '";
    comandoSQL += codigo;
    comandoSQL += "'";
}

ComandoDeletarEstudante::ComandoDeletarEstudante(string matricula) {
    comandoSQL = "DELETE FROM estudante WHERE matricula = '";
    comandoSQL += matricula;
    comandoSQL += "'";
}
