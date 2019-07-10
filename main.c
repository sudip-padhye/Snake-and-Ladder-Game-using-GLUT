#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>

#define maxx 11
#define maxy 11
#define dx 30
#define dy 30

struct snake
{
int head;
int tail;
};

struct ladder
{
int bottom;
int top;       
};

struct snake s[2];
struct ladder l[3];

static GLint oldp1x=100,oldp1y=120,oldp2x=120,oldp2y=120,initial=1,flag=0;
static GLint game_mode=1,player1=1,player2=0,play1pos=0,play2pos=0,ptx,pty,finish=0;
static int msg11=1,msg12=0,msg21=0,msg22=0,msg31=0,msg32=0,msg33=0,msg34=0,msg35=0,msg36=0;
static int msg41=0,msg42=0,msg43=0,msg51=0,msg52=0,msg61=0;
GLfloat x[maxx]={0.0},y[maxy]={0.0};
GLfloat x0=150,y0=150;                                  
GLint i,j,top_face;


char college[100]="K.L.E. Institute of Technology, Hubli-580030";
char dept[100]="Department of Computer Science & Engineering";
char heading[100]="Made by                                                                 Guides";
char row1[100]="Sudip P. (2KE12CS054)                                       Prof.Kiran M.";
char row2[100]="Chandrashekar M. (2KE13CS403)                    Prof.Vijaymahantesh K.";
char emsg[100]="Press ENTER to start the game";
char title[50]="Snakes & Ladders Game";
char msgwin[20]="Message Window";
char mode1[20]="Human v/s Human";
char mode2[19]="Human v/s Computer";
char player1msg[30]="Player 1 (Press A)";
char player2msg[30]="Player 2 (Press L)";
char comp[10]="Computer";
char dash[100]="---------------------------------------------------------------------------------------";
char player1turn[21]="It's Player 1's turn";
char player2turn[21]="It's Player 2's turn";
char snake_bite1[50]="Oops! Snake have bitten Player 1";
char snake_bite2[50]="Oops! Snake have bitten Player 2";
char snake_bite3[50]="Oops! Snake have bitten Computer";
char ladder_climb1[50]="Wow! Player 1 has climbed the ladder";
char ladder_climb2[50]="Wow! Player 2 has climbed the ladder";
char ladder_climb3[50]="Wow! Computer has climbed the ladder";
char cgtmsg_p1[50]="Congratulations!!! Player 1 has won";
char cgtmsg_p2[50]="Congratulations!!! Player 2 has won";
char cgtmsg_comp[50]="Congratulations!!! Computer has won";
char invkey[50]="Invalid Key Pressed.";
char errmsg[30]="Invalid Option. Game is Over";
char load[11]="LOADING...";
char miss_msg1[50]="Little Unlucky.Less required to proceed";
char miss_msg2[50]="to 100.Better Luck next time";

void init();
void start_screen();
void print_text(int x,int y,char str[],float r,float g,float b);
void frontscreen();
void load_screen();
void display();
void locpt_conv(int loc);
void disp_fig();
void dice();
void throw_dice();
void menu(int id);
void mouse(int btn,int state,int x,int y);
void keys( unsigned char key, int x, int y );

void init()
{
     glClearColor(0,1,0.7,1);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,499.0,0.0,499.0);
     glutPostRedisplay();
}

void start_screen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,1,0.5,1);
    
    glColor3f(1.0,0.0,0.0);
    
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);         //S
     glVertex2f(150,450);
     glVertex2f(100,400);
     glVertex2f(150,350);
     glVertex2f(100,300);
     glEnd();
     
     glBegin(GL_LINE_STRIP);          //N
     glVertex2f(175,300);
     glVertex2f(175,450);
     glVertex2f(225,300);
     glVertex2f(225,450);
     glEnd();
     
     glBegin(GL_LINE_STRIP);         //A
     glVertex2f(250,300);
     glVertex2f(275,450);
     glVertex2f(300,300);
     glEnd();
     glBegin(GL_LINES);
     glVertex2f(250,375);
     glVertex2f(300,375);
     glEnd();
     
     glBegin(GL_LINE_STRIP);         //K
     glVertex2f(325,450);
     glVertex2f(325,300);
     glVertex2f(325,375);
     glVertex2f(350,450);
     glVertex2f(325,375);
     glVertex2f(350,300);
     glEnd();
     
     glBegin(GL_LINES);             //E
     glVertex2f(375,450);
     glVertex2f(375,300);
     glVertex2f(375,450);
     glVertex2f(400,450);
     glVertex2f(375,300);
     glVertex2f(400,300);
     glVertex2f(375,375);
     glVertex2f(400,375);
     glEnd();
     
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_LINE_STRIP);         //A
     glVertex2f(175,150);
     glVertex2f(200,250);
     glVertex2f(225,150);
     glEnd();
     glBegin(GL_LINES);
     glVertex2f(175,200);
     glVertex2f(225,200);
     glEnd();
     
     glBegin(GL_LINE_STRIP);          //N
     glVertex2f(250,150);
     glVertex2f(250,250);
     glVertex2f(275,150);
     glVertex2f(275,250);
     glEnd();
     
     glBegin(GL_LINE_LOOP);          //D
     glVertex2f(300,150);
     glVertex2f(300,250);
     glVertex2f(325,200);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);        //L
     glVertex2f(100,125);
     glVertex2f(100,10);
     glVertex2f(125,10);
     glEnd();
     
     glBegin(GL_LINE_STRIP);         //A
     glVertex2f(150,10);
     glVertex2f(175,125);
     glVertex2f(200,10);
     glEnd();
     glBegin(GL_LINES);
     glVertex2f(150,62);
     glVertex2f(200,62);
     glEnd();
     
     glBegin(GL_LINE_LOOP);          //D
     glVertex2f(225,10);
     glVertex2f(225,125);
     glVertex2f(250,62);
     glEnd();
     
     glBegin(GL_LINE_LOOP);          //D
     glVertex2f(275,10);
     glVertex2f(275,125);
     glVertex2f(300,62);
     glEnd();
     
     glBegin(GL_LINES);             //E
     glVertex2f(325,125);
     glVertex2f(325,10);
     glVertex2f(325,125);
     glVertex2f(350,125);
     glVertex2f(325,10);
     glVertex2f(350,10);
     glVertex2f(325,62);
     glVertex2f(350,62);
     glEnd();
     
     glBegin(GL_LINE_STRIP);          //R
     glVertex2f(375,10);
     glVertex2f(375,125);
     glVertex2f(400,94);
     glVertex2f(375,62);
     glVertex2f(400,10);
     glEnd();
     
     glFlush();  
     glLineWidth(0.5);   
}

void print_text(int x,int y,char str[],float r,float g,float b)
{
     glRasterPos2i(x,y);                                                        //displays msg passed as parameter
     for(i=0;str[i]!='\0';i++)
     {
     glColor3f(r,g,b);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
     }
}    

void frontscreen()
{
 glClear(GL_COLOR_BUFFER_BIT);
     print_text(184,480,college,0.0,0.0,1.0);              //displays college name
     print_text(180,450,dept,0.7,0.0,1.0);                 //displays dept.
     print_text(210,380,title,0.0,0.0,0.0);             //displays project name 
     print_text(80,370,dash,0.0,0.0,0.0);              //displays dashes   
     print_text(170,340,heading,0.0,0.0,0.0);          //displays heading of table
     print_text(80,330,dash,0.0,0.0,0.0);            //displays dashes  
     print_text(170,310,row1,0.0,0.0,0.0);           //displays 1st row in table  
     print_text(170,290,row2,0.0,0.0,0.0);                //displays 2nd row in table   
     print_text(80,270,dash,0.0,0.0,0.0);               //displays dashes
     print_text(200,100,emsg,1.0,0.1,1.0);                 //displays "enter msg"  
     glFlush();
}

void load_screen()
{
     glClear(GL_COLOR_BUFFER_BIT);
     print_text(245,250,load,1.0,0.0,1.0);              //displays loading
     
     glColor3f(1,1,1);
     glBegin(GL_POLYGON);
     glVertex2f(40,110);
     glVertex2f(40,40);
     glVertex2f(460,40);
     glVertex2f(460,110);
     glEnd();
     glFlush();
 
     glColor3f(0.545,0.6434,0.743);
     glBegin(GL_POLYGON);
     glVertex2f(50,100);
     glVertex2f(50,50);
     glVertex2f(130,50);
     glVertex2f(130,100);
     glEnd();
     sleep(1000);
     glFlush();
     
     glBegin(GL_POLYGON);
     glVertex2f(130,100);
     glVertex2f(130,50);
     glVertex2f(210,50);
     glVertex2f(210,100);
     glEnd();
     sleep(1000);
     glFlush();
     
     glBegin(GL_POLYGON);
     glVertex2f(210,100);
     glVertex2f(210,50);
     glVertex2f(290,50);
     glVertex2f(290,100);
     glEnd();
     sleep(1000);
     glFlush();
     
     glBegin(GL_POLYGON);
     glVertex2f(290,100);
     glVertex2f(290,50);
     glVertex2f(370,50);
     glVertex2f(370,100);
     glEnd();
     sleep(1000);
     glFlush();
     
     glBegin(GL_POLYGON);
     glVertex2f(370,100);
     glVertex2f(370,50);
     glVertex2f(450,50);
     glVertex2f(450,100);
     glEnd();
     sleep(2000);
     glFlush();
     flag=3;
     glutPostRedisplay();
}

void display()
{
     int k=0,num=1,px=165,py=165,pnum=0;
     glClear(GL_COLOR_BUFFER_BIT);
     if(flag==0)
       start_screen();
     else if(flag==1)
       frontscreen ();
     else if(flag==2)
       load_screen();
     else
     { 
     for(i=0;i<maxx;i++)                                                        //computing board co-ordinates
     x[i]=x0+i*dx;
     for(j=0;j<maxy;j++)
     y[j]=y0+j*dy;                                                              //drawing game board
     for(i=0;i<maxx-1;i++)
     for(j=0;j<maxy-1;j++)
     {
                          if(k==0)
                          {
                          k=1;
                          glColor3f(1.0,0.5,0.0);
                          glBegin(GL_POLYGON);
                          glVertex2f(x[i],y[j]);
                          glVertex2f(x[i],y[j+1]);
                          glVertex2f(x[i+1],y[j+1]);
                          glVertex2f(x[i+1],y[j]);
                          glEnd();
                          }
                          else if(k==1)
                          {
                          k=2;
                          glColor3f(1.0,1.0,0.0);
                          glBegin(GL_POLYGON);
                          glVertex2f(x[i],y[j]);
                          glVertex2f(x[i],y[j+1]);
                          glVertex2f(x[i+1],y[j+1]);
                          glVertex2f(x[i+1],y[j]);
                          glEnd();
                          }
                          
                          else
                          {
                          k=0;
                          glColor3f(0.0,1.0,0.0);
                          glBegin(GL_POLYGON);
                          glVertex2f(x[i],y[j]);
                          glVertex2f(x[i],y[j+1]);
                          glVertex2f(x[i+1],y[j+1]);
                          glVertex2f(x[i+1],y[j]);
                          glEnd();
                          }                          
     }
     
     glLineWidth(5.0);
     glBegin(GL_LINE_LOOP);                                                     //LADDER 1
     glColor3f(0.0,0.5,0.5);
     glVertex2d(395,315);
     glVertex2d(415,315);
     glVertex2d(415,345);
     glVertex2d(395,345);
     glVertex2d(395,375);
     glVertex2d(415,375);
     glVertex2d(415,405);
     glVertex2d(395,405);
     glVertex2d(395,375);
     glVertex2d(415,375);
     glVertex2d(415,345);
     glVertex2d(395,345);
     glEnd();
     glBegin(GL_LINES);
     glVertex2d(395,315);
     glVertex2d(395,305);
     glVertex2d(415,315);
     glVertex2d(415,305);
     glVertex2d(395,405);
     glVertex2d(395,415);
     glVertex2d(415,405);
     glVertex2d(415,415);
     glEnd();
     
     glBegin(GL_LINE_LOOP);                                                     //LADDER 2
     glColor3f(0.0,0.5,0.5);
     glVertex2d(255,230);
     glVertex2d(265,225);
     glVertex2d(275,245);
     glVertex2d(265,250);
     glVertex2d(272,271);
     glVertex2d(282,262);
     glVertex2d(275,245);
     glVertex2d(265,250);
     glEnd();
     glBegin(GL_LINES);
     glVertex2d(250,225);
     glVertex2d(255,230);
     glVertex2d(260,220);
     glVertex2d(265,225);
     glVertex2d(272,271);
     glVertex2d(278,285);
     glVertex2d(290,280);
     glVertex2d(282,262);
     glEnd();
     
     glBegin(GL_LINE_LOOP);                                                     //LADDER 3
     glColor3f(0.0,0.5,0.5);
     glVertex2d(185,195);
     glVertex2d(205,195);
     glVertex2d(205,225);
     glVertex2d(185,225);
     glVertex2d(185,255);
     glVertex2d(205,255);
     glVertex2d(205,285);
     glVertex2d(185,285);
     glVertex2d(185,315);
     glVertex2d(205,315);
     glVertex2d(205,345);
     glVertex2d(185,345);
     glVertex2d(185,375);
     glVertex2d(205,375);
     glVertex2d(205,225);
     glVertex2d(185,225);
     glVertex2d(185,375);
     glEnd();
     glBegin(GL_LINES);
     glVertex2d(185,385);
     glVertex2d(185,375);
     glVertex2d(205,385);
     glVertex2d(205,375);
     glVertex2d(185,195);
     glVertex2d(185,185);
     glVertex2d(205,195);
     glVertex2d(205,185);
     glEnd();
     
     glBegin(GL_LINE_STRIP);                                                    //Snake 1
     glColor3f(1.0,1.0,0.0);
     glVertex2d(260,430);
     glVertex2d(285,405);
     glVertex2d(270,390);
     glVertex2d(315,345);
     glEnd();
     glRasterPos2i(257,427);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'>');
     
     glBegin(GL_LINE_STRIP);                                                    //Snake 2
     glColor3f(1.0,0.0,1.0);
     glVertex2d(370,280);
     glVertex2d(345,255);
     glVertex2d(375,240);
     glVertex2d(330,210);
     glVertex2d(345,195);
     glVertex2d(315,165);
     glEnd();
     glRasterPos2i(370,278);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'<');
     glLineWidth(0.5);
     
     for(i=1;i<=10;i++)                                                         //block numbering
     {
     for(j=1;j<=10;j++)
     {
         if((i%2)!=0 && (num%10)!=0)
         {
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(px,py);
                pnum=num;
                
                if((pnum/10)==0)
                {
                pnum=(pnum%10);
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(px,py);
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
                }
                  
                else
                {
                pnum=(pnum/10); 
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(px,py);
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
                pnum=(num%10);
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
                }
                 
                num++;
                px=px+30;
         }
         
         else if(num==100)
         {
          pnum=num;
          glColor3f(0.0,0.0,0.0);
          glRasterPos2i(px-2,py);
          pnum=1;
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
          pnum=0;
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
          pnum=0;
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');
         }
         else if((num%10)==0)
         {
         pnum=num;
         glColor3f(0.0,0.0,0.0);
         glRasterPos2i(px,py);
         pnum=(pnum/10);
         glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');   
         pnum=0;
         glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0'); 
         num++;
         py=py+30;    
         }
         else if((i%2)==0)
         {
         pnum=num;
         glColor3f(0.0,0.0,0.0);
         glRasterPos2i(px,py);
         pnum=(pnum/10);
         glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');  
         pnum=(num%10);
         glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pnum+'0');   
         num++;
         px=px-30;     
         }
     }
     }   
     print_text(30,430,msgwin,0.0,0.0,1.0);                                     //Displays "msg window"
     print_text(220,480,title,0.0,0.0,1.0);                                     //Displaying title "Snakes and Ladders game"
     print_text(80,470,dash,0.0,0.0,0.0);                                       //Displaying dashes
     
     glBegin(GL_POLYGON);                                                       //Black border around the board
     glColor3f(0.0,0.0,0.0);
     glVertex2d(147,150);
     glVertex2d(150,150);
     glVertex2d(150,450);
     glVertex2d(147,450);
     glEnd();
     glBegin(GL_POLYGON);                                                       
     glColor3f(0.0,0.0,0.0);
     glVertex2d(450,150);
     glVertex2d(453,150);
     glVertex2d(453,450);
     glVertex2d(450,450);
     glEnd();
     glBegin(GL_POLYGON);                                                       
     glColor3f(0.0,0.0,0.0);
     glVertex2d(147,150);
     glVertex2d(453,150);
     glVertex2d(453,145);
     glVertex2d(147,145);
     glEnd();
     glBegin(GL_POLYGON);                                                       
     glColor3f(0.0,0.0,0.0);
     glVertex2d(453,450);
     glVertex2d(453,455);
     glVertex2d(147,455);
     glVertex2d(147,450);
     glEnd();
     
     glColor3f(1,1,1);                                                          //dice's outer body
     glBegin(GL_POLYGON);
     glVertex2f(10,10);
     glVertex2f(10,100);
     glVertex2f(80,100);
     glVertex2f(80,10);
     glEnd();
     glBegin(GL_POLYGON);
     glVertex2f(10,100);
     glVertex2f(15,110);
     glVertex2f(85,110);
     glVertex2f(80,100);
     glEnd();
     glBegin(GL_POLYGON);
     glVertex2f(80,100);
     glVertex2f(85,110);
     glVertex2f(85,20);
     glVertex2f(80,10);
     glEnd();
     glColor3f(0,0,0);
     glBegin(GL_LINE_STRIP);
     glVertex2f(10,10);
     glVertex2f(80,10);
     glVertex2f(80,100);
     glVertex2f(10,100);
     glVertex2f(10,10);
     glVertex2f(80,10);
     glVertex2f(85,20);
     glVertex2f(85,110);
     glVertex2f(15,110);
     glVertex2f(10,100);
     glVertex2f(80,100);
     glVertex2f(85,110);
     glEnd();
     
     
     glBegin(GL_POLYGON);                                                       //Black Window on left screen
     glColor3f(0.0,0.0,0.0);
     glVertex2d(0,200);
     glVertex2d(130,200);
     glVertex2d(130,420);
     glVertex2d(0,420);
     glEnd();
     glFlush();
     
    if((msg11 || msg12) && initial==0)
    {
       if(msg11)
       {
           print_text(5,410,mode1,1.0,1.0,1.0);                                 //displays Human v/s Human
       }
       
       else if(msg12)
       {
           print_text(5,410,mode2,1.0,1.0,1.0);                                 //displays Human v/s computer
       }
    }
   
    if((msg21 || msg22) && finish==0)
    {
       if(msg21)
       {
       msg21=0;
        print_text(5,360,player1turn,1.0,1.0,1.0);                              //Displaying "Player 1's turn"
       }
       
       else
       {
       msg22=0;
       print_text(5,360,player2turn,1.0,1.0,1.0);                               //Displaying "Player 2's turn"
       }
    }
    
    if(msg31 || msg32 || msg33 || msg34 || msg35 || msg36)
    {
        if(msg31)
        {
        msg31=0;
        print_text(5,310,snake_bite1,1.0,1.0,1.0);                              //displays snake bites player1
        }
        
        else if(msg32)
        {
        msg32=0;
        print_text(5,310,snake_bite2,1.0,1.0,1.0);                              //displays snake bites player2
        }
         
        else if(msg33)
        {
        msg33=0;
        print_text(5,310,ladder_climb1,1.0,1.0,1.0);                            //displays player1 climbed ladder
        }
          
        else if(msg34)
        {
        msg34=0;
        print_text(5,310,ladder_climb2,1.0,1.0,1.0);                            //displays player2 climbed ladder
        }
        
        else if(msg35)
        {
        msg35=0;
        print_text(5,310,snake_bite3,1.0,1.0,1.0);                              //displays snake bites player2
        }
        
        else if(msg36)
        {
        msg36=0;
        print_text(5,310,ladder_climb3,1.0,1.0,1.0);                            //displays player2 climbed ladder
        }
    }
    
    if(msg41 || msg42 || msg43)
    {
      if(msg41)
      {
       msg41=0;
       print_text(5,260,cgtmsg_p1,1.0,1.0,1.0);                                 //Displaying player 1 won
      }
      
      else if(msg42)
      {
       msg42=0;
       print_text(5,260,cgtmsg_p2,1.0,1.0,1.0);                                 //Displaying player 2 won
      }
      
      else if(msg43)
      {
      msg43=0;
       print_text(5,260,cgtmsg_comp,1.0,1.0,1.0);                               //Displaying computer won
      }
    }
    
    if(msg51 || msg52)
    {
      if(msg51)
      {
      msg51=0;
     print_text(5,210,invkey,1.0,1.0,1.0);                                      //Displaying Invalid key
      }
      
      else
      {
      msg52=0;
      print_text(5,210,errmsg,1.0,1.0,1.0);                                     //Displaying Invalid Option
      }
    }
    
    if(msg61 && finish==0)
    {
      msg61=0;
      glColor3f(0.0,0.0,0.0);
      print_text(250,80,miss_msg1,0.0,0.0,0.0);                                  //Displaying just missed 100
      print_text(250,65,miss_msg2,0.0,0.0,0.0);                                  //Displaying just missed 100 (continued)
    }
     
     glBegin(GL_POLYGON);                                                       //red polygon for player at bottom
     glColor3f(1.0,0.0,0.0);
     glVertex2d(180,10);
     glVertex2d(180,25);
     glVertex2d(195,25);
     glVertex2d(195,10);
     glEnd();
     
print_text(198,10,player1msg,0.0,0.0,0.0);                                      //Displays "Player 1"
 
 glBegin(GL_POLYGON);                                                           //blue polygon for player at bottom
     glColor3f(0.0,0.0,1.0);
     glVertex2d(300,10);
     glVertex2d(300,25);
     glVertex2d(315,25);
     glVertex2d(315,10);
     glEnd();
 
if(msg11)
{
 print_text(318,10,player2msg,0.0,0.0,0.0);                                     //Displays "Player 2"
}
else if(msg12)
{
 print_text(318,10,comp,0.0,0.0,0.0);                                           //Displays "Computer" as Player 2
}    

if(initial==1)
{
disp_fig();
player1=0;
player2=1;
disp_fig();
player1=1;
player2=0;
initial=0;
msg21=1;
msg22=0;
if(msg11)
{
 print_text(5,410,mode1,1.0,1.0,1.0);                                           //displays Human v/s Human
 print_text(5,360,player1turn,1.0,1.0,1.0);                                     //displays player 1's turn
}
else if(msg12)
{
 print_text(5,410,mode2,1.0,1.0,1.0);                                           //displays Human v/s Computer
 print_text(5,360,player1turn,1.0,1.0,1.0);                                     //displays player 1's turn
}
glFlush(); 
}

else
{
   dice(top_face);
   disp_fig();
}     
}
glFlush();
}

void locpt_conv(int loc)
{
ptx=x0;
pty=y0;

for(i=2;i<=loc;i++)
{
                   if(i>100)
                    continue;
                   else if((i-1)%10==0)
                   {
                        pty=pty+30;
                   }
                   else if((((i/10)%2)==0 && (i%10)!=0) || ((i%10)==0 && (i/10)%2!=0))
                   {
                        ptx=ptx+30;
                   }
                   else
                   {
                       ptx=ptx-30;
                   }
}    
}

void disp_fig()
{  

if((oldp1x != oldp2x) || (oldp1y != oldp2y))
{                                                                                                                                   
glBegin(GL_POLYGON);                                                            //player 1 coin moves ahead
glColor3f(1.0,0.0,0.0);
glVertex2d(oldp1x+7,oldp1y+7);
glVertex2d(oldp1x+22,oldp1y+7);
glVertex2d(oldp1x+22,oldp1y+22);
glVertex2d(oldp1x+7,oldp1y+22);
glEnd();

glBegin(GL_POLYGON);                                                            //player 2 coin moves ahead
glColor3f(0.0,0.0,1.0);
glVertex2d(oldp2x+7,oldp2y+7);
glVertex2d(oldp2x+22,oldp2y+7);
glVertex2d(oldp2x+22,oldp2y+22);
glVertex2d(oldp2x+7,oldp2y+22);
glEnd();
}

else
{
glBegin(GL_POLYGON);                                                            //player 1 coin moves ahead
glColor3f(1.0,0.0,0.0);
glVertex2d(oldp1x,oldp1y+7);
glVertex2d(oldp1x+15,oldp1y+7);
glVertex2d(oldp1x+15,oldp1y+22);
glVertex2d(oldp1x,oldp1y+22);
glEnd();

glBegin(GL_POLYGON);                                                            //player 2 coin moves ahead
glColor3f(0.0,0.0,1.0);
glVertex2d(oldp2x+15,oldp2y+7);
glVertex2d(oldp2x+30,oldp2y+7);
glVertex2d(oldp2x+30,oldp2y+22);
glVertex2d(oldp2x+15,oldp2y+22);
glEnd();
}

}

void dice(int num)
{
     glColor3f(0.0,0.0,0.0);
     switch(num)
     {
       case 1:glBegin(GL_POLYGON);                                     //displays 1 dot
              glVertex2f(40,50);
              glVertex2f(50,50);
              glVertex2f(50,60);
              glVertex2f(40,60);
              glEnd();
              glFlush();
            break;
       
       case 2:
            glBegin(GL_POLYGON);                                        //displays 2 dots
              glVertex2f(40,40);
              glVertex2f(50,40);
              glVertex2f(50,50);
              glVertex2f(40,50);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(40,60);
              glVertex2f(50,60);
              glVertex2f(50,70);
              glVertex2f(40,70);
              glEnd();
              glFlush();
            break;
      
       case 3:glBegin(GL_POLYGON);                                         //displays 3 dots
              glVertex2f(40,30);
              glVertex2f(50,30);
              glVertex2f(50,40);
              glVertex2f(40,40);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(40,50);
              glVertex2f(50,50);
              glVertex2f(50,60);
              glVertex2f(40,60);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(40,70);
              glVertex2f(50,70);
              glVertex2f(50,80);
              glVertex2f(40,80);
              glEnd();
              glFlush();
            break;
       
       case 4:glBegin(GL_POLYGON);                                       //displays 4 dots
              glVertex2f(30,40);
              glVertex2f(40,40);
              glVertex2f(40,50);
              glVertex2f(30,50);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(30,60);
              glVertex2f(40,60);
              glVertex2f(40,70);
              glVertex2f(30,70);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(50,40);
              glVertex2f(60,40);
              glVertex2f(60,50);
              glVertex2f(50,50);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(50,60);
              glVertex2f(60,60);
              glVertex2f(60,70);
              glVertex2f(50,70);
              glEnd();
              glFlush();
            break;
       
       case 5:glBegin(GL_POLYGON);                                       //displays 5 dots
              glVertex2f(30,40);
              glVertex2f(40,40);
              glVertex2f(40,50);
              glVertex2f(30,50);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(30,60);
              glVertex2f(40,60);
              glVertex2f(40,70);
              glVertex2f(30,70);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(50,40);
              glVertex2f(60,40);
              glVertex2f(60,50);
              glVertex2f(50,50);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(50,60);
              glVertex2f(60,60);
              glVertex2f(60,70);
              glVertex2f(50,70);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(42,50);
              glVertex2f(48,50);
              glVertex2f(48,60);
              glVertex2f(42,60);
              glEnd();
              glFlush();
            break;
       
       case 6:glBegin(GL_POLYGON);                                        //displays 6 dots
              glVertex2f(25,30);
              glVertex2f(35,30);
              glVertex2f(35,40);
              glVertex2f(25,40);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(25,50);
              glVertex2f(35,50);
              glVertex2f(35,60);
              glVertex2f(25,60);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(25,70);
              glVertex2f(35,70);
              glVertex2f(35,80);
              glVertex2f(25,80);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(55,30);
              glVertex2f(65,30);
              glVertex2f(65,40);
              glVertex2f(55,40);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(55,50);
              glVertex2f(65,50);
              glVertex2f(65,60);
              glVertex2f(55,60);
              glEnd();
              glBegin(GL_POLYGON);
              glVertex2f(55,70);
              glVertex2f(65,70);
              glVertex2f(65,80);
              glVertex2f(55,80);
              glEnd();
              glFlush();
            break;
       }
}
     
void throw_dice()
{
     s[0].head=97,s[0].tail=66,s[1].head=48,s[1].tail=6;
     l[0].bottom=19,l[0].top=79,l[1].bottom=24,l[1].top=45,l[2].bottom=52,l[2].top=89;
     
     if(finish==0)             
     {                           
     srand(time(NULL));
     top_face=(rand()%6)+1;
     if(player1)
     {
                if(100-play1pos<top_face)
                {
                 msg61=1;
                 goto next;
                }
                else
                {
                play1pos+=top_face;
                for(i=0;i<2;i++)                                                //Snake bite condition
                {
                if(s[i].head==play1pos)
                {
                glutPostRedisplay();
                play1pos=s[i].tail;
                msg31=1;
                sleep(500);
                }
                }
                for(i=0;i<3;i++)                                                //Ladder condition
                {
                    if(l[i].bottom==play1pos)
                    {
                    glutPostRedisplay();
                    play1pos=l[i].top;
                    msg33=1;
                    sleep(500);
                    }
                }
                locpt_conv(play1pos);
                oldp1x=ptx;
                oldp1y=pty;
                }
     }
     else
     {
         if(100-play2pos<top_face)
         {
              msg61=1;
              goto next;
         }
         else
         {
                play2pos+=top_face;
                for(i=0;i<2;i++)                                                //Snake bite condition
                {
                if(s[i].head==play2pos)
                {
                glutPostRedisplay();
                play2pos=s[i].tail;
                if(msg11)
                {
                msg32=1;
                msg35=0;
                }
                else if(msg12)
                {
                msg32=0;
                msg35=1;
                }
                sleep(500);
                }
                }
                for(i=0;i<3;i++)                                                //Ladder condition
                {
                if(l[i].bottom==play2pos)
                {
                glutPostRedisplay();
                play2pos=l[i].top;
                if(msg11)
                {
                msg34=1;
                msg36=0;
                }
                else if(msg12)
                {
                msg34=0;
                msg36=1;
                }
                sleep(500);    
                }
                }
         locpt_conv(play2pos);
         oldp2x=ptx;
         oldp2y=pty;
         }
     }
 next:glutPostRedisplay();
     
     if(play1pos>=100)
     {
       finish=1;
       msg41=1;
     }
     else if(play2pos>=100)
     {
       finish=1;
       if(msg11)
       {
       msg42=1;
       msg43=0;
       }
       else if(msg12)
       {
       msg42=0;
       msg43=1;
       }
     }  
     
     if((top_face==6 && game_mode==1) || (top_face==6 && game_mode==2 && player1))
     return;
     else if(top_face==6 && game_mode==2 && player2)
     {
     glutPostRedisplay();  
     throw_dice();
     }
     
     if(player1)
     {
     player1=0;
     player2=1;
     msg22=1;
     msg21=0;               
                if(game_mode==2)
                {
                   glutPostRedisplay();
                   throw_dice();
                }
     }
     else
     {
         player1=1;
         player2=0;
         msg21=1;
         msg22=0;
     }
     }
     else
     glutPostRedisplay();
}     

void menu(int id)
{
     switch(id)
     {
            case 1:game_mode=1;
                 player1=1;
                 player2=0;
                   msg11=1;
                   msg12=0;
                   msg61=0;              
                   play1pos=0;
                   play2pos=0;
                   finish=0;
                   initial=1;
                   oldp1x=100;
                   oldp1y=120;
                   oldp2x=120;
                   oldp2y=120;
                   glFlush();
                   break;
           
            case 2:game_mode=2;
                 player1=1;
                 player2=0;
                   msg11=0;
                   msg12=1; 
                   msg61=0;                  
                   play1pos=0;
                   play2pos=0;
                   finish=0;
                   initial=1;
                   oldp1x=100;
                   oldp1y=120;
                   oldp2x=120;
                   oldp2y=120;
                    break;
            
            case 3:exit(0);             
     }
     glutPostRedisplay();
}              

void mouse(int btn,int state,int x,int y)
{
     if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
     {
        glutCreateMenu(menu);
        glutAddMenuEntry("Play Human v/s Human",1);
        glutAddMenuEntry("Play Human v/s Computer",2);
        glutAddMenuEntry("Quit",3);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
     }
}

void keys(unsigned char key, int x, int y )

{
  switch(key)
 {
  case 13:if(flag==0)                         //Ascii of 'enter' key is 13
          flag=1;
          else if(flag==1) 
          flag=2;
          break;
  
  case 'A':if(finish==0 && player1 && flag==3)
               {
                msg21=1;
                throw_dice();
               }
                 
                 else if(finish==0 && player2 && flag==3)
                 {
                   msg51=1;
                 } 
                 
                 else if(finish==1)
                  {
                   msg52=1;
                  }
                 break;
   
   case 'a':if(finish==0 && player1 && flag==3)
                 {
                msg21=1;
                throw_dice();
                 }
                 
                  else if(finish==0 && player2 && flag==3)
                 {
                   msg51=1;
                 } 
                 
                 else if(finish==1)
                  {
                   msg52=1;
                  }
                 break;
    
  case 'L':if(finish==0 && player2 && flag==3)
                   {
                   msg22=1;
                  throw_dice();
                  }
                  
                   else if(finish==0 && player1 && flag==3)
                 {
                   msg51=1;
                 } 
                  
                  else if(finish==1)
                  {
                   msg52=1;
                  }  
                   break;  
  case 'l':if(finish==0 && player2 && flag==3)
                 {
                 msg22=1;
                 throw_dice();
                 }
                  
                  else if(finish==0 && player1 && flag==3)
                 {
                   msg51=1;
                 } 
                  
                  else if(finish==1)
                  {
                   msg52=1;
                  }  
                   break;   
                   
 default:if(finish==0 && flag==3)
           msg51=1;
         else if(finish==1)
           msg52=1;
         break;   
         
 }
    glutPostRedisplay();
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Snakes and Ladders Game");
    glutFullScreen();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    init();
    glutMainLoop();
}
