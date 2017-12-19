#ifndef BLACKBIRD_BINANCE_H
#define BLACKBIRD_BINANCE_H

#include "quote_t.h"

#include <string>

struct json_t;
struct Parameters;

namespace BINANCE {

quote_t getQuote(Parameters& params);

double getAvail(Parameters& params, std::string currency);

double getActivePos(Parameters& params);

double getLimitPrice(Parameters& params, double volume, bool isBid);

}

#endif //BLACKBIRD_BINANCE_H
