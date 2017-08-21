#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  //fill i_error buffer with 0s
  for (int i = 0; i < NUM_INTEGRATOR_ERROR_STEPS; i++){
    i_error_v[i] = 0;
  }
  num_steps = 0;

}

void PID::UpdateError(double cte) {
  this->d_error = cte - p_error;
  this->p_error = cte;

  num_steps++;
  num_steps = num_steps % NUM_INTEGRATOR_ERROR_STEPS;

  //create a buffer to "forget" old i_error values
  i_error_v[num_steps] = cte;

  this->i_error = 0;
  for (int i = 0; i < NUM_INTEGRATOR_ERROR_STEPS; i++){

    this->i_error += i_error_v[i];
  }

}

double PID::TotalError() {

  double stwAngle =  -Kp * p_error -Ki * i_error - Kd * d_error;

  if (stwAngle> 1){
    stwAngle = 1.0;
  }
  else if (stwAngle < -1){
    stwAngle = -1.0;
  }


  return stwAngle;

}

