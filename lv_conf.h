#ifndef LV_CONF_H
#define LV_CONF_H

#define LV_USE_OS           LV_OS_NONE
#define LV_USE_LOG          0
#define LV_BUILD_EXAMPLES   0

#define LV_USE_ASSERT_NULL  0
#define LV_USE_ASSERT_MEM   0
#define LV_USE_ASSERT_OBJ   0
#define LV_USE_ASSERT_STR   0

#define LV_COLOR_DEPTH      16
#define LV_COLOR_16_SWAP    1

#define LV_HOR_RES_MAX      320
#define LV_VER_RES_MAX      240

#define LV_TICK_CUSTOM 1
#define LV_TICK_CUSTOM_INCLUDE <Arduino.h>
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (millis())

#endif
