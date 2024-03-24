#include <iostream>
#include <webview.h>

int main() {
  try {
    webview::webview w(false, nullptr);
    w.set_title("Navigation");
    w.set_size(1080, 720, WEBVIEW_HINT_NONE);
    // w.set_html("Thanks for using webview!");
    w.navigate("https://google.com");
    w.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}