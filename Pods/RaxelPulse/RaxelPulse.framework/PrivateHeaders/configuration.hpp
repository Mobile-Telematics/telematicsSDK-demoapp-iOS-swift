#ifndef FIRMWARE_CONFIG_H_
#define FIRMWARE_CONFIG_H_
// =============================================================================
//              Настройки модуля работы с акселерометром
// =============================================================================

/// @brief максимально допустимое отклонение (в мм/с^2) модуля измеренного вектора ускорения
/// от гравитационной константы, ниже которого считается, что автомобиль стоит на месте
/// (или движется равномерно) и происходит адаптация гравитационного вектора.
#define CFG_GM_GRAVITY_THRESHOLD_MMBYSS     500

/// @brief Минимальная скорость (км/ч), при которой допустима адаптация курса.
#define CFG_COURSE_MIN_SPEED                10

/// @brief Максимальное отклонение длины вектора ускорения (в мм/с2) от
/// вычисленного на основе данных GPS, ниже которого
/// допустима адаптация курса.
#define CFG_COURSE_MAX_DIFFERENCE_TO_GPS    500

/// @brief Максимальное время (в мс) между прочитанными показаниями скорости
/// меньше которого допустима адаптация курса.
/// Данный параметр служит для отбраковки показаний скорости, полученных во
/// время сбоя работы ELM.
#define CFG_COURSE_MAX_SPEED_TO_SPEED_TIME_MS 1500

/// @brief Постоянная времени предварительной НЧ фильтрации сырых данных.
/// Если предварительная фильтрация не требуется, то данный параметр следует
/// закомментировать. Старое значение 0.333
#define CFG_PREFILTER_LOWPASS_K           0.5

/// @brief Постоянная времени НЧ фильтрации вектора курса.
#define CFG_COURSE_LOWPASS_K              0.0015

/// @brief Постоянная времени НЧ фильтрации вектора гравитации.
#define CFG_GRAVITY_LOWPASS_K             0.002

#define CFG_MIN_SPEED_EVENT               6.000f
#define CFG_MIN_CORNERING_ACCEL           3.000f
#define CFG_MIN_BRAKING_ACCEL            -2.700f
#define CFG_MIN_ACCELERATION_ACCEL        2.700f

#define CFG_GRAVITY                       9.810f
#define CFG_MAX_GRAVITY_DRIFT             1.000f

#define CFG_MIN_EVENT_DURATION            600.0f
#define CFG_MIN_CRASH_DURATION            10.0f
#define CFG_MAX_EVENT_PAUSE               3000.0f
#define CFG_MAX_CRASH_PAUSE               60000.0f
//15 км/ч в метрах в секунду
#define CFG_MEDIAN_CRASH_SPEED            4.16F

#define CFG_MAX_WORK_ACCURACY             25.0f

#define CFG_STATISTICAL_PRECISION         10000

#endif /* FIRMWARE_CONFIG_H_ */
