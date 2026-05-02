#ifndef DBSTATUS_H
#define DBSTATUS_H

enum class DBStatus {
    OK,
    FileNotFound,
    PermissionDenied,
    InvalidFormat,
    ReadError,
    WriteError,
    AlreadyExists
};

#endif
