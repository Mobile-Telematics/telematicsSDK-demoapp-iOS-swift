#ifndef READPRINT_H
#define READPRINT_H

#include <iostream>
#include <fstream>
#include "FindEvent.h"

void StopLog(void);
bool StartLog(std::string filename);

bool ReadData(std::string line,double * timestamp, double *x, double *y, double *z,double * speed,coordinate *geopoint,double *accuracy,std::string *local_time);

bool FindTimestampData (std::string line, std::string name, double * value);
bool FindReadDoubleData(std::string line, std::string name, double * value);
bool FindReadUInt32Data(std::string line, std::string name, uint32_t * value);
bool FindReadString    (std::string line, std::string name, std::string * value, size_t count);

bool PrintEventOptimized (EventData *event);
bool PrintLog(Vec32 in, Vec32 out,double timestamp,double speed, coordinate geopoint, std::string local_time);

bool ReadEventLog(std::string line, size_t *p, size_t *c, size_t *a, size_t *b);
bool FindLostSensorInterval(std::string line);

#endif // READPRINT_H
