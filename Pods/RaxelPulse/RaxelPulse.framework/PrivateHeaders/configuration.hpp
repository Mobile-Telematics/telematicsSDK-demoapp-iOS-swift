#ifndef FIRMWARE_CONFIG_H_
#define FIRMWARE_CONFIG_H_
// =============================================================================
//              Õ‡ÒÚÓÈÍË ÏÓ‰ÛÎˇ ‡·ÓÚ˚ Ò ‡ÍÒÂÎÂÓÏÂÚÓÏ
// =============================================================================

/// @brief Ï‡ÍÒËÏ‡Î¸ÌÓ ‰ÓÔÛÒÚËÏÓÂ ÓÚÍÎÓÌÂÌËÂ (‚ ÏÏ/Ò^2) ÏÓ‰ÛÎˇ ËÁÏÂÂÌÌÓ„Ó ‚ÂÍÚÓ‡ ÛÒÍÓÂÌËˇ
/// ÓÚ „‡‚ËÚ‡ˆËÓÌÌÓÈ ÍÓÌÒÚ‡ÌÚ˚, ÌËÊÂ ÍÓÚÓÓ„Ó Ò˜ËÚ‡ÂÚÒˇ, ˜ÚÓ ‡‚ÚÓÏÓ·ËÎ¸ ÒÚÓËÚ Ì‡ ÏÂÒÚÂ
/// (ËÎË ‰‚ËÊÂÚÒˇ ‡‚ÌÓÏÂÌÓ) Ë ÔÓËÒıÓ‰ËÚ ‡‰‡ÔÚ‡ˆËˇ „‡‚ËÚ‡ˆËÓÌÌÓ„Ó ‚ÂÍÚÓ‡.
#define CFG_GM_GRAVITY_THRESHOLD_MMBYSS     500

/// @brief ÃËÌËÏ‡Î¸Ì‡ˇ ÒÍÓÓÒÚ¸ (ÍÏ/˜), ÔË ÍÓÚÓÓÈ ‰ÓÔÛÒÚËÏ‡ ‡‰‡ÔÚ‡ˆËˇ ÍÛÒ‡.
#define CFG_COURSE_MIN_SPEED                10

/// @brief Ã‡ÍÒËÏ‡Î¸ÌÓÂ ÓÚÍÎÓÌÂÌËÂ ‰ÎËÌ˚ ‚ÂÍÚÓ‡ ÛÒÍÓÂÌËˇ (‚ ÏÏ/Ò2) ÓÚ
/// ‚˚˜ËÒÎÂÌÌÓ„Ó Ì‡ ÓÒÌÓ‚Â ‰‡ÌÌ˚ı GPS, ÌËÊÂ ÍÓÚÓÓ„Ó
/// ‰ÓÔÛÒÚËÏ‡ ‡‰‡ÔÚ‡ˆËˇ ÍÛÒ‡.
#define CFG_COURSE_MAX_DIFFERENCE_TO_GPS    500

/// @brief Ã‡ÍÒËÏ‡Î¸ÌÓÂ ‚ÂÏˇ (‚ ÏÒ) ÏÂÊ‰Û ÔÓ˜ËÚ‡ÌÌ˚ÏË ÔÓÍ‡Á‡ÌËˇÏË ÒÍÓÓÒÚË
/// ÏÂÌ¸¯Â ÍÓÚÓÓ„Ó ‰ÓÔÛÒÚËÏ‡ ‡‰‡ÔÚ‡ˆËˇ ÍÛÒ‡.
/// ƒ‡ÌÌ˚È Ô‡‡ÏÂÚ ÒÎÛÊËÚ ‰Îˇ ÓÚ·‡ÍÓ‚ÍË ÔÓÍ‡Á‡ÌËÈ ÒÍÓÓÒÚË, ÔÓÎÛ˜ÂÌÌ˚ı ‚Ó
/// ‚ÂÏˇ Ò·Óˇ ‡·ÓÚ˚ ELM.
#define CFG_COURSE_MAX_SPEED_TO_SPEED_TIME_MS 1500

/// @brief œÓÒÚÓˇÌÌ‡ˇ ‚ÂÏÂÌË ÔÂ‰‚‡ËÚÂÎ¸ÌÓÈ Õ◊ ÙËÎ¸Ú‡ˆËË Ò˚˚ı ‰‡ÌÌ˚ı.
/// ≈ÒÎË ÔÂ‰‚‡ËÚÂÎ¸Ì‡ˇ ÙËÎ¸Ú‡ˆËˇ ÌÂ ÚÂ·ÛÂÚÒˇ, ÚÓ ‰‡ÌÌ˚È Ô‡‡ÏÂÚ ÒÎÂ‰ÛÂÚ
/// Á‡ÍÓÏÏÂÌÚËÓ‚‡Ú¸. —Ú‡ÓÂ ÁÌ‡˜ÂÌËÂ 0.333
#define CFG_PREFILTER_LOWPASS_K           0.5

/// @brief œÓÒÚÓˇÌÌ‡ˇ ‚ÂÏÂÌË Õ◊ ÙËÎ¸Ú‡ˆËË ‚ÂÍÚÓ‡ ÍÛÒ‡.
#define CFG_COURSE_LOWPASS_K              0.0015

/// @brief œÓÒÚÓˇÌÌ‡ˇ ‚ÂÏÂÌË Õ◊ ÙËÎ¸Ú‡ˆËË ‚ÂÍÚÓ‡ „‡‚ËÚ‡ˆËË.
#define CFG_GRAVITY_LOWPASS_K             0.002

#define CFG_MIN_SPEED_EVENT               6.000f
#define CFG_MIN_CORNERING_ACCEL           3.000f
#define CFG_MIN_BRAKING_ACCEL            -2.700f
#define CFG_MIN_ACCELERATION_ACCEL        2.700f

#define CFG_GRAVITY                       9.810f
#define CFG_MAX_GRAVITY_DRIFT             1.000f

#define CFG_MIN_EVENT_DURATION            600.0f
#define CFG_MAX_EVENT_PAUSE               3000.0f

#define CFG_MAX_WORK_ACCURACY             25.0f

#define CFG_STATISTICAL_PRECISION         10000

#endif /* FIRMWARE_CONFIG_H_ */
