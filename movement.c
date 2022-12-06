#include "movement.h"
#include "open_interface.h"
#include "lcd.h"
#include <math.h>
//Moves the bot forward by the desired distance
double move_forward(oi_t *sensor, float centimeters){
    double distance = 0;
    oi_setWheels(200, 200);
    while(distance < centimeters){
        oi_update(sensor);
        if(sensor->bumpLeft ||sensor->bumpRight){
            oi_setWheels(0, 0);
            return 0;
            }
        if(sensor_data->bumpLeft || sensor_data->bumpright || sensor_data->cliffLeft || sensor_data->cliffRight || sensor_data->cliffFrontLeft || sensor_data->cliffFrontRight){
	        sensor(sensor_data);
	        oi_setwheels(0, 0);
            }
        timer_waitMillis(5);
        oi_update(sensor_data);
        if(sensor_data->cliffLeft > 4095 || sensor_data->cliffRight > 4095 || sensor_data->cliffFrontLeft > 4095 || sensor_data->cliffFrontRight > 4095){
	        sensor(sensor_data);
	        oi_setwheels(0, 0);
            }
        distance += sensor->distance;
        }
       oi_setWheels(0, 0);
       return 1;
}
void reverse(oi_t *sensor, float centimeters){
    double distance = 0;
    oi_setWheels(-200, -200);
    while(distance < centimeters){

        oi_update(sensor);
        distance -= sensor->distance;
    }
    oi_setWheels(0, 0);

}

//Turns the bot clockwise by the desired angle
void turn_clockwise(oi_t *sensor, double degrees){
    lcd_init();
    oi_setWheels(-50, 50);
    oi_update(sensor);
    double angle = 0;
    degrees *= -1;
    while(angle > degrees){

        oi_update(sensor);
        angle += sensor->angle;
        }
    lcd_printf("%f", angle);
    oi_setWheels(0, 0);
}

void turn_counterclockwise(oi_t *sensor, double degrees){
    oi_setWheels(50, -50);
    oi_update(sensor);
    double angle = 0;
    while(angle < degrees){

        oi_update(sensor);
        angle += sensor->angle;
        }
    oi_setWheels(0, 0);
}
