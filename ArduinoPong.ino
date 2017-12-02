/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * 
 * Arduino Pong by Gilbert Martinelli and Akash Kumar
 */
#define H1 11
#define H2 2 
#define H3 7
#define H4 8
#define H5 3
#define H6 6
#define H7 4
#define H8 5

#define L1 A3
#define L2 A2
#define L3 A1
#define L4 10
#define L5 A0
#define L6 9
#define L7 A4
#define L8 A5

const byte gameSpeed = 10;  //number of ticks for each frame of gameplay

byte p1height = 3;  //player 1 paddle
byte p2height = 4;  //player 2 paddle

byte ballX = 3; //ball position
byte ballY = 3;

byte speedX = 0;  //ball speed
byte speedY = 0;

unsigned char gameSpace[8][8] = 
{
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};

unsigned char bigHeart[8][8] =  //Heart-shaped(big)
{
  0,0,0,0,0,0,0,0,
  0,1,1,0,0,1,1,0,
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  0,1,1,1,1,1,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,1,1,0,0,0,
};

unsigned char smallHeart[8][8] =    //Heart-shaped(small)
{
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,1,0,0,1,0,0,
  0,1,1,1,1,1,1,0,
  0,1,1,1,1,1,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,1,1,0,0,0,
  0,0,0,0,0,0,0,0,
};

unsigned char smileyFace[8][8] =   //Other Animation                     
{
  0,0,1,1,1,1,0,0,
  0,1,0,0,0,0,1,0,
  1,0,1,0,0,1,0,1,
  1,0,0,0,0,0,0,1,
  1,0,1,0,0,1,0,1,
  1,0,0,1,1,0,0,1,
  0,1,0,0,0,0,1,0,
  0,0,1,1,1,1,0,0,
};

void blank()
{
  for(int i = 0 ; i < 8 ; i++)
  {
    for(int j = 0; j < 8 ; j++)
    {
      gameSpace[i][j] = 0;
    }
  }
}

void setup()
{
  pinMode(H1,OUTPUT);
  pinMode(H2,OUTPUT);
  pinMode(H3,OUTPUT);
  pinMode(H4,OUTPUT);
  pinMode(H5,OUTPUT);
  pinMode(H6,OUTPUT);
  pinMode(H7,OUTPUT);
  pinMode(H8,OUTPUT);
  
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(L7,OUTPUT);
  pinMode(L8,OUTPUT);
}

void loop()
{
  for(int i = 0 ; i < gameSpeed ; i++)
  {
    if(i == gameSpeed-1)  //game loop: does work on the last tick
    {
      blank();
      gameSpace[0][p1height] = 1;
      gameSpace[0][p1height+1] = 1;
      gameSpace[7][p2height] = 1;
      gameSpace[7][p2height+1] = 1;
      gameSpace[ballX][ballY] = 1;
    }
    Display(gameSpace); //do this every tick
  }
}

void Display(unsigned char dat[8][8])                 //display function
{
  digitalWrite(L1,LOW);    //select 1th row
  digitalWrite(H1,dat[0][0]);
  digitalWrite(H2,dat[1][0]);
  digitalWrite(H3,dat[2][0]);
  digitalWrite(H4,dat[3][0]);
  digitalWrite(H5,dat[4][0]);
  digitalWrite(H6,dat[5][0]);
  digitalWrite(H7,dat[6][0]);
  digitalWrite(H8,dat[7][0]); 
  delay(1);         //Wait LED is lit.
  Clear();          //Clear shadow
 
  digitalWrite(L2,LOW);     //select 2th row
  digitalWrite(H1,dat[0][1]);
  digitalWrite(H2,dat[1][1]);
  digitalWrite(H3,dat[2][1]);
  digitalWrite(H4,dat[3][1]);
  digitalWrite(H5,dat[4][1]);
  digitalWrite(H6,dat[5][1]);
  digitalWrite(H7,dat[6][1]);
  digitalWrite(H8,dat[7][1]);
  delay(1);
  Clear();
  
  digitalWrite(L3,LOW);       //select 3th row
  digitalWrite(H1,dat[0][2]);
  digitalWrite(H2,dat[1][2]);
  digitalWrite(H3,dat[2][2]);
  digitalWrite(H4,dat[3][2]);
  digitalWrite(H5,dat[4][2]);
  digitalWrite(H6,dat[5][2]);
  digitalWrite(H7,dat[6][2]);
  digitalWrite(H8,dat[7][2]);
  delay(1);
  Clear();
  
  digitalWrite(L4,LOW);     //select 4th row
  digitalWrite(H1,dat[0][3]);
  digitalWrite(H2,dat[1][3]);
  digitalWrite(H3,dat[2][3]);
  digitalWrite(H4,dat[3][3]);
  digitalWrite(H5,dat[4][3]);
  digitalWrite(H6,dat[5][3]);
  digitalWrite(H7,dat[6][3]);
  digitalWrite(H8,dat[7][3]);
  delay(1);
  Clear();
  
  digitalWrite(L5,LOW);         //select 5th row
  digitalWrite(H1,dat[0][4]);
  digitalWrite(H2,dat[1][4]);
  digitalWrite(H3,dat[2][4]);
  digitalWrite(H4,dat[3][4]);
  digitalWrite(H5,dat[4][4]);
  digitalWrite(H6,dat[5][4]);
  digitalWrite(H7,dat[6][4]);
  digitalWrite(H8,dat[7][4]);
  delay(1);
  Clear();
  
  digitalWrite(L6,LOW);       //select 6th row
  digitalWrite(H1,dat[0][5]);
  digitalWrite(H2,dat[1][5]);
  digitalWrite(H3,dat[2][5]);
  digitalWrite(H4,dat[3][5]);
  digitalWrite(H5,dat[4][5]);
  digitalWrite(H6,dat[5][5]);
  digitalWrite(H7,dat[6][5]);
  digitalWrite(H8,dat[7][5]);
  delay(1);
  Clear();
  
  digitalWrite(L7,LOW);     //select 7th row
  digitalWrite(H1,dat[0][6]);
  digitalWrite(H2,dat[1][6]);
  digitalWrite(H3,dat[2][6]);
  digitalWrite(H4,dat[3][6]);
  digitalWrite(H5,dat[4][6]);
  digitalWrite(H6,dat[5][6]);
  digitalWrite(H7,dat[6][6]);
  digitalWrite(H8,dat[7][6]);
  delay(1);
  Clear();
  
  digitalWrite(L8,LOW);      //select 8th row
  digitalWrite(H1,dat[0][7]);
  digitalWrite(H2,dat[1][7]);
  digitalWrite(H3,dat[2][7]);
  digitalWrite(H4,dat[3][7]);
  digitalWrite(H5,dat[4][7]);
  digitalWrite(H6,dat[5][7]);
  digitalWrite(H7,dat[6][7]);
  digitalWrite(H8,dat[7][7]);
  delay(1);  
  Clear();
}

void Clear() //clear display
{
  digitalWrite(H1,LOW);
  digitalWrite(H2,LOW);
  digitalWrite(H3,LOW);
  digitalWrite(H4,LOW);
  digitalWrite(H5,LOW);
  digitalWrite(H6,LOW);
  digitalWrite(H7,LOW);
  digitalWrite(H8,LOW);
  
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,HIGH);
}

