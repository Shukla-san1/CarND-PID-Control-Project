#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	this->Kp = Kp_;
	this->Ki = Ki_;
	this->Kd = Kd_;

	//initlizing errors
	p_error = 0.0;
	i_error = 0.0;
	d_error =0.0;


}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {
	double total_error = 0.0 ;
	total_error = - Kp*p_error  - Kd*d_error - Ki*i_error;
	return total_error;
}

