#ifndef DATATYPETIME_H_
#define DATATYPETIME_H_

#include "DataTypeBase.h"
#include "DataTypeInt.h"

/*
各种时间。
*/
namespace GarbageMayor
{
    /*
    年yyyy。
    年：short。
    */
    class DTtimey
        : public DTbase
    {
    private:
        short year;
    
    public:
        DTtimey();
        DTtimey(short year_);
        DTtimey(const DTtimey & dt);
        ~DTtimey();
        
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
    
    public:
        short get_year() const;
        void set_year(short year_);
        
    public:
        bool operator == (const DTtimey & dt) const;
        bool operator != (const DTtimey & dt) const;
        bool operator < (const DTtimey & dt) const;
        bool operator <= (const DTtimey & dt) const;
        bool operator > (const DTtimey & dt) const;
        bool operator >= (const DTtimey & dt) const;
    };
    
    /*
    年月日yyyymmdd。
    年：short。
    月：char，1~12。
    日：char，1~31，严格判断。
    */
    class DTtimed
        : public DTbase
    {
    private:
        short year;
        char month;
        char day;
    
    public:
        DTtimed();
        DTtimed(short year_, char month_, char day_);
        DTtimed(const DTtimed & dt);
        ~DTtimed();
        
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
    
    public:
        short get_year() const;
        char get_month() const;
        char get_day() const;
        void set_year(short year_);
        void set_month(char month_);
        void set_day(char day_);
        void set_ymd(short year_, char month_, char day_);
        
    public:
        bool operator == (const DTtimed & dt) const;
        bool operator != (const DTtimed & dt) const;
        bool operator < (const DTtimed & dt) const;
        bool operator <= (const DTtimed & dt) const;
        bool operator > (const DTtimed & dt) const;
        bool operator >= (const DTtimed & dt) const;
    };
    
    /*
    时分秒hhmmss。
    时：char，0~24，闰秒：24:00:00。
    分：char，0~59。
    秒：char，0~59。
    */
    class DTtimes
        : public DTbase
    {
    private:
        char hour;
        char minute;
        char second;
    
    public:
        DTtimes();
        DTtimes(char hour_, char minute_, char second_);
        DTtimes(const DTtimes & dt);
        ~DTtimes();
        
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
    
    public:
        char get_hour() const;
        char get_minute() const;
        char get_second() const;
        void set_hour(char hour_);
        void set_minute(char minute_);
        void set_second(char second_);
        void set_hms(char hour_, char minute_, char second_);
        
    public:
        bool operator == (const DTtimes & dt) const;
        bool operator != (const DTtimes & dt) const;
        bool operator < (const DTtimes & dt) const;
        bool operator <= (const DTtimes & dt) const;
        bool operator > (const DTtimes & dt) const;
        bool operator >= (const DTtimes & dt) const;
    };
    
    /*
    年月日时分秒yyyymmddhhmmss。
    年：short。
    月：char，1~12。
    日：char，1~31，严格判断。
    时：char，0~24，闰秒24:00:00。
    分：char，0~59。
    秒：char，0~59。
    */
    class DTtimeds
        : public DTbase
    {
    private:
        short year;
        char month;
        char day;
        char hour;
        char minute;
        char second;
    
    public:
        DTtimeds();
        DTtimeds(short year_, char month_, char day_, char hour_, char minute_, char second_);
        DTtimeds(const DTtimeds & dt);
        ~DTtimeds();
        
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
    
    public:
        short get_year() const;
        char get_month() const;
        char get_day() const;
        char get_hour() const;
        char get_minute() const;
        char get_second() const;
        void set_year(short year_);
        void set_month(char month_);
        void set_day(char day_);
        void set_ymd(short year_, char month_, char day_);
        void set_hour(char hour_);
        void set_minute(char minute_);
        void set_second(char second_);
        void set_hms(char hour_, char minute_, char second_);
        void set_ymdhms(short year_, char month_, char day_, char hour_, char minute_, char second_);
        
    public:
        bool operator == (const DTtimeds & dt) const;
        bool operator != (const DTtimeds & dt) const;
        bool operator < (const DTtimeds & dt) const;
        bool operator <= (const DTtimeds & dt) const;
        bool operator > (const DTtimeds & dt) const;
        bool operator >= (const DTtimeds & dt) const;
    };
    
    /*
    年月日时分秒毫微yyyymmddhhmmssmmmuuu。
    年：short。
    月：char，1~12。
    日：char，1~31，严格判断。
    时：char，0~24，闰秒24:00:00。
    分：char，0~59。
    秒：char，0~59。
    毫秒：short，0~999。
    微秒：short，0-999。
    */
    class DTtimedsu
        : public DTbase
    {
    private:
        short year;
        char month;
        char day;
        char hour;
        char minute;
        char second;
        short millisecond;
        short microsecond;
    
    public:
        DTtimedsu();
        DTtimedsu(short year_, char month_, char day_, char hour_, char minute_, char second_, short millisecond, short microsecond);
        DTtimedsu(const DTtimedsu & dt);
        ~DTtimedsu();
        
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
    
    public:
        short get_year() const;
        char get_month() const;
        char get_day() const;
        char get_hour() const;
        char get_minute() const;
        char get_second() const;
        short get_millisecond() const;
        short get_microsecond() const;
        void set_year(short year_);
        void set_month(char month_);
        void set_day(char day_);
        void set_ymd(short year_, char month_, char day_);
        void set_hour(char hour_);
        void set_minute(char minute_);
        void set_second(char second_);
        void set_hms(char hour_, char minute_, char second_);
        void set_ymdhms(short year_, char month_, char day_, char hour_, char minute_, char second_);
        void set_millisecond(short millisecond_);
        void set_microsecond(short microsecond_);
        void set_ymdhmsmu(short year_, char month_, char day_, char hour_, char minute_, char second_, short millisecond, short microsecond);
        
    public:
        bool operator == (const DTtimedsu & dt) const;
        bool operator != (const DTtimedsu & dt) const;
        bool operator < (const DTtimedsu & dt) const;
        bool operator <= (const DTtimedsu & dt) const;
        bool operator > (const DTtimedsu & dt) const;
        bool operator >= (const DTtimedsu & dt) const;
    };
}


#endif // DATATYPETIME_H_
