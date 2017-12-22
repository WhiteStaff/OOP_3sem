#include "exceptions.h"

FileNameError::FileNameError(std::string message) : exception(message.c_str()) {};

SectionNameError::SectionNameError(std::string message) : exception(message.c_str()) {};