#include <allegro.h>
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "mando.h"
#include "Score.h"
#include "datos.h"
#include "bomba.h"
#include "menu.h"
#include "jugador.h"
JUGADOR* bomberman = new JUGADOR1();
JUGADOR* bombermanBlack = new JUGADOR2();
#include "mapa.h"
using namespace std;
void reinicio(){
    bomberman->respawn();
    bombermanBlack->respawn();
    for(int i=0;i<17;i++){
        for(int j=0;j<25;j++){
            plano2[i][j]=0;
        }
    }
    for(int i=1;i<16;i+=2){
        for(int j=1;j<24;j++){
            mapa[i][j]=2;
        }
    }
    for(int i=2;i<16;i+=2){
        for(int j=1;j<24;j+=2){
            mapa[i][j]=2;
        }
    }
    mapa[1][1]=0;
    mapa[1][2]=0;
    mapa[2][1]=0;
    mapa[1][23]=0;
    mapa[2][23]=0;
    mapa[1][22]=0;
    bomberman->reiniciar_pos();
    bombermanBlack->reiniciar_pos();
    fondo=load_bitmap("mapa.bmp",NULL);


}

void imprimir(){
    textprintf_ex(fondo, font, 10, 10,makecol(255, 255, 255),makecol(34,177,76), "Bombas JUG1: %d   ", bomberman->hyt()->bombsize());
    textprintf_ex(fondo, font, 10, 25, makecol(255, 255, 255),makecol(34,177,76), "Vidas JUG1: %d   ", bomberman->cantvidas());
    textprintf_ex(fondo, font, 10, 40, makecol(255, 255, 255),makecol(34,177,76), "Puntaje JUG1: %d   ", bomberman->hug()->puntAct());
    textprintf_ex(fondo, font, 10, 55, makecol(255, 255, 255),makecol(34,177,76), "BOMB JUG1: %d   ", bomberman->hyt()->limite());
    textprintf_ex(fondo, font, 500, 10,makecol(255, 255, 255),makecol(34,177,76), "Bombas: %d", bombermanBlack->hyt()->bombsize());
    textprintf_ex(fondo, font, 500, 25, makecol(255, 255, 255),makecol(34,177,76), "Vidas JUG2: %d   ", bombermanBlack->cantvidas());
    textprintf_ex(fondo, font, 500, 40, makecol(255, 255, 255),makecol(34,177,76), "Puntaje JUG2: %d   ", bombermanBlack->hug()->puntAct());
    textprintf_ex(fondo, font, 500, 55, makecol(255, 255, 255),makecol(34,177,76), "BOMB JUG1: %d   ", bombermanBlack->hyt()->limite());
}

void valor(){
    bloque=load_bmp("bloque.bmp",NULL);
    prog01= load_bitmap("prog01.bmp",NULL);
    prog02= load_bitmap("prog02.bmp",NULL);
    prog03= load_bitmap("prog03.bmp",NULL);
    prog04= load_bitmap("prog04.bmp",NULL);
    prog05= load_bitmap("prog05.bmp",NULL);
    prog06= load_bitmap("prog06.bmp",NULL);
    prog07= load_bitmap("prog07.bmp",NULL);
    prog08= load_bitmap("prog08.bmp",NULL);
    prog09= load_bitmap("prog09.bmp",NULL);
    prog10= load_bitmap("prog10.bmp",NULL);
    prog11= load_bitmap("prog11.bmp",NULL);
    prog12= load_bitmap("prog12.bmp",NULL);
    bomba1=load_bitmap("bomba.bmp",NULL);
    fondo=load_bitmap("mapa.bmp",NULL);
    pant1_2= load_bitmap("1.bmp",NULL);
    pant1_1= load_bitmap("2.bmp",NULL);
    pant2_2= load_bitmap("3.bmp",NULL);
    pant2_1= load_bitmap("4.bmp",NULL);
    pant3_2= load_bitmap("5.bmp",NULL);
    pant3_1= load_bitmap("6.bmp",NULL);
    music1= load_bitmap("fondo_sound_1_1.bmp",NULL);
    music2= load_bitmap("fondo_sound_1_2.bmp",NULL);
    opti1_1= load_bitmap("option1_1.bmp",NULL);
    opti1_2= load_bitmap("option1_2.bmp",NULL);
    explosion=load_bitmap("explosion.bmp",NULL);
    muertepant=load_bitmap("MUERTE.bmp",NULL);
    bloque_indes=load_bitmap("bloque_indes.bmp",NULL);
    SCORD=load_bitmap("scores.bmp",NULL);
    icon=load_bitmap("icon_bomb.bmp",NULL);
    icon_jug=load_bitmap("icon_jug.bmp",NULL);
}

void juego(int salir, menu* principal, int yu, int condi_salir, int sonido, int elejir_music, sub_menu* minimenu, bool par){

    while(salir!=1){
        while(!key[KEY_ENTER]){
            principal->ejecuta_main();
            if(key[KEY_ESC]){
                salir=1;
                break;
            }
        }
        if(principal->variable_menu==1){
            break;
        }
        if(principal->variable_menu==2){
            yu=1;
        }
        while(!key[KEY_L] && yu==1){
                blit(SCORD,screen, 0,0,0,0,768,600);
                for(int i=0;i<dats.sizes();i++){
                    textprintf_ex(SCORD, font, 200, 300 +10*i,makecol(255, 255, 255),makecol(34,177,76), "PUNTAJE: %d", dats.puntaje(i));
            }}
        yu=0;
        if(principal->variable_menu==0){

             while(!key[KEY_L] && condi_salir==1){
                if(sonido==0){
                    blit(music1,screen, 0,0,0,0,768,600);
                }
                if(sonido==1){
                    blit(music2,screen, 0,0,0,0,768,600);
                }
                if(key[KEY_UP]){
                    elejir_music=1;
                    sonido=0;
                }
                if(key[KEY_DOWN]){
                    elejir_music=2;
                    sonido=1;
                }
            }
            if(condi_salir==1){
                if(elejir_music==1){
                    minimenu=new musica1(minimenu);
                        minimenu->poner();
                }
                if(elejir_music==2){
                    minimenu=new musica2(minimenu);
                        minimenu->poner();
                }
            }
            condi_salir=0;
            MAPA::GetInstance().colocar_icons();
            while(bomberman->siguevivo() && bombermanBlack->siguevivo() && !key[KEY_ESC]){
                blit(buffer,screen, 0,0,0,0,768,600);
                if(key[KEY_LCONTROL]){par=true;}
                imprimir();
                if(!par){textprintf_ex(fondo, font, 180, 10, makecol(255, 255, 255),makecol(34,177,76), "Presione Crl para iniciar el JUG2");}
                else textprintf_ex(fondo, font, 180, 10, makecol(255, 255, 255),makecol(34,177,76), "                                    ");
                draw_sprite(buffer,fondo,0,0);
                MAPA::GetInstance().dibujar_explosion();
                MAPA::GetInstance().dibujar_bloque();
                bomberman->muerte();
                bomberman->movimiento();
                bomberman->posxy();
                bomberman->aum_vid();
                bomberman->poner_bomba();
                if(par){
                    bombermanBlack->muerte();
                    bombermanBlack->movimiento();
                    bombermanBlack->posxy();
                    bombermanBlack->aum_vid();
                    bombermanBlack->poner_bomba();
                }
                }
            reinicio();
            par=false;
        }
        if(principal->variable_menu==1){
            while(!key[KEY_ESC]){
                principal->ejecuta_option();
            }
        }
        if(salir!=1){
            while(!key[KEY_K]){
            blit(muertepant,screen, 0,0,0,0,768,600);
            if(key[KEY_ESC]){
                salir=1;
                break;
            }
            }
        }
    }
}

int main(){
    allegro_init();
    install_keyboard();
    install_joystick(JOY_TYPE_AUTODETECT);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,768,600,0,0);
    thread paso (valor);
    paso.join();
    xbox_input();
    int numero_mapa=0;
    buffer=create_bitmap(768,600);
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    set_volume(230, 200);
    sonido2 = load_wav("pant_sound2.wav");
    sonido = load_wav("pant_sound.wav");
    menu principal;
    personaje=prog01;
    personaje2=prog01;
    int ventana=principal.variable_menu;
    int yu=0;
    int salir=0;
    int sonido12=0;
    int condi_salir=1;
    int elejir_music=1;
    bool par=false;
    dats.guardar(1500);
    dats.guardar(1050);
    dats.guardar(1750);
    dats.guardar(1570);
    sub_menu *minimenu=new musica();
    thread game(juego,salir, &principal, yu,condi_salir, sonido12, elejir_music, minimenu, par);
    game.join();
    destroy_sample(sonido2);
    return 0;
}
END_OF_MAIN();
