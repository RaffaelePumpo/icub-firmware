//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: rt_modf.cpp
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.51
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Fri Jul 18 14:44:09 2025
//
#include "rtwtypes.h"
#include "rt_modf.h"
#include <cmath>
#include <cfloat>

real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    boolean_T yEq;
    y = std::fmod(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > std::floor(u1))) {
      real32_T q;
      q = std::abs(u0 / u1);
      yEq = (std::abs(q - std::floor(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
