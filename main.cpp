#include "MetalTranslate.h"

int main() {
  MetalTranslate::MetalTranslateConfig config;

  MetalTranslate::MetalTranslate translate(config);

  std::string result =
      translate.Translate("Translating text with MetalTranslate", "en", "es");

  std::cout << "Result: " << result << std::endl;

  return 0;
}
