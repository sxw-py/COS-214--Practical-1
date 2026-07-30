#include "TransformationRegistry.h"
#include "Transformation.h"
#include <iostream>
#include <vector>

int main(){
    TransformationRegistry registry;

    // register prototypes
    registry.registerStep("dedup", new DeduplicateStep("dedup"));
    registry.registerStep("agg", new AggregateByRegionStep("agg"));

    // create a deduplicate instance and test
    Transformation* t = registry.create("dedup");
    if (t){
        std::cout << "Created: " << t->getName() << "\n";
        std::vector<std::string> v {"a","a","b","b","b","c","c"};
        auto out = t->apply(v);
        std::cout << "apply(dedup):";
        for (auto &s : out) std::cout << ' ' << s;
        std::cout << "\n";

        // clone test
        Transformation* t2 = t->clone();
        std::cout << "Cloned name: " << t2->getName() << "\n";
        delete t2;
        delete t; // created by registry->clone()
    } else {
        std::cout << "Failed to create dedup\n";
    }

    // missing key
    Transformation* missing = registry.create("missing");
    std::cout << "create(missing) -> " << (missing ? "not-null" : "null") << "\n";
    if (missing) delete missing;

    // replace prototype and ensure it is used
    registry.registerStep("dedup", new DeduplicateStep("dedup2"));
    Transformation* t3 = registry.create("dedup");
    std::cout << "After replace, created: " << (t3 ? t3->getName() : "null") << "\n";
    if (t3){
        auto out2 = t3->apply(std::vector<std::string>{"x","x","y"});
        std::cout << "apply(dedup2):";
        for (auto &s : out2) std::cout << ' ' << s;
        std::cout << "\n";
        delete t3;
    }

    // aggregate prototype
    Transformation* agg = registry.create("agg");
    if (agg){
        std::cout << "Created agg: " << agg->getName() << "\n";
        auto r = agg->apply(std::vector<std::string>{"a","b"});
        std::cout << "apply(agg):";
        for (auto &s : r) std::cout << ' ' << s;
        std::cout << "\n";
        delete agg;
    }

    std::cout << "Test complete\n";
    return 0;
}
