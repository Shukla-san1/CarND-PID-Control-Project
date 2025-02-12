# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Decription

#### Propotional(P) control:
* The proportional term produces an output value that is proportional to the current error value (CTE). The proportional response can be adjusted by multiplying the error by a constant Kp, called the proportional gain constant.
* When P controller applied to car , it will slightly overshoot, (no matter how small the constant (Kp) is . Also it never really converge . It will be called as “marginally stable”.
*If the value of control parameter (kp) increases, then oscillate faster.
* Having bigger Kp makes it output bigger in each step, making the output value (steer value) changed drastically with in few steps. Vehicle swerving left and right too fast losing the steer control.
#### Integral (I) controller: 
* The contribution from the integral term is proportional to both the magnitude of the error and the duration of the error. The integral in a PID controller is the sum of the instantaneous error over time and gives the accumulated offset that should have been corrected previously. The accumulated error is then multiplied by the integral gain (Ki) and added to the controller output.  
* The purpose of the this term is to compensate for systematic biases.  For example if the wheel of car is not aligned properly and dragging the vehicle in specific direction. Such kind of bias can be eliminated by this controller.  
* In this project, its value is very less (~appx. zero).  

#### Derivative (D) Controller :  
* The derivative of the process error is calculated by determining the slope of the error over time and multiplying this rate of change by the derivative gain Kd. The magnitude of the contribution of the derivative term to the overall control action is termed the derivative gain, Kd.  
* Derivative action predicts system behavior and thus improves settling time and stability of the system. Also system converges.  
* It smoothens the output of system. Higher Kd makes vehicle very sensitive  and lower kd takes long time to reach the desired value. 

Here is the final equation looks like for PID:

	U =   - ( Kp * cte  +  Ki * int_cte   + Kd * diff_cte)

Where :
* U : Control variable (example : steer angle , acceleration/throttle)  
* Int_cte : Integral cross track error. Sum of all previous cte.  
* Diff_cte : Differential cross track error.  cte(t) – cte(t-1) / dt   

### Hyperparameters (Kp , Ki, Kd coefficients) tuning :
* I tune the hyperparameter manually.  
* I had started from Kp =1.0, Ki = 0, Kd=1 then later keep decreasing Kp and started increasing KD and see how it behaves on the track.
  
  * I see lot of jerky motion on track on higher value of Kp. So strated reducing it in factor of .1 from and noticed that at .2 where it was prety smooth.
  * When Kd value decreases , the car is not driving smooth, also near the bridge and sharp turn it run over red area. 
  * When kd value increases , the car is driving smooth also on sharp turn, it reasonably works well. Not run over red area. started increasing it with .2.  I choose 4  value.  
* Last but not least , I played with Ki . In our case we don’t have any systematic bias, so I choose this parameter value very low (0.0001).  
* After several test, increasing and decreasing constants and testing how each of the performed, below is final value for which car drive the complete Track and driving is also smooth.  
* Final coefficients values :  
  * Kp : 0.2  
  * Ki : 0.0001    
  * Kd : 4 
* The Video (video.ogv) of sucusessfully driving the car is shared in project repo.  
