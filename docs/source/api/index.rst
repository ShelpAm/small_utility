API
###

log
***

ProcessMessageInfo - process the message information
====================================================
void **ProcessMessageInfo**\ (char const \*log_format, char const \*content, Time const &time, LogLevel const log_level);

| **Parameters**
| *log_format*
|     Contains the format that the message would take with.
|     There are some built-in arguments. You can choose followings into your own log format:
|     $(content)
|     $(time)
|     $(log_level)
| *content*
|     Represents the message content you would present.
| *time*
|     Represents logging time.
| *log_level*
|     Represents the log level, which decides if the message should be logged.
