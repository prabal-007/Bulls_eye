#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<math.h>

 void graph();
 void startgraph();
 void initmouse();
 void showmouse();
 void hidemouse();
 void getmouse();
 void setmouse();
      union REGS in,out;
      int px=0, py=0;
      int click =0 ;
      void bullseye();   void face(double);    double findpercent();
       void* arrowimage() ;
 void main()
  {

bk: startgraph();
    initmouse();showmouse();
    void* arrowimg = arrowimage();
    cleardevice();
    setbkcolor(LIGHTBLUE);
  //  graph();
    settextstyle(2,0,6);
    setcolor(LIGHTRED);
    outtextxy(180,0,"===Hit the Bulls Eye===");
    //setfillstyle(1,LIGHTGRAY);
    //graph();

    double   markspercent = findpercent();
      setcolor(LIGHTBLUE); //to set color for text & outline of shapes.
      bullseye();
      setcolor(WHITE); // normal again
    //  graph();
  int arrowpercentamt;
  int length = 420 - 280;  //140...
  arrowpercentamt = length * markspercent/100;  //%ageamt = amt*percent/100
		//let markspercent:50%
		// 140*50/100 = 70
  int arrowycoord = 420 - arrowpercentamt; //exact y location of arrow got it.
		  //420 - 70 = 350
    char str[70];
    sprintf(str,"%.lf",markspercent);
    strcat(str,"%");
    for(int j=420;j>=arrowycoord;j--)
    {
      if(j== arrowycoord)
      {
	 putimage(140,j,arrowimg,1); //show  & dont hide..
	 outtextxy(140-40,j-10,str);// graph(); getch();
	 break;
      }//end if.

      putimage(140,j,arrowimg,1);  //show
      delay(60);
      putimage(140,j,arrowimg,1);//hide..

    } //end for..

    face(markspercent);

   getch();
     gotoxy(30,5); printf("Try Again? (y/n)  : ");
    char ch;
    fflush(stdin); ch = getche();
    if(ch=='y' || ch=='Y')
    {
      cleardevice(); closegraph(); goto bk;
    }
    cleardevice(); //to avoid distortion at exit of code.
    closegraph();
  }//end main...
     void* arrowimage()
      {
	//outtextxy(100,440,"=================>"); //alt 205 Í
	outtextxy(100,440,">>>ÍÍÍÍÍÍÍÍÍÍÍÍÍÍ>"); //14 times

	void* arrowimg =(void*)malloc(imagesize(100,440,250,450));

	getimage(100,440,250,450,arrowimg);
	graph();

	getch();
	return arrowimg;
      } //end of arrowimage()..

  void face(double markspercent)
   {
	  char str[80];
	  settextstyle(2,0,6); setcolor(BLUE);
	  int st=0,end=0; //start and end angles.for smiley
	  if(markspercent >= 80)
	  {
	   sprintf(str,"Hurray! Goal Seeked");
	   st=180, end=360;
	  //happy smile.. set angle 180 - 360 degree

	  } //end if.
	  else if(markspercent >= 40)
	  {
	   sprintf(str,"It is good...");
	   st = 190, end = 350; //lil smile..
	  //happy smile.. set angle 180 - 360 degree
	  }//end else if.
	  else  //below 40...
	   {
	     sprintf(str,"It is sad...");
	     st=0, end = 180;

	   }
	  setfillstyle(1,WHITE);
	  bar3d(410+10,60,620,250,10,1);
	  outtextxy(420+10,80,str);
	  //add happy smiley..
	  circle(520,190,50); //face..
	  circle(500,170,10); //left eye.
	  circle(540,170,10); //right eye.
     ellipse(520,210,st,end,30,15);

   }//end face()..

   double findpercent()
    {
    double maxmarks,marksobtained,markspercent;
    gotoxy(3,3); printf("Enter Maximum Marks: ");
    gotoxy(25,3); cin>>maxmarks;
    gotoxy(3,4); printf("Enter Marks Scored: ");
    gotoxy(25,4); cin>>marksobtained;
    if(marksobtained > maxmarks)
      {
	gotoxy(3,5);
	printf("MarksScored should be <= Max.marks.Renter plz..");
	sleep(2); cleardevice();
	main();
      }//end if....
    markspercent = fabs( (marksobtained*100)/maxmarks ) ; //fabs: kill all 71.35354543 frustration..
    gotoxy(3,5); printf("Percentage: %.lf %",markspercent);

    return markspercent;
    } //end of findpercent..
   void bullseye()
    {
     int x=280,y=280;

      int color = RED;
      int i;
      for(i=140;i>=20;i=i-20)// will not reach at 5...
       {
	 if(color == RED)
	   color = WHITE ;
	 else
	   color = RED;

	 setfillstyle(1,color);
	 fillellipse(x,y,i,i); // fillellipse used for fillingcolor  circle
	 delay(60);

       }//end for...
      setfillstyle(1,RED);
      fillellipse(x,y,5,5); //for tiny red point.

    } //end bullseye()..
  void  graph()      //temp code for xy axis....
  {
      int x; //  x axis..
    int y; //  y axis..
    int i; //  loop..
    char xsg[10]; // x coordinate msg.
    char ysg[10]; // y coordinate msg.
    setbkcolor(LIGHTBLUE);
    settextstyle(2,0,2);

    for(x=0,y=0;x<=639;x=x+20,y=y+20)
      {
	//for x axis....
	setcolor(WHITE);
	line(x,0,x,479);
	sprintf(xsg,"%d",x);
	outtextxy(x+2,0,xsg);

	//for y axis...
	setcolor(WHITE);
	line(0,y,639,y);
	sprintf(ysg,"%d",y);
	outtextxy(0+2,y+1,ysg);

	// red color for x axis..
	setcolor(RED);
	line(x+10,0+10,x+10,479);
	line(0+10,y+10,639,y+10); //for y axis..

      } //end for..



  }//end graph()...


  void startgraph()
   {
       /* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
       /* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi"); //egavga.bgi
	delay(50);
     errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
     {
      cout<<"Graphics error:"<<grapherrormsg(errorcode)<<endl;
      cout<<"Press any key to halt.";
      getch();
      exit(1); /* terminate with an error code */
     }

  } //end of startgraph()..

 // mouse functions
    void initmouse()
     {
	in.x.ax=0;
	int86(51,&in,&out);

     }//end initmouse()...
     void showmouse()
       {
	      setmouse();
	      in.x.ax=1;
	      int86(51,&in,&out);

	 } //end showmouse()...

       void getmouse()
       {

	       in.x.ax=3;
	       int86(51,&in,&out);
	       click=out.x.bx;
	       px=out.x.cx;
	       py=out.x.dx;
	}

      void hidemouse()
       {
	    //  setmouse();
	      in.x.ax=2;
	      int86(51,&in,&out);
	}
      void setmouse( )          //int &px,int &py)
      {
	     in.x.ax= 4;
	     in.x.cx= 0 ;  //px;
	     in.x.dx= 0;  // py;
	     in.x.bx= 0;
	     int86(0x33,&in,&out);
      }
