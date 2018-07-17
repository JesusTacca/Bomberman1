class JUGADOR
{
public:
    virtual int cantvidas()=0;
    virtual void muerte()=0;
    virtual void movimiento()=0;
    virtual void poner_bomba()=0;
    virtual bool siguevivo()=0;
    virtual void respawn()=0;
    virtual bomba<int>* hyt()=0;
    virtual puntaje<int>* hug()=0;
    virtual void posxy()=0;
    virtual void aum_vid()=0;
    virtual void reiniciar_pos()=0;
};

class JUGADOR1: public JUGADOR
{
    int px=48,py=107;
    int temp=0;
    int vidas=5;
    puntaje<int> pnt;
    bomba<int> bmb;
public:
    JUGADOR1(){}
    int cantvidas(){
        return vidas;}
    void muerte(){
        if(plano2[(py-75)/30][(px+3)/30]==5 ||
           plano2[(py-75)/30][(px-16)/30]==5 ||
           plano2[(py-76)/30][(px-15)/30]==5 ||
           plano2[(py-50)/30][(px-15)/30]==5 ||
           plano2[(py-75)/30][(px+3)/30]==6 ||
           plano2[(py-75)/30][(px-16)/30]==6 ||
           plano2[(py-76)/30][(px-15)/30]==6 ||
           plano2[(py-50)/30][(px-15)/30]==6){
            px=48;
            py=107;
            vidas--;}}
    void movimiento(){
            draw_sprite(buffer,personaje,px,py);
            if(key[KEY_RIGHT]){
                if(mapa[(py-75)/30][(px+3)/30]!=1 &&
                   mapa[(py-57)/30][(px+3)/30]!=1 &&
                   mapa[(py-75)/30][(px+3)/30]!=2 &&
                   mapa[(py-57)/30][(px+3)/30]!=2)
                    px++;
                    temp++;
                    if(temp>0 && temp<=30) personaje=prog10;
                    else if(temp>30 && temp<60) personaje=prog11;
                    else personaje=prog12;}
            if(key[KEY_LEFT]){
                if(mapa[(py-75)/30][(px-16)/30]!=1 &&
                   mapa[(py-57)/30][(px-16)/30]!=1 &&
                   mapa[(py-75)/30][(px-16)/30]!=2 &&
                   mapa[(py-57)/30][(px-16)/30]!=2)
                    px--;
                    temp++;
                    if(temp>0 && temp<=30) personaje=prog05;
                    else if(temp>30 && temp<60) personaje=prog06;
                    else personaje=prog04;}
            if(key[KEY_UP]){
                if(mapa[(py-76)/30][(px-15)/30]!=1 &&
                   mapa[(py-76)/30][(px+2)/30]!=1 &&
                   mapa[(py-76)/30][(px-15)/30]!=2 &&
                   mapa[(py-76)/30][(px+2)/30]!=2)
                    py--;
                    temp++;
                    if(temp>0 && temp<=30) personaje=prog08;
                    else if(temp>30 && temp<60) personaje=prog09;
                    else personaje=prog07;}
            if(key[KEY_DOWN]){
                if(mapa[(py-50)/30][(px-15)/30]!=1 &&
                   mapa[(py-50)/30][(px+2)/30]!=1 &&
                   mapa[(py-50)/30][(px-15)/30]!=2 &&
                   mapa[(py-50)/30][(px+2)/30]!=2)
                    py++;
                    temp++;
                    if(temp>0 && temp<=30) personaje=prog02;
                    else if(temp>30 && temp<60) personaje=prog03;
                    else personaje=prog01;}
            if(temp>=60)temp=0;}

    void poner_bomba(){
            void xbox_input();
            if(key[KEY_SPACE]){
                bmb.colocar(px,py,3);
                }}
    bool siguevivo(){
        if(vidas==0){
            pnt.muertejug();
            return false;}
        else
            return true;}
    void respawn(){
        vidas=5;}
    puntaje<int>* hug(){
        return &pnt;}
    bomba<int>* hyt(){
        return &bmb;}
    void posxy(){
        if(plano3[(py-65)/30][(px-8)/30]==1001){
            plano3[(py-65)/30][(px-8)/30]=0;
            bmb.maslimit();
            }
            }
    void aum_vid(){
        if(plano3[(py-65)/30][(px-8)/30]==1005){
            plano3[(py-65)/30][(px-8)/30]=0;
            vidas++;
            }
            }
     void reiniciar_pos(){
        px=48;
        py=107;
     }
};


class JUGADOR2: public JUGADOR
{
    int px=706,py=109;
    int temp=0;
    int vidas=5;
    puntaje<int> pnt;
    bomba<int> bmb;
public:
    JUGADOR2(){}
    int cantvidas(){
        return vidas;}
    void muerte(){
        if(plano2[(py-75)/30][(px+3)/30]==5 ||
           plano2[(py-75)/30][(px-16)/30]==5 ||
           plano2[(py-76)/30][(px-15)/30]==5 ||
           plano2[(py-50)/30][(px-15)/30]==5 ||
           plano2[(py-75)/30][(px+3)/30]==6 ||
           plano2[(py-75)/30][(px-16)/30]==6 ||
           plano2[(py-76)/30][(px-15)/30]==6 ||
           plano2[(py-50)/30][(px-15)/30]==6){
            px=705;
            py=107;
            vidas--;}}
    void movimiento(){

            draw_sprite(buffer,personaje2,px,py);
            xbox_input();
            if(key[KEY_D]){
                if(mapa[(py-75)/30][(px+3)/30]!=1 &&
                   mapa[(py-57)/30][(px+3)/30]!=1 &&
                   mapa[(py-75)/30][(px+3)/30]!=2 &&
                   mapa[(py-57)/30][(px+3)/30]!=2)
                    px++;
                    temp++;
                    if(temp>0 && temp<=30) personaje2=prog10;
                    else if(temp>30 && temp<60) personaje2=prog11;
                    else personaje2=prog12;}
            if(key[KEY_A]){
                if(mapa[(py-75)/30][(px-16)/30]!=1 &&
                   mapa[(py-57)/30][(px-16)/30]!=1 &&
                   mapa[(py-75)/30][(px-16)/30]!=2 &&
                   mapa[(py-57)/30][(px-16)/30]!=2)
                    px--;
                    temp++;
                    if(temp>0 && temp<=30) personaje2=prog05;
                    else if(temp>30 && temp<60) personaje2=prog06;
                    else personaje2=prog04;}
            if(key[KEY_W]){
                if(mapa[(py-76)/30][(px-15)/30]!=1 &&
                   mapa[(py-76)/30][(px+2)/30]!=1 &&
                   mapa[(py-76)/30][(px-15)/30]!=2 &&
                   mapa[(py-76)/30][(px+2)/30]!=2)
                    py--;
                    temp++;
                    if(temp>0 && temp<=30) personaje2=prog08;
                    else if(temp>30 && temp<60) personaje2=prog09;
                    else personaje2=prog07;}
            if(key[KEY_S]){
                if(mapa[(py-50)/30][(px-15)/30]!=1 &&
                   mapa[(py-50)/30][(px+2)/30]!=1 &&
                   mapa[(py-50)/30][(px-15)/30]!=2 &&
                   mapa[(py-50)/30][(px+2)/30]!=2)
                    py++;
                    temp++;
                    if(temp>0 && temp<=30) personaje2=prog02;
                    else if(temp>30 && temp<60) personaje2=prog03;
                    else personaje2=prog01;}
            if(temp>=60)temp=0;
    }
    void poner_bomba(){
            xbox_input();
            if(key[KEY_R]){
                bmb.colocar(px,py,9);
                }}
    bool siguevivo(){
        if(vidas==0){
            pnt.muertejug();
            return false;}
        else
            return true;}
    void respawn(){
        vidas=5;}
    puntaje<int>* hug(){
        return &pnt;}
    bomba<int>* hyt(){
        return &bmb;}
    void posxy(){
        if(plano3[(py-65)/30][(px-8)/30]==1001){
            plano3[(py-65)/30][(px-8)/30]=0;
            bmb.maslimit();
            }
            }
    void aum_vid(){
        if(plano3[(py-65)/30][(px-8)/30]==1005){
            plano3[(py-65)/30][(px-8)/30]=0;
            vidas++;
            }
            }
    void reiniciar_pos(){
        int px=706,py=109;
    }
};
