#ifndef FINDEVENT_H
#define FINDEVENT_H

#include <vector>

#include <stdint.h>
#include <string>
#include <vector>
#include "Tools/vec32.hpp"
#include "accident_detection.hpp"
#include "statistical.hpp"
#include <uuid/uuid.h>
//#include "uuid.hpp"
#include <inttypes.h>


enum class EventName:size_t
{
  NOT_DEFINED=0,
  PHONE_USING,
  CORNERING,
  ACCELERATION,
  BRAKING,
  ACCIDENT,
  DISTORTION
};

std::ostream& operator<<(std::ostream& out, EventName& name);


class coordinate{
public:
      double latitude;
      double longitude;
      explicit coordinate(double latitude_ = 0.0f ,double longitude_ = 0.0f):
        latitude(latitude_),longitude(longitude_){
      }
      ~coordinate(){
      }
      
};

class DataPoint{
public:
    double time;
    double speed;
    double accuracy;
    coordinate geopoint;
    Vec32  acceleration;
    Vec32  gyroscope;
    void clear(){
        time = 0.0f;
        speed = 0.0f;
        accuracy = 0.0f;
        acceleration.Clear();
        gyroscope.Clear();
        geopoint = coordinate();
    }
    DataPoint():time(0.0f),speed(0.0f),accuracy(0.0f){
        clear();
    }
    ~DataPoint(){
        clear();
    }
};


class EventPoint{
    public:
    //Поля продолжительности
    uuid_t id_;
    double duration;
    double pure_duration;
    double prev_start_speed;
    double reliability;
    DataPoint start,stop;
    
    EventName name;
    
    AccidentTrigger trigger_;
    
    StatisticalValue speed,x,y,z,accuracy;
    void clear(){
        uuid_clear(id_);
        trigger_ = AccidentTrigger::NOT_DEFINED;
        start.clear();
        stop.clear();
        duration = 0.0;
        pure_duration = 0.0;
        reliability = 0.0;
        speed = StatisticalValue();
        x = StatisticalValue();
        y = StatisticalValue();
        z = StatisticalValue();
        accuracy = StatisticalValue();
        name = EventName::NOT_DEFINED;
        return;
    }

    std::string GetUUIDString(void){
        uuid_string_t str;
        uuid_unparse(id_, str);
        return std::string(str);
    };
    
    EventPoint(){
        clear();
    };
    ~EventPoint(){
        clear();
    };
};

class EventData{
  public:
  std::vector <EventPoint> vector_;
  StatisticalData speed,x,y,z,accuracy;
  EventName name_;
  EventPoint point_;
  bool state_ ;
  bool seach_state_;
  double last_state_time_;
  void clear(void){
    vector_.clear();
    point_.clear();
    state_ = false;
    seach_state_ = false;
    last_state_time_ = 0.0;
    speed.Clear();
    x.Clear();
    y.Clear();
    z.Clear();
    accuracy.Clear();
  }
  explicit EventData(EventName name = EventName::NOT_DEFINED){
      clear();
      name_ = name;
  }
  ~EventData(){
      clear();
  }
};


class SensorSample{
public:
    int64_t time;
    int64_t index;
    double gps_speed;
    Vec32  acc;
    Vec32  gyro;
    SensorSample(){
        gps_speed = 0.0;
        time = 0;
        index = 0;
        acc = Vec32();
        gyro = Vec32();
    };
    SensorSample(int64_t sapmle_time, int64_t id_, Vec32 acceleration, Vec32 gyroscope, double speed){
        index = id_;
        gps_speed = speed;
        time = sapmle_time;
        acc = acceleration;
        gyro = gyroscope;
    };
};

class RAWSensorData{
public:
    #define SAMPLE_LENGTH 5000
    static SensorSample RAWSampleBefore[SAMPLE_LENGTH];
    static SensorSample RAWSampleAfter [SAMPLE_LENGTH];
    
    RAWSensorData();
    void ClearSensorData();
    bool GetSensorData();
    bool RecordRAWSample(DataPoint &current_point, AccidentTrigger trigger, const uuid_t guid);
    int64_t event_start_time;
    size_t GetRAWBufferSizeAfter(void);
    size_t GetRAWBufferSizeBefore(void);
    std::string GetUUIDString(void);
    uuid_t id_;
private:
    size_t RAWId;
    size_t RAWBeforeCount;
    size_t RAWAfterSize;
    bool AccidentDetect;
    bool RAWSampleReady;
};


class FindEvent{
public:
    
    static RAWSensorData sd;
    
    static bool RecordRAWSample(DataPoint &current_point, AccidentTrigger trigger);
    
/// brief: Функция проверяющая есть ли событие, обьединяющая части событий и формирующе событие
    static bool FindEventOptimized(EventData &event, DataPoint &current_point, bool event_triger);
/// brief: Функция проверяющая есть ли авария, обьединяющая части событий и формирующе событие
    static bool FindAccidentOptimized(EventData &event, DataPoint &current_point, AccidentTrigger trigger);
/// brief: Функция проверяющая есть ли авария, обьединяющая части событий и формирующе событие
    static bool RAWFindEvent(EventData &event, DataPoint &current_point, bool event_triger, size_t min_event_duration, size_t max_event_pause, AccidentTrigger trigger);

/// brief: Функция проверяющая есть ли не завершенное событие и если есть то завершающее ее.
    static bool GetLastEvent(EventData &event);
    static size_t CheakEvent(EventData &event);

//Функция получения Event в реальном времени
//event - ссылка на обьект хранящий эвенты
//clear_out - удалям ли полученные данные из обьекта
    static EventData GetEvents(EventData &event, bool clear_out);
    static double GetPrevSpeed(double speed);
};
    
#endif // FINDEVENT_H
