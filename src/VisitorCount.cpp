#include "VisitorCounter.h"
#include <iostream>
VisitorCounter::VisitorCounter() {}

void VisitorCounter::addVisitor(const std::string& enterTimeStr, const std::string& leaveTimeStr) {
    Visitor visitor(enterTimeStr, leaveTimeStr);
    visitors.push_back(visitor);
    updateVisitorCounts(visitor);
}

void VisitorCounter::updateVisitorCounts(const Visitor& visitor) {
    for (int hour = visitor.getEnterTime().hour; hour <= visitor.getLeaveTime().hour; ++hour) {
        for (int minute = 0; minute < 60; ++minute) {
            if ((hour > visitor.getEnterTime().hour || (hour == visitor.getEnterTime().hour && minute >= visitor.getEnterTime().minute)) &&
                (hour < visitor.getLeaveTime().hour || (hour == visitor.getLeaveTime().hour && minute <= visitor.getLeaveTime().minute))) {
                std::string timeStr = std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute);
                visitorCounts[timeStr]++;
            }
        }
    }
}

std::pair<std::pair<std::string, std::string>, int> VisitorCounter::findMaxVisitorPeriod() const{
    int maxVisitors = 0;
    std::string startTime, endTime;

    for (auto it = visitorCounts.begin(); it != visitorCounts.end(); ++it) {
        if (it->second > maxVisitors) {
            maxVisitors = it->second;
            startTime = it->first;
            endTime = it->first;
        }
        else if (it->second == maxVisitors) {
            endTime = it->first;
        }
    }
    auto result = std::make_pair(std::make_pair(startTime, endTime), maxVisitors);

    return result;
}
