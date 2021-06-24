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
  Vec32       prefiltered; // ÔÂ‰‚‡ËÚÂÎ¸ÌÓ ÓÚÙËÎ¸ÚÓ‚‡ÌÌÓÂ ÁÌ‡˜ÂÌËÂ

  Vec32       average;
  uint16_t    average_cycles;

  Vec32       gravity;
  uint32_t    gravity_adaptation_cycles;

  Vec32       course;
  uint32_t    course_adaptation_cycles;

  /// a - Û„ÓÎ ÔÓ‚ÓÓÚ‡ ‚ÓÍÛ„ OX, b - Û„ÓÎ ÔÓ‚ÓÓÚ‡ ‚ÓÍÛ„ OY
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
  /// @brief ÛÒÚ‡Ì‡‚ÎË‚‡ÂÚ Ì‡˜‡Î¸ÌÓÂ ÁÌ‡˜ÂÌËÂ „‡‚ËÚ‡ˆËË.
  /// ≈ÒÎË NULL, ÚÓ Ò˜ËÚ‡ÂÚÒˇ, ˜ÚÓ ÁÌ‡˜ÂÌËÂ „‡‚ËÚ‡ˆËË Â˘Â ÌÂ ÓÔÂ‰ÂÎÂÌÓ.
  void SetInitialGravity(const Vec32* g);

  /// @brief ÛÒÚ‡Ì‡‚ÎË‚‡ÂÚ Ì‡˜‡Î¸ÌÓÂ ÁÌ‡˜ÂÌËÂ ÍÛÒÓ‚Ó„Ó ‚ÂÍÚÓ‡.
  /// ≈ÒÎË NULL, ÚÓ Ò˜ËÚ‡ÂÚÒˇ, ˜ÚÓ ÁÌ‡˜ÂÌËÂ Â˘Â ÌÂ ÓÔÂ‰ÂÎÂÌÓ.
  void SetInitialCourse(const Vec32* course);

  void SetSpeed(double speed);
  //bool GetCourse( Vec32* course ) const;
  //bool GetGravity( Vec32* g ) const;


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
