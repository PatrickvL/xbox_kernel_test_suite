#pragma once

#include <excpt.h>
#include "util/output.h"

// Registry type constants not provided by nxdk
#ifndef REG_DWORD
#define REG_DWORD 4
#endif

#ifndef STATUS_CANCELLED
#define STATUS_CANCELLED ((NTSTATUS)0xC0000120L)
#endif

#ifndef DUPLICATE_CLOSE_SOURCE
#define DUPLICATE_CLOSE_SOURCE 0x00000001
#endif

#ifndef IRP_MJ_READ
#define IRP_MJ_READ 0x03
#endif

#ifndef IRP_MJ_WRITE
#define IRP_MJ_WRITE 0x04
#endif

#ifndef STATUS_SHARING_VIOLATION
#define STATUS_SHARING_VIOLATION ((NTSTATUS)0xC0000043L)
#endif

#ifndef STATUS_INVALID_DEVICE_REQUEST
#define STATUS_INVALID_DEVICE_REQUEST ((NTSTATUS)0xC0000010L)
#endif

// IRQL levels not provided by nxdk
#ifndef PROFILE_LEVEL
#define PROFILE_LEVEL 27
#endif
#ifndef HIGH_LEVEL
#define HIGH_LEVEL 31
#endif

// SLIST_ENTRY alias not provided by nxdk
#ifndef _SLIST_ENTRY_DEFINED
#define _SLIST_ENTRY_DEFINED
typedef SINGLE_LIST_ENTRY SLIST_ENTRY, *PSLIST_ENTRY;
#endif

// Kernel dispatcher object types not provided by nxdk
#ifndef _KOBJECTS_DEFINED
#define _KOBJECTS_DEFINED
typedef enum _KOBJECTS {
    EventNotificationObject = 0,
    EventSynchronizationObject = 1,
    MutantObject = 2,
    QueueObject = 4,
    SemaphoreObject = 5,
    ThreadObject = 6,
    TimerNotificationObject = 8,
    TimerSynchronizationObject = 9,
} KOBJECTS;
#endif

#define ASSERT_HEADER BOOL test_passed = 1;

#define ASSERT_FOOTER(test_name) \
    if(!test_passed) { \
        print("  Test '%s' FAILED", test_name); \
    } \
    return test_passed;

#define GEN_CHECK_EX(check_var, expected_var, varname, func_line) \
    if(check_var != expected_var) { \
        print( \
            ((sizeof(check_var) > 4) ? \
            "  ERROR(line %d): Expected %s = 0x%llx, Got = 0x%llx" : \
            "  ERROR(line %d): Expected %s = 0x%x, Got = 0x%x") \
            , func_line, varname, expected_var, check_var \
        ); \
        TEST_FAILED(); \
    }
#define GEN_CHECK(check_var, expected_var, varname) GEN_CHECK_EX(check_var, expected_var, varname, __LINE__)

#define GEN_CHECK_RANGE_EX(check_var, expected_var, size, varname, func_line) \
    if(check_var < expected_var || check_var > expected_var + size) { \
        print( \
            ((sizeof(check_var) > 4) ? \
            "  ERROR(line %d): Expected range %s = 0x%x-0x%llx, Got = 0x%llx" : \
            "  ERROR(line %d): Expected range %s = 0x%x-0x%x, Got = 0x%x") \
            , func_line, varname, expected_var, expected_var + size, check_var \
        ); \
        TEST_FAILED(); \
    }
#define GEN_CHECK_RANGE(check_var, expected_var, size, varname) GEN_CHECK_RANGE_EX(check_var, expected_var, size, varname, __LINE__)

#define GEN_CHECK_ARRAY_EX(check_var, expected_var, size, varname, func_line) \
    for (unsigned i = 0; i < size; i++) { \
        if (check_var[i] != expected_var[i]) { \
            print( \
                ((sizeof(check_var[i]) > 4) ? \
                "  ERROR(line %d): Expected array %s[%u] = 0x%llx, Got = 0x%llx" : \
                "  ERROR(line %d): Expected array %s[%u] = 0x%x, Got = 0x%x") \
                , func_line, varname, i, expected_var[i], check_var[i] \
            ); \
            TEST_FAILED(); \
        } \
    }
#define GEN_CHECK_ARRAY(check_var, expected_var, size, varname) GEN_CHECK_ARRAY_EX(check_var, expected_var, size, varname, __LINE__)

#define GEN_CHECK_ARRAY_MEMBER_EX(var, m_check, m_expected, size, varname, func_line) \
    for (unsigned i = 0; i < size; i++) { \
        if (var[i].m_check != var[i].m_expected) { \
            print( \
                ((sizeof(var[i].m_check) > 4) ? \
                "  ERROR(line %d): Expected array %s[%u].%s = 0x%llx, Got %s[%u].%s = 0x%llx" : \
                "  ERROR(line %d): Expected array %s[%u].%s = 0x%x, Got %s[%u].%s = 0x%x") \
                , func_line, varname, i, #m_expected, var[i].m_expected, varname, i, #m_check, var[i].m_check \
            ); \
            TEST_FAILED(); \
        } \
    }
#define GEN_CHECK_ARRAY_MEMBER(var, m_check, m_expected, size, varname) GEN_CHECK_ARRAY_MEMBER_EX(var, m_check, m_expected, size, varname, __LINE__)
