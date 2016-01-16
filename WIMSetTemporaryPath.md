SetTemporaryPath will set a path that the WIMG engine can use to store temporary files during image creation and loading. During capture, it's used to store files as they are compressed and to serialize metadata. During application it's used to store metadata as it is deserialized. The path should be writeable by the calling process and have generous free space. The function will return true or false for success and failure, [GetLastError](GetLastError.md) can return extended error information.