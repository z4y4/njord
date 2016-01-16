RegisterHotKey will register a hotkey with the hotkey thread and create the hotkey thread if necessary.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| Keycode  | String   | The character you want to register as a hotkey. Only the first character in the string passed will be used. |
| Flags    | UInt16   | Flags that specify whether control, alt, and/or shift should be held down before firing this keycode. |
| Function | String   | The name of the JavaScript function to call when the hotkey is fired. |

## Return code ##
If the function succeeds, it will return the id number of the hotkey that was registered. Otherwise, it will return false.

## Remarks ##
This function is synchronous, in that it won't return until the hotkey thread has actually registered the hotkey. The numeric value of the hotkey can be passed to [UnregisterHotKey](UnregisterHotKey.md).