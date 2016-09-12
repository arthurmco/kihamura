#include "Media.hpp"

Media::Media(const char* name)
{
    this->_name = std::string{name};
}

const char* Media::GetName() const
{
    return _name.c_str();
}

void Media::SetName(char* name)
{
    _name = name;
}
