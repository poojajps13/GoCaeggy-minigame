#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
int r,r1,i,j,l,t=6,e=1;
char ch[25][8]={"00","05","10","15","20","25","30","35","40","45","50","55","60","65","70","75","80","85","90","95","100","110"};
void random()
{
    srand(time(NULL));
    r1=rand()%6;
}
void update()
{
    j=0;
    if(t>3)t--;
    random();
    settextstyle(0,HORIZ_DIR,3);
    outtextxy(300,100,"SCORE");
    outtextxy(330,120,ch[l]);
    delay(1000);
}
void land()
{
    setfillstyle(SOLID_FILL,12);
    line(0,800,1000,800);
    floodfill(0,0,WHITE);
    setfillstyle(1,7);
    line(0,402,1000,402);
    floodfill(0,0,WHITE);
}
void blocks()
{
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(0,0,WHITE);
    rectangle(100,140,170,160);
    rectangle(450,140,520,160);
    rectangle(55,210,125,230);
    rectangle(490,210,560,230);
    rectangle(150,70,220,90);
    rectangle(400,70,470,90);
}
void person(char a)
{
    if(a=='a' && i>-300)i=i-18;
    else if(a=='d' && i<280)i=i+18;
    circle(330+i,282,20);circle(324+i,280,5);circle(338+i,280,5);line(330+i,285,330+i,290);line(330+i,290,333+i,290);
    ellipse(330+i,292,180,360,8,5);ellipse(311+i,282,90,270,6,7);ellipse(349+i,282,270,90,6,7);//face
    ellipse(330+i,267,0,360,30,5);ellipse(330+i,265,0,180,20,10);//hat
    rectangle(310+i,300,350+i,350);//stomach
    rectangle(300+i,300,310+i,340);//hand
    rectangle(350+i,300,360+i,340);//hand
    circle(305+i,345,7);//palm
    circle(355+i,345,7);//palm
    rectangle(317+i,350,327+i,390);//leg
    rectangle(337+i,350,347+i,390);//legT
    rectangle(315+i,390,327+i,400);//foot
    rectangle(337+i,390,349+i,400);//foot
}
int basket(char a)
{
    setfillstyle(9,4);
    ellipse(331+i,352,180,360,23,15);
    fillellipse(331+i,355,23,15);
    bar(307+i,340,352+i,350);
    rectangle(307+i,340,352+i,350);
    return (307+i);
}
void fall(int x,int y,int z)
{
    int i;
    char a;
    for(i=0;i<2000;i=i+20){
    a=0;
    setfillstyle(9,15);
    ellipse(x,y+i,0,360,10,15);
    fillellipse(x,y+i,10,15 );
    settextstyle(0,HORIZ_DIR,3);
    outtextxy(220,15,"GO CAEGGY");
    blocks();
    land();
    delay(100*t);
    if(kbhit())a=getch();
    while(kbhit()){getch();}
    cleardevice();
    person(a);
    z=basket(a);
    if(y+i>=405)
    {
        e=0;
        break;
    }
    else if((z<=x&&x<=(z+45))&&((y+i)>=310&&(y+i)<=350))
    {
        l++;
        Beep(300,700);
        update();
        break;
    }
  }
}
void eggs(char x)
{
    setfillstyle(9,15);
    if(r1==0)
    {
        ellipse(65+j,195,0,360,10,15);
        fillellipse(65+j,195,10,15);
        if(65+j==135) fall(135,195,x);
    }
    else if(r1==1)
    {
        ellipse(110+j,125,0,360,10,15);
        fillellipse(110+j,125,10,15);
        if(110+j==180) fall(180,125,x);
    }
    else if(r1==2)
    {
        ellipse(160+j,55,0,360,10,15);
        fillellipse(160+j,55,10,15);
        if(160+j==230)fall(230,55,x);
    }
    else if(r1==3)
    {
        ellipse(460-j,55,0,360,10,15);
        fillellipse(460-j,55,10,15);
        if(460-j==390)fall(390,55,x);
    }
    else if(r1==4)
    {
        ellipse(510-j,125,0,360,10,15);
        fillellipse(510-j,125,10,15);
        if(510-j==440) fall(440,125,x);
    }
    else if(r1==5)
    {
        ellipse(550-j,195,0,360,10,15);
        fillellipse(550-j,195,10,15);
        if(550-j==480)fall(480,195,x);
    }
    j=j+10;
}
int main()
{
    int gd=0,gm;
    char a,str[25];
    system("color 3e");
    printf("\n\n           ENTER YOUR NAME:\t");
    scanf("%[^\n]",str);
    initwindow(640,470,"GO CAEGGY");
    do
    {
        settextstyle(3,HORIZ_DIR,5);
        outtextxy(150,150,"GAME START");
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(180,250,"INSTRUCTIONS:");
        outtextxy(180,300,"Press 'a' for left");
        outtextxy(180,350,"Press 'd' for right");
        Beep(500,500);
        delay(3000);
    }
    while(0);
    cleardevice();
    blocks();
    person(0);
    basket(0);
    land();
    random();
    do
    {delay(1000);}
    while(0);
    while(e)
    {
        a=0;
        if(l==20) break;
        settextstyle(0,HORIZ_DIR,3);
        outtextxy(220,15,"GO CAEGGY");
        blocks();
        land();
        delay(100*t);
        if(kbhit()){ a=getch(); }
        while(kbhit()){getch();}
        cleardevice();
        person(a);
        basket(a);
        eggs(a);
    }
    if(l==20)
    {
    do
    {
    update();
        settextstyle(0,HORIZ_DIR,3);
        outtextxy(220,220,"GAME FINISH");
        outtextxy(230,250,"YOU WIN");
        outtextxy(240,180,str);
        delay(1000);
    }
    while(0);
    }
    else
    {
    do
    {
        update();
        settextstyle(0,HORIZ_DIR,3);
        outtextxy(210,150,"  GAME OVER");
        outtextxy(240,180,str);
        Beep(700,2000);
        delay(1000);
    }
    while(0);
    }
    getch();
    closegraph();
    return 0;
}
