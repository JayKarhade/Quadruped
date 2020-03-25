#include <Servo.h>
int x; //x coordinate of the point where the quadruped has to traverse
int y; //y coordinate of the point where the quadruped has to traverse
int L1; /*srtide length (distance by which COG moves in one cycle)(same notation as that used in the report, l1 is almost equal to
distance traversed by COG in one cycle*/
int cou = 0;
int cou1 =0;
int cou2 = 0;
int dtime = 100;
int a_ul;     //alpha angle for the actuator between coxa and femur in ulf(same notation  as per the report)
int b_ul;      //beta angle for the actuator between femur and tibia in ulf
int g_ul;      //gamma angle for the actuator between coxa and body in ulf

int a_ur;     
int b_ur;     
int g_ur;

int a_bl;     
int b_bl;      
int g_bl;

int a_br;     
int b_br;     
int g_br;

Servo ulc;//servo at the actuator connecting the body and the upper left coxa
Servo ulf;//servo at the actuator connecting the upper left coxa and the upper left femur 
Servo ult;//servo at the actuator connecting the upper left femur and the upper left tibia

Servo urc;
Servo urf;
Servo urt;

Servo blc;
Servo blf;
Servo blt;

Servo brc;
Servo brf;
Servo brt;


void setup() {
  ulc.attach(1); 
  ulf.attach(2);
  ult.attach(3);
  urc.attach(4);
  urf.attach(5);
  urt.attach(6);
  blc.attach(7);
  blf.attach(8);
  blt.attach(9);
  brc.attach(10);
  brf.attach(11);
  brt.attach(12);// attaches the servo to pins.
  Serial.begin(9600);

}

void loop() 
{
Serial.print("enter the x coordinate");
while(Serial.available==0){};
x = Serial.parseInt();

Serial.print("enter the y coordinate");
while(Serial.available==0){};
y = Serial.parseInt();
void initial_pos();
while(cou!=(y/L1))//to take it to any point along the y direction
{
  brf.write(a_br);
  delay(dtime);
  brc.write(g_br);
  delay(dtime);
  brt.write(b_br);
  delay(dtime);
   brf.write(a_br);
   delay(dtime);

   blf.write(b_bl);
   urf.write(b_ur);
   ulf.write(b_ul);

   urf.write(a_ur);
  delay(dtime);
  urc.write(g_ur);
  delay(dtime);
  urt.write(b_ur);
  delay(dtime);
   urf.write(a_ur);
   delay(dtime);

   blf.write(b_bl);
   brf.write(b_ur);
   ulf.write(b_ul);

   blf.write(a_bl);
  delay(dtime);
  blc.write(g_bl);
  delay(dtime);
  blt.write(b_bl);
  delay(dtime);
   blf.write(a_bl);
   delay(dtime);

   blf.write(b_ul);
   urf.write(b_ur);
   ulf.write(b_br);

    ulf.write(a_ul);
  delay(dtime);
  ulc.write(g_ul);
  delay(dtime);
  ult.write(b_ul);
  delay(dtime);
   ulf.write(a_ul);
   delay(dtime);

   blf.write(b_bl);
   urf.write(b_ur);
   ulf.write(b_br);
   
  cou++;
}

while(cou2!=5)//this part is for turning the bot without traversing
{
 urf.write(initialangle+20);//rotating its servo by its initial angle plus some 20 degrees
 urc.write(36); 
 urf.write(-20);//to set the foot ont the ground again

 ulf.write(initialangle+20);//rotating its servo by its initial angle plus some 20 degrees
 ulc.write(36); 
 ulf.write(-20);

 brf.write(initialangle+20);//rotating its servo by its initial angle plus some 20 degrees
 brc.write(36); 
 brf.write(-20);

 blf.write(initialangle+20);//rotating its servo by its initial angle plus some 20 degrees
 blc.write(36); 
 blf.write(-20);
  }

  while(cou2!=(x/L1))//to take it to any point along the x direction
{
  brf.write(a_br);
  delay(dtime);
  brc.write(g_br);
  delay(dtime);
  brt.write(b_br);
  delay(dtime);
   brf.write(a_br);
   delay(dtime);

   blf.write(b_bl);
   urf.write(b_ur);
   ulf.write(b_ul);

   urf.write(a_ur);
  delay(dtime);
  urc.write(g_ur);
  delay(dtime);
  urt.write(b_ur);
  delay(dtime);
   urf.write(a_ur);
   delay(dtime);

   blf.write(b_bl);
   brf.write(b_ur);
   ulf.write(b_ul);

   blf.write(a_bl);
  delay(dtime);
  blc.write(g_bl);
  delay(dtime);
  blt.write(b_bl);
  delay(dtime);
   blf.write(a_bl);
   delay(dtime);

   blf.write(b_ul);
   urf.write(b_ur);
   ulf.write(b_br);

    ulf.write(a_ul);
  delay(dtime);
  ulc.write(g_ul);
  delay(dtime);
  ult.write(b_ul);
  delay(dtime);
   ulf.write(a_ul);
   delay(dtime);

   blf.write(b_bl);
   urf.write(b_ur);
   ulf.write(b_br);
   
  cou2++;
}

 
  
}
void initial_pos(){
    ulf_1.write();
    ulf_2.write();
    ulf_3.write();
    urf_1.write();
    urf_2.write();
    urf_3.write();
    blf_1.write();
    blf_2.write();
    blf_3.write();
    brf_1.write();
    brf_2.write();
    brf_3.write();
}
