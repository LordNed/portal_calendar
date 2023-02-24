#include <Arduino.h>
#include "config.h"

#ifndef PORTALCALENDAR_GLOBAL_H
#define PORTALCALENDAR_GLOBAL_H

#ifdef DEBUG
#define DEBUG_PRINT(...) Serial.printf(__VA_ARGS__); Serial.print('\n')
#else
#define DEBUG_PRINT(...)
#endif

#define uS_PER_S 1000000
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_DAY (SECONDS_PER_HOUR * 24)

#define clamp(x, y) min(max(x, -y), y)

#define ERROR_RETRY_INTERVAL_SECONDS            ERROR_RETRY_INTERVAL_MINUTES * 60
#define ERROR_AFTER_SECONDS_WITHOUT_INTERNET    ERROR_AFTER_HOURS_WITHOUT_INTERNET * 3600
#define SECONDS_BEFORE_MIDNIGHT_TO_SYNC_1       MINUTES_BEFORE_MIDNIGHT_TO_SYNC_1 * 60
#define SECONDS_BEFORE_MIDNIGHT_TO_SYNC_2       MINUTES_BEFORE_MIDNIGHT_TO_SYNC_2 * 60
#define TZ_LOOKUP_TIMEOUT_MS                    TZ_LOOKUP_TIMEOUT_SECONDS * 1000
#define NTP_TIMEOUT_MS                          NTP_TIMEOUT_SECONDS * 1000

#define DEBUG_PRINT_SECONDS(message, totalSeconds) \
{ \
  int32_t hours = totalSeconds / (60*60); \
  int32_t minutes = (totalSeconds % (60*60)) / 60; \
  int32_t seconds = (totalSeconds % (60*60)) % 60; \
  DEBUG_PRINT("%s Total Seconds: %llu (Hours: %d Mins: %d Seconds: %d)", message, totalSeconds, hours, minutes, seconds);\
}

#define DEBUG_PRINT_NTP(msg, t) \
{ \
    time(&t); \
    tm now; \
    localtime_r(&t, &now); \
    char timestr[30]; \
    strftime(timestr, sizeof(timestr), "%d-%m-%Y %H:%M:%S", &now); \
    DEBUG_PRINT("%s %s", msg, timestr); \
}

#endif // PORTALCALENDAR_GLOBAL_H
