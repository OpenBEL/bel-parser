require './lib_bel.rb'
require 'benchmark'

SAMPLES = 1_000_000
puts Benchmark.benchmark(Benchmark::CAPTION, 7, Benchmark::FORMAT, "TOTAL:", "AVG:") { |bm|
  results = []
  SAMPLES.times {
    results << Benchmark.measure {
      LibBEL.tokenize_term('p(HGNC:AKT1)').each do |token|
        LibBEL.print_token(token)
      end
    }
  }
  [results.reduce(&:+), (results.reduce(&:+)) / SAMPLES]
}
