#include "PID.h"
#include <iostream>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  first_iteration_passed = false;
}

void PID::UpdateError(double cte) {
  if (!first_iteration_passed){
    d_error = 0;
    first_iteration_passed = true;
  }
  else {
    d_error = cte - p_error;
  }
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  return Kp * p_error + Ki * i_error + Kd * d_error;
}
