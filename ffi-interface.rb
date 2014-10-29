#!/usr/bin/env ruby

module LibBEL

  class << self

    def rubinius?
      defined?(RUBY_ENGINE) && ("rbx" == RUBY_ENGINE)
    end

    # @api_private
    # Determine FFI constant for this ruby engine.
    def find_ffi
      if rubinius?
        if const_defined? "::Rubinius::FFI"
          ::Rubinius::FFI
        elsif const_defined? "::FFI"
          ::FFI
        else
          require "ffi"
          ::FFI
        end
      else # mri, jruby, etc
        require "ffi"
        ::FFI
      end
    end

    # @api_private
    # Extend with the correct ffi implementation.
    def load_ffi
      ffi_module = LibBEL::find_ffi
      extend ffi_module::Library
      ffi_module
    end

    # @api_private
    # Loads the libkyotocabinet shared library.
    def load_libBEL
      ffi_module = find_ffi
      extend ffi_module::Library

      begin
        ffi_lib "BEL"
      rescue LoadError
        begin
          ffi_lib "libBEL.so"
        rescue LoadError
          ffi_lib "./libBEL.so"
        end
      end
    end
  end

  # Constant holding the FFI module for this ruby engine.
  FFI = LibBEL::load_ffi
  LibBEL::load_libBEL

  # typedef enum bel_token_type
  enum :bel_token_type, [
    :IDENT,   0,
    :STRING,
    :O_PAREN,
    :C_PAREN,
    :COLON,
    :COMMA,
    :SPACES
  ]

  class BelToken < FFI::Struct
    layout :type,      :bel_token_type,
           :pos_start, :int,
           :pos_end,   :int,
           :value,     :pointer
  end

  class BelTokenList < FFI::Struct
    layout :length,    :int,
           :tokens,    BelToken.ptr
  end

  attach_function :bel_new_token,        [:bel_token_type, :pointer, :pointer, :pointer], :pointer
  attach_function :bel_new_token_list,   [:int                                         ], :pointer
  attach_function :tokenize_term,        [:string                                      ], :pointer
  attach_function :bel_print_token_list, [:pointer                                     ], :void
  attach_function :free_bel_token,       [:pointer                                     ], :void
  attach_function :free_bel_token_list,  [:pointer                                     ], :void
end

module LibBELApi
  extend LibBEL

  def self.bel_new_token(bel_token_type, string, offset, length)
    ptr = FFI::MemoryPointer.from_string(string)
    LibBEL::BelToken.new(
      super(:IDENT, ptr, ptr.slice(offset, 1), ptr.slice((offset + length), 1))
    )
  end

  def self.bel_new_token_list(length)
    LibBEL::BelTokenList.new(super(length))
  end

  def self.tokenize_term(string)
    LibBEL::BelTokenList.new(super(string))
  end
end

bel_token = LibBELApi::bel_new_token(:IDENT, 'p(HGNC:AKT1)', 2, 4)
puts "type: #{bel_token[:type]}, start: #{bel_token[:pos_start]}, end: #{bel_token[:pos_end]}, value: #{bel_token[:value].read_string}"
bel_token_list = LibBELApi::bel_new_token_list(256)
puts "list: #{bel_token_list[:length]}"
100_000.times {
  list = LibBELApi::tokenize_term('p(HGNC:AKT1)')
  LibBELApi::bel_print_token_list(list)
  LibBELApi::free_bel_token_list(list)
}
