#include <iostream>
#include <ctranslate2/translator_pool.h>

int main() {
  const size_t num_translators = 1;
  const size_t num_threads_per_translator = 4;
  ctranslate2::TranslatorPool translator(num_translators,
                                         num_threads_per_translator,
                                         "models/test/",
                                         ctranslate2::Device::CPU);

  const std::vector<std::vector<std::string>> batch = {{"▁H", "ello", "▁world", "!"}};
  const std::vector<ctranslate2::TranslationResult> results = translator.translate_batch(batch);

  for (const auto& token : results[0].output())
    std::cout << token << ' ';
  std::cout << std::endl;
  return 0;
}
