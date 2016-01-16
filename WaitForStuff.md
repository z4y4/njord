WaitForStuff will wait for a single event to fire.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| Target   | DOMNode  | The node which has the event you want to wait for. |
| Event    | String   | The event you want to wait for. |
| Timeout (optional) | UInt32   | The amount of time that can elapse before giving up. |

If no timeout is specified, the function will wait forever. If the event is signaled, the function returns true. If the function fails or times out, the return value is false.