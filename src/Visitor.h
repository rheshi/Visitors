#ifndef VISITOR_H
#define VISITOR_H

#include <string>

/**
 * @brief Structure to represent time in hours and minutes.
 */
struct Time {
    int hour; /**< Hour value */
    int minute; /**< Minute value */
};

/**
 * @brief Class to represent a visitor with entering and leaving times.
 */
class Visitor {
public:
    /**
     * @brief Constructs a Visitor object.
     * @param enterTimeStr The entering time of the visitor in "hh:mm" format.
     * @param leaveTimeStr The leaving time of the visitor in "hh:mm" format.
     */
    Visitor(const std::string& enterTimeStr, const std::string& leaveTimeStr);

    /**
     * @brief Gets the entering time of the visitor.
     * @return The entering time as a Time structure.
     */
    Time getEnterTime() const;

    /**
     * @brief Gets the leaving time of the visitor.
     * @return The leaving time as a Time structure.
     */
    Time getLeaveTime() const;

private:
    Time enterTime; /**< Entering time of the visitor */
    Time leaveTime; /**< Leaving time of the visitor */
};

#endif // VISITOR_H
