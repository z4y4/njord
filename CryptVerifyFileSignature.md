CryptVerifyFileSignature will verify the signature produced by a call to [CryptSignFile](CryptSignFile.md).

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| FileName | String   | The path to the file to verify the signature for |
| SignedHash | String   | The encoded signature to verify |
| UseSHA   | Boolean  | Whether the function should hash the file using SHA, otherwise MD5 is used |
| CertPath | String   | The path to the certificate whose private key was used to produce the signature |

## Return Value ##
If there were no errors and the signature matches the file, the function returns true; otherwise it returns false. Information about any errors can be retreived with [GetLastError](GetLastError.md).

## Remarks ##
Only the first two parameters are required. The function is designed so it can not only check signatures, but can also check hashes. If you wanted to verify an MD5 hash of a file with no certificate, you could call CryptVerifySignature("path to file", "thehash"). Depending on whether a certificate is passed, the function will attempt to convert the signedhash parameter from hexadecimal and base-64 encoding respectively. As with [CryptSignFile](CryptSignFile.md), the function reads the file to verify in 4kb at a time and adds it to the hash. The function uses the Windows Cryptography API and has no dependencies.