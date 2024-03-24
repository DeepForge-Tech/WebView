# WebView
A tiny cross-platform webview library for C/C++ to build modern cross-platform GUIs.

The goal of the project is to create a common HTML5 UI abstraction layer for the most widely used platforms.

It supports two-way JavaScript bindings (to call JavaScript from C/C++ and to call C/C++ from JavaScript).

## Platform Support

Platform | Technologies
-------- | ------------
Linux    | [GTK 3][gtk], [WebKitGTK][webkitgtk]
macOS    | Cocoa, [WebKit][webkit]
Windows  | [Windows API][win32-api], [WebView2][ms-webview2]