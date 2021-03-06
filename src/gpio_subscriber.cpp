#include "ros/ros.h"
#include "std_msgs/Bool.h"

#include <wiringPi.h>

#define LED1    8

void Callback(const std_msgs::Bool::ConstPtr state)
{
    ROS_INFO("I heard GPIO state: [%d]", state->data);
    digitalWrite(LED1, state->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "GPIO_sub");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("gpio_state", 1000, Callback);

    ros::spin();
    return 0;
}