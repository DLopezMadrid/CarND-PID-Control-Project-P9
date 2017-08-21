#ifndef PID_H
#define PID_H

#include <vector>
#define NUM_INTEGRATOR_ERROR_STEPS 150
class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  //std::vector <double> i_error_v[];
  double i_error_v[NUM_INTEGRATOR_ERROR_STEPS];
  int num_steps;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
