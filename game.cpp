#include<iostream>
#include<vector>
#include<SDL.h>
#include <time.h>
#include "SDL_image.h"
#include "khoitao.h"

using namespace std;


int scroll_pos,doi,enemy_doi,coinLenDoi[3]={0,200,400},coin,enemy_XP;
double enemy_coin;
int L1[4]={0,10,20,40},L2[4]={0,20,40,80},L3[4]={0,20,40,150};
int maunhachinh,maunhachinh_enemy,maunhachinhmax[4]={0,100,250,500};
int cooldownlinh,cooldownenemy;
int skill_x[9]={0,-5,5,0,-5,5,-5,0,5},skill_y[9]={0,0,5,-5,5,0,-5,5,-5},skill_temp,skill_cooldown;

SDL_Texture *png_cooldown2,*png_cooldown1,*png_coin,*png_up,*png_gamebg,*png_gamemenu,*png_L1,*png_L2,*png_L3;
SDL_Texture *png_0,*png_1,*png_2,*png_3,*png_4,*png_5,*png_6,*png_7,*png_8,*png_9;
SDL_Rect rect,rect1,r;
struct info
{
    int x;
    int y;
    string file;
    int status;
    int tamdanh;
    int mau;
    int maumax;
    int dame;
    int coin;
};
info mouse;
vector<info> linh,enemy_linh;

void game_khoitao(SDL_Window* window,SDL_Renderer* renderer)
{
    srand(time(0));
    png_0=IMG_LoadTexture(renderer,"0.png");
    png_1=IMG_LoadTexture(renderer,"1.png");
    png_2=IMG_LoadTexture(renderer,"2.png");
    png_3=IMG_LoadTexture(renderer,"3.png");
    png_4=IMG_LoadTexture(renderer,"4.png");
    png_5=IMG_LoadTexture(renderer,"5.png");
    png_6=IMG_LoadTexture(renderer,"6.png");
    png_7=IMG_LoadTexture(renderer,"7.png");
    png_8=IMG_LoadTexture(renderer,"8.png");
    png_9=IMG_LoadTexture(renderer,"9.png");

    string st="D1L1.png";
    png_L1=IMG_LoadTexture(renderer,st.c_str());
    st="D1L2.png";
    png_L2=IMG_LoadTexture(renderer,st.c_str());
    st="D1L3.png";
    png_L3=IMG_LoadTexture(renderer,st.c_str());
    png_gamebg=IMG_LoadTexture(renderer,"gamebg.png");
    png_gamemenu=IMG_LoadTexture(renderer,"gamemenu.png");
    png_cooldown1=IMG_LoadTexture(renderer,"cooldown1.png");
    png_cooldown2=IMG_LoadTexture(renderer,"cooldown2.png");
    png_coin=IMG_LoadTexture(renderer,"coin.png");
    png_up=IMG_LoadTexture(renderer,"up.png");

    while(linh.empty()!=true)linh.pop_back();
    while(enemy_linh.empty()!=true)enemy_linh.pop_back();
    scroll_pos=0;doi=1;enemy_doi=1;coin=5000;enemy_coin=50;
    enemy_XP=0;
    cooldownlinh=0;
    cooldownenemy=0;
    maunhachinh=100;maunhachinh_enemy=100;
    SDL_SetRenderDrawColor( renderer,255, 0, 0,0 );
    skill_temp=0;
}

void renso(SDL_Window* window,SDL_Renderer* renderer,SDL_Rect rr,int so)
{
    SDL_Rect rrect;
    int t=so,ttemp=1,ttemp1;

    rrect.x=rr.x;
    rrect.y=rr.y;
    rrect.w=rr.w;
    rrect.h=rr.h;
    if(t>999)ttemp=1000;else
    if(t>99)ttemp=100;else
    if(t>9)ttemp=10;
    while(ttemp>0){
        ttemp1=t/ttemp;
        t%=ttemp;
        ttemp/=10;
        rrect.x+=rrect.w;
        switch(ttemp1)
        {
            case 0:
                SDL_RenderCopy(renderer,png_0,NULL,&rrect);
                break;
            case 1:
                SDL_RenderCopy(renderer,png_1,NULL,&rrect);
                break;
            case 2:
                SDL_RenderCopy(renderer,png_2,NULL,&rrect);
                break;
            case 3:
                SDL_RenderCopy(renderer,png_3,NULL,&rrect);
                break;
            case 4:
                SDL_RenderCopy(renderer,png_4,NULL,&rrect);
                break;
            case 5:
                SDL_RenderCopy(renderer,png_5,NULL,&rrect);
                break;
            case 6:
                SDL_RenderCopy(renderer,png_6,NULL,&rrect);
                break;
            case 7:
                SDL_RenderCopy(renderer,png_7,NULL,&rrect);
                break;
            case 8:
                SDL_RenderCopy(renderer,png_8,NULL,&rrect);
                break;
            case 9:
                SDL_RenderCopy(renderer,png_9,NULL,&rrect);
                break;
        }
    }
}

void button_L1(SDL_Window* window,SDL_Renderer* renderer)
{
    if(mouse.x>=202&&mouse.x<=272)
    if(mouse.y>=24&&mouse.y<=94)
    if(coin>=L1[doi]){
        cooldownlinh=60;
        coin-=L1[doi];
        info temp;
        temp.file="D1/L1/L1T0D1_00000.png";
        temp.file[1]+=doi-1;
        temp.file[11]+=doi-1;
        temp.tamdanh=0;
        if(doi==1){
            temp.mau=30;
            temp.maumax=30;
            temp.dame=10;
            temp.coin=10;
        }else
        if(doi==2){
            temp.mau=60;
            temp.maumax=60;
            temp.dame=15;
            temp.coin=20;
        }else
        if(doi==3){
            temp.mau=120;
            temp.maumax=120;
            temp.dame=20;
            temp.coin=40;
        }
        temp.status=0;
        temp.x=132;
        temp.y=585;
        linh.push_back(temp);


    }
}

void button_L2(SDL_Window* window,SDL_Renderer* renderer)
{
    if(mouse.x>=306&&mouse.x<=376)
    if(mouse.y>=24&&mouse.y<=94)
    if(coin>=L2[doi]){
        cooldownlinh=60;
        coin-=L2[doi];
        info temp;
        temp.file="D1/L2/L2T0D1_00000.png";
        temp.file[1]+=doi-1;
        temp.file[11]+=doi-1;
        if(doi<3)temp.tamdanh=0;else temp.tamdanh=80;
        if(doi==1){
            temp.mau=50;
            temp.maumax=50;
            temp.dame=10;
            temp.coin=20;
        }else
        if(doi==2){
            temp.mau=120;
            temp.maumax=120;
            temp.dame=15;
            temp.coin=40;
        }else
        if(doi==3){
            temp.mau=120;
            temp.maumax=120;
            temp.dame=30;
            temp.coin=80;
        }
        temp.status=0;
        temp.x=132;
        temp.y=585;
        linh.push_back(temp);

    }
}

void button_L3(SDL_Window* window,SDL_Renderer* renderer)
{
    if(mouse.x>=410&&mouse.x<=480)
    if(mouse.y>=24&&mouse.y<=94)
    if(coin>=L3[doi]){
        cooldownlinh=60;
        coin-=L3[doi];
        info temp;
        temp.file="D1/L3/L3T0D1_00000.png";
        temp.file[1]+=doi-1;
        temp.file[11]+=doi-1;
        if(doi==1){
            temp.mau=30;
            temp.maumax=30;
            temp.dame=15;
            temp.coin=20;
            temp.tamdanh=50;
        }else
        if(doi==2){
            temp.mau=60;
            temp.maumax=60;
            temp.dame=20;
            temp.coin=40;
            temp.tamdanh=50;
        }else
        if(doi==3){
            temp.mau=200;
            temp.maumax=200;
            temp.dame=40;
            temp.coin=150;
            temp.tamdanh=100;
        }
        temp.status=0;
        temp.x=132;
        temp.y=585;
        linh.push_back(temp);

    }
}

void button_Lendoi(SDL_Window* window,SDL_Renderer* renderer)
{
    if(mouse.x>=514&&mouse.x<=584)
    if(mouse.y>=24&&mouse.y<=94)
    if(doi<3)
    if(coinLenDoi[doi]<=coin)
    {   coin-=coinLenDoi[doi];
        doi++;
        maunhachinh+=maunhachinhmax[doi]-maunhachinhmax[doi-1];
        string st="D1L1.png";
        st[1]+=doi-1;
        png_L1=IMG_LoadTexture(renderer,st.c_str());
        st[3]++;
        png_L2=IMG_LoadTexture(renderer,st.c_str());
        st[3]++;
        png_L3=IMG_LoadTexture(renderer,st.c_str());
    }
}

void button_skill(SDL_Window* window,SDL_Renderer* renderer)
{
    if(skill_cooldown<=0)skill_temp=151;

}

void event(SDL_Window* window,SDL_Renderer* renderer)
{
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_MOUSEBUTTONDOWN:{

                Uint32 buttons = SDL_GetMouseState(&mouse.x, &mouse.y);
                if(cooldownlinh<=0){
                    button_L1(window,renderer);
                    button_L2(window,renderer);
                    button_L3(window,renderer);
                }
                button_Lendoi(window,renderer);

                break;
            }
            case SDL_MOUSEMOTION:{
                Uint32 buttons = SDL_GetMouseState(&mouse.x, &mouse.y);
                break;
            }

        }
        switch(e.key.keysym.sym)
        {
            case SDLK_ESCAPE:
               quitSDL(window,renderer);
                break;
        }
    }
    if(mouse.y>=200)
    if(0<=mouse.x&&mouse.x<=100)scroll_pos=max(scroll_pos-20,0);else
    if(100<mouse.x&&mouse.x<=250)scroll_pos=max(scroll_pos-10,0);else
    if(1400<=mouse.x&&mouse.x<=1500)scroll_pos=min(scroll_pos+20,750);else
    if(1250<=mouse.x&&mouse.x<1400)scroll_pos=min(scroll_pos+10,750);
}


void renmap(SDL_Window* window,SDL_Renderer* renderer)
{
    rect.x=-5-scroll_pos+skill_x[max(skill_temp%9,0)];
    rect.y=-5+skill_y[max(skill_temp%9,0)];
    rect.w=2260;
    rect.h=760;
    SDL_RenderCopy(renderer,png_gamebg,NULL,&rect);

}

void rengamemenu(SDL_Window* window,SDL_Renderer* renderer)
{
    rect.x=-2;
    rect.y=0;
    rect.w=1504;
    rect.h=230;
    SDL_RenderCopy(renderer,png_gamemenu,NULL,&rect);

    rect.y=24;
    rect.w=70;
    rect.h=70;

    rect1.y=100;
    rect1.w=20;
    rect1.h=20;

    rect.x=202;
    rect1.x=202;
    if(cooldownlinh>30)SDL_RenderCopy(renderer,png_cooldown2,NULL,&rect);
    else if(cooldownlinh>=0)SDL_RenderCopy(renderer,png_cooldown1,NULL,&rect);
    else SDL_RenderCopy(renderer,png_L1,NULL,&rect);
    SDL_RenderCopy(renderer,png_coin,NULL,&rect1);
    if(doi==1)renso(window,renderer,rect1,10);else
    if(doi==2)renso(window,renderer,rect1,20);else
    if(doi==3)renso(window,renderer,rect1,40);


    rect.x=306;
    rect1.x=306;
    if(cooldownlinh>30)SDL_RenderCopy(renderer,png_cooldown2,NULL,&rect);
    else if(cooldownlinh>=0)SDL_RenderCopy(renderer,png_cooldown1,NULL,&rect);
    else SDL_RenderCopy(renderer,png_L2,NULL,&rect);
    SDL_RenderCopy(renderer,png_coin,NULL,&rect1);
    if(doi==1)renso(window,renderer,rect1,20);else
    if(doi==2)renso(window,renderer,rect1,40);else
    if(doi==3)renso(window,renderer,rect1,80);


    rect.x=410;
    rect1.x=410;
    if(cooldownlinh>30)SDL_RenderCopy(renderer,png_cooldown2,NULL,&rect);
    else if(cooldownlinh>=0)SDL_RenderCopy(renderer,png_cooldown1,NULL,&rect);
    else SDL_RenderCopy(renderer,png_L3,NULL,&rect);
    SDL_RenderCopy(renderer,png_coin,NULL,&rect1);
    if(doi==1)renso(window,renderer,rect1,20);else
    if(doi==2)renso(window,renderer,rect1,40);else
    if(doi==3)renso(window,renderer,rect1,150);


    rect.x=514;
    rect1.x=514;
    if(doi<3){
        SDL_RenderCopy(renderer,png_up,NULL,&rect);
        SDL_RenderCopy(renderer,png_coin,NULL,&rect1);
    }
    if(doi==1)renso(window,renderer,rect1,200);else
    if(doi==2)renso(window,renderer,rect1,400);

    r.x=20;
    r.y=40;
    r.w=25;
    r.h=25;
    renso(window,renderer,r,coin);

}

void renmaunhachinh(SDL_Window* window,SDL_Renderer* renderer)
{
    rect.x=20-scroll_pos;
    rect.y=600-300*max(maunhachinh,0)/maunhachinhmax[doi];
    rect.w=30;
    rect.h=300*max(maunhachinh,0)/maunhachinhmax[doi];
    SDL_RenderFillRect( renderer, &rect );

    rect.x=2200-scroll_pos;
    rect.y=600-300*max(maunhachinh_enemy,0)/maunhachinhmax[enemy_doi];
    rect.w=30;
    rect.h=300*max(maunhachinh_enemy,0)/maunhachinhmax[enemy_doi];

    SDL_RenderFillRect( renderer, &rect );
}


void renlinh(SDL_Window* window,SDL_Renderer* renderer)
{
    rect.x=132+skill_x[max(skill_temp%9,0)];
    rect.y=580+skill_y[max(skill_temp%9,0)];
    rect.w=100;
    rect.h=125;

    int tempx=0,tempenemyx=2082;
    if(!enemy_linh.empty())tempenemyx=enemy_linh.front().x;

    for(info &templinh:linh){

        rect1.x=templinh.x+10-scroll_pos+skill_x[max(skill_temp%9,0)];
        rect1.y=590+skill_y[max(skill_temp%9,0)];
        rect1.w=30*templinh.mau/templinh.maumax;
        rect1.h=5;
        SDL_RenderFillRect( renderer, &rect1 );

        SDL_Texture* bg= IMG_LoadTexture(renderer,templinh.file.c_str());
        rect.x=templinh.x-scroll_pos+skill_x[max(skill_temp%9,0)];
        SDL_RenderCopy(renderer,bg,NULL,&rect);

        if(templinh.file[9]=='1'||templinh.file[9]=='2')
        if(templinh.file[17]=='7'&&templinh.file[16]=='1')
        if(!enemy_linh.empty())enemy_linh.front().mau-=templinh.dame;else maunhachinh_enemy-=templinh.dame;

        if(templinh.mau<=0)
        {
            if(templinh.file[9]=='1'||templinh.file[9]=='2')
            if(templinh.file[16]=='1')
            if(templinh.file[17]>='4'&&templinh.file[17]<'7')
            enemy_linh.front().mau-=templinh.dame;
            linh.erase(linh.begin());
        }
        if(templinh.file[17]=='9')
        {
            if(templinh.file[16]=='2')
            {
                if(templinh.file[9]=='3')linh.erase(linh.begin());else
                {
                    templinh.file[17]='0';
                    templinh.file[16]='0';
                }
            }else
            {
                templinh.file[17]='0';
                templinh.file[16]+=1;
            }
        }else templinh.file[17]+=1;


        if(templinh.x+55<=tempx||tempx==0)
        {
            if(templinh.x+5<=tempenemyx)templinh.x+=5;

        }else
        if(templinh.tamdanh+templinh.x<tempenemyx){
                templinh.file[17]='0';
                templinh.file[16]='0';
        }else
        if(templinh.status==1)
        {
            templinh.status=2;
            templinh.file[9]='2';
        }

        if(templinh.x+templinh.tamdanh>=tempenemyx||templinh.x==tempenemyx){
            if(templinh.x+55<=tempx||tempx==0)
            templinh.file[9]='1';else
            templinh.file[9]='2';
            if(templinh.x+5>tempenemyx) templinh.file[9]='2';
            if(templinh.status!=int(templinh.file[9])-48){
                templinh.status=int(templinh.file[9])-48;
                templinh.file[17]='0';
                templinh.file[16]='0';
            }
        }else
        if(templinh.status!=0)
        {
                templinh.status=0;
                templinh.file[9]='0';
                templinh.file[17]='0';
                templinh.file[16]='0';

        }
        tempx=templinh.x;
        SDL_DestroyTexture(bg);
    }

}

void renenemylinh(SDL_Window* window,SDL_Renderer* renderer)
{

    rect.x=132+skill_x[max(skill_temp%9,0)];
    rect.y=580+skill_y[max(skill_temp%9,0)];
    rect.w=100;
    rect.h=125;

    int tempx=2500,tempenemyx=132;
    if(!linh.empty())tempenemyx=linh.front().x;

    for(info &templinh:enemy_linh){

        rect1.x=templinh.x+60-scroll_pos+skill_x[max(skill_temp%9,0)];
        rect1.y=590+skill_y[max(skill_temp%9,0)];
        rect1.w=30*templinh.mau/templinh.maumax;
        rect1.h=5;
        SDL_RenderFillRect( renderer, &rect1 );

        SDL_Texture* bg= IMG_LoadTexture(renderer,templinh.file.c_str());
        rect.x=templinh.x-scroll_pos+skill_x[max(skill_temp%9,0)];
        SDL_RenderCopyEx(renderer,bg,NULL,&rect,0,NULL,SDL_FLIP_HORIZONTAL);

        if(templinh.file[9]=='1'||templinh.file[9]=='2')
        if(templinh.file[17]=='7'&&templinh.file[16]=='1')
        if(!linh.empty())linh.front().mau-=templinh.dame;else maunhachinh-=templinh.dame;

        if(templinh.mau<=0)
        {
            coin+=1.3*enemy_linh.front().coin;
            enemy_linh.erase(enemy_linh.begin());
        }
        if(templinh.file[17]=='9')
        {
            if(templinh.file[16]=='2')
            {
                if(templinh.file[9]=='3')enemy_linh.erase(enemy_linh.begin());else
                {
                    templinh.file[17]='0';
                    templinh.file[16]='0';
                }
            }else
            {
                templinh.file[17]='0';
                templinh.file[16]+=1;
            }
        }else templinh.file[17]+=1;


        if(templinh.x-55>=tempx||tempx==2500)
        {
            if(templinh.x-5>=tempenemyx)templinh.x-=5;
        }else
        if(templinh.x-templinh.tamdanh>tempenemyx){

            templinh.file[17]='0';
            templinh.file[16]='0';
        }


        if(templinh.x-templinh.tamdanh<=tempenemyx||templinh.x==tempenemyx){

            if(templinh.x-55>=tempx||tempx==2500)
            templinh.file[9]='1';else
            templinh.file[9]='2';
            if(templinh.x-5<tempenemyx) templinh.file[9]='2';
            if(templinh.status==0){
                templinh.status=int(templinh.file[9])-48;
                templinh.file[17]='0';
                templinh.file[16]='0';
            }
        }
        else
        if(templinh.status!=0)
        {
                templinh.status=0;
                templinh.file[9]='0';
                templinh.file[17]='0';
                templinh.file[16]='0';

        }
        tempx=templinh.x;
        SDL_DestroyTexture(bg);
    }

}

void AI()
{
    if(cooldownenemy<=0)
    {
        int randlinh=rand()%3+1;
        if(!linh.empty()&&linh.front().x>1250)cooldownenemy=60;
        else if(!linh.empty()&&linh.front().x>750)cooldownenemy=90;
        else cooldownenemy=120;
        if(randlinh==1)
        if(L1[enemy_doi]<=enemy_coin)
        {
            enemy_coin-=L1[enemy_doi];
            info temp;
            temp.file="D1/L1/L1T0D1_00000.png";
            temp.file[1]+=enemy_doi-1;
            temp.file[11]+=enemy_doi-1;
            temp.tamdanh=0;
            if(enemy_doi==1){
                temp.mau=30;
                temp.maumax=30;
                temp.dame=10;
                temp.coin=10;
            }else
            if(enemy_doi==2){
                temp.mau=60;
                temp.maumax=60;
                temp.dame=15;
                temp.coin=20;
            }else
            if(enemy_doi==3){
                temp.mau=120;
                temp.maumax=120;
                temp.dame=20;
                temp.coin=40;
            }
            temp.status=0;
            temp.y=585;

            temp.x=2082;
            enemy_linh.push_back(temp);
        }else cooldownenemy=10;
        if(randlinh==2)
        if(L2[enemy_doi]<=enemy_coin)
        {
            enemy_coin-=L2[enemy_doi];
            info temp;
            temp.file="D1/L2/L2T0D1_00000.png";
            temp.file[1]+=enemy_doi-1;
            temp.file[11]+=enemy_doi-1;
            temp.tamdanh=0;
            if(enemy_doi<3)temp.tamdanh=0;else temp.tamdanh=80;
            if(enemy_doi==1){
                temp.mau=50;
                temp.maumax=50;
                temp.dame=10;
                temp.coin=20;
            }else
            if(enemy_doi==2){
                temp.mau=120;
                temp.maumax=120;
                temp.dame=15;
                temp.coin=40;
            }else
            if(enemy_doi==3){
                temp.mau=120;
                temp.maumax=120;
                temp.dame=30;
                temp.coin=80;
            }
            temp.status=0;
            temp.y=585;

            temp.x=2082;
            enemy_linh.push_back(temp);
        }else cooldownenemy=10;
        if(randlinh==3)
        if(L3[enemy_doi]<=enemy_coin)
        {
            enemy_coin-=L3[enemy_doi];
            info temp;
            temp.file="D1/L3/L3T0D1_00000.png";
            temp.file[1]+=enemy_doi-1;
            temp.file[11]+=enemy_doi-1;
            temp.tamdanh=0;
            if(enemy_doi==1){
                temp.mau=30;
                temp.maumax=30;
                temp.dame=15;
                temp.coin=20;
                temp.tamdanh=50;
            }else
            if(enemy_doi==2){
                temp.mau=60;
                temp.maumax=60;
                temp.dame=20;
                temp.coin=40;
                temp.tamdanh=50;
            }else
            if(enemy_doi==3){
                temp.mau=200;
                temp.maumax=200;
                temp.dame=40;
                temp.coin=150;
                temp.tamdanh=100;
            }
            temp.status=0;
            temp.y=585;

            temp.x=2082;
            enemy_linh.push_back(temp);
        }else cooldownenemy=10;

    }
}

void loopgame(SDL_Window* window,SDL_Renderer* renderer,int &dokho)
{

    game_khoitao(window,renderer);

    while(maunhachinh*maunhachinh_enemy>0)
    {
        enemy_XP++;
        cooldownlinh--;
        cooldownenemy--;

        skill_cooldown--;
        skill_temp--;


        enemy_coin=enemy_coin+((double)enemy_doi*(dokho))/10;
        if(enemy_doi<3&&enemy_XP>=3600){
            enemy_doi++;
            maunhachinh_enemy+=maunhachinhmax[enemy_doi]-maunhachinhmax[enemy_doi-1];
            enemy_XP-=3600;

        }
        SDL_RenderClear(renderer);
        event(window,renderer);
        renmap(window,renderer);
        rengamemenu(window,renderer);
        renmaunhachinh(window,renderer);
        AI();
        renlinh(window,renderer);
        renenemylinh(window,renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }
    int x,y;
    SDL_Texture *png_win=IMG_LoadTexture(renderer,"win.png");
    SDL_Texture *png_lose=IMG_LoadTexture(renderer,"lose.png");
    SDL_Texture *png_sword=IMG_LoadTexture(renderer,"sword.png");
    if(maunhachinh_enemy==0)SDL_RenderCopy(renderer,png_win,NULL,NULL);
    else SDL_RenderCopy(renderer,png_lose,NULL,NULL);
    SDL_RenderPresent(renderer);
    while(true)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){

                case SDL_MOUSEBUTTONDOWN:{
                    Uint32 buttons = SDL_GetMouseState(&x, &y);
                    if(x>=500&&x<=1000){
                        if(y>=390&&y<=450) return;
                        if(y>=450&&y<=510) quitSDL(window,renderer);
                        return ;
                    }
                    break;
                }
                case SDL_MOUSEMOTION:{
                    rect.x=515;
                    rect.y=-100;
                    rect.h=30;
                    rect.w=100;
                    Uint32 buttons = SDL_GetMouseState(&x, &y);
                    SDL_RenderClear(renderer);
                    if(maunhachinh_enemy==0)SDL_RenderCopy(renderer,png_win,NULL,NULL);
                    else SDL_RenderCopy(renderer,png_lose,NULL,NULL);
                    if(x>=500&&x<=1000)
                    {
                        if(y>=390&&y<=450) rect.y=403;
                        if(y>=450&&y<=510) rect.y=463;
                        SDL_RenderCopy(renderer,png_sword,NULL,&rect);
                    }
                    SDL_RenderPresent(renderer);
                    break;
                }
            }
            switch(e.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                   quitSDL(window,renderer);
                    break;

            }
        }
        SDL_Delay(30);
    }
    SDL_DestroyTexture(png_win);
    SDL_DestroyTexture(png_lose);
    SDL_DestroyTexture(png_sword);
    SDL_DestroyTexture(png_cooldown2);
    SDL_DestroyTexture(png_cooldown1);
    SDL_DestroyTexture(png_coin);
    SDL_DestroyTexture(png_up);
    SDL_DestroyTexture(png_gamebg);
    SDL_DestroyTexture(png_gamemenu);
    SDL_DestroyTexture(png_L1);
    SDL_DestroyTexture(png_L2);
    SDL_DestroyTexture(png_L3);
    SDL_DestroyTexture(png_cooldown1);
    SDL_DestroyTexture(png_0);
    SDL_DestroyTexture(png_1);
    SDL_DestroyTexture(png_2);
    SDL_DestroyTexture(png_3);
    SDL_DestroyTexture(png_4);
    SDL_DestroyTexture(png_5);
    SDL_DestroyTexture(png_6);
    SDL_DestroyTexture(png_7);
    SDL_DestroyTexture(png_8);
    SDL_DestroyTexture(png_9);


}
