#include <allegro.h>

BITMAP* buffer;
BITMAP* bmp;
PALETTE pal;

int gecici_x ;
int gecici_y ;
int gecici_x1 ;
int gecici_y1 ;
int gecici_x2 ;
int gecici_y2 ;
int r=0;
int g=0;
int b=0;

float kalinlik=1;
float cap=50;

void getMouseInfo(){

if(mouse_b==1){
    gecici_x = mouse_x;
    gecici_y = mouse_y;
}

if(mouse_b==2){
    gecici_x1 = mouse_x;
    gecici_y1 = mouse_y;
}

if(mouse_b==3){
    gecici_x2 = mouse_x;
    gecici_y2 = mouse_y;
}

}

void updateScreen()
{

 circlefill( screen, gecici_x, gecici_y, kalinlik, makecol( r, g, b));

 draw_sprite( buffer, screen, 0, 0);

}

void drawCircle()
{

    circle ( screen, gecici_x, gecici_y, cap, makecol( r,g,b));

    draw_sprite( buffer, screen, 0, 0);

}

void drawDortgen()
{
    rect(screen,gecici_x1,gecici_y1,gecici_x,gecici_y,makecol(r,g,b));

    draw_sprite( buffer, screen, 0, 0);

}

void drawUcgen()
{
    triangle(screen,340,100,gecici_x,gecici_y,gecici_x1,gecici_y1,makecol(r,g,b));
}

void main()
{

allegro_init();

install_mouse();

install_keyboard();

set_window_title("Basit Paint Uygulamasi");

set_color_depth(16);

set_gfx_mode( GFX_AUTODETECT_WINDOWED, 680, 480, 0, 0);

buffer = create_bitmap( 680, 480);

show_mouse(screen);

clear_to_color(screen,makecol(255,255,255));

BITMAP* arkaPlan=load_bitmap("Arkaplan2.bmp",NULL);

BITMAP* arkaPlan2=load_bitmap("arkaplan.bmp",NULL);

BITMAP* kayit=load_bitmap("dump.bmp",NULL);

while( !key[KEY_ESC]){

blit(arkaPlan,screen,0,0,0,0,680,43);

blit(arkaPlan2,screen,0,0,600,43,80,22);

getMouseInfo();

tekrar:

if(((mouse_x>640 && mouse_x<680) && (mouse_y>0 && mouse_y<40)) && (mouse_b & 1) )
{
kalinlik=1;

r=255;
g=255;
b=0;

updateScreen();

}

else if(((mouse_x>600 && mouse_x<640) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=255;
b=0;
g=0;

updateScreen();

}

else if(((mouse_x>560 && mouse_x<600) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=0;
b=0;
g=255;

updateScreen();

}

else if(((mouse_x>520 && mouse_x<560) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=0;
b=255;
g=0;

updateScreen();

}

else if(((mouse_x>480 && mouse_x<520) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=0;
b=0;
g=0;

updateScreen();

}

else if(((mouse_x>440 && mouse_x<480) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=255;
b=255;
g=255;

updateScreen();

}

else if(((mouse_x>400 && mouse_x<440) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=255;
b=255;
g=0;

updateScreen();

}

else if(((mouse_x>360 && mouse_x<400) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=125;
b=255;
g=255;

updateScreen();

}

else if(((mouse_x>320 && mouse_x<360) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=125;
b=125;
g=125;

updateScreen();

}

else if(((mouse_x>280 && mouse_x<320) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
kalinlik=1;

r=255;
b=20;
g=125;

updateScreen();

}

else if(((mouse_x>240 && mouse_x<280) && (mouse_y>0 && mouse_y<20))&& (mouse_b & 1))
{

kalinlik=kalinlik+0.01;
cap=cap+0.1;

updateScreen();

}

else if(((mouse_x>240 && mouse_x<280) && (mouse_y>20 && mouse_y<40))&& (mouse_b & 1))
{

kalinlik=kalinlik-0.01;
cap=cap-0.1;

updateScreen();

}

else if(((mouse_x>200 && mouse_x<240) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
r=255;
b=255;
g=255;

kalinlik=30;

updateScreen();

}

else if(((mouse_x>40 && mouse_x<80) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{
      get_palette(pal);
      bmp = create_sub_bitmap(screen, 0, 43, 680, 437);
      save_bitmap("dump.bmp", bmp, pal);
      destroy_bitmap(bmp);
}
else if(((mouse_x>0 && mouse_x<40) && (mouse_y>0 && mouse_y<40))&& (mouse_b & 1))
{

    blit(kayit,screen,0,0,0,43,680,480);


}

else if(key[KEY_F])
{

   line(screen,gecici_x,gecici_y,gecici_x1,gecici_y1,makecol(r,g,b));


}

else if(key[KEY_D])
{
    drawCircle();
}

else if(key[KEY_S])
{
    drawDortgen();
}

else if(key[KEY_A])
{
    drawUcgen();
}


else if(key[KEY_SPACE])
{

    clear_to_color(screen,makecol(255,255,255));

}

else
{
updateScreen();
}

}

}

END_OF_MAIN();


