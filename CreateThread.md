CreateThread will take a JavaScript function and execute it in its own thread. It takes one argument, the function to execute, and will return nothing. Under the hood, this function uses the same mechanism as [Eval](Eval.md), except that it will only execute in a separate thread and accepts a function instead of a string. As in [Eval](Eval.md), the new thread shares the same global object as the caller and will thus share all the variables that are in the global scope.