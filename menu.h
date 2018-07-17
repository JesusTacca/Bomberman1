class menu{
public:

    int variable_menu;
    int variable_option;
    int variable_cambio;
    int atras=0;

    menu(){
        variable_cambio=0;
        variable_menu=0;
    }
    void ejecuta_main(){
        if(variable_menu==0){
            if(variable_cambio<200){
                blit(pant1_1,screen, 0,0,0,0,768,600);
                variable_cambio++;
            }
            if(variable_cambio>=200){
                blit(pant1_2,screen, 0,0,0,0,768,600);
                variable_cambio++;
                if(variable_cambio>=400){
                    variable_cambio=0;
                }
            }
        }
        if(variable_menu==1){
            if(variable_cambio<200){
                blit(pant2_1,screen, 0,0,0,0,768,600);
                variable_cambio++;
            }
            if(variable_cambio>=200){
                blit(pant2_2,screen, 0,0,0,0,768,600);
                variable_cambio++;
                if(variable_cambio>=400){
                    variable_cambio=0;
                }
            }
        }
        if(variable_menu==2){
            if(variable_cambio<200){
                blit(pant3_1,screen, 0,0,0,0,768,600);
                variable_cambio++;
            }
            if(variable_cambio>=200){
                blit(pant3_2,screen, 0,0,0,0,768,600);
                variable_cambio++;
                if(variable_cambio>=400){
                    variable_cambio=0;
                }
            }
        }
        if(key[KEY_DOWN] && variable_menu>=0 && variable_menu<2){
            variable_menu++;
            rest(50);
        }
        if(key[KEY_UP] && variable_menu<=2 && variable_menu>0){
            variable_menu--;
            rest(50);
        }
    }
    void ejecuta_option(){
        if(variable_option=0){
            blit(opti1_1,screen, 0,0,0,0,768,600);
        }
        if(variable_option=1){
            blit(opti1_2,screen, 0,0,0,0,768,600);
        }
        if(key[KEY_RIGHT] && variable_option<1){
            variable_option=1;
        }
        if(key[KEY_LEFT] && variable_option>0){
            variable_option=0;
        }
    }
};





class sub_menu{
public:
    bool condicion;
    virtual void poner()=0;
};
class musica:public sub_menu{
public:
    bool condicion;
    musica(){
        condicion=false;
    }
    void poner(){

    }
};
class decorator:public sub_menu{
public:
    sub_menu *menu1;
    void poner(){
        menu1->poner();
    }
};
class musica1:public decorator{
public:
    musica1(sub_menu *A){
        this->menu1=A;
    }
    void poner(){
        play_sample(sonido,200,150,1000,0);
    }
};
class musica2:public decorator{
public:
    musica2(sub_menu *A){
        this->menu1=A;
    }
    void poner(){
        play_sample(sonido2,200,150,1000,0);
    }
};

