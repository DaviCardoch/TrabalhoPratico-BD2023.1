#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <string>

using namespace std;

class Estudante {
private:
    string email;
    string matricula;
    string curso;
    string senha;
    string nome;
    string adm;
public:
    void setNome(const string &nome);
    string getNome() const;
    void setSenha(const string &senha);
    string getSenha() const;
    void setCurso(const string &curso);
    string getCurso() const;
    void setMatricula(const string &matricula);
    string getMatricula() const;
    void setEmail(const string &email);
    string getEmail() const;
    void setAdm(const string &adm);
    string getAdm() const;
};

inline void Estudante::setNome(const string &nome){
    this->nome = nome;
}

inline string Estudante::getNome() const{
    return nome;
}
inline void Estudante::setSenha(const string &senha){
    this->senha = senha;
}

inline string Estudante::getSenha() const{
    return senha;

}inline void Estudante::setCurso(const string &curso){
    this->curso = curso;
}

inline string Estudante::getCurso() const{
    return curso;

}inline void Estudante::setMatricula(const string &matricula){
    this->matricula = matricula;
}

inline string Estudante::getMatricula() const{
    return matricula;
}

inline void Estudante::setEmail(const string &email){
    this->email = email;
}

inline string Estudante::getEmail() const{
    return email;
}

inline void Estudante::setAdm(const string &adm){
    this->adm = adm;
}

inline string Estudante::getAdm() const{
    return adm;
}


class Avaliacao {
private:
    string codigo;
    string matricula;
    string codProfessor;
    string avaliacao;
public:
    void setCodigo(const string &codigo);
    string getCodigo() const;
    void setMatricula(const string &matricula);
    string getMatricula() const;
    void setCodProfessor(const string &codProfessor);
    string getCodProfessor() const;
    void setAvaliacao(const string &avaliacao);
    string getAvaliacao() const;
};

inline void Avaliacao::setCodigo(const string &codigo){
    this->codigo=codigo;
}

inline string Avaliacao::getCodigo() const{
    return codigo;
}

inline void Avaliacao::setMatricula(const string &matricula){
    this->matricula=matricula;
}

inline string Avaliacao::getMatricula() const{
    return matricula;
}

inline void Avaliacao::setCodProfessor(const string &codProfessor){
    this->codProfessor=codProfessor;
}

inline string Avaliacao::getCodProfessor() const{
    return codProfessor;
}

inline void Avaliacao::setAvaliacao(const string &avaliacao){
    this->avaliacao=avaliacao;
}

inline string Avaliacao::getAvaliacao() const{
    return avaliacao;
}

class Denuncia {
private:
    string matricula;
    string codAvaliacao;
public:
    void setCodAvaliacao(const string &codAvalicao);
    string getCodAvaliacao() const;
    void setMatricula(const string &matricula);
    string getMatricula() const;
};

inline void Denuncia::setMatricula(const string &matricula){
    this->matricula=matricula;
}

inline string Denuncia::getMatricula() const{
    return matricula;
}

inline void Denuncia::setCodAvaliacao(const string &codAvaliacao){
    this->codAvaliacao=codAvaliacao;
}

inline string Denuncia::getCodAvaliacao() const{
    return codAvaliacao;
}



#endif // ENTIDADES_H_INCLUDED
