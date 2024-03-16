# Algorithm for finding max the visitors active during period
1. Parse the input file line by line, extracting entering and leaving times for each visitor.
2. For each visitor, iterate through the time interval from their entering time to leaving time, incrementing a counter for each minute within that interval.
3. Maintain a global maximum count and corresponding start and end times.
4. After processing all visitors, return the start and end times corresponding to the maximum count.
