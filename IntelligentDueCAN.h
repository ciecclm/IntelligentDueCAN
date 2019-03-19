//
//  IntelligentDueCAN.hpp
//  
//
//  Created by clm on 2019/3/19.
//

#ifndef IntelligentDueCAN_h
#define IntelligentDueCAN_h
#include "variant.h"
#include "due_can.h"
#endif /* intelligentDueCAN_h */

class CIntelligent_due_CAN
{
private:
    int driver_mode;
    int driver_ID;
    CAN_FRAME outgoing;
    void resetdriver(int drv_ID );
    void setmode(int drv_ID,int mode );
public:
    CIntelligent_due_CAN();
    //void initdriver(int baud,int group,int number,int mode);
    void initdriver(int baud,int drv_ID,int mode);
    
    //void speedwheel(int temp_velocity,int group,int number);
    void speedwheel(int temp_velocity,int moto_ID);
    void speedwheel(int temp_velocity,int drv_ID,int moto_ID);
    void setposition(int position,int moto_ID);
    void setposition(int position,int drv_ID,int moto_ID);
    void setpositionspeed(int speed,int moto_ID);
    void setpositionspeed(int speed,int drv_ID,int moto_ID);
    void testwheel(int moto_ID);
    void testwheel(int drv_ID,int moto_ID);
};

