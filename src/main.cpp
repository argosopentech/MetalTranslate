#include "MetalTranslate.h"

#include <iostream>
#include <string>

void help() {
  std::cout << "Usage: metaltranslate <text> <source code> <target code>\n"
            << "Example: metaltranslate \"my text to translate\" en es\n";
}

int main(int argc, char **argv) {
  MetalTranslate::MetalTranslateConfig config;

  MetalTranslate::MetalTranslate metalTranslate(config);

  if (argc < 2) {
    help();
    return 1;
  }

  std::string q(argv[1]);

  std::string sourceCode = "en";
  if (argc > 2) {
    sourceCode = std::string(argv[2]);
  }

  std::string targetCode = "es";
  if (argc > 3) {
    sourceCode = std::string(argv[3]);
  }

  std::string result = metalTranslate.Translate(q, sourceCode, targetCode);

  std::cout << result << std::endl;

  return 0;
}
