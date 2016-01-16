SetDllDirectory will add to the search path for windows to locate DLLs. This can be useful if you are loading nJord extensions which require their own support libraries, and you don't want to put all the libraries in one folder. For more information about this function, see the MSDN documentation on [SetDllDirectory](http://msdn.microsoft.com/en-us/library/ms686203(VS.85).aspx)

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| Path     | String   | Specifies the path to add to the search paths. |

## Return value ##
The function will return true or false for success and failure respectively, call [GetLastError](GetLastError.md) for more information.