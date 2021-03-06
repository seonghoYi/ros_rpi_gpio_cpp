#include "ros/ros.h"
#include "std_msgs/Bool.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "GPIO_pub");
    ros::NodeHandle n;

    ros::Publisher gpio_pub = n.advertise<std_msgs::Bool>("gpio_state", 1000);

    ros::Rate loop_rate(10);


    std_msgs::Bool gpio_state;
    gpio_state.data = false;
    while(ros::ok())
    {
        

        ROS_INFO("I sent GPIO state: [%d]", gpio_state.data);
        
        gpio_state.data ^= true;

        gpio_pub.publish(gpio_state);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}