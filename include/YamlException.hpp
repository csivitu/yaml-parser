#pragma once

#include <iostream>

namespace YamlParser
{
    class InputSubSystemException : public std::exception
    {
    public:
        const char *what() const noexcept override
        {
            return "Provide more details to the exception";
        }
    };

    class YamlNodeScalarChildError : public std::exception
    {
    public:
        const char *what() const noexcept override
        {
            return "Type SCALAR Cannot have Children";
        }
    };

    class ScalarNodeAssignmentError : public std::exception
    {
    public:
        const char *what() const noexcept override
        {
            return "Type SCALAR Cannot have Children";
        }
    };

    class VectorNodeAssignmentError : public std::exception
    {
    public:
        const char *what() const noexcept override
        {
            return "Type VECTOR Cannot be assigned";
        }
    };
    class MapNodeAssignmentError : public std::exception
    {
    public:
        const char *what() const noexcept override
        {
            return "Type MAP Cannot be assigned";
        }
    };

} // namespace YamlParser
