/***************************************************************************
  *   Copyright (C) 2019  by Andreas Langhoff
  *                                          <andreas.langhoff@frm2.tum.de> *
  *   This program is free software; you can redistribute it and/or modify  *
  *   it under the terms of the GNU General Public License v3 as published  *
  *   by the Free Software Foundation;                                      *
  ***************************************************************************/

#ifndef simpleLogger_hpp__
#define simpleLogger_hpp__
#pragma once
#include <boost/iostreams/device/file_descriptor.hpp>


//#define BOOST_LOG_DYN_LINK // necessary when linking the boost_log library dynamically
#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>



#include "stdafx.h"
#include <boost/log/core/core.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sinks/auto_newline_mode.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <fstream>
#include <ostream>
#ifdef WIN32_PRE10OLDSTYLE
#include "coloured_console_sink.h"
#endif
#ifdef __cpp_lib_string_view
#include "magic_enum/include/magic_enum.hpp"


template<typename E,magic_enum::Enum<E>>
inline boost::log::BOOST_LOG_VERSION_NAMESPACE::basic_record_ostream<char>& operator<<(boost::log::BOOST_LOG_VERSION_NAMESPACE::basic_record_ostream<char>& p, E& e) {
    std::stringstream ss;
    e.print(ss);
    p << ss.str();
    return p;
}



namespace magic_enum {



    namespace ostream_operators {

        template <typename E>
        inline boost::log::formatting_ostream&  operator<<(boost::log::formatting_ostream& os, E value)  {
            if (auto name = enum_name(value); !name.empty()) {
                for (auto c : name) {
                    os.put(c);
                }
            }
            else {
                os << enum_integer(value);
            }

            return os;
        }

        template  <typename E>
        inline boost::log::formatting_ostream&  operator<<(boost::log::formatting_ostream& os, std::optional<E> value) {
            if (value.has_value()) {
                os << value.value();
            }

            return os;
        }

    } // namespace magic_enum::ostream_operators
}
#else
#pragma message("magic_enum excluded:  C++ 17 not found")
#endif
// just log messages with severity >= SEVERITY_THRESHOLD are written
extern EXTERN_FUNCDECLTYPE boost::log::trivial::severity_level SEVERITY_THRESHOLD;

// register a global logger
BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>)


// just a helper macro used by the macros below - don't use it in your code
#define LOG(severity) BOOST_LOG_SEV(logger::get(),boost::log::trivial::severity)

// ===== log macros =====
#define LOG_DEBUG   LOG(debug)
#define LOG_INFO    LOG(info)
#define LOG_WARNING LOG(warning)
#define LOG_ERROR   LOG(error)


namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", logging::trivial::severity_level)


void coloring_formatter( logging::record_view const& rec, logging::formatting_ostream& strm);
namespace Zweistein
{

    namespace Logger {
        void Add_File_Sink(std::string logfile);
    }
}



#endif



