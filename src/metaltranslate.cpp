#include <iostream>
#include <ctranslate2/translator_pool.h>
#include <onmt/Tokenizer.h>

int main() {
  std::string source_str("Hello world, we are translating with MetalTranslate.");

  onmt::Tokenizer tokenizer(onmt::Tokenizer::Mode::Conservative,
		  onmt::Tokenizer::Flags::JoinerAnnotate);
  std::vector<std::string> tokens;
  tokenizer.tokenize(source_str, tokens);
  for(const auto& token: tokens) std::cout << token << ' ';
  std::cout << std::endl;

  // CTranslate2
  const size_t num_translators = 1;
  const size_t num_threads_per_translator = 4;
  ctranslate2::TranslatorPool translator(num_translators,
                                         num_threads_per_translator,
                                         "models/test/",
                                         ctranslate2::Device::CPU);

  // const std::vector<std::vector<std::string>> batch = {{"▁H", "ello", "▁world", "!"}};
  const std::vector<std::vector<std::string>> batch = {tokens};
  const std::vector<ctranslate2::TranslationResult> results = translator.translate_batch(batch);

  for (const auto& token : results[0].output())
    std::cout << token << ' ';
  std::cout << std::endl;
  return 0;
}
