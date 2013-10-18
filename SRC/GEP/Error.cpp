////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Error.h"
#include <iostream>
#include <cstdlib>

namespace GEP
{
////////////////////////////////////////////////////////////
void Error::FatalError(std::string msg)
{
    std::cerr<<"Error :: "<<msg<<std::endl;
    exit(EXIT_FAILURE);
}

} // namespace GEP