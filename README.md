This is `pybtswitch`, a Python for S60 extension for turning Bluetooth
ON and OFF. This is useful as the Bluetooth stack cannot be used
unless Bluetooth has been turned ON.

Only PyS60 1.4.x series is supported by this extension.

Note that this extension relies on an S60 SDK plugin API, and is for
this reason kept as a separate library, as it is not buildable unless
the SDK plugin has been installed.

The extension may also not be binary compatible with just any given
device. The `module.pkg.in` file in the source code lists some of the
devices that have been confirmed to be compatible.

And yes, there used to be a Python for S60 extension named `btswitch`
with the same functionality, but the source code for that one no
longer seems to be easy to come by.
