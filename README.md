This is `pybtswitch`, a Python for S60 extension for
turning Bluetooth ON and OFF. This is useful as the
Bluetooth stack cannot be used unless Bluetooth has
been turned ON.

Note that this extension relies on an S60 SDK plugin
API, and is for this reason kept as a separate library,
as it is not buildable unless the SDK plugin has been
installed, and it may also not be compatible with
any given device.

