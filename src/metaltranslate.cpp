#include <iostream>
#include <ctranslate2/translator_pool.h>
#include <onmt/Tokenizer.h>

int main() {
  std::string source_str("Hello world, we are translating with MetalTranslate.");

  std::string model_dir("models/translate-fairseq_m2m_100_418M/");

  // Tokenizer
  onmt::Tokenizer tokenizer(model_dir + "sentencepiece.model");
  std::vector<std::string> tokens;
  tokenizer.tokenize(source_str, tokens);

  std::string source_prefix = "__en__";
  tokens.insert(tokens.begin(), source_prefix);

  std::cout << "Tokens:" << std::endl;
  for(const auto& token: tokens) std::cout << token << ' ';
  std::cout << std::endl;

  // CTranslate2
  const size_t num_translators = 1;
  const size_t num_threads_per_translator = 4;
  ctranslate2::TranslatorPool translator(num_translators,
                                         num_threads_per_translator,
                                         model_dir + "model",
                                         ctranslate2::Device::CPU);

  const std::vector<std::vector<std::string>> batch = {tokens};
  const std::vector<std::vector<std::string>> target_prefix = {{"__es__"}};
  const int max_batch_size = 2024;

  const std::vector<ctranslate2::TranslationResult> results = translator.translate_batch(
		  batch,
		  target_prefix);

  std::cout << "Translation Result:" << std::endl;

  for (const auto& token : results[0].output())
    std::cout << token << ' ';
  std::cout << std::endl;
  return 0;
}
