# rbt   

  Little arduino robot   
  
### Fisics Specs   
  
  * 2 DC Motors(Left, Right)
  * l298N Motor controller
  * 3 HC-SR04 Ultrasonic Sensor
  * Triple Axis Magnetometer - HMC5883 (Compass)
  * Arduino Uno
  
### Functions   
  
##### void motor(int action)   
  Motor controller by actions:
  
  0-Motors Stopped  
  1-Motors Forward  
  2-Left Forward, Right Stopped  
  3-Left Stopped, Right Forward  
  4-Left Reverse, Right Stopped  
  5-Left Stopped, Right Reverse  
  6-Motors Reverse  
  7-Left Full Speed Forward, Right Half Speed Forward  
  8-Left Half Speed Forward, Right Full Speed Forward  
  
  
##### float magsen(void)  
  Return the magnetic reading in degrees

##### 
  
    
  
