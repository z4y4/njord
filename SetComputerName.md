SetComputerName will update the NetBIOS/DNS hostname for the local computer, it encapsulates [SetComputerNameEx](http://msdn.microsoft.com/en-us/library/ms724931%28VS.85%29.aspx) from the Windows C API.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| NewName  | String   | The new name you want to assign to the computer, it must be a valid hostname. |
| Type     | UInt32   | Flags to control how the name is set |

## Return Value ##
If the function succeeds, it will return true, otherwise false. For more information about errors call [GetLastError](GetLastError.md).

## Remarks ##
The function will accept the following flags.

| **Name** | **Description** |
|:---------|:----------------|
| ComputerNamePhysicalDnsDomain | Changes the DNS domain name |
| ComputerNamePhysicalDnsHostname | Changes the DNS host name |
| ComputerNamePhysicalNetBIOS | Changes the NetBIOS host name |

The type parameter is an enumeration, not a bitmask; only one value can be supplied in a single call. Even after calling this function, the active computer name may not be set properly for purposes of joining a domain.