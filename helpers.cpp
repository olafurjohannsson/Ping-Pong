

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <sstream>

class Helper {

public:
template <typename T> static std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

static const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}



};

#endif
