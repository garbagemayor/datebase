#include <cstdio>
#include <assert.h>

#include "DataTypeTime.h"

namespace GarbageMayor
{
    /*
    年yyyy。
    */
    DTtimey::DTtimey()
        : year(2017) 
    {
        type = dt_timey;
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
    }
    void DTtimey::write()
    {
        printf("%d", (int)year);
    }
    int DTtimey::get_size() const
    {
        return 2;
    }
    
    /*
    年月日yyyymmdd。
    */
    DTtimed::DTtimed()
        : year(2017), month(1), day(1)
    {
        type = dt_timed;
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
        scanf("%d-%d-%d", &tmp_1, &tmp_2, &tmp_3);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        
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
    void DTtimed::write()
    {
        printf("%4d-%02d-%02d", (int)year, (int)month, (int)day);
    }
    int DTtimed::get_size() const
    {
        return 4;
    }
    
    void DTtimed::set_year(short year_)
    {
        year = year_;
        month = 1;
        day = 1;
        
        assert(year != 0);
    }
    void DTtimed::set_month(char month_)
    {
        month = month_;
        day = 1;
        
        assert(1 <= month && month <= 12);
    }
    void DTtimed::set_day(char day_)
    {
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
    }
    
    bool DTtimed::operator == (const DTtimed & dt) const
    {
        return 
            year == dt.year &&
            month == dt.month && 
            day == dt.day;
    }
    bool DTtimed::operator != (const DTtimed & dt) const
    {
        return 
            year != dt.year || 
            month != dt.month || 
            day != dt.day;
    }
    bool DTtimed::operator < (const DTtimed & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && 
                day < dt.day);
    }
    bool DTtimed::operator <= (const DTtimed & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && 
                day <= dt.day);
    }
    bool DTtimed::operator > (const DTtimed & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && 
                day > dt.day);
    }
    bool DTtimed::operator >= (const DTtimed & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && 
                day >= dt.day);
    }
    
    /*
    时分秒hhmmss。
    */
    DTtimes::DTtimes()
        : hour(0), minute(0), second(0)
    {
        type = dt_times;
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
    }
    void DTtimes::write()
    {
        printf("%02d:%02d:%02d", (int)hour, (int)minute, (int)second);
    }
    int DTtimes::get_size() const 
    {
        return 3;
    }
    
    void DTtimes::set_hour(char hour_)
    {
        hour = hour_;
        minute = 0;
        second = 0;
        
        assert(0 <= hour && hour <= 24);
    }
    void DTtimes::set_minute(char minute_)
    {
        minute = minute_;
        second = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimes::set_second(char second_)
    {
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
    }
    
    bool DTtimes::operator == (const DTtimes & dt) const
    {
        return 
            hour == dt.hour && 
            minute == dt.minute && 
            second == dt.second;
    }
    bool DTtimes::operator != (const DTtimes & dt) const
    {
        return 
            hour != dt.hour || 
            minute != dt.minute || 
            second != dt.second;
    }
    bool DTtimes::operator < (const DTtimes & dt) const
    {
        return 
            hour < dt.hour || 
            hour == dt.hour && (
                minute < dt.minute || 
                minute == dt.minute && 
                second < dt.second);
    }
    bool DTtimes::operator <= (const DTtimes & dt) const
    {
        return 
            hour < dt.hour || 
            hour == dt.hour && (
                minute < dt.minute || 
                minute == dt.minute && 
                second <= dt.second);
    }
    bool DTtimes::operator > (const DTtimes & dt) const
    {
        return 
            hour > dt.hour || 
            hour == dt.hour && (
                minute > dt.minute || 
                minute == dt.minute && 
                second > dt.second);
    }
    bool DTtimes::operator >= (const DTtimes & dt) const
    {
        return 
            hour > dt.hour || 
            hour == dt.hour && (
                minute > dt.minute || 
                minute == dt.minute && 
                second >= dt.second);
    }
    
    /*
    年月日时分秒yyyymmddhhmmss。
    */
    DTtimeds::DTtimeds()
        : year(2017), month(1), day(1)
        , hour(0), minute(0), second(0)
    {
        type = dt_timeds;
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
        int tmp_1, tmp_2, tmp_3, tmp_4, tmp_5, tmp_6;
        scanf("%d-%d-%d--%d:%d:%d", &tmp_1, &tmp_2, &tmp_3, &tmp_4, &tmp_5, &tmp_6);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        hour = tmp_4;
        minute = tmp_5;
        second = tmp_6;
        
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
    void DTtimeds::write()
    {
        printf("%4d-%02d-%02d--%02d:%02d:%02d", (int)year, (int)month, (int)day, (int)hour, (int)minute, (int)second);
    }
    int DTtimeds::get_size() const
    {
        return 7;
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
    }
    void DTtimeds::set_month(char month_)
    {
        month = month_;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        
        assert(1 <= month && month <= 12);
    }
    void DTtimeds::set_day(char day_)
    {
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
    }
    void DTtimeds::set_hour(char hour_)
    {
        hour = hour_;
        minute = 0;
        second = 0;
        
        assert(0 <= hour && hour <= 24);
    }
    void DTtimeds::set_minute(char minute_)
    {
        minute = minute_;
        second = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimeds::set_second(char second_)
    {
        second = second_;
        
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || second == 0);
    }
    void DTtimeds::set_hms(char hour_, char minute_, char second_)
    {
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
    }
    
    bool DTtimeds::operator == (const DTtimeds & dt) const
    {
        return 
            year == dt.year && 
            month == dt.month && 
            day == dt.day && 
            hour == dt.hour && 
            minute == dt.minute && 
            second == dt.second;
    }
    bool DTtimeds::operator != (const DTtimeds & dt) const
    {
        return 
            year != dt.year || 
            month != dt.month || 
            day != dt.day || 
            hour != dt.hour || 
            minute != dt.minute || 
            second != dt.second;
    }
    bool DTtimeds::operator < (const DTtimeds & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && (
                    day < dt.day || 
                    day == dt.day && (
                        hour < dt.hour || 
                        hour == dt.hour && (
                            minute < dt.minute || 
                            minute == dt.minute && 
                            second < dt.second))));
    }
    bool DTtimeds::operator <= (const DTtimeds & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && (
                    day < dt.day || 
                    day == dt.day && (
                        hour < dt.hour || 
                        hour == dt.hour && (
                            minute < dt.minute || 
                            minute == dt.minute && 
                            second <= dt.second))));
    }
    bool DTtimeds::operator > (const DTtimeds & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && (
                    day > dt.day || 
                    day == dt.day && (
                        hour > dt.hour || 
                        hour == dt.hour && (
                            minute > dt.minute || 
                            minute == dt.minute && 
                            second > dt.second))));
    }
    bool DTtimeds::operator >= (const DTtimeds & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && (
                    day > dt.day || 
                    day == dt.day && (
                        hour > dt.hour || 
                        hour == dt.hour && (
                            minute > dt.minute || 
                            minute == dt.minute && 
                            second >= dt.second))));
    }
    
    /*
    年月日时分秒毫yyyymmddhhmmss。
    */
    DTtimedsu::DTtimedsu()
        : year(2017), month(1), day(1)
        , hour(0), minute(0), second(0)
        , millisecond(0), microsecond(0)
    {
        type = dt_timedsu;
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
        int tmp_1, tmp_2, tmp_3, tmp_4, tmp_5, tmp_6, tmp_7, tmp_8;
        scanf("%d-%d-%d--%d:%d:%d.%d.%d", &tmp_1, &tmp_2, &tmp_3, &tmp_4, &tmp_5, &tmp_6, &tmp_7, &tmp_8);
        year = tmp_1;
        month = tmp_2;
        day = tmp_3;
        hour = tmp_4;
        minute = tmp_5;
        second = tmp_6;
        millisecond = tmp_7;
        microsecond = tmp_8;
        
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
    void DTtimedsu::write()
    {
        printf("%4d-%02d-%02d--%02d:%02d:%02d.%03d.%03d", (int)year, (int)month, (int)day, (int)hour, (int)minute, (int)second, (int)millisecond, (int)microsecond);
    }
    int DTtimedsu::get_size() const
    {
        return 11;
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
    }
    void DTtimedsu::set_month(char month_)
    {
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
    }
    void DTtimedsu::set_hour(char hour_)
    {
        hour = hour_;
        minute = 0;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= hour && hour <= 24);
    }
    void DTtimedsu::set_minute(char minute_)
    {
        minute = minute_;
        second = 0;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= minute && minute <= 59);
        assert(hour <= 23 || minute == 0);
    }
    void DTtimedsu::set_second(char second_)
    {
        second = second_;
        millisecond = 0;
        microsecond = 0;
        
        assert(0 <= second && second <= 59);
        assert(hour <= 23 || second == 0);
    }
    void DTtimedsu::set_hms(char hour_, char minute_, char second_)
    {
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
    void DTtimedsu::set_millisecond(short millisecond_)
    {
        millisecond = millisecond_;
        microsecond = 0;
        
        assert(0 <= millisecond && millisecond <= 999);
    }
    void DTtimedsu::set_microsecond(short microsecond_)
    {
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
    }
    
    bool DTtimedsu::operator == (const DTtimedsu & dt) const
    {
        return 
            year == dt.year && 
            month == dt.month && 
            day == dt.day && 
            hour == dt.hour && 
            minute == dt.minute && 
            second == dt.second &&
            millisecond == dt.millisecond &&
            microsecond == dt.microsecond;
    }
    bool DTtimedsu::operator != (const DTtimedsu & dt) const
    {
        return 
            year != dt.year || 
            month != dt.month || 
            day != dt.day || 
            hour != dt.hour || 
            minute != dt.minute || 
            second != dt.second ||
            millisecond != dt.millisecond ||
            microsecond != dt.microsecond;
    }
    bool DTtimedsu::operator < (const DTtimedsu & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && (
                    day < dt.day || 
                    day == dt.day && (
                        hour < dt.hour || 
                        hour == dt.hour && (
                            minute < dt.minute || 
                            minute == dt.minute && (
                                second < dt.second ||
                                second == dt.second && (
                                    millisecond < dt.millisecond ||
                                    millisecond == dt.millisecond &&
                                    microsecond < dt.microsecond))))));
    }
    bool DTtimedsu::operator <= (const DTtimedsu & dt) const
    {
        return 
            year < dt.year || 
            year == dt.year && (
                month < dt.month || 
                month == dt.month && (
                    day < dt.day || 
                    day == dt.day && (
                        hour < dt.hour || 
                        hour == dt.hour && (
                            minute < dt.minute || 
                            minute == dt.minute && (
                                second < dt.second ||
                                second == dt.second && (
                                    millisecond < dt.millisecond ||
                                    millisecond == dt.millisecond &&
                                    microsecond <= dt.microsecond))))));
    }
    bool DTtimedsu::operator > (const DTtimedsu & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && (
                    day > dt.day || 
                    day == dt.day && (
                        hour > dt.hour || 
                        hour == dt.hour && (
                            minute > dt.minute || 
                            minute == dt.minute && (
                                second > dt.second ||
                                second == dt.second && (
                                    millisecond > dt.millisecond ||
                                    millisecond == dt.millisecond &&
                                    microsecond > dt.microsecond))))));
    }
    bool DTtimedsu::operator >= (const DTtimedsu & dt) const
    {
        return 
            year > dt.year || 
            year == dt.year && (
                month > dt.month || 
                month == dt.month && (
                    day > dt.day || 
                    day == dt.day && (
                        hour > dt.hour || 
                        hour == dt.hour && (
                            minute > dt.minute || 
                            minute == dt.minute && (
                                second > dt.second ||
                                second == dt.second && (
                                    millisecond > dt.millisecond ||
                                    millisecond == dt.millisecond &&
                                    microsecond >= dt.microsecond))))));
    }
    
    
    
    
    
    
    
    
    
    
    
}
