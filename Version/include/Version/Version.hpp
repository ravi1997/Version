#ifndef __VERSION_H__
#define __VERSION_H__

#include <Version/types.hpp>
#include <Version/Property.hpp>

namespace Version{

    class Version{
        public:
            using VersionType = unsigned int;
        private:
        Property::PropertiesContainer<std::string> properties{ major,
                                                               minor,
                                                               fix };

        void
        setProperty (Property::details::PropertyContainer<std::string> pc)
        {
          properties (pc);
        }

      public:
        template <typename... t> Version (t... properties) 
        {
          (setProperty (properties), ...);
        }
        Version(const Version&);
        Version(std::string);
        Version& operator=(const Version&);
        Version& operator=(std::string);


        VersionType getMajor ();
        VersionType getMinor();
        VersionType getFix ();

        std::string getString();

        Version getNextFix();
        Version getNextMinor();
        Version getNextMajor();

        bool operator== ( Version &);
        bool operator!=( Version&);
        bool operator>=( Version&);
        bool operator<=( Version&);
        bool operator< ( Version &);
        bool operator> ( Version &);

        static Version get(auto value){
          if constexpr (std::is_same_v<decltype(value),std::string>)
            return Version{value};
          else
            return {};
        }

    };

    extern Property::Property<Version> version;
}


#endif // __VERSION_H__