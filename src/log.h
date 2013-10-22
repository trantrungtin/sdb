/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __LOG_H
#define __LOG_H

#define  SDB_TRACE    1
#define  DEBUG_ENV       "SDB_DEBUG"
extern int loglevel_mask;

typedef enum {
    SDBLOG_FATAL = 1,
    SDBLOG_ERROR,
    SDBLOG_DEBUG,
    SDBLOG_INFO,
    SDBLOG_FIXME
} LogLevel;

#define LOG_FATAL(args...) \
        do { \
            logging(SDBLOG_FATAL, __FILE__, __FUNCTION__, __LINE__, args);\
            exit(255);} while(0)

#define LOG_ASSERT(cond)  do { if (!(cond)) LOG_FATAL( "assertion failed '%s'\n", #cond); } while (0)


#define LOG_ERROR(args...) \
        do { if ((loglevel_mask & (1 << SDBLOG_ERROR)) != 0) { \
            logging(SDBLOG_ERROR, __FILE__, __FUNCTION__, __LINE__, args); } } while(0)

#define LOG_DEBUG(args...) \
        do { if ((loglevel_mask & (1 << SDBLOG_DEBUG)) != 0) { \
            logging(SDBLOG_DEBUG, __FILE__, __FUNCTION__, __LINE__, args); } } while(0)

#define LOG_INFO(args...) \
        do { if ((loglevel_mask & (1 << SDBLOG_INFO)) != 0) { \
            logging(SDBLOG_INFO, __FILE__, __FUNCTION__, __LINE__, args); } } while(0)

#define LOG_FIXME(args...) \
        do { if ((loglevel_mask & (1 << SDBLOG_FIXME)) != 0) { \
            logging(SDBLOG_FIXME, __FILE__, __FUNCTION__, __LINE__, args); } } while(0)

void log_init(void);
void logging(LogLevel level, const char *filename, const char *funcname, int line_number, const char *fmt, ...);

// define for a while for testing
#undef D
#define D LOG_DEBUG
#undef DR
#define DR LOG_DEBUG
#define SDB_TRACING  ((loglevel_mask & (1 << SDBLOG_DEBUG)) != 0)

#endif