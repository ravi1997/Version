#ifndef __VERSION_PROPERTY_H__
#define __VERSION_PROPERTY_H__

#include <Property/Property.hpp>

namespace Version{
extern Property::Property<unsigned int> major;
extern Property::Property<unsigned int> minor;
extern Property::Property<unsigned int> fix;
}


#endif // __VERSION_PROPERTY_H__