#ifndef SEND_EMAIL_H
#define SEND_EMAIL_H

struct Result;
struct Parameters;
struct VenueSpread;

void sendEmail(const std::vector<VenueSpread>& spreads, Parameters &params);

// After a trade is done, sends an email with the details
// of the results.
// The email credentials are in the configuration file.
void sendEmail(const Result &res, Parameters &params);

#endif
