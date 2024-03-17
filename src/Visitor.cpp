#include "Visitor.h"
#include <cstdlib>

Visitor::Visitor(const std::string& enterTimeStr, const std::string& leaveTimeStr) {
    sscanf_s(enterTimeStr.c_str(), "%d:%d", &enterTime.hour, &enterTime.minute);
    sscanf_s(leaveTimeStr.c_str(), "%d:%d", &leaveTime.hour, &leaveTime.minute);
}

Time Visitor::getEnterTime() const {
    return enterTime;
}

Time Visitor::getLeaveTime() const {
    return leaveTime;
}
