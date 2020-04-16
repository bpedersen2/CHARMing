
#pragma once
#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/sinks/auto_newline_mode.hpp>

#ifdef WIN32_PRE10OLDSTYLE
class coloured_console_sink : public boost::log::sinks::basic_formatted_sink_backend<char, boost::log::sinks::synchronized_feeding>
{
public:
    static void consume(boost::log::record_view const& rec, string_type const& formatted_string);

    static boost::log::sinks::auto_newline_mode auto_newline;
    void set_auto_newline_mode(boost::log::sinks::auto_newline_mode mode);
};

#include <iostream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#ifdef ERROR 
#undef ERROR
#endif


#include <boost/log/trivial.hpp>
#include <boost/log/attributes/value_extraction.hpp>
#include <boost/log/attributes/attribute_value.hpp>

WORD get_colour(boost::log::trivial::severity_level level);

#endif




