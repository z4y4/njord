QueryServiceStatus will return the current state of a service. It takes one argument, the name of the service, and returns either its state as a UInt32 or false on failure. Call [GetLastError](GetLastError.md) for more information about the error.