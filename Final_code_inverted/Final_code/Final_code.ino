
//timer setup for timer0, timer1, and timer2.
//For arduino uno or any board with ATMEL 328/168.. diecimila, duemilanove, lilypad, nano, mini...

//this code will enable all th114.74 arduino timer interrupts.
//timer0 will interrupt at 2kHz
//timer1 will interrupt at 1Hz
//timer2 will interrupt at 8kHz
int oldval=1000;
//storage variables
boolean toggle0 = 0;
boolean toggle1 = 0;
boolean toggle2 = 0;
double i;
double t=22000;
void setup(){
  
  //set pins as outputs
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
Serial.begin(9600);
  pinMode(10, OUTPUT);

cli();//stop interrupts
 
//set timer0 interrupt at 2kHz
  TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 77.125;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS02) ;
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);

//set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 77.125;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 and CS10 bits for 64 prescaler
  TCCR1B |= (1 << CS12);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
 digitalWrite(12,0);
  digitalWrite(11,0);
//sei();//allow interrupts//////////////Deleteeeeeeeeeeeeeee
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);

}//end setup

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
    digitalWrite(12,toggle0);
    toggle0 = !toggle0;
  }
 


ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)



    digitalWrite(11,toggle1);
    toggle1 = !toggle1;

}
//  flag=0;
boolean setf=1,onlyone=0;
int value=0,count=0,state=0;
void set_f1(int f);
void set_f2(int f);
 void delay_ms(void);
 boolean sa,re,ga,ma,pa,da,ni,saa;
void loop()
{value=0;
sa=digitalRead(2);
re=digitalRead(3);
ga=digitalRead(4);
ma=digitalRead(5);
pa=digitalRead(6);
da=digitalRead(7);
ni=digitalRead(8);
saa=digitalRead(9);
if(sa)
value+=128;
if(re)
value+=64;
if(ga)
value+=32;
if(ma)
value+=16;
if(pa)
value+=8;
if(da)
value+=4;
if(ni)
value+=2;
if(saa)
value+=1;
state=0;
Serial.println(value);
 //if((value==128) ||(value==64) ||(value==32) ||(value==16) ||(value==8) ||(value==4) ||(value==2) ||(value==1))
//            {onlyone=1;}

        if(value!=oldval)
        {                 if(value==0)
                           {cli();
                           }
                          else if(value==128)
                            {set_f1(0);
                             set_f2(129.20);
                            }
                          else if(value==64)
                            {set_f1(0);
                             set_f2(114.74);
                            }
                          else if(value==32)
                            {set_f1(0);
                             set_f2(103.16);    
                            }
                          else if(value==16)
                            {set_f1(0);
                             set_f2(96.65);    
                            }
                          else if(value==8)
                            {set_f1(0);
                             set_f2(85.80);  
                            }
                          else if(value==4)
                            {set_f1(0);
                             set_f2(77.125);
                            }
                          else if(value==2)
                            {set_f1(0);
                             set_f2(68.44);  
                            }
                          else if(value==1) 
                            {   set_f2(64.10);
                            set_f1(0);
                            }
////////////////////     
                          else
                          {if(value<18)
                          {
                            switch (value)
                                {
                                case 17:
                                 set_f1(96.65);
                                 set_f2(64.10);    
                                 break;
                                case 12:
                                 set_f1(85.81);
                                 set_f2(77.12);    
                                 break;
                                case 10:
                                 set_f1(85.81);
                                 set_f2(68.44);    
                                 break;
                                case 9:
                                 set_f1(85.81);
                                 set_f2(64.10);    
                                 break;
                                case 6:
                                 set_f1(77.12);
                                 set_f2(68.44);    
                                 break;
                                case 5:
                                 set_f1(77.12);
                                 set_f2(64.10);    
                                 break;
                                case 3:
                                 set_f1(68.44);
                                 set_f2(64.10);    
                                 break;
                                 default:///////////////////////////////////////////////////////////////
                                 set_f1(68.44);
                                 set_f2(64.10);  
                                  break;
                                }
                          }
                          else if(value<48)
                          {
                            switch (value)
                                {
                                case 40:
                                 set_f1(103.17);
                                 set_f2(85.81);    
                                 break;
                                case 36:
                                 set_f1(103.17);
                                 set_f2(77.12);    
                                 break;
                                case 34:
                                 set_f1(103.17);
                                 set_f2(68.44);    
                                 break;
                                case 33:
                                 set_f1(103.17);
                                 set_f2(64.10);    
                                 break;
                                case 24:
                                 set_f1(96.65);
                                 set_f2(85.81);    
                                 break;
                                case 20:
                                 set_f1(96.65);
                                 set_f2(77.12);    
                                 break;
                                case 18:
                                 set_f1(96.65);
                                 set_f2(68.44);    
                                 break;
                                 default:///////////////////////////////////////////////////////////////
                                 set_f1(96.65);
                                 set_f2(68.44);   
                                  break;
                                }
                          }
                          else if(value<129)
                          {
                            switch (value)
                                {
                                case 96:
                                 set_f1(103.17);
                                 set_f2(114.74);    
                                 break;
                                case 80:
                                 set_f1(96.65);
                                 set_f2(114.74);    
                                 break;
                                case 72:
                                 set_f1(114.74);
                                 set_f2(85.81);    
                                 break;
                                case 68:
                                 set_f1(114.74);
                                 set_f2(77.12);    
                                 break;
                                case 66:
                                 set_f1(114.74);
                                 set_f2(68.44);    
                                 break;
                                case 65:
                                 set_f1(114.74);
                                 set_f2(64.10);    
                                 break;
                                case 48:
                                 set_f1(96.65);
                                 set_f2(103.17);    
                                 break;
                                 default:///////////////////////////////////////////////////////////////
                                 set_f1(96.65);
                                 set_f2(103.17);  
                                  break;
                                }
                          }      
                           else 
                          {
                            switch (value)
                                {
                                case 192:
                                 set_f1(129.20);
                                 set_f2(114.74);  

                                 break;
                                case 160:
                                 set_f1(129.20);
                                 set_f2(103.17);    
                                 break;
                                case 144:
                                 set_f1(129.20);
                                 set_f2(96.65);    
                                 break;
                                case 136:
                                 set_f1(129.20);
                                 set_f2(85.81);    
                                 break;
                                case 132:
                                 set_f1(129.20);
                                 set_f2(77.12);    
                                 break;
                                case 130:
                                 set_f1(129.20);
                                 set_f2(68.44);    
                                 break;
                                case 129:

                                 set_f1(129.20);
                                 set_f2(64.10);    
                                 break;
                                 default:///////////////////////////////////////////////////////////////
                                 set_f1(96.65);
                                 set_f2(103.17);  
                                  break;
                                }
                          }     

                           }
                         
                            
////////////////////

        }
oldval=value;
//toggle2 = !toggle2;
//digitalWrite(10,toggle2);
onlyone=0;
}
void set_f1(int f)
{ 
  if(f!=0)
  { cli();
TIMSK1 |= (1 << OCIE1A);
  OCR1A = f;
  TCNT1  = 0;//initialize counter value to 0
  sei();
  }
  else
  {cli();
  TIMSK1 &= (0 << OCIE1A);
  sei(); }
}



void set_f2(int f)
{
  if(f!=0)
  { cli();
  TIMSK0 |= (1 << OCIE0A);
  OCR0A = f;
  TCNT0  = 0;//initialize counter value to 0
  sei();
 //  Serial.println(f);
  }
  else
  {cli();
 TIMSK0 &= (0 << OCIE0A);
  sei(); }
}




  void delay_ms(void)
{for(i=0;i<t;i++)
{count++;
}
  }
  
