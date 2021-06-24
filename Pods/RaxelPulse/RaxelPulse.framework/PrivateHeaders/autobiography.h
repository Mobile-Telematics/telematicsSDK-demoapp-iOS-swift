//
//  autobiography.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#define outputFieldCount 50
#define fieldNamesCount 11
#define maximumCount 200
#define maxMaxCount maximumCount*100
#define maxPointCount 100

namespace autobiography {
    
    class XYZ{
    public:
        double X;
        double Y;
        double Z;
    };
    
    class InputModel {
    public:
        long long timestamp; // Время (по данным GNSS приёмника), когда были получена данная запись.
        long long tick_timestamp; // Время локальное + смещение таймзоны
        double latitude; // Широта в градусах * 10^-9
        double longitude; // Долгота в градусах * 10^-9
        double locationSpeed; // Скорость км/ч
        double locationTrueHeading; // Направление на север, градусы
        int height; // Высота над уровнем моря в миллиметрах
        double accelerometerTimestamp_sinceReboot; // время для ускорения
        XYZ accelerometerAcceleration; // ускорение по акселерометру по оси X(м/с^2)
        double gyroTimestamp_sinceReboot; // время для гироскопа
        XYZ gyroRotation; // угловая скорость по оси X(рад/с)
        char loggingTime[26];
    };
    
    class OutputModel{
    public:
        double time_in_sec;
        XYZ accel_filtered;
        XYZ gyroRotation_filter;
        XYZ accel_adapted;
        XYZ zero_spin_offset_;
        XYZ gyroRotation_adapted;
        double running_m;
        double sinA;
        double cosA;
        double sinB;
        double cosB;
        double sinC;
        double cosC;
        double angleA;
        double angleB;
        double angleC;
        double average_GyroRotationZ;
        double speedChangeTime;
        double adoptedLengthXY;
        double adoptedLengthXYavg;
        double accelX_longitudinal;
        double accelY_lateral;
        double accelZ_adapted;
        double gyroZ_angle;
        double gyroY_angle;
        double gyroX_angle;
        int max_avg_x;
        int max_avg_y;
        int max_avg_z;
        int flag1;
        int flag_final;
        double alpha1;
        double alpha2;
        double alpha3;
        double alpha4;
        bool gravityAdopIndex;
        bool courseAdopIndex;
        int turn_A;
        int turn_B;
        bool index_A;
        bool index_B;
    };
    
    class LogModel : public InputModel, public OutputModel {
    };
    
    class Autobiography{
    public:
        LogModel processInputModel(InputModel model);
    private:
        char InputFile[1024];
        InputModel InputModels[maxMaxCount];
        OutputModel OutputModels[maxMaxCount];
        int currInd; // индекс текущего элемента в OutputModels
        int FieldNameNum[fieldNamesCount]; // хранит номер запятой (FieldNameIndex[i]) для соответствующего поля (FieldName[i])
        void String2InputModel(const char* line);
        void Processing();
        LogModel OutputModel2String();
        int PointCount;
        void ParseFirstLine(const char* firstLine);
        char* FirstLine2String();
        void Reshape();
        void EvalRunning();
        void EvalAccel_filtered();
        void EvalGravityAdopIndex();
        void EvalGyroRotation_filter();
        void EvalCosSinAB();
        void EvalAccel_adapted();
        void EvalGyroRotation_adapted();
        void EvalSpeedChangeTime();
        void EvalAverage_GyroRotationZ();
        void EvalAdoptedLengthXYavg();
        void EvalCosCSinC();
        void EvalOutput();
        void EvalMaxAvgX();
        void EvalMaxAvgY();
        void EvalMaxAvgZ();
        void EvalFlags();
        void EvalTurns();
        void EvalIndexes();
    };
    
}
