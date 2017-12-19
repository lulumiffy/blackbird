#include "binance.h"
#include "parameters.h"
#include "curl_fun.h"
#include "utils/restapi.h"
#include "unique_json.hpp"


namespace BINANCE {

std::string tickerMapping(const std::string& input){
    std::string data = input;
    // TODO
    return data;
}

static RestApi& queryHandle(Parameters &params)
{
    static RestApi query ("https://api.binance.com",
                          params.cacert.c_str(), *params.logFile);
    return query;
}

quote_t getQuote(Parameters &params)
{
    auto &exchange = queryHandle(params);
    std::string url("/api/v3/ticker/bookTicker?symbol=");
    url += (tickerMapping(params.leg1) + tickerMapping(params.leg2));
    unique_json root { exchange.getRequest(url) };
    const char *quote = json_string_value(json_object_get(json_array_get(json_object_get(root.get(), "bidPrice"), 0), "price"));
    auto bidValue = quote ? std::stod(quote) : 0.0;
    quote = json_string_value(json_object_get(json_array_get(json_object_get(root.get(), "askPrice"), 0), "price"));
    auto askValue = quote ? std::stod(quote) : 0.0;
    return std::make_pair(bidValue, askValue);
}

double getAvail(Parameters& params, std::string currency) {
    // TODO
    return 0.0;
}

double getActivePos(Parameters& params) {
    // TODO
    return 0.0;
}

double getLimitPrice(Parameters& params, double volume, bool isBid) {
    // TODO
    return 0.0;
}

}
