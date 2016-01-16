Eval will take an arbitrary string and run it as JavaScript code, optionally in another thread.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| theScript | String   | The code to evaluate |
| async    | Boolean  | Whether to run in a separate thread (defaults to false) |

## Return Value ##
If the script is evaluated asyncronously, this function will return nothing. Otherwise it will return the value return value of the script evaluated. If the script doesn't return a value, it will return nothing.

## Remarks ##
The function will evaluate a string as code in the same global object as the caller but in a separate context if called asynchronously. In both asynchronous and synchronous mode, the evaluated code will share all the variables with the calling context.