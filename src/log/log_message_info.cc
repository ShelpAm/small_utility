#include "log/log_message_info.h"

#include <map>
#include <sstream>

#include "utility/small_utility.h"
#include "time/time.h"

namespace small_utility {

namespace log_stuff {

LogMessageInfo::LogMessageInfo(
      char const *log_format, char const *content, char const*file_name,
      int const line, char const *function_name, time_stuff::time const &t,
      LogLevel const log_level) {
  ProcessMessageInfo(log_format, content, file_name, line, function_name, t,
                     log_level);
}

void LogMessageInfo::ProcessMessageInfo(
      char const *log_format, char const *content, char const*file_name,
      int const line, char const *function_name, time_stuff::time const &t,
      LogLevel const log_level) {
  string_stuff::string log_format_string(log_format);
  std::stringstream terminal_string_stream, argument_name_string_stream;
  std::map<char const *, string_stuff::string> format_map;
  // convert t, log_level to strings.
  format_map.insert(std::make_pair("content", content));
  //format_map.insert(std::make_pair("line", string(line)));
  format_map.insert(std::make_pair("function_name", function_name));
  time_stuff::time temp_time = t;
  temp_time.set_to_current_time();
  //format_map.insert(mkpair("time", temp_time.to_string(
  //          "$(year)-$(month)-$(day) $(hour):$(minute):$(second)")));
  //format_map.insert(mkpair("log_level", log_level.to_string());
  bool argument_flag = false;
  for (int i = 0; i != log_format_string.size(); ++i) {
    if (argument_flag) {
      if (unequal(log_format_string[i], ')')) {
        argument_name_string_stream << log_format_string[i];
      } else {
        // search for the value of key, argument_name_string_stream.
        auto it = format_map.find(argument_name_string_stream.str().c_str());
        terminal_string_stream <<
          (equal(it, format_map.end()) ? "" : (*it).second.c_string());
        argument_name_string_stream.str("");
        argument_flag = false;
      }
      continue;
    }
    if (equal(log_format_string.sub_string_length(i, 2), "$(")) {
      argument_flag = true;
      ++i;
    } else if (equal(log_format_string[i], '\\')) {
      terminal_string_stream << log_format_string[i + 1];
      ++i;
    } else {
      terminal_string_stream << log_format_string[i];
    }
  }
  message_ = terminal_string_stream.str().c_str();
}

}

}
