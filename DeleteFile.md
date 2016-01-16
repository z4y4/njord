DeleteFile encapsulates the native Win32 function [Delete File](http://msdn.microsoft.com/en-us/library/aa363915(VS.85).aspx). All arguments are the same.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| Path     | String   | Specifies the file to delete. |

## Return Value ##
If the function succeeds, the return value is true otherwise it is false. Call [GetLastError](GetLastError.md) to get extended error information.

## Remarks ##


If an application attempts to delete a file that does not exist, the DeleteFile function fails with ERROR\_FILE\_NOT\_FOUND. If the file is a read-only file, the function fails with ERROR\_ACCESS\_DENIED.

If you request delete permission at the time you create a file, you can delete or rename the file with that handle, but not with any other handle. For more information, see File Security and Access Rights.

The DeleteFile function fails if an application attempts to delete a file that is open for normal I/O or as a memory-mapped file.

The DeleteFile function marks a file for deletion on close. Therefore, the file deletion does not occur until the last handle to the file is closed. Subsequent calls to CreateFile to open the file fail with ERROR\_ACCESS\_DENIED.

Symbolic link behavior—

If the path points to a symbolic link, the symbolic link is deleted, not the target. To delete a target, you must call CreateFile and specify FILE\_FLAG\_DELETE\_ON\_CLOSE.