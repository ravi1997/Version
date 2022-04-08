#ifndef __VERSION_PROPERTY_C__
#define __VERSION_PROPERTY_C__

#include <Version/Property.hpp>

namespace Version {
Property::Property<unsigned int> major{"MAJOR",0};
Property::Property<unsigned int> minor{ "MINOR", 0 };
Property::Property<unsigned int> fix{ "FIX", 0 };
}

#endif // __VERSION_PROPERTY_C__