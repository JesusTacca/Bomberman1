template<class T>class bomba;
template<class T>
class bomba{
    T cantBomb=0;
    T limit=2;
public:
    void colocar(T x, T y, T a){
        if(a==3 && mapa[(y-63)/30][(x-7)/30]!=3 && cantBomb<limit){
            cantBomb++;
            mapa[(y-63)/30][(x-7)/30]=a;
            plano[(y-63)/30][(x-7)/30]=200;}
        if(a==9 && mapa[(y-63)/30][(x-7)/30]!=9 && cantBomb<limit){
            cantBomb++;
            mapa[(y-63)/30][(x-7)/30]=a;
            plano[(y-63)/30][(x-7)/30]=200;}
    }
    void expbomb(){
        cantBomb--;}
    T bombsize(){
        return cantBomb;}
    void cbom(){
        cantBomb=0;}
    void maslimit(){
        limit++;
    }
    T limite(){
        return limit;
    }
};
