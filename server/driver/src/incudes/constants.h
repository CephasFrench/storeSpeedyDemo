#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

inline std::string currentLocation = "DefaultLoc";
inline const std::string storagePath = "/Users/cameronhardin/Desktop/storeSpeedyPOC/backEnd/server/storage/";

inline const int COMPUTE_PATH_MAX_RETRIES = 1;
inline const int COMPUTE_PATH_TIMEOUT_DURATION = 15000;  // milliseconds
inline const int UPDATE_AISLE_DATA_MAX_RETRIES = 3;
inline const int UPDATE_AISLE_DATA_TIMEOUT_DURATION = 5000;  // milliseconds
inline const int UPDATE_LOCATION_MAX_RETRIES = 3;
inline const int UPDATE_LOCATION_TIMEOUT_DURATION = 5000;  // milliseconds
inline const int GROCERY_LIST_MAX_RETRIES = 3;
inline const int GROCERY_LIST_TIMEOUT_DURATION = 5000;  // milliseconds
inline const int UPDATE_GROCERY_LIST_MAX_RETRIES = 5;  // Should nearly always work but this is a buffer jic
inline const int UPDATE_GROCERY_LIST_TIMEOUT_DURATION = 5000;  // Should communicate pretty quickly, but again a buffer
inline const int CHECK_ITEM_MAX_RETRIES = 3;
inline const int CHECK_ITEM_TIMEOUT_DURATION = 4000;  // Should take no more than 4 seconds

#endif // CONSTANTS_H
