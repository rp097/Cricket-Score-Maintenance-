#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
class bowl
{
 protected:
	  int c,b,o;
	  int team1;
	  float team2;
 public:
	bowl()
	{
	 b=0;
	 o=0;
	 c=0;
	}
	void win(int,int);
	void win(float,float);
};
void bowl::win(int x,int y)
{
 team1=x;
 int temp=y;
 if((int)team1&&(int)temp)
 {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"TEAM 1 WINS");
  getch();
 }
}
void bowl::win(float x,float y)
{
 team2=x;
 float temp=y;
 if((float)team2&&(float)temp)
 {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"TEAM 2 WINS");
  getch();
 }
}
class score
{
 int scr,wkt;
 int choice;
 public:
     score()
     {
      scr=0;
      wkt=0;
     }
     score(int,int);
     void scr_display();
     //void bowl_stats();
     int toss_res();
     int tabulate(int);
};
//int score::scr;
//int score::wkt;
//int score::choice;
score::score(int s,int w)
{
 wkt=w;
 scr=s;
}
int score::toss_res()
{
 randomize();
 int toss=random(1);
 int toss1;
 if(toss==0)
 {
  cout<<"TEAM1 calls \nEnter 0 for heads and 1 for Tails:";
  cin>>toss1;
  if(toss1==random(toss))
  {
     cout<<"TEAM1 won the toss and chose to bat first";
     getch();
     return 2;
  }
  else
  {
     cout<<"TEAM2 won the toss and chose to bat first";
     getch();
     return 3;
   }
 }
 else
 {
  cout<<"TEAM2 calls \nEnter 0 for heads and 1 for Tails:";
  cin>>toss1;
  if(toss1==random(toss))
  {
     cout<<"TEAM1 won the toss and chose to bowl first";
     getch();
     return 2;
  }
  else
  {
     cout<<"TEAM2 won the toss and chose to bowl first";
    getch();
    return 3;
   }
 }
}
int score::tabulate(int choice1)
{
 choice=choice1;
 int scr1;
 int byes;
 switch(choice)
 {
  case 1:scr=scr+1;
	 break;
  case 2:scr=scr+2;
	 break;
  case 3:scr=scr+3;
	 break;
  case 4:scr=scr+4;
	 break;
  case 6:scr=scr+6;
	 break;
  case 7:scr+=1;
	 break;
  case 8:scr+=1;
	 break;
  case 9:cout<<"Enter number of runs:";
	 cin>>byes;
	 scr+=byes;
	 break;
  case 10:cout<<"Enter number of runs:";
	  cin>>byes;
	  scr+=byes;
	  break;
  case 11:wkt+=1;
	  break;
  case 12:scr+=0;
	  break;
 }
 scr1=scr;
 return scr1;
}
void score::scr_display()
{
 cout<<"\t\t\tCURRENT SCORE\n\n";
 cout<<"\tRUNS\t\t\t\tWICKETS\n";
 cout<<"\t"<<scr<<"\t\t\t\t"<<wkt<<endl;
}
class rp:public bowl
{
 char name[30];
 int pscore;
 char style;
 int choice2,chc;
 public:
      void set(char [],char,int);
      void player_score(int);
      void player_balls(int);
      void bowl_stats();
      void display();
      void player_stats();
};
//int rp::pscore;
void rp::set(char name1[],char style1,int pscore1)
{
 strcpy(name,name1);
 style=style1;
 pscore=pscore1;
}
void rp::player_balls(int choice1)
{
  chc=choice1;
  switch(chc)
  {
   case 1:b++;
	  break;
   case 2:b++;
	  break;
   case 3:b++;
	  break;
   case 4:b++;
	  break;
   case 6:b++;
	  break;
   case 7:b=b+0;
	  break;
   case 8:b=b+0;
	  break;
   case 9:b++;
	  break;
   case 10:b++;
	   break;
   case 11:b++;
	   c++;
	   break;
   case 12:b++;
	   break;
 }
}
void rp::player_score(int choice1)
{
 choice2=choice1;
 switch(choice2)
 {
  case 1:pscore+=1;
	break;
  case 2:pscore+=2;
	break;
  case 3:pscore+=3;
	break;
  case 4:pscore+=4;
	break;
  case 6:pscore+=6;
	break;
  case 7:pscore=pscore+0;
	 break;
  case 8:pscore=pscore+0;
	 break;
  case 9:pscore=pscore+0;
	 break;
  case 10:pscore=pscore+0;
	 break;
  case 11:pscore=pscore+0;
	  break;
  case 12:pscore=pscore+0;
	  break;
 }
}
void rp::bowl_stats()
{
 int overs=b/6;
 int bcount=b%6;
 cout<<name<<"\t\t\t"<<overs<<"."<<bcount<<"\t\t\t"<<c<<endl;
}
void rp::display()
{
 cout<<name<<" \t\t\t\t "<<style<<endl;
}
void rp::player_stats()
{
 cout<<name<<"\t\t\t\t"<<style<<"\t\t\t\t"<<pscore<<endl;
}
int main()
{
 rp team1[11],team2[11];
 score t1(0,0),t2(0,0);
 bowl obj1,obj2;
 int i1=2,i2=3;
 float f1=2.46,f2=3.14;
 int gd=DETECT,gm,inn;
 clrscr();

 int i,j,ovr1=0,balls1=0,choice1,bnum1,batnum1=0,prev,t1scr,t2scr;
 int ovr2=0,balls2=0,w2=0,bnum2,batnum2=0;
 char name1[30],style1,ch;
 int w1=0;
 cout<<"\t\t*********PLAYER STYLE**********\n Batsman-B\tBowler-b\tAllrounder-a\n";
 cout<<"Enter player details for TEAM1:\n";
 for(i=0;i<11;i++)
 {
  cout<<"Enter name of player"<<i+1<<":";
  cin>>name1;
  cout<<"Player Attribute:";
  cin>>style1;
  team1[i].set(name1,style1,0);
 }
 cout<<"Enter the player details for TEAM2:\n";
 for(i=0;i<11;i++)
 {
  cout<<"Enter name of player"<<i+1<<":";
  cin>>name1;
  cout<<"Player Attribute:";
  cin>>style1;
  team2[i].set(name1,style1,0);
 }
 clrscr();
 cout<<"\t \tTEAM 1 \t \t \t \n";
 cout<<"Name\t\t\t\tStyle\n";
 for(j=0;j<11;j++)
  team1[j].display();
 cout<<"\t \tTEAM 2 \t \t \t \n";
 cout<<"Name\t\t\t\tStyle\n";
 for(j=0;j<11;j++)
  team2[j].display();
 cout<<"Press any key to continue to match or Esc to exit.."<<endl;
 ch=getch();
 if(ch==27)
  exit(0);
 clrscr();
 inn=t1.toss_res();
 if(inn==2)
 {
  //change_bowler:
  clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team2[i].display();
   }
  cin>>bnum2;
  while(w1<11)
  {
  clrscr();
  cout<<"\t \t \t LEGEND \t \t \t \n";
  cout<<"One run:1\nTwo runs:2\nThree runs:3\nBoundary:4\nSix:6\nWide Ball:7\n";
  cout<<"No Ball:8\nByes:9\nLeg Byes:10\nWicket:11\nDot Ball:12\n";
  cin>>choice1;
  if(choice1==7 || choice1==8)
   balls1+=0;
  else
   balls1++;
  if(choice1==1 || choice1==3 ||balls1==6)
  {
   prev=batnum1;
   team1[batnum1].player_score(choice1);
   if(prev<=batnum1)
    batnum1 ++;
   else
    batnum1--;
  }
  else
  {
   team1[batnum1].player_score(choice1);
  }
  team2[bnum2-1].player_balls(choice1);
  if(choice1==11)
  {
   w1=w1+1;
   if(prev<=batnum1)
    batnum1=batnum1+2;
   else
    batnum1+=1;
   if(w1==10)
    break;
  }
  t1scr=t1.tabulate(choice1);
  clrscr();
  t1.scr_display();
  gotoxy(25,5);
  if(balls1==6)
  {
   balls1=0;
   ovr1=ovr1+1;
   cout<<"OVERS:"<<ovr1<<".0";
   clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team2[i].display();
   }
  cin>>bnum2;
  }
  else
  {
   cout<<"OVERS:"<<ovr1<<"."<<balls1;
  }
  if(ovr1==20)
   break;
  getch();
  }
  t1scr=t1.tabulate(11);
  clrscr();
  t1.scr_display();
  gotoxy(25,5);
  cout<<"OVERS:"<<ovr1<<"."<<balls1;
  getch();
  clrscr();
  initgraph(&gd,&gm,"");
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"END OF INNINGS");
  settextstyle(0,0,2);
  outtextxy(30,150,"Press any key to view scorecard..");
  getch();
  cleardevice();
  cout<<"\t\t\t******SCORECARD******\t\t\t"<<endl;
  cout<<"\n\n";
  cout<<"NAME\t\t\t\tSTYLE\t\t\t\tSCORE\n";
  for(i=0;i<11;i++)
   team1[i].player_stats();
  getch();
  cleardevice();
  cout<<"***********************BOWLING STATISTICS**************************";
  cout<<"\nBOWLER NAME\t\tOVERS\t\tWICKETS\n";
  for(i=0;i<11;i++)
   team2[i].bowl_stats();
  getch();
  //change_bowler1:
  clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team1[i].display();
   }
  cin>>bnum1;
  while(w2<11)
  {
  clrscr();
  cout<<"\t \t \t LEGEND \t \t \t \n";
  cout<<"One run:1\nTwo runs:2\nThree runs:3\nBoundary:4\nSix:6\nWide Ball:7\n";
  cout<<"No Ball:8\nByes:9\nLeg Byes:10\nWicket:11Dot ball:12\n";
  cin>>choice1;
  if(choice1==7 || choice1==8)
   balls2+=0;
  else
   balls2++;
  if(choice1==1 || choice1==3 ||balls2==6)
  {
   prev=batnum2;
   team2[batnum2].player_score(choice1);
   if(prev<=batnum2)
    batnum2++;
   else
    batnum2--;
  }
  else
  {
   team2[batnum2].player_score(choice1);
  }
  team1[bnum1-1].player_balls(choice1);
  if(choice1==11)
  {
   w2=w2+1;
   if(prev<=batnum1)
    batnum1=batnum1+2;
   else
    batnum2+=1;
   if(w2==10)
    break;
  }
  t2scr=t2.tabulate(choice1);
  if(t2scr>t1scr)
  {
   obj1.win(f1,f2);
   break;
  }
  clrscr();
  t2.scr_display();
  gotoxy(25,5);
  if(balls2==6)
  {
   balls2=0;
   ovr2=ovr2+1;
   cout<<"OVERS:"<<ovr2<<".0";
   clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team1[i].display();
   }
  cin>>bnum1;
  }
  else
  {
   cout<<"OVERS:"<<ovr2<<"."<<balls2;
  }
  if(ovr2==20)
   break;
  getch();
  }
  t2scr=t2.tabulate(11);
  clrscr();
  t2.scr_display();
  gotoxy(25,5);
  cout<<"OVERS:"<<ovr2<<"."<<balls2;
  getch();
  clrscr();
  initgraph(&gd,&gm,"");
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"END OF INNINGS");
  settextstyle(0,0,2);
  outtextxy(30,150,"Press any key to view scorecard..");
  getch();
  cleardevice();
  cout<<"\t\t\t******SCORECARD******\t\t\t"<<endl;
  cout<<"\n\n";
  cout<<"NAME\t\t\t\tSTYLE\t\t\t\tSCORE\n";
  for(i=0;i<11;i++)
   team2[i].player_stats();
  getch();
  cleardevice();
  cout<<"***********************BOWLING STATISTICS**************************";
  cout<<"\nBOWLER NAME\t\tOVERS\t\tWICKETS\n";
  for(i=0;i<11;i++)
   team1[i].bowl_stats();
  getch();
 }
 else
 {
   //change_bowler2:
  clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team1[i].display();
   }
  cin>>bnum1;
  while(w2<11)
  {
  clrscr();
  cout<<"\t \t \t LEGEND \t \t \t \n";
  cout<<"One run:1\nTwo runs:2\nThree runs:3\nBoundary:4\nSix:6\nWide Ball:7\n";
  cout<<"No Ball:8\nByes:9\nLeg Byes:10\nWicket:11Dot ball:12\n";
  cin>>choice1;
  if(choice1==7 || choice1==8)
   balls2+=0;
  else
   balls2++;
  if(choice1==1 || choice1==3 ||balls2==6)
  {
   prev=batnum2;
   team2[batnum2].player_score(choice1);
   if(prev<=batnum2)
    batnum2++;
   else
    batnum2--;
  }
  else
  {
   team2[batnum2].player_score(choice1);
  }
  team1[bnum1-1].player_balls(choice1);
  if(choice1==11)
  {
   w2=w2+1;
   if(prev<=batnum2)
    batnum2=batnum2+2;
   else
    batnum2+=1;
   if(w2==10)
    break;
  }
  t2scr=t2.tabulate(choice1);
  clrscr();
  t2.scr_display();
  gotoxy(25,5);
  if(balls2==6)
  {
   balls2=0;
   ovr2=ovr2+1;
   cout<<"OVERS:"<<ovr2<<".0";
   clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team1[i].display();
   }
  cin>>bnum1;
  }
  else
  {
   cout<<"OVERS:"<<ovr2<<"."<<balls2;
  }
  if(ovr2==20)
   break;
  getch();
  }
  t2scr=t2.tabulate(11);
  clrscr();
  t2.scr_display();
  gotoxy(25,5);
  cout<<"OVERS:"<<ovr2<<"."<<balls2;
  getch();
  clrscr();
  initgraph(&gd,&gm,"");
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"END OF INNINGS");
  settextstyle(0,0,2);
  outtextxy(30,150,"Press any key to view scorecard..");
  getch();
  cleardevice();
  cout<<"\t\t\t******SCORECARD******\t\t\t"<<endl;
  cout<<"\n\n";
  cout<<"NAME\t\t\t\tSTYLE\t\t\t\tSCORE\n";
  for(i=0;i<11;i++)
   team2[i].player_stats();
  getch();
  cleardevice();
  cout<<"***********************BOWLING STATISTICS**************************";
  cout<<"\nBOWLER NAME\t\tOVERS\t\tWICKETS\n";
  for(i=0;i<11;i++)
   team1[i].bowl_stats();
  getch();
   //change_bowler3:
  clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team2[i].display();
   }
  cin>>bnum2;
  while(w1<11)
  {
  clrscr();
  cout<<"\t \t \t LEGEND \t \t \t \n";
  cout<<"One run:1\nTwo runs:2\nThree runs:3\nBoundary:4\nSix:6\nWide Ball:7\n";
  cout<<"No Ball:8\nByes:9\nLeg Byes:10\nWicket:11\nDot Ball:12\n";
  cin>>choice1;
  if(choice1==7 || choice1==8)
   balls1+=0;
  else
   balls1++;
 if(choice1==1 || choice1==3 ||balls1==5)
  {
   prev=batnum1;
   team1[batnum1].player_score(choice1);
   if(prev<=batnum1)
    batnum1++;
   else
    batnum1--;
  }
  else
  {
   team1[batnum1].player_score(choice1);
  }
  team2[bnum2-1].player_balls(choice1);
  if(choice1==11)
  {
   w1=w1+1;
   if(prev<=batnum1)
    batnum1=batnum1+2;
   else
    batnum1+=1;
   if(w1==10)
    break;
  }
  t1scr=t1.tabulate(choice1);
  clrscr();
  t1.scr_display();
  gotoxy(25,5);
  if(balls1==6)
  {
   balls1=0;
   ovr1=ovr1+1;
   cout<<"OVERS:"<<ovr1<<".0";
   clrscr();
  cout<<"CHOOSE BOWLER\n\n";
   for(i=0;i<11;i++)
   {
     cout<<i+1<<".";
     team2[i].display();
   }
  cin>>bnum2;
  }
  else
  {
   cout<<"OVERS:"<<ovr1<<"."<<balls1;
  }
  if(ovr1==20)
   break;
  getch();
  }
  t1scr=t1.tabulate(11);
  if(t1scr>t2scr)
  {
   obj2.win(i1,i2);
   goto last;
  }
  clrscr();
  t1.scr_display();
  gotoxy(25,5);
  cout<<"OVERS:"<<ovr1<<"."<<balls1;
  getch();
  clrscr();
  initgraph(&gd,&gm,"");
  setbkcolor(BLACK);
  setcolor(MAGENTA);
  settextstyle(0,0,5);
  outtextxy(50,100,"END OF INNINGS");
  settextstyle(0,0,2);
  outtextxy(30,150,"Press any key to view scorecard..");
  getch();
  cleardevice();
  cout<<"\t\t\t******SCORECARD******\t\t\t"<<endl;
  cout<<"\n\n";
  cout<<"NAME\t\t\t\tSTYLE\t\t\t\tSCORE\n";
  for(i=0;i<11;i++)
   team1[i].player_stats();
  getch();
  cleardevice();
  cout<<"***********************BOWLING STATISTICS**************************";
  cout<<"\nBOWLER NAME\t\tOVERS\t\tWICKETS\n";
  for(i=0;i<11;i++)
   team2[i].bowl_stats();
  getch();
 }
 last:
 getch();
 return 0;
}