#ifndef MILITO_CPP_COMMONDECKS_H
#define MILITO_CPP_COMMONDECKS_H

#include <yaml-cpp/yaml.h>

const UnitCard light_cavalry {
        "Light_Cavalry",
        5,
        1,
        1,
};

const UnitCard slingers{
        "Slingers",
        3,
        1,
        1,
        true,
};


void xyz() {
    YAML::Node node = YAML::Load("{pi: 3.14159, [0, 1]: integers}");
    auto pi = node["pi"].as<double>();

    printf("%f", pi);

}

#endif //MILITO_CPP_COMMONDECKS_H
