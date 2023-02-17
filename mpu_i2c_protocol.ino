#include<Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(0x68);//ket noi dia chi cho mpu
  Wire.write(0x6B);//dia chi thanh ghi reset mpu
  Wire.write(0x00);//dua thanh ghi ve 0
  Wire.endTransmission(true); 
  
  Wire.beginTransmission(0x68);
  Wire.write(0x1C); //dia chi thanh ghi cau hinh gia toc                 
  Wire.write(0x00); //dua thanh ghi ve gia tri 0
  Wire.endTransmission(true); 

  
  Wire.beginTransmission(0x68);
  
  Wire.write(0x19); //thanh ghi chia ty le mau
  Wire.write(0x00);//dua ve 0  
  Wire.endTransmission(true);

      
  
}
void loop()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x3b);// accel-xout-h
  
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,6,true);//doc lien tiep 6 thanh ghi tu 0x3b cua mpu
   float accel_x = (Wire.read()<<8 | Wire.read())/16384.0;
   float accel_y = (Wire.read()<<8 | Wire.read())/16384.0;
   float accel_z = (Wire.read()<<8 | Wire.read())/16384.0;
 float accAngleX = (atan(accel_y / sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * 180 / PI) - 0.58;
float accAngleY = (atan(-1 * accel_x / sqrt(pow(accel_y, 2) + pow(accel_z, 2))) * 180 / PI) + 1.58;

   Wire.beginTransmission(0x68);
  Wire.write(0x43);// gyro-xout-h  
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,6,true);//doc lien tiep 6 thanh ghi tu 0x43 cua mpu
    float gyro_x = (Wire.read() << 8 | Wire.read())/131.0;
    float gyro_y = (Wire.read() << 8 | Wire.read())/131.0;
    float gyro_z = (Wire.read() << 8 | Wire.read())/131.0;

    float roll = 0.96 * gyro_x + 0.04 * accel_x;
  float pitch = 0.96 * gyro_y + 0.04 * accel_y;

  Serial.println(roll);
  Serial.println(pitch);
  delay(500);
}
