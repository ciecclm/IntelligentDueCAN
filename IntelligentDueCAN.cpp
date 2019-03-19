//
//  IntelligentDueCAN.cpp
//  
//
//  Created by clm on 2019/3/19.
//

#include "IntelligentDueCAN.h"
CIntelligent_due_CAN::CIntelligent_due_CAN()
{
    driver_mode=3;
    driver_ID=0;
}

void CIntelligent_due_CAN::resetdriver(int drv_ID)
{
    driver_ID=drv_ID;
    outgoing.id=(0x600+driver_ID);
    outgoing.length=8;
    outgoing.extended = false;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x23002001;
    Can0.sendFrame(outgoing);
    delay(500);
}
void CIntelligent_due_CAN::setmode(int drv_ID,int mode )
{
    //CAN_FRAME outgoing;
    //outgoing.id = temp;//0x021;
    outgoing.id = (0x600+drv_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    if(mode==3)
        outgoing.data.bytes[1]=0x00;
    if(mode==4)
        outgoing.data.bytes[1]=0x01;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=0x01;
    outgoing.data.bytes[4]=0x00;
    outgoing.data.bytes[5]=0x00;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
    delay(500);
}

void CIntelligent_due_CAN::speedwheel(int temp_velocity,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+driver_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(temp_velocity)&0xff;
    outgoing.data.bytes[5]=(temp_velocity>>8)&0xff;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::speedwheel(int temp_velocity,int drv_ID,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+drv_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(temp_velocity)&0xff;
    outgoing.data.bytes[5]=(temp_velocity>>8)&0xff;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::setposition(int position,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+driver_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x01;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(position)&0xff;
    outgoing.data.bytes[5]=(position>>8)&0xff;
    outgoing.data.bytes[6]=(position>>16)&0xff;
    outgoing.data.bytes[7]=(position>>24)&0xff;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::setposition(int position,int drv_ID,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+drv_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x01;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(position)&0xff;
    outgoing.data.bytes[5]=(position>>8)&0xff;
    outgoing.data.bytes[6]=(position>>16)&0xff;
    outgoing.data.bytes[7]=(position>>24)&0xff;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::setpositionspeed(int speed,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+driver_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x02;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(speed)&0xff;
    outgoing.data.bytes[5]=(speed>>8)&0xff;
    outgoing.data.bytes[6]=(speed>>16)&0xff;
    outgoing.data.bytes[7]=(speed>>24)&0xff;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::setpositionspeed(int speed,int drv_ID,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+drv_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x02;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(speed)&0xff;
    outgoing.data.bytes[5]=(speed>>8)&0xff;
    outgoing.data.bytes[6]=(speed>>16)&0xff;
    outgoing.data.bytes[7]=(speed>>24)&0xff;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::initdriver(int baud=CAN_BPS_1000K,int drv_ID=1,int mode=3)
{
    Can0.begin(baud);
    Can0.watchFor();
    resetdriver(drv_ID);
    //setmode(group,drv_ID,mode);
}
void CIntelligent_due_CAN::testwheel(int moto_ID=0)
{
    outgoing.id = 0x600+driver_ID;
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=0xf4;
    outgoing.data.bytes[5]=0x01;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;/*
                                 outgoing.data.bytes[7]=0x23;
                                 outgoing.data.bytes[6]=0x00;
                                 outgoing.data.bytes[5]=0x20;
                                 outgoing.data.bytes[4]=0x01;
                                 outgoing.data.bytes[3]=0xf4;
                                 outgoing.data.bytes[2]=0x01;
                                 outgoing.data.bytes[1]=0x00;
                                 outgoing.data.bytes[0]=0x00;*/
    Can0.sendFrame(outgoing);
    
}
void CIntelligent_due_CAN::testwheel(int drv_ID,int moto_ID)
{
    outgoing.id = 0x600+drv_ID;
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=0xf4;
    outgoing.data.bytes[5]=0x01;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
    
}

