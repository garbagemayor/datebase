#include <cstdio>
#include <assert.h>

#include "DataTypeTime.h"

namespace GarbageMayor
{
    /*
    年yyyy。
    */
    DTtimey::DTtimey()
        : year(0) 
    {
        type = dt_null;
    }
    DTtimey::DTtimey(short year_)
        : year(year_)
    {
        assert(year != 0);
        type = dt_timey;
    }
    DTtimey::DTtimey(const DTtimey & dt)
        : year(dt.year)
    {
        year = dt_timey;
    }
    DTtimey::~DTtimey() {}
    
    void DTtimey::read()
    {
        int tmp;
        scanf("%d", &tmp);
        year = tmp;
        
        assert(year != 0);
        type = dt_timey;
    }
    void DTtimey::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%d", (int)year);
    }
    void DTtimey::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&year, 2, 1, file);
        
        assert(type == dt_timey || type == dt_null);
        if(type == dt_null)
            year = 0;
        else
            assert(year != 0);
    }
    void DTtimey::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&year, 2, 1, file);
    }
    int DTtimey::size() const
    {
        return 1 + 2;
    }
    void DTtimey::clear()
    {
        type = dt_null;
        year = 0;
    }
    
    short DTtimey::get_year() const
    {
        assert(type == dt_timey);
        return year;
    }
    void DTtimey::set_year(short year_)
    {
        year = year_;
        
        assert(year != 0);
        type = dt_timey;
    }
    
    bool DTtimey::operator == (const DTtimey & dt) const
    {
        if(type != dt.type)
            return false;
        return year == dt.year;
    }
    bool DTtimey::operator != (const DTtimey & dt) const
    {
        if(type != dt.type)
            return true;
        return year != dt.year;
    }
    bool DTtimey::operator < (const DTtimey & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        return year < dt.year;
    }
    bool DTtimey::operator <= (const DTtimey & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        return year <= dt.year;
    }
    bool DTtimey::operator > (const DTtimey & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        return year > dt.year;
    }
    bool DTtimey::operator >= (const DTtimey & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        return year >= dt.year;
    }
    
    /*
    年月日yyyymmdd。
    */
    DTtimed::DTtimed()
        : year(0), month(0), day(0)
    {
        type = dt_null;
    }
    DTtimed::DTtimed(short year_, char month_, char day_)
        : year(year_), month(month_), day(day_)
    {
        type = dt_timed;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
    }
    DTtimed::DTtimed(const DTtimed & dt)
        : year(dt.year), month(dt.month), day(dt.day)
    {
        type = dt_timed;
    }
    
    void DTtimed::read()
    {
        int tmp_1, tmp_2, tmp_3;
        char tmp_4[4] = { 0, 0, 0, 0, };
        scanf("%d%3[BC-]%d-%d", &tmp_1, tmp_4, &tmp_2, &tmp_3);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        if(tmp_4[0] == 'B' && tmp_4[1] == 'C')
            year = -year;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        type = dt_timed;
    }
    void DTtimed::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        if(year > 0)
            printf("%d", (int)year);
        else
            printf("%dBC", (int)-year);
        printf("-%02d-%02d", (int)month, (int)day);
    }
    void DTtimed::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&year, 2, 1, file);
        fread(&month, 1, 1, file);
        fread(&day, 1, 1, file);
        
        assert(type == dt_timed || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            assert(year != 0);
            assert(1 <= month && month <= 12);
            if(month == 4 || month == 6 || month == 9 || month == 11)
                assert(day <= 30);
            else if(month == 2)
            {
                if(year >= 1)
                {
                    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
                else
                {
                    if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
            }
            else 
                assert(1 <= day && day <= 31);
        }
    }
    void DTtimed::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&year, 2, 1, file);
        fwrite(&month, 1, 1, file);
        fwrite(&day, 1, 1, file);
    }
    int DTtimed::size() const
    {
        return 1 + 2 + 1 + 1;
    }
    void DTtimed::clear() 
    {
        type = dt_null;
        year = 0;
        month = 0;
        day = 0;
    }
    
    short DTtimed::get_year() const
    {
        assert(type == dt_timed);
        return year;
    }
    char DTtimed::get_month() const
    {
        assert(type == dt_timed);
        return month;
    }
    char DTtimed::get_day() const
    {
        assert(type == dt_timed);
        return day;
    }
    void DTtimed::set_year(short year_)
    {
        year = year_;
        month = 1;
        day = 1;
        
        assert(year != 0);
        type = dt_timey;
    }
    void DTtimed::set_month(char month_)
    {
        assert(type == dt_timed);
        assert(year != 0);
        month = month_;
        day = 1;
        
        assert(1 <= month && month <= 12);
        type = dt_timey;
    }
    void DTtimed::set_day(char day_)
    {
        assert(type == dt_timed);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        day = day_;
        
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        type = dt_timey;
    }
    void DTtimed::set_ymd(short year_, char month_, char day_)
    {
        year = year_;
        month = month_;
        day = day_;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        type = dt_timey;
    }
    
    bool DTtimed::operator == (const DTtimed & dt) const
    {
        if(type != dt.type)
            return false;
        if(year != dt.year)
            return false;
        if(month != dt.month)
            return false;
        return day == dt.day;
    }
    bool DTtimed::operator != (const DTtimed & dt) const
    {
        if(type != dt.type)
            return true;
        if(year != dt.year)
            return true;
        if(month != dt.month)
            return true;
        return day != dt.day;
    }
    bool DTtimed::operator < (const DTtimed & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        return day < dt.day;
    }
    bool DTtimed::operator <= (const DTtimed & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        return day <= dt.day;
    }
    bool DTtimed::operator > (const DTtimed & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        return day > dt.day;
    }
    bool DTtimed::operator >= (const DTtimed & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        return day >= dt.day;
    }
    
    /*
    时分秒hhmmss。
    */
    DTtimes::DTtimes()
        : hour(0), minute(0), second(0)
    {
        type = dt_null;
    }
    DTtimes::DTtimes(char hour_, char minute_, char second_)
        : hour(hour_), minute(minute_), second(second_)
    {
        type = dt_times;
        
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
    }
    DTtimes::DTtimes(const DTtimes & dt)
        : hour(dt.hour), minute(dt.minute), second(dt.second)
    {
        type = dt_times;
    }
    
    void DTtimes::read()
    {
        int tmp_1, tmp_2, tmp_3;
        scanf("%d:%d:%d", &tmp_1, &tmp_2, &tmp_3);
        hour = tmp_1;
        minute = tmp_2;
        second = tmp_3;
        
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        type = dt_times;
    }
    void DTtimes::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%02d:%02d:%02d", (int)hour, (int)minute, (int)second);
    }
    void DTtimes::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&hour, 1, 1, file);
        fread(&minute, 1, 1, file);
        fread(&second, 1, 1, file);
        
        assert(type == dt_times || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            assert(0 <= hour && hour <= 24);
            assert(0 <= minute && minute <= 59);
            assert(0 <= second && second <= 59);
            assert(hour <= 23 || (minute == 0 && second == 0));
        }
    }
    void DTtimes::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&hour, 1, 1, file);
        fwrite(&minute, 1, 1, file);
        fwrite(&second, 1, 1, file);
    }
    int DTtimes::size() const 
    {
        return 1 + 1 + 1 + 1;
    }
    void DTtimes::clear()
    {
        type = dt_null;
        hour = 0;
        minute = 0;
        second = 0;
    }
    
    char DTtimes::get_hour() const
    {
        assert(type == dt_times);
        return hour;
    }
    char DTtimes::get_minute() const
    {
        assert(type == dt_times);
        return minute;
    }
    char DTtimes::get_second() const
    {
        assert(type == dt_times);
        return second;
    }
    void DTtimes::set_hour(char hour_)
    {
        hour = hour_;
        minute = 0;
        second = 0;
        
        assert(0 <= hour && hour <= 24);
        type = dt_times;
    }
    void DTtimes::set_minute(char minute_)
    {
        assert(type == dt_times);
        assert(0 <= hour && hour <= 24);
        minute = minute_;
        second = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimes::set_second(char second_)
    {
        assert(type == dt_times);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
        second = second_;
        
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || second == 0);
    }
    void DTtimes::set_hms(char hour_, char minute_, char second_)
    {
        hour = hour_;
        minute = minute_;
        second = second_;
        
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        type = dt_times;
    }
    
    bool DTtimes::operator == (const DTtimes & dt) const
    {
        if(type != dt.type)
            return false;
        if(hour != dt.hour)
            return false;
        if(minute != dt.minute)
            return false;
        return second == dt.second;
    }
    bool DTtimes::operator != (const DTtimes & dt) const
    {
        if(type != dt.type)
            return true;
        if(hour != dt.hour)
            return true;
        if(minute != dt.minute)
            return true;
        return second != dt.second;
    }
    bool DTtimes::operator < (const DTtimes & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        return second < dt.second;
    }
    bool DTtimes::operator <= (const DTtimes & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        return second <= dt.second;
    }
    bool DTtimes::operator > (const DTtimes & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        return second > dt.second;
    }
    bool DTtimes::operator >= (const DTtimes & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        return second > dt.second;
    }
    
    /*
    年月日时分秒yyyymmddhhmmss。
    */
    DTtimeds::DTtimeds()
        : year(0), month(0), day(0)
        , hour(0), minute(0), second(0)
    {
        type = dt_null;
    }
    DTtimeds::DTtimeds(short year_, char month_, char day_, char hour_, char minute_, char second_)
        : year(year_), month(month_), day(day_)
        , hour(hour_), minute(minute_), second(second_)
    {
        type = dt_timeds;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
    }
    DTtimeds::DTtimeds(const DTtimeds & dt)
        : year(dt.year), month(dt.month), day(dt.day)
        , hour(dt.hour), minute(dt.minute), second(dt.second)
    {
        type = dt_timeds;
    }
    
    void DTtimeds::read()
    {
        int tmp_1, tmp_2, tmp_3;
        char tmp_4[4] = { 0, 0, 0, 0, };
        scanf("%d%3[BC-]%d-%d", &tmp_1, tmp_4, &tmp_2, &tmp_3);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        if(tmp_4[0] == 'B' && tmp_4[1] == 'C')
            year = -year;
        scanf("--%d:%d:%d", &tmp_1, &tmp_2, &tmp_3);
        hour = tmp_1;
        minute = tmp_2;
        second = tmp_3;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        type = dt_timeds;
    }
    void DTtimeds::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        if(year > 0)
            printf("%d", (int)year);
        else
            printf("%dBC", (int)-year);
        printf("-%02d-%02d", (int)month, (int)day);
        printf("--%02d:%02d:%02d", (int)hour, (int)minute, (int)second);
    }
    void DTtimeds::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&year, 2, 1, file);
        fread(&month, 1, 1, file);
        fread(&day, 1, 1, file);
        fread(&hour, 1, 1, file);
        fread(&minute, 1, 1, file);
        fread(&second, 1, 1, file);
        
        assert(type == dt_timeds || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            assert(year != 0);
            assert(1 <= month && month <= 12);
            if(month == 4 || month == 6 || month == 9 || month == 11)
                assert(day <= 30);
            else if(month == 2)
            {
                if(year >= 1)
                {
                    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
                else
                {
                    if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
            }
            else 
                assert(1 <= day && day <= 31);
            assert(0 <= hour && hour <= 24);
            assert(0 <= minute && minute <= 59);
            assert(0 <= second && second <= 59);
            assert(hour <= 23 || (minute == 0 && second == 0));
        }
    }
    void DTtimeds::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&year, 2, 1, file);
        fwrite(&month, 1, 1, file);
        fwrite(&day, 1, 1, file);
        fwrite(&hour, 1, 1, file);
        fwrite(&minute, 1, 1, file);
        fwrite(&second, 1, 1, file);
    }
    int DTtimeds::size() const
    {
        return 1 + (2 + 1 + 1) + (1 + 1 + 1);
    }
    void DTtimeds::clear()
    {
        type = dt_null;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    
    short DTtimeds::get_year() const
    {
        assert(type == dt_timed);
        return year;
    }
    char DTtimeds::get_month() const
    {
        assert(type == dt_timed);
        return month;
    }
    char DTtimeds::get_day() const
    {
        assert(type == dt_timed);
        return day;
    }
    char DTtimeds::get_hour() const
    {
        assert(type == dt_times);
        return hour;
    }
    char DTtimeds::get_minute() const
    {
        assert(type == dt_times);
        return minute;
    }
    char DTtimeds::get_second() const
    {
        assert(type == dt_times);
        return second;
    }
    void DTtimeds::set_year(short year_)
    {
        year = year_;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        
        assert(year != 0);
        type = dt_timeds;
    }
    void DTtimeds::set_month(char month_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        month = month_;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        
        assert(1 <= month && month <= 12);
    }
    void DTtimeds::set_day(char day_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        day = day_;
        hour = 0;
        minute = 0;
        second = 0;
        
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
    }
    void DTtimeds::set_ymd(short year_, char month_, char day_)
    {
        year = year_;
        month = month_;
        day = day_;
        hour = 0;
        minute = 0;
        second = 0;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        type = dt_timeds;
    }
    void DTtimeds::set_hour(char hour_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        hour = hour_;
        minute = 0;
        second = 0;
        
        assert(0 <= hour && hour <= 24);
    }
    void DTtimeds::set_minute(char minute_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        minute = minute_;
        second = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimeds::set_second(char second_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
        second = second_;
        
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || second == 0);
    }
    void DTtimeds::set_hms(char hour_, char minute_, char second_)
    {
        assert(type == dt_timeds);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        hour = hour_;
        minute = minute_;
        second = second_;
        
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
    }
    void DTtimeds::set_ymdhms(short year_, char month_, char day_, char hour_, char minute_, char second_)
    {
        year = year_;
        month = month_;
        day = day_;
        hour = hour_;
        minute = minute_;
        second = second_;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        type = dt_timeds;
    }
    
    bool DTtimeds::operator == (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return false;
        if(year != dt.year)
            return false;
        if(month != dt.month)
            return false;
        if(day != dt.day)
            return false;
        if(hour != dt.hour)
            return false;
        if(minute != dt.minute)
            return false;
        return second == dt.second;
    }
    bool DTtimeds::operator != (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return true;
        if(year != dt.year)
            return true;
        if(month != dt.month)
            return true;
        if(day != dt.day)
            return true;
        if(hour != dt.hour)
            return true;
        if(minute != dt.minute)
            return true;
        return second != dt.second;
    }
    bool DTtimeds::operator < (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        if(day != dt.day)
            return day < dt.day;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        return second < dt.second;
    }
    bool DTtimeds::operator <= (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        if(day != dt.day)
            return day < dt.day;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        return second <= dt.second;
    }
    bool DTtimeds::operator > (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        if(day != dt.day)
            return day > dt.day;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        return second > dt.second;
    }
    bool DTtimeds::operator >= (const DTtimeds & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        if(day != dt.day)
            return day > dt.day;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        return second >= dt.second;
    }
    
    /*
    年月日时分秒毫微yyyymmddhhmmssmmmuuu。
    */
    DTtimedsu::DTtimedsu()
        : year(0), month(0), day(0)
        , hour(0), minute(0), second(0)
        , millisecond(0), microsecond(0)
    {
        type = dt_null;
    }
    DTtimedsu::DTtimedsu(short year_, char month_, char day_, char hour_, char minute_, char second_, short millisecond_, short microsecond_)
        : year(year_), month(month_), day(day_)
        , hour(hour_), minute(minute_), second(second_)
        , millisecond(millisecond_), microsecond(microsecond_)
    {
        type = dt_timedsu;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        assert(0 <= millisecond && millisecond <= 999);
        assert(0 <= microsecond && microsecond <= 999);
    }
    DTtimedsu::DTtimedsu(const DTtimedsu & dt)
        : year(dt.year), month(dt.month), day(dt.day)
        , hour(dt.hour), minute(dt.minute), second(dt.second)
        , millisecond(dt.millisecond), microsecond(dt.microsecond)
    {
        type = dt_timedsu;
    }
    
    void DTtimedsu::read()
    {
        int tmp_1, tmp_2, tmp_3;
        char tmp_4[4] = { 0, 0, 0, 0, };
        scanf("%d%3[BC-]%d-%d", &tmp_1, tmp_4, &tmp_2, &tmp_3);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        if(tmp_4[0] == 'B' && tmp_4[1] == 'C')
            year = -year;
        scanf("--%d:%d:%d", &tmp_1, &tmp_2, &tmp_3);
        hour = tmp_1;
        minute = tmp_2;
        second = tmp_3;
        scanf(".%d.%d", &tmp_1, &tmp_2);
        millisecond = tmp_1;
        microsecond = tmp_2;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        assert(0 <= millisecond && millisecond <= 999);
        assert(0 <= microsecond && microsecond <= 999);
    }
    void DTtimedsu::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        if(year > 0)
            printf("%d", (int)year);
        else
            printf("%dBC", (int)-year);
        printf("-%02d-%02d", (int)month, (int)day);
        printf("--%02d:%02d:%02d", (int)hour, (int)minute, (int)second);
        printf(".%03d.%03d", (int)millisecond, (int)microsecond);
    }
    void DTtimedsu::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&year, 2, 1, file);
        fread(&month, 1, 1, file);
        fread(&day, 1, 1, file);
        fread(&hour, 1, 1, file);
        fread(&minute, 1, 1, file);
        fread(&second, 1, 1, file);
        fread(&millisecond, 2, 1, file);
        fread(&microsecond, 2, 1, file);
        
        assert(type == dt_timedsu || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            assert(year != 0);
            assert(1 <= month && month <= 12);
            if(month == 4 || month == 6 || month == 9 || month == 11)
                assert(day <= 30);
            else if(month == 2)
            {
                if(year >= 1)
                {
                    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
                else
                {
                    if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                        assert(day <= 29);
                    else
                        assert(day <= 28);
                }
            }
            else 
                assert(1 <= day && day <= 31);
            assert(0 <= hour && hour <= 24);
            assert(0 <= minute && minute <= 59);
            assert(0 <= second && second <= 59);
            assert(hour <= 23 || (minute == 0 && second == 0));
            assert(0 <= millisecond && millisecond <= 999);
            assert(0 <= microsecond && microsecond <= 999);
        }
    }
    void DTtimedsu::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&year, 2, 1, file);
        fwrite(&month, 1, 1, file);
        fwrite(&day, 1, 1, file);
        fwrite(&hour, 1, 1, file);
        fwrite(&minute, 1, 1, file);
        fwrite(&second, 1, 1, file);
        fwrite(&millisecond, 2, 1, file);
        fwrite(&microsecond, 2, 1, file);
    }
    int DTtimedsu::size() const
    {
        return 1 + (2 + 1 + 1) + (1 + 1 + 1) + (2 + 2);
    }
    void DTtimedsu::clear()
    {
        type = dt_null;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
    }
    
    short DTtimedsu::get_year() const
    {
        assert(type == dt_timed);
        return year;
    }
    char DTtimedsu::get_month() const
    {
        assert(type == dt_timed);
        return month;
    }
    char DTtimedsu::get_day() const
    {
        assert(type == dt_timed);
        return day;
    }
    char DTtimedsu::get_hour() const
    {
        assert(type == dt_times);
        return hour;
    }
    char DTtimedsu::get_minute() const
    {
        assert(type == dt_times);
        return minute;
    }
    char DTtimedsu::get_second() const
    {
        assert(type == dt_times);
        return second;
    }
    short DTtimedsu::get_millisecond() const
    {
        assert(type == dt_timed);
        return millisecond;
    }
    short DTtimedsu::get_microsecond() const
    {
        assert(type == dt_timed);
        return microsecond;
    }
    void DTtimedsu::set_year(short year_)
    {
        year = year_;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(year != 0);
        type = dt_timedsu;
    }
    void DTtimedsu::set_month(char month_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        month = month_;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(1 <= month && month <= 12);
    }
    void DTtimedsu::set_day(char day_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        day = day_;
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
    }
    void DTtimedsu::set_ymd(short year_, char month_, char day_)
    {
        year = year_;
        month = month_;
        day = day_;
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        type = dt_timedsu;
    }
    void DTtimedsu::set_hour(char hour_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        hour = hour_;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= hour && hour <= 24);
    }
    void DTtimedsu::set_minute(char minute_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        minute = minute_;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimedsu::set_second(char second_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
        second = second_;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || second == 0);
    }
    void DTtimedsu::set_hms(char hour_, char minute_, char second_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        hour = hour_;
        minute = minute_;
        second = second_;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
    }
    void DTtimedsu::set_ymdhms(short year_, char month_, char day_, char hour_, char minute_, char second_)
    {
        year = year_;
        month = month_;
        day = day_;
        hour = hour_;
        minute = minute_;
        second = second_;
        millisecond = 0;
        microsecond = 0;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        type = dt_timeds;
    }
    void DTtimedsu::set_millisecond(short millisecond_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        millisecond = millisecond_;
        microsecond = 0;
        
        assert(0 <= millisecond && millisecond <= 999);
    }
    void DTtimedsu::set_microsecond(short microsecond_)
    {
        assert(type == dt_timedsu);
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        assert(0 <= millisecond && millisecond <= 999);
        microsecond = microsecond_;
        
        assert(0 <= microsecond && microsecond <= 999);
    }
    void DTtimedsu::set_ymdhmsmu(short year_, char month_, char day_, char hour_, char minute_, char second_, short millisecond_, short microsecond_)
    {
        year = year_;
        month = month_;
        day = day_;
        hour = hour_;
        minute = minute_;
        second = second_;
        millisecond = millisecond_;
        microsecond = microsecond_;
        
        assert(year != 0);
        assert(1 <= month && month <= 12);
        if(month == 4 || month == 6 || month == 9 || month == 11)
            assert(day <= 30);
        else if(month == 2)
        {
            if(year >= 1)
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
            else
            {
                if(-year % 4 == 1 && (-year % 100 != 1 || -year % 400 == 1))
                    assert(day <= 29);
                else
                    assert(day <= 28);
            }
        }
        else 
            assert(1 <= day && day <= 31);
        assert(0 <= hour && hour <= 24);
        assert(0 <= minute && minute <= 59);
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || (minute == 0 && second == 0));
        assert(0 <= millisecond && millisecond <= 999);
        assert(0 <= microsecond && microsecond <= 999);
        type = dt_timedsu;
    }
    
    bool DTtimedsu::operator == (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return false;
        if(year != dt.year)
            return false;
        if(month != dt.month)
            return false;
        if(day != dt.day)
            return false;
        if(hour != dt.hour)
            return false;
        if(minute != dt.minute)
            return false;
        if(second != dt.second)
            return false;
        if(millisecond != dt.millisecond)
            return false;
        return microsecond == dt.microsecond;
    }
    bool DTtimedsu::operator != (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return true;
        if(year != dt.year)
            return true;
        if(month != dt.month)
            return true;
        if(day != dt.day)
            return true;
        if(hour != dt.hour)
            return true;
        if(minute != dt.minute)
            return true;
        if(second != dt.second)
            return true;
        if(millisecond != dt.millisecond)
            return true;
        return microsecond == dt.microsecond;
    }
    bool DTtimedsu::operator < (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        if(day != dt.day)
            return day < dt.day;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        if(second != dt.second)
            return second < dt.second;
        if(millisecond != dt.millisecond)
            return millisecond < dt.millisecond;
        return microsecond < dt.microsecond;
    }
    bool DTtimedsu::operator <= (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(year != dt.year)
            return year < dt.year;
        if(month != dt.month)
            return month < dt.month;
        if(day != dt.day)
            return day < dt.day;
        if(hour != dt.hour)
            return hour < dt.hour;
        if(minute != dt.minute)
            return minute < dt.minute;
        if(second != dt.second)
            return second < dt.second;
        if(millisecond != dt.millisecond)
            return millisecond < dt.millisecond;
        return microsecond <= dt.microsecond;
    }
    bool DTtimedsu::operator > (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        if(day != dt.day)
            return day > dt.day;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        if(second != dt.second)
            return second > dt.second;
        if(millisecond != dt.millisecond)
            return millisecond > dt.millisecond;
        return microsecond > dt.microsecond;
    }
    bool DTtimedsu::operator >= (const DTtimedsu & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(year != dt.year)
            return year > dt.year;
        if(month != dt.month)
            return month > dt.month;
        if(day != dt.day)
            return day > dt.day;
        if(hour != dt.hour)
            return hour > dt.hour;
        if(minute != dt.minute)
            return minute > dt.minute;
        if(second != dt.second)
            return second > dt.second;
        if(millisecond != dt.millisecond)
            return millisecond > dt.millisecond;
        return microsecond >= dt.microsecond;
    }
}
