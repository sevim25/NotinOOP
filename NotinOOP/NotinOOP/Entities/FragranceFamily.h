#pragma once
#include <string>

enum class FragranceFamily {
    FLORAL,
    WOODY,
    FRESH,
    ORIENTAL,
    UNKNOWN
};

inline std::string toString(FragranceFamily f) {
    switch (f) {
    case FragranceFamily::FLORAL:   return "FLORAL";
    case FragranceFamily::WOODY:    return "WOODY";
    case FragranceFamily::FRESH:    return "FRESH";
    case FragranceFamily::ORIENTAL: return "ORIENTAL";
    default:
        return "UNKNOWN";
    }
};

inline FragranceFamily fromString(const std::string& s) {
    if (s == "FLORAL") {
        return FragranceFamily::FLORAL;
    }
    else if (s == "WOODY") {
        return FragranceFamily::WOODY;
    }
    else if (s == "FRESH") {
        return FragranceFamily::FRESH;
    }
    else if (s == "ORIENTAL") {
        return FragranceFamily::ORIENTAL;
    }

    return FragranceFamily::UNKNOWN;
};