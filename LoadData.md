LoadData is the primary way of getting information into a browser. It takes a string that holds an HTML document or fragment and renders it. Calling LoadData will unregister any events registered previously.

## Parameters ##
| **Name** | **Type** | **Description** |
|:---------|:---------|:----------------|
| dataToLoad | String   | String to be loaded into the browser |
| baseURL  | String   | Base URL for the page being loaded, for resolving links and images |
| target   | String   | ID of the element that you want to register a DOM event on |
| action   | String   | The action you want to wait for (defaults to "click") |
| contentType | String   | The MIME type of the string being loaded (defaults to "text/html") |