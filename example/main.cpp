#include <iostream>
#include <Version/version.hpp>
#include <Property/Property.hpp>


class Project{
  Property::PropertiesContainer<std::string> properties {Version::version};

  void
  setProperty (Property::details::PropertyContainer<std::string> pc)
  {
    properties (pc);
  }

public:
  template <typename... t> Project (t... properties)
  {
    (setProperty (properties), ...);
  }

  void draw(){
    auto v = properties[Version::version];
    std::cout<<"Version : "<<v.getString()<<std::endl;
  }
};

int main(){
  Version::Version v = std::string{"100.0.1"};
  Version::Version vNext = v.getNextFix();

  if(v<vNext)
    std::cout<<"Great"<<std::endl;
  else
    std::cout<<"Not Great"<<std::endl;

  Project p{Version::version = { Version::major = 100, Version::minor = 0 }};
  p.draw();
  return 0;
}
