#ifndef VISITORCOUNTER_H
#define VISITORCOUNTER_H

#include "Visitor.h"
#include <unordered_map>
#include <string>
#include <vector>

/**
 * @brief Class to count visitors and find the time period with the most number of visitors.
 */
class VisitorCounter {
public:
    /**
     * @brief Constructs a VisitorCounter object.
     */
    VisitorCounter();

    /**
     * @brief Adds a visitor to the count.
     * @param enterTimeStr The entering time of the visitor in "hh:mm" format.
     * @param leaveTimeStr The leaving time of the visitor in "hh:mm" format.
     */
    void addVisitor(const std::string& enterTimeStr, const std::string& leaveTimeStr);

    /**
     * @brief Finds the time period with the most number of visitors.
     * @return A pair representing the time period with the most visitors (start time, end time and visitor count).
     */
    std::pair<std::pair<std::string, std::string>, int> findMaxVisitorPeriod() const;

private:
    std::unordered_map<std::string, int> visitorCounts; /**< Map to store visitor counts for each minute */
    std::vector<Visitor> visitors; /**< vector to store visitors */
    /**
     * @brief Updates the visitor counts for each minute between enter and leave time.
     * @param visitor The visitor to be counted.
     */
    void updateVisitorCounts(const Visitor& visitor);
};

#endif // VISITORCOUNTER_H
