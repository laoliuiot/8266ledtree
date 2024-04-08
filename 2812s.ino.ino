      //strip.show(); // 显示LED条带上的颜色 
  //   strip.setPixelColor(59+i, colours[c]); // 设置第1个LED的颜色  红色 59-76  +17
    //  strip.setPixelColor(94-i, colours[c]); // 设置第2个LED的颜色  红色 94-77 -17

    //   strip.setPixelColor(95+i, colours[c]); // 设置第3个LED的颜色  红色95-112
    //  strip.setPixelColor(130-i, colours[c]); // 设置第4个LED的颜色  红色130-113
      
    //   strip.setPixelColor(131+i, colours[c]); // 设置第5个LED的颜色  红色131-148
     // strip.setPixelColor(166-i, colours[c]); // 设置第6个LED的颜色  红色166-149

    // strip.setPixelColor(167+i, colours[c]); // 设置第7个LED的颜色  167-184 
    //  strip.setPixelColor(202-i, colours[c]); // 设置第8个LED的颜色  红色202-185

    //   strip.setPixelColor(203+i, colours[c]); // 设置第9个LED的颜色  红色203-220
//颜色只跑到10，后面颜色太深不好看
#include <Adafruit_NeoPixel.h>
//创作不易，使用时，请知道是我的代码laoliuiot 
// 定义WS2812的数量
#define NUM_LEDS 220

// 定义WS2812灯珠的引脚
#define PIN 2

// 声音传感器引脚
const int micPin =A0; // 假设你将麦克风连接到A0引脚

// 创建NeoPixel对象
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t colours[18] ;
uint32_t dcolour;


void setup() {
   pinMode(micPin, INPUT);
    Serial.begin(115200);  //定义波特率
   strip.begin();
  // put your setup code here, to run once:
   strip.setBrightness(3);//灯珠亮度30省电

   strip.show(); 
 
 
    colours[0]=strip.Color(60,179,113);//春天的绿色
  colours[1]=strip.Color( 144,238,144);//淡绿色
    colours[2]=strip.Color(124,252,0);//草坪绿
    colours[4]=strip.Color( 255,248,220);//玉米色
    colours[3]=strip.Color( 255,255,0);//黄色
    
    colours[5]= strip.Color( 255,165,0);// 橙色
      colours[6]=strip.Color( 255,140,0);//深橙色
      colours[7]=strip.Color( 255,69,0);//橙红色
      colours[8]= strip.Color( 139,0,0);//深红色
      colours[9]= strip.Color( 255,0,0 );// 红色
        colours[10]=strip.Color( 139,0,139);//深洋红色
        colours[11]= strip.Color( 128,0,128);//  紫色
        colours[12]=strip.Color(138,43,226);//深紫罗兰的蓝色

        colours[13]=strip.Color( 123,104,238);// 适中的板岩暗蓝灰色
          colours[14]=strip.Color( 0,0,255);//蓝色
          colours[15]=strip.Color(135,206, 235);
          colours[16]=strip.Color(30 ,144 ,255);
          colours[17]=strip.Color(0 ,0, 255);
      dcolour=colours[0];

  
      // 设置IO0脚为输出模式  
      pinMode(2, OUTPUT);  
      
      // 点亮LED  
      digitalWrite(2, HIGH);  
       
    //   delay(1000); // 等待一秒  
      
      // 开始闪烁LED  
    //   while (true) {  
     //    digitalWrite(2, LOW);   // LED熄灭  
     //    delay(500);             // 等待500毫秒  
     //    digitalWrite(2, HIGH);  // LED点亮  
     //    delay(500);             // 等待500毫秒  
     //  }
      
      for(int i=1;i<=58;i++)
      {
          strip.setPixelColor(i, colours[10]); // 设置第i个LED的颜色  红色
          delay(70); // 等待70毫秒  
          strip.show(); // 显示LED条带上的颜色 
      }
}
int c=0;
//关闭一部分灯的函数
void turnOffLEDs(uint16_t start, uint16_t end) {  
  if (start < 1 || start > end || end > NUM_LEDS) {  
    // 输入验证，确保起始和结束索引在有效范围内  
    Serial.println("Invalid LED index range!");  
    return;  
  }  
  
  // 关闭指定范围内的LED  
  for (uint16_t i = start; i <= end; i++) {  
    strip.setPixelColor(i, 0); // 将LED颜色设置为黑色（关闭）  
  }  
  strip.show(); // 更新LED灯带以显示更改  
}
//打开一部分灯方法，开始，结束，颜色
void turnOnLEDs(uint16_t start, uint16_t end, uint32_t color) {  
  if (start < 1 || start > end || end > NUM_LEDS) {  
    // 输入验证，确保起始和结束索引在有效范围内  
    Serial.println("Invalid LED index range!");  
    return;  
  }  
  
  // 打开（设置颜色）指定范围内的LED  
  for (uint16_t i = start; i <= end; i++) {  
    strip.setPixelColor(i, color); // 设置LED颜色  
  }  
  strip.show(); // 更新LED灯带以显示更改  
}

void baozhumofang(){ //特效2烟花效果
   strip.clear();
   for(int i = 1; i <= 56; i += 3) {  //58会超出去
      turnOnLEDs(i,i+3, colours[9]);//点亮树根 红色
      delay(60); // 等待70毫秒 快速上升
        turnOffLEDs(i,i+3);//关闭 
    }
      for(int i=0;i<18;i++)
  {
      strip.setPixelColor(59+i, colours[c]); // 设置第i个LED的颜色  红色 59-76  +17
      strip.setPixelColor(94-i, colours[c]); // 设置第i个LED的颜色  红色 94-77 -17

       strip.setPixelColor(95+i, colours[c]); // 设置第i个LED的颜色  红色95-112
      strip.setPixelColor(130-i, colours[c]); // 设置第i个LED的颜色  红色130-113
      
       strip.setPixelColor(131+i, colours[c]); // 设置第i个LED的颜色  红色131-148
      strip.setPixelColor(166-i, colours[c]); // 设置第i个LED的颜色  红色166-149

         strip.setPixelColor(167+i, colours[c]); // 设置第i个LED的颜色  167-184 
      strip.setPixelColor(202-i, colours[c]); // 设置第i个LED的颜色  红色202-185

       strip.setPixelColor(203+i, colours[c]); // 设置第i个LED的颜色  红色203-220
 
      delay(70); // 等待70毫秒  
      strip.show(); // 显示LED条带上的颜色 
  }
   strip.clear();
   for(int i=0;i<50;i++)
   {
     
     strip.setPixelColor(getRandNum(59,NUM_LEDS), colours[getRandNum(0,16)]); // 烟花散开效果
     strip.show();
   }

     c++; 
   if(c>=16)c=0;


}//烟花特效2
void baozhu(){ //特效1烟花效果
  
 strip.clear();
   for(int i=1;i<=58;i++)
      {
          strip.setPixelColor(i, colours[c]); // 设置第i个LED的颜色  红色
           strip.show(); // 显示LED条带上的颜色 
         
      }
  
  for(int i=0;i<18;i++)
  {
      strip.setPixelColor(59+i, colours[c]); // 设置第i个LED的颜色  红色 59-76  +17
      strip.setPixelColor(94-i, colours[c]); // 设置第i个LED的颜色  红色 94-77 -17

       strip.setPixelColor(95+i, colours[c]); // 设置第i个LED的颜色  红色95-112
      strip.setPixelColor(130-i, colours[c]); // 设置第i个LED的颜色  红色130-113
      
       strip.setPixelColor(131+i, colours[c]); // 设置第i个LED的颜色  红色131-148
      strip.setPixelColor(166-i, colours[c]); // 设置第i个LED的颜色  红色166-149

         strip.setPixelColor(167+i, colours[c]); // 设置第i个LED的颜色  167-184 
      strip.setPixelColor(202-i, colours[c]); // 设置第i个LED的颜色  红色202-185

       strip.setPixelColor(203+i, colours[c]); // 设置第i个LED的颜色  红色203-220
 
      delay(70); // 等待70毫秒  
      strip.show(); // 显示LED条带上的颜色 
  }

     c++; 
   if(c>=16)c=0;
     

}
//生成随机数方法
int getRandNum(int minValue, int maxValue) {  
    // 确保minValue小于maxValue  
    if (minValue >= maxValue) {  
        // 如果输入不正确，可以返回一个错误值或者抛出异常  
        return -1; // 或者你可以选择其他错误处理机制  
    }  
  
    // 计算范围大小  
    int range = maxValue - minValue + 1;  
  
    // 生成随机数并映射到指定范围  
    int randomNum = minValue + random(range);  
  
    return randomNum;  
}

void fenhuolun(){ //特效2 风火轮
   strip.clear();
   for(int i = 1; i <= 56; i += 3) {  //58会超出去
      turnOnLEDs(i,i+3, colours[9]);//点亮树根 红色
      delay(60); // 等待70毫秒 快速上升
        turnOffLEDs(i,i+3);//关闭 
    }
    
  //turnOnLEDs(1,58, colours[c]);//点亮树根

    turnOnLEDs(59,76, colours[c]);//设置第一根灯带亮
    delay(70); // 等待70毫秒  
     turnOnLEDs(77,94, colours[c]);//设置第二根灯带亮
    turnOffLEDs(59,76);//关闭第一根灯带
    delay(70); // 等待70毫秒 

     turnOnLEDs(95,112, colours[c]);//设置第3根灯带亮
    turnOffLEDs(77,94);//关闭第2根灯带
    delay(70); // 等待70毫秒 
     turnOnLEDs(113,130, colours[c]);//设置第4根灯带亮
    turnOffLEDs(95,112);//关闭第3根灯带
    delay(70); // 等待70毫秒 
     turnOnLEDs(131,148, colours[c]);//设置第5根灯带亮
    turnOffLEDs(113,130);//关闭第4根灯带
    delay(70); // 等待70毫秒 
    turnOnLEDs(149,166, colours[c]);//设置第6根灯带亮
    turnOffLEDs(131,148);//关闭第5根灯带
    delay(70); // 等待70毫秒
    turnOnLEDs(167,184, colours[c]);//设置第7根灯带亮
    turnOffLEDs(149,166);//关闭第6根灯带
    delay(70); // 等待70毫秒 
    turnOnLEDs(185,202, colours[c]);//设置第8根灯带亮
    turnOffLEDs(167,184);//关闭第7根灯带
    delay(70); // 等待70毫秒     
     turnOnLEDs(203,220, colours[c]);//设置第9根灯带亮
    turnOffLEDs(185,202);//关闭第8根灯带
    delay(70); // 等待70毫秒 

    turnOnLEDs(41,58, colours[c]);//设置树根半个颜色
    turnOffLEDs(203,220);//关闭第8根灯带
    delay(70); // 等待70毫秒     
    
  

 
     c++; 
   if(c>=16)c=0;
   

     

}//--特效2
void huaduonquan(int i){ //打开花朵其中第n圈
 
      strip.setPixelColor(59+i, dcolour); // 设置第i个LED的颜色  红色 59-76  +17
      strip.setPixelColor(94-i, dcolour); // 设置第i个LED的颜色  红色 94-77 -17

       strip.setPixelColor(95+i, dcolour); // 设置第i个LED的颜色  红色95-112
      strip.setPixelColor(130-i, dcolour); // 设置第i个LED的颜色  红色130-113
      
       strip.setPixelColor(131+i, dcolour); // 设置第i个LED的颜色  红色131-148
      strip.setPixelColor(166-i, dcolour); // 设置第i个LED的颜色  红色166-149

         strip.setPixelColor(167+i, dcolour); // 设置第i个LED的颜色  167-184 
      strip.setPixelColor(202-i, dcolour); // 设置第i个LED的颜色  红色202-185

       strip.setPixelColor(203+i, dcolour); // 设置第i个LED的颜色  红色203-220
 
         
      strip.show(); // 显示LED条带上的颜色 
  
  }//打开花朵其中第n圈

void shenkongshangse(int gaodu){ //从花朵第0圈，点亮到第n圈
for(int i=0;i<gaodu;i++)
  {
      strip.setPixelColor(59+i, dcolour); // 设置第i个LED的颜色  红色 59-76  +17
      strip.setPixelColor(94-i, dcolour); // 设置第i个LED的颜色  红色 94-77 -17

       strip.setPixelColor(95+i, dcolour); // 设置第i个LED的颜色  红色95-112
      strip.setPixelColor(130-i, dcolour); // 设置第i个LED的颜色  红色130-113
      
       strip.setPixelColor(131+i, dcolour); // 设置第i个LED的颜色  红色131-148
      strip.setPixelColor(166-i, dcolour); // 设置第i个LED的颜色  红色166-149

         strip.setPixelColor(167+i, dcolour); // 设置第i个LED的颜色  167-184 
      strip.setPixelColor(202-i, dcolour); // 设置第i个LED的颜色  红色202-185

       strip.setPixelColor(203+i, dcolour); // 设置第i个LED的颜色  红色203-220
 
         
      strip.show(); // 显示LED条带上的颜色 
  }
  }
void shengkongzhidian  ()//2024年4月5日14:47:43，可以用，现在做个以前那样一行一行点，以前那个看着漂亮
{

    int soundLevel = analogRead(micPin);
 
 // dcolour=colours[2];//默认最低颜色
   // baozhumofang(); //特效2烟花效果
 //fenhuolun();//风火轮效果
 
strip.clear();

 if(soundLevel<=320) {   turnOnLEDs(1,38,dcolour);//点亮半树干
 }
 
 if(soundLevel>320) { dcolour=colours[2]; turnOnLEDs(1,58,dcolour);//点亮全树干
 }
   if(soundLevel>500) {dcolour=colours[16]; shenkongshangse(18);  return; } 
     if(soundLevel>490) {dcolour=colours[16]; shenkongshangse(17);  return; } 
        if(soundLevel>480) {dcolour=colours[16]; shenkongshangse(16);  return; } 
  if(soundLevel>470) { dcolour=colours[15];shenkongshangse(15); return;  } 
  if(soundLevel>460) {dcolour=colours[14]; shenkongshangse(14);   return;}
   if(soundLevel>450) {dcolour=colours[14]; shenkongshangse(13);  return; } 
      if(soundLevel>440) {dcolour=colours[14]; shenkongshangse(12);  return; }  
     if(soundLevel>430) {dcolour=colours[13]; shenkongshangse(11);  return; } 

     if(soundLevel>420) { dcolour=colours[12];shenkongshangse(10); return;  }
  if(soundLevel>410) { dcolour=colours[11];shenkongshangse(9);  return; } 
  if(soundLevel>400) {dcolour=colours[10]; shenkongshangse(8);  return; } 
    if(soundLevel>390)  {dcolour=colours[9]; shenkongshangse(7);  return; } 
  if(soundLevel>380) { dcolour=colours[8];shenkongshangse(6);   return;} 
  if(soundLevel>370)  {dcolour=colours[7]; shenkongshangse(5);   return;} 
  if(soundLevel>360) {dcolour=colours[6]; shenkongshangse(4);  return; } 
      if(soundLevel>350) { dcolour=colours[5];shenkongshangse(3);  return; } 
   if(soundLevel>340) { dcolour=colours[4];shenkongshangse(2); return;  } 


 if(soundLevel>330) { dcolour=colours[3];  shenkongshangse(1); return; } 

 
}
void loop() {

 int soundLevel = analogRead(micPin);

 // 打印声音值到串行监视器

if(soundLevel>510){dcolour=colours[17];}
else if(soundLevel>490){dcolour=colours[16];}
else if(soundLevel>480){dcolour=colours[15];}
else if(soundLevel>470){dcolour=colours[14];}
else if(soundLevel>460){dcolour=colours[13];}
else if(soundLevel>450){dcolour=colours[12];}
else if(soundLevel>440){dcolour=colours[11];}
else if(soundLevel>430){dcolour=colours[10];}
else if(soundLevel>420){dcolour=colours[9];}
else if(soundLevel>410){dcolour=colours[8];}
else if(soundLevel>400){dcolour=colours[7];}
else if(soundLevel>390){dcolour=colours[6];}
else if(soundLevel>380){dcolour=colours[5];}
else if(soundLevel>370){dcolour=colours[4];}
else if(soundLevel>360){dcolour=colours[3];}
else if(soundLevel>350){dcolour=colours[2];}
else if(soundLevel>340){dcolour=colours[1];}
else if(soundLevel>330){dcolour=colours[0];}
else if(soundLevel>320){dcolour=colours[0];}
else if(soundLevel>310){dcolour=colours[0];}
else if(soundLevel<300){dcolour=colours[0];}

  

 // Serial.println("yanse"+dcolour);
 
//上面代码疑似与下面代码可以合并，但是效果不一样的，下面代码是一行一行点亮的
//

 
 strip.clear();
if(soundLevel<=320) {   turnOnLEDs(1,38,colours[9]);//点亮半树干
}
if(soundLevel>320) { turnOnLEDs(1,58,colours[9]);//点亮全树干
}

 if(soundLevel>330)
 {
  huaduonquan(0);//打开第0圈
  
 } 
      if(soundLevel>340) { huaduonquan(1);  //打开第1圈 } 
      if(soundLevel>350) { huaduonquan(2);   } 
      if(soundLevel>360) { huaduonquan(3);   } 
      if(soundLevel>370) { huaduonquan(4);   } 
      if(soundLevel>380) { huaduonquan(5);   } 
      if(soundLevel>390) { huaduonquan(6);   } 
      if(soundLevel>400) { huaduonquan(7);   } 
      if(soundLevel>410) { huaduonquan(8);   } 
      if(soundLevel>420) { huaduonquan(9);   } 
      if(soundLevel>430){ huaduonquan(10);   } 
      if(soundLevel>440) { huaduonquan(11);   } 
      if(soundLevel>450) { huaduonquan(12);   } 
      if(soundLevel>460) { huaduonquan(13);   } 
      if(soundLevel>480) { huaduonquan(14);   } 
      if(soundLevel>490) { huaduonquan(15);   } 
      if(soundLevel>500) { huaduonquan(16);   } 
      if(soundLevel>510) { huaduonquan(17);   } 
      if(soundLevel>520) { huaduonquan(18);   } 
   } 

}
