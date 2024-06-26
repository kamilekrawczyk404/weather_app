//
// Created by Kamil Krawczyk on 25/04/2024.
//

#include "Location.h"

Location::Location(std::string& name) {
    // replace any spaces with "+"
    for(char& c : name) {
        if (c == ' ') {
            c = '+';
        }
    }
    this->name = name;
    
    FetchAPI api(getUrl());

    if (!api.errorMessage.empty()) {
        this->errorMessage = api.errorMessage;
    } else {
        // assign coordinates for a location
        this->lat = api.fetchedData["results"][0]["geometry"]["location"]["lat"].get<double>();
        this->lon = api.fetchedData["results"][0]["geometry"]["location"]["lng"].get<double>();
        this->fullLocationName = api.fetchedData["results"][0]["address_components"][0]["long_name"].get<std::string>();
    }
    
    
}

std::string Location::getUrl() {
    std::string url = "https://maps.googleapis.com/maps/api/geocode/json?address=" + this->name + "&key=" + GOOGLE_API_KEY;
    
    return url;
}

bool Location::isOk() {
    return this->errorMessage.empty();
}
