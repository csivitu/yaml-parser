#pragma once

#include <iostream>
#include <exception>

namespace YamlParser
{

    class YamlException: virtual public std::exception {
    
protected:

  
    std::string error_message;      ///< Error message
    
public:

    /** Constructor (C++ STL string, int, int).
     *  @param msg The error message
    
     */
    explicit 
    YamlException(const std::string& msg):
       error_message(msg)
        {}

    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~YamlException() throw () {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *  is in possession of the YamlException object. Callers must
     *  not attempt to free the memory.
     */
    virtual const char* what() const throw () {
       return error_message.c_str();
    }

};

} // namespace YamlParser
