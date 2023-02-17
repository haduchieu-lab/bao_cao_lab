#define datapin  12
#define cspin  10
#define clkpin  11



void Clear()
{
  for(int i=1;i<9;i++)
  {
    matrix_shiftout(i,0x00);
  }
}
void matrix_shiftout(byte address,byte data)
{
  shiftOut(datapin,clkpin,MSBFIRST,address);
    shiftOut(datapin,clkpin,MSBFIRST,data);
    
  digitalWrite(cspin,1);
  digitalWrite(cspin,0);
}
void setup()
{
  pinMode(datapin,OUTPUT);
  pinMode(clkpin,OUTPUT);
  pinMode(cspin,OUTPUT);
  digitalWrite(cspin,0);
  
  matrix_shiftout(0x0C,0x00);//tat den
  matrix_shiftout(0x09,0x00);//decode
  matrix_shiftout(0x0B,0x07);//chay tu 0 den 7
  matrix_shiftout(0x0C,0x01);//bat den
  Clear();
}
void A()
{
  matrix_shiftout(4,0x33);
  matrix_shiftout(5,0x33);
  matrix_shiftout(3,0xFE);
  matrix_shiftout(6,0xFE);
  matrix_shiftout(2,0xFC);
  matrix_shiftout(7,0xFC);
  
  
  
}
void B()
{
  matrix_shiftout(4,0xb3);
  matrix_shiftout(5,0xb3);
  matrix_shiftout(3,0xFF);
  matrix_shiftout(6,0xFE);
  matrix_shiftout(2,0xFf);
  matrix_shiftout(7,0x7C);
}
void C()
{
  matrix_shiftout(4,0xC3);
  matrix_shiftout(5,0xC3);
   matrix_shiftout(3,0xE7);
  matrix_shiftout(6,0xFE);
  matrix_shiftout(2,0xFf);
  matrix_shiftout(7,0x7C);
  
}
void loop()
{
  
 matrix_shiftout(1,0xf0); 
 matrix_shiftout(8,0xc8); 
 matrix_shiftout(6,0x05); 
//A();
  
matrix_shiftout(0x0C,0x00);
 
  matrix_shiftout(0x0C,0x01);

  
  
  
  
}
