#ifndef MAJORDOMO_PRELUDE_H
#define MAJORDOMO_PRELUDE_H
#include <stdint.h>

#ifndef RFLOAT_VALUE
#define RFLOAT_VALUE(v) (RFLOAT(v)->value)
#endif

#include <ruby/encoding.h>
#include <ruby/io.h>

#ifdef HAVE_RUBY_THREAD_H
#include <ruby/thread.h>
#endif

extern rb_encoding *binary_encoding;
#define MajordomoEncode(str) rb_enc_associate(str, binary_encoding)

#endif
