#include <ros.h>
#include <std_msgs/UInt16.h>
ros::NodeHandle  nh;



std_msgs::UInt16 str_msg;

ros::Publisher pub_range( "/bamper_1", &str_msg);
ros::Publisher pub_range2("/bamper_2", &str_msg);
ros::Publisher pub_range3("/bamper_3", &str_msg);
ros::Publisher pub_range4("/bamper_4", &str_msg);

void setup() {
  //start serial connection
//  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  nh.initNode();
  nh.advertise(pub_range);
  nh.advertise(pub_range2);
  nh.advertise(pub_range3);
  nh.advertise(pub_range4);
}

void loop() {
  int sensorVal1 = digitalRead(2);
  int sensorVal2 = digitalRead(3);
  int sensorVal3 = digitalRead(4);
  int sensorVal4 = digitalRead(5);
//  Serial.print("  1 = ");
//  Serial.print(sensorVal1);
//  Serial.print("  2 = ");
//  Serial.print(sensorVal2);
//  Serial.print("  3 = ");
//  Serial.print(sensorVal3);
//  Serial.print("  4 = ");
//  Serial.println(sensorVal4);

    str_msg.data = sensorVal1;
    pub_range.publish(&str_msg);
     str_msg.data = sensorVal2;
    pub_range2.publish(&str_msg);
     str_msg.data = sensorVal3;
    pub_range3.publish(&str_msg);
     str_msg.data = sensorVal4;
    pub_range4.publish(&str_msg);
    nh.spinOnce();

}
