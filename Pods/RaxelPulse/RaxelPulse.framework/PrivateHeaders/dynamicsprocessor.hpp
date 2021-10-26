#ifndef DYNAMICSPROCESSOR_H
#define DYNAMICSPROCESSOR_H

#include <stdint.h>
#include "Tools/vec32.hpp"
#include "Tools/lowpassfilter.hpp"

#include "configuration.hpp"

struct Angle {
  double sin;
  double cos;
};

struct AverageState {
  double   speed;
  int32_t   samples_count;
  Vec32     acceleration;
};

struct DynamicState {
  Vec32       prefiltered; // предварительно отфильтрованное значение

  Vec32       average;
  uint16_t    average_cycles;

  Vec32       gravity;
  uint32_t    gravity_adaptation_cycles;

  Vec32       course;
  uint32_t    course_adaptation_cycles;

    /// a - угол поворота вокруг OX, b - угол поворота вокруг OY
  Angle       gravity_a, gravity_b, course_c;

  double      prev_speed;
  double      prev_prev_speed;
  double      prev_speed_timestamp;

  double      error;
  uint8_t     valid;
    
  double      time_;
};


class DynamicsProcessor
{
public:
  DynamicsProcessor();
    /// @brief устанавливает начальное значение гравитации.
    /// Если NULL, то считается, что значение гравитации еще не определено.
  void SetInitialGravity(const Vec32* g);

    /// @brief устанавливает начальное значение курсового вектора.
    /// Если NULL, то считается, что значение еще не определено.
  void SetInitialCourse(const Vec32* course);

  void SetSpeed(double speed);

  void Update(Vec32* result, const Vec32& src, const double time_);
  DynamicState    state;
private:
  double Now();
  void SetInitialValues();
  bool AdaptToGravity(const Vec32* src);
  void PushSpeedReading(double speed);
  static void RotateX(Vec32* dst, const Vec32* src, const Angle* ax);
  static void RotateY(Vec32* dst, const Vec32* src, const Angle* ay);
  static void RotateZ(Vec32* dst, const Vec32* src, const Angle* az);
  static void GetXYDirection(Angle* dst_ax, Angle* dst_ay, const Vec32* src);
  static void GetZDirection(Angle* dst_az, const Vec32* src);
};

#endif // DYNAMICSPROCESSOR_H
