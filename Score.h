template<class Y>class BaseDatos;
template<class Y>
#include <vector>
class BaseDatos
{
    std::vector<Y> scores;
public:
    Y puntaje(Y a){
            return scores[a];}
    void guardar(Y a){
            scores.push_back(a);}
    Y sizes(){
        return scores.size();}
};
BaseDatos<int> dats;
template<class U>class puntaje;
template<class U>
class puntaje
{
    U punt=0;
public:
    puntaje(){}
    void bloqdes(){
        punt+=50;}
    void jugase(){
        punt=punt+400;}
    void muertejug(){
        dats.guardar(punt);
        punt=0;}
    U puntAct(){
        return punt;}
};
