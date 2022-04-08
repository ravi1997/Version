#ifndef __VERSION_C__
#define __VERSION_C__

#include <Version/Version.hpp>

namespace Version{
  Property::Property<Version> version{"VERSION",Version{major=0,minor=2,fix=0}};
auto split
    = [] (std::string s, std::string delimiter) -> std::vector<std::string> {
  using namespace std;
  size_t pos_start = 0, pos_end, delim_len = delimiter.length ();
  string token;
  vector<string> res;

  while ((pos_end = s.find (delimiter, pos_start)) != string::npos)
    {
      token = s.substr (pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back (token);
    }

  res.push_back (s.substr (pos_start));
  return res;
};


Version::Version(const Version& v):
    properties{v.properties}
{}


Version::Version(std::string sv){

  auto vals = split(sv,".");
  setProperty(major = std::stoul(vals[0]));
  setProperty (minor = std::stoul (vals[1]));
  setProperty (fix = std::stoul (vals[2]));
}

Version& Version::operator=(const Version& v){
    properties = v.properties;
    return *this;
}

Version& Version::operator=(std::string sv){
    auto vals = split(sv,".");

    setProperty (major = std::stoul (vals[0]));
    setProperty (minor = std::stoul (vals[1]));
    setProperty (fix = std::stoul (vals[2]));
    return *this;
}

Version::VersionType Version::getMajor (){
  return properties[major];
}
Version::VersionType Version::getMinor (){
  return properties[minor];
}
Version::VersionType Version::getFix (){
  return properties[fix];
}

std::string Version::getString (){
    using namespace std;
    return string{} + to_string(getMajor()) + "." + to_string(getMinor()) + "." + to_string(getFix());
}

Version Version::getNextFix (){
    return Version{major=getMajor(),minor=getMinor(),fix=getFix()+1};
}
Version Version::getNextMinor (){
  return Version{ major = getMajor (), minor = getMinor ()+1,
                  fix = 0 };
}
Version Version::getNextMajor (){
  return Version{ major = getMajor () +1 , minor = 0, fix = 0 };
}

        bool Version::operator== (Version & v){
          return (properties[major] == v.properties[major] && properties[minor] == v.properties[minor] && properties[fix] == v.properties[fix]);
        }

        bool Version::operator!=( Version&v){
          return !(*this==v);
        }

        bool Version::operator>=( Version&v){
          return (*this==v) || (*this > v);
        }
        bool Version::operator<=( Version&v){
          return (*this==v) || (*this<v);
        }
        bool Version::operator< ( Version &v){
          return (properties[major]<v.properties[major] || properties[minor]<v.properties[minor] || properties[fix]<v.properties[fix]);
        }
        bool Version::operator> ( Version & v){
          return (properties[major]>v.properties[major] || properties[minor]>v.properties[minor] || properties[fix]>v.properties[fix]);
        }

}



#endif // __VERSION_C__